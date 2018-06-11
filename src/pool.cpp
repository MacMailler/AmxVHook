#include "pool.hpp"

extern "C" {
	int AMXEXPORT AMXAPI amx_CoreInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_CoreCleanup(AMX *amx);
	int AMXEXPORT AMXAPI amx_FloatInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_FloatCleanup(AMX *amx);
	int AMXEXPORT AMXAPI amx_StringInit(AMX *amx);
	int AMXEXPORT AMXAPI amx_StringCleanup(AMX *amx);
}


namespace AmxVHook {
	boost::shared_ptr<Pool> gPool;
	extern boost::shared_ptr<Debug> gDebug;


	Pool::Pool() {
		this->location = "AmxVHook\\mods";

		boost::filesystem::path path = boost::filesystem::system_complete(boost::filesystem::path(this->location, boost::filesystem::native));
		if (!boost::filesystem::exists(path))
			boost::filesystem::create_directory(path);
	}

	Pool::~Pool() {
		this->clear();
	}

	void Pool::make() {
		gDebug->log("Pool initing...");

		boost::filesystem::path mods = boost::filesystem::system_complete(boost::filesystem::path(this->location, boost::filesystem::native));
		if (!boost::filesystem::exists(mods) || !boost::filesystem::is_directory(mods)) {
			gDebug->log("Mods directory not found!");
			return;
		}

		gDebug->log("Loading mods from '%s'", mods.string().c_str());

		boost::filesystem::directory_iterator end;
		for (boost::filesystem::directory_iterator it(mods); it != end; ++it) {
			if (it->path().extension() == ".amx") {
				this->loadMod(it->path());
			}
		}

		gDebug->log("Loaded %d mods!", pool.size());
	}

	cell Pool::loadAmx(AMX * amx, char * path, const char * name) {
		cell err = AMX_ERR_NONE;

		gDebug->log("Loading mod '%s'...", name);

		if ((err = aux_LoadProgram(amx, path, NULL)) == AMX_ERR_NONE) {
			amx_CoreInit(amx);
			amx_FloatInit(amx);
			amx_StringInit(amx);

			for (const auto& list : natives)
				err = amx_Register(amx, list, -1);

			if (err == AMX_ERR_NONE) {
				int num;
				amx_NumNatives(amx, &num);
				gDebug->log("Mod '%s' loaded! Registred natives: %d", name, num);
				this->exec(amx, "onModLoad");
			}
			else {
				gDebug->log("Failed to load '%s' mod! %s", name, aux_StrError(err));
				aux_FreeProgram(amx);
			}
		}
		else gDebug->log("Failed to load '%s' mod. %s!", name, aux_StrError(err));

		return err;
	}

	void Pool::clear() {
		for (const auto& i : pool) {
			amx_StringCleanup(i.second.amx);
			amx_FloatCleanup(i.second.amx);
			amx_CoreCleanup(i.second.amx);
			aux_FreeProgram(i.second.amx);
			delete i.second.amx;
		}
		pool.clear();

		gDebug->log("All mods unloaded!");
	}

	void Pool::remake() {
		this->clear();
		this->make();
	}

	std::unordered_map<std::string, Mod>::iterator & Pool::find(std::string & name) {
		return pool.find(name);
	}

	size_t Pool::size() {
		return this->pool.size();
	}

	cell Pool::loadMod(boost::filesystem::path path) {
		Mod mod;
		cell err;

		mod.amx = new AMX;
		mod.path = path;

		err = this->loadAmx(mod.amx, (char *)path.string().c_str(), path.filename().string().c_str());
		if (err == AMX_ERR_NONE)
			pool.insert({ path.stem().string(), mod });

		return err;
	}

	bool Pool::unloadMod(std::string & name) {
		gDebug->log("Unloading mod '%s.amx'...", name.c_str());

		auto i = pool.find(name);
		if (!i->first.empty()) {
			this->exec(i->second.amx, "onModUnload");

			amx_StringCleanup(i->second.amx);
			amx_FloatCleanup(i->second.amx);
			amx_CoreCleanup(i->second.amx);
			aux_FreeProgram(i->second.amx);

			delete i->second.amx;

			pool.erase(name);

			return true;
		}
		return false;
	}

	bool Pool::reloadMod(std::string & name) {
		gDebug->log("Unloading mod '%s.amx'...", name.c_str());
	
		std::unordered_map<std::string, Mod>::iterator i = pool.find(name);
		if (!i->first.empty()) {
			this->exec(i->second.amx, "onModUnload");

			amx_StringCleanup(i->second.amx);
			amx_FloatCleanup(i->second.amx);
			amx_CoreCleanup(i->second.amx);
			aux_FreeProgram(i->second.amx);

			gDebug->log("Mod '%s.amx' unloaded!", name.c_str());

			if (this->loadAmx(i->second.amx, (char *)i->second.path.string().c_str(), i->second.path.filename().string().c_str()) == AMX_ERR_NONE)
				return true;
		}
		return false;
	}

	void Pool::setLocation(std::string dir) {
		this->location = dir;
	}

	void Pool::setNatives(std::list<AMX_NATIVE_INFO *> n) {
		this->natives = n;
	}

	cell Pool::exec(AMX * amx, const char * funcname) {
		cell ret;
		int index;
		if (amx_FindPublic(amx, funcname, &index) == AMX_ERR_NONE)
			amx_Exec(amx, &ret, index);

		return ret;
	}

	cell Pool::execAll(const char * funcname) {
		cell count = 0;
		for (const auto& i : pool) {
			cell ret;
			int index;
			if (amx_FindPublic(i.second.amx, funcname, &index) == AMX_ERR_NONE) {
				count++;
				amx_Exec(i.second.amx, &ret, index);
			}
		}
		return count;
	}

	void Pool::onModInputText(char *text) {
		for (const auto& i : pool) {
			int index;
			cell ret, amx_addr, *phys_addr;
			if (amx_FindPublic(i.second.amx, "onModInputText", &index) == AMX_ERR_NONE) {
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, text, 0, 0);
				amx_Exec(i.second.amx, &ret, index);
				amx_Release(i.second.amx, amx_addr);
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