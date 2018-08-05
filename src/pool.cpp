#include "pool.hpp"

extern "C" {
	int AMXEXPORT AMXAPI amx_CoreInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_CoreCleanup(AMX *amx);
	int AMXEXPORT AMXAPI amx_FloatInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_FloatCleanup(AMX *amx);
	int AMXEXPORT AMXAPI amx_StringInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_StringCleanup(AMX *amx);
	int AMXEXPORT AMXAPI amx_FileInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_FileCleanup(AMX *amx);
}


namespace AmxVHook {

	boost::shared_ptr<Pool> gPool;
	extern boost::shared_ptr<Debug> gDebug;

	Pool::Pool() {
		this->location = boost::filesystem::system_complete("AmxVHook\\Mods");

		if (!boost::filesystem::exists(this->location))
			boost::filesystem::create_directory(this->location);
	}

	Pool::~Pool() {
		this->clear();
	}

	void Pool::make() {
		gDebug->log("Pool initing...");

		if (!boost::filesystem::exists(this->location) || !boost::filesystem::is_directory(this->location)) {
			gDebug->log("Mods directory not found!");
			return;
		}

		gDebug->log("Loading mods from '%s'", this->location.string().c_str());

		boost::filesystem::directory_iterator end;
		for (boost::filesystem::directory_iterator it(this->location); it != end; ++it) {
			if (it->path().extension() == ".amx") {
				this->loadMod((boost::filesystem::path)it->path());
			}
		}

		gDebug->log("Loaded %d mods!", pool.size());
	}

	cell Pool::loadAmx(AMX * amx, boost::filesystem::path & path) {
		cell err = AMX_ERR_NONE;
		std::string name = path.filename().string();

		gDebug->log("Loading mod '%s'...", name);

		if ((err = Utility::Amx::load(amx, (std::string)path.string())) == AMX_ERR_NONE) {
			amx_CoreInit(amx);
			amx_FloatInit(amx);
			amx_StringInit(amx);
			amx_FileInit(amx);

			for (const auto& list : natives)
				err = amx_Register(amx, list, -1);

			if (err == AMX_ERR_NONE) {
				gDebug->log("Mod '%s' loaded! Registred natives: %d", name, Utility::Amx::getNumNatives(amx));

				this->exec(amx, "onModLoad");
			}
			else {
				gDebug->log("Failed to load '%s' mod! %s", name, Utility::Amx::errorToString(err));
				Utility::Amx::cleanup(amx);
			}
		}
		else gDebug->log("Failed to load '%s' mod. %s!", name, Utility::Amx::errorToString(err));

		return err;
	}

	void Pool::clear() {
		for (const auto& i : pool) {
			amx_FileCleanup(i.second.amx);
			amx_StringCleanup(i.second.amx);
			amx_FloatCleanup(i.second.amx);
			amx_CoreCleanup(i.second.amx);
			Utility::Amx::cleanup(i.second.amx);
			delete i.second.amx;
		}
		pool.clear();

		gDebug->log("All mods unloaded!");
	}

	void Pool::remake() {
		this->clear();
		this->make();
	}

	std::unordered_map<std::string, Mod>::iterator Pool::find(std::string & name) {
		return pool.find(name);
	}

	bool Pool::contains(std::string & name) {
		return pool.find(name) != pool.end();
	}

	size_t Pool::size() {
		return pool.size();
	}

	cell Pool::loadMod(boost::filesystem::path & path) {
		Mod mod;
		cell err;

		mod.amx = new AMX;
		mod.path = path;

		err = this->loadAmx(mod.amx, path);
		if (err == AMX_ERR_NONE)
			pool.insert({ path.stem().string(), mod });

		return err;
	}

	bool Pool::unloadMod(std::string & name) {
		gDebug->log("Unloading mod '%s.amx'...", name.c_str());

		if (!this->contains(name))
			return false;

		this->exec(pool[name].amx, "onModUnload");

		amx_StringCleanup(pool[name].amx);
		amx_FloatCleanup(pool[name].amx);
		amx_CoreCleanup(pool[name].amx);
		Utility::Amx::cleanup(pool[name].amx);

		delete pool[name].amx;

		pool.erase(name);

		return true;
	}

	bool Pool::reloadMod(std::string & name) {
		gDebug->log("Unloading mod '%s.amx'...", name.c_str());

		if (!this->contains(name))
			return false;

		this->exec(pool[name].amx, "onModUnload");

		amx_StringCleanup(pool[name].amx);
		amx_FloatCleanup(pool[name].amx);
		amx_CoreCleanup(pool[name].amx);
		Utility::Amx::cleanup(pool[name].amx);

		gDebug->log("Mod '%s.amx' unloaded!", name.c_str());

		if (this->loadAmx(pool[name].amx, pool[name].path) == AMX_ERR_NONE)
			return true;

		return false;
	}

	void Pool::setLocation(boost::filesystem::path & dir) {
		this->location = dir;
	}

	void Pool::setNatives(std::list<AMX_NATIVE_INFO *> n) {
		this->natives = n;
	}

	boost::filesystem::path Pool::getLocation() {
		return this->location;
	}

	cell Pool::exec(AMX * amx, const std::string & funcname, std::stack<boost::variant<cell, std::string>> * params) {
		int index;
		cell ret;
		if (amx_FindPublic(amx, funcname.c_str(), &index) == AMX_ERR_NONE) {
			if (params != nullptr) {
				std::queue<cell> amxAddr;
				while (!params->empty()) {
					boost::variant<cell, std::string> value = std::move(params->top());
					if (value.type() == typeid(cell)) {
						amx_Push(amx, boost::get<cell>(value));
					}
					else {
						cell tempAddr;
						amx_PushString(amx, &tempAddr, NULL, boost::get<std::string>(value).c_str(), 0, 0);
						amxAddr.push(tempAddr);
					}
					params->pop();
				}
				amx_Exec(amx, &ret, index);
				while (!amxAddr.empty())
					amx_Release(amx, amxAddr.front()), amxAddr.pop();
			}
			else {
				amx_Exec(amx, &ret, index);
			}
		}

		return ret;
	}

	void Pool::execAll(const std::string & funcname, std::stack<boost::variant<cell, std::string>> * params) {
		for (const auto& i : pool)
			this->exec(i.second.amx, funcname, params);
	}

	void Pool::onModInputText(char *text) {
		for (const auto& i : pool) {
			int index;
			cell ret, amx_addr, *phys_addr;
			if (amx_FindPublic(i.second.amx, "onModInputText", &index) == AMX_ERR_NONE) {
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, text, 0, 0);
				amx_Exec(i.second.amx, &ret, index);
				amx_Release(i.second.amx, amx_addr);

				if (ret == 1)
					break;
			}
		}
	}

	void Pool::onModInputCommand(char * cmd, cell params) {
		for (const auto& i : pool) {
			int index;
			cell ret, amx_addr, *phys_addr;
			if (amx_FindPublic(i.second.amx, "onModInputCommand", &index) == AMX_ERR_NONE) {
				amx_Push(i.second.amx, params);
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, cmd, 0, 0);
				amx_Exec(i.second.amx, &ret, index);
				amx_Release(i.second.amx, amx_addr);

				if (ret == 1)
					break;
			}
		}
	}
};