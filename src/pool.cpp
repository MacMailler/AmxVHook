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

	std::shared_ptr<Pool> gPool;
	extern std::shared_ptr<Log> gLog;

	Pool::Pool() : location(Fs::system_complete(".")) {}
	Pool::Pool(const std::string & dir) : location(Fs::system_complete(dir)) {}

	Pool::~Pool() {
		clear();
	}

	void Pool::make() {
		gLog->log("Pool initing...");

		if (Fs::exists(location) && Fs::is_directory(location)) {
			gLog->log("Loading mods from '%s'", location.string().c_str());

			Fs::directory_iterator end;
			for (Fs::directory_iterator it(location); it != end; ++it) {
				if (it->path().extension() == ".amx") {
					this->loadMod((Fs::path)it->path());
				}
			}

			gLog->log("Loaded %d mods!", pool.size());
		}
		else {
			gLog->log("Mods directory not found!");
		}
	}

	cell Pool::loadAmx(AMX * amx, Fs::path & path) {
		cell err = AMX_ERR_NONE;
		std::string name = path.filename().string();

		gLog->log("Loading mod '%s'...", name);

		if ((err = Aux::load(amx, (std::string)path.string())) == AMX_ERR_NONE) {
			amx_CoreInit(amx);
			amx_FloatInit(amx);
			amx_StringInit(amx);
			amx_FileInit(amx);

			for (const auto& list : natives)
				err = amx_Register(amx, list, -1);

			if (err == AMX_ERR_NONE) {
				gLog->log("Mod '%s' loaded! Registred natives: %d", name, Aux::getNumNatives(amx));
#if defined AMXDBG
				uint16_t flags;
				amx_Flags(amx, &flags);
				if ((flags & AMX_FLAG_DEBUG) == 0)
					gLog->log("Debug info: '%s' has no debug information!", name);
#endif
				this->exec(amx, "onModLoad");
			}
			else {
				gLog->log("Failed to load '%s' mod! %s", name, Aux::strError(err));
				Aux::cleanup(amx);
			}
		}
		else gLog->log("Failed to load '%s' mod. %s!", name, Aux::strError(err));

		return err;
	}

	void Pool::clear() {
		for (const auto& i : pool) {
			amx_FileCleanup(i.second.amx);
			amx_StringCleanup(i.second.amx);
			amx_FloatCleanup(i.second.amx);
			amx_CoreCleanup(i.second.amx);
			Aux::cleanup(i.second.amx);
			delete i.second.amx;
		}
		pool.clear();

		gLog->log("All mods unloaded!");
	}

	void Pool::remake() {
		this->clear();
		this->make();
	}

	ModPool::iterator Pool::find(std::string & name) {
		return pool.find(name);
	}

	ModPool::iterator Pool::find(AMX * amx) {
		ModPool::iterator i = pool.begin();

		while (i != pool.end()) {
			if (i->second.amx == amx)
				return i;

			i++;
		}

		return i;
	}

	bool Pool::contains(std::string & name) {
		return pool.find(name) != pool.end();
	}

	size_t Pool::size() {
		return pool.size();
	}

	cell Pool::loadMod(Fs::path & path) {
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
		gLog->log("Unloading mod '%s.amx'...", name.c_str());

		if (!this->contains(name))
			return false;

		this->exec(pool[name].amx, "onModUnload");

		amx_StringCleanup(pool[name].amx);
		amx_FloatCleanup(pool[name].amx);
		amx_CoreCleanup(pool[name].amx);
		Aux::cleanup(pool[name].amx);

		delete pool[name].amx;

		pool.erase(name);

		return true;
	}

	bool Pool::reloadMod(std::string & name) {
		gLog->log("Unloading mod '%s.amx'...", name.c_str());

		if (!this->contains(name))
			return false;

		this->exec(pool[name].amx, "onModUnload");

		amx_StringCleanup(pool[name].amx);
		amx_FloatCleanup(pool[name].amx);
		amx_CoreCleanup(pool[name].amx);
		Aux::cleanup(pool[name].amx);

		gLog->log("Mod '%s.amx' unloaded!", name.c_str());

		if (this->loadAmx(pool[name].amx, pool[name].path) == AMX_ERR_NONE)
			return true;

		return false;
	}

	void Pool::setLocation(Fs::path & dir) {
		this->location = dir;
	}

	void Pool::setNatives(NativeList n) {
		this->natives = n;
	}

	Fs::path Pool::getLocation() {
		return this->location;
	}

	cell Pool::exec(AMX * amx, const std::string & funcname, AmxArgs * params) {
		return execByIndex(amx, Aux::getPublicIndex(amx, funcname), params);
	}

	cell Pool::execByIndex(AMX * amx, const int index, AmxArgs * params) {
		cell ret;

		if (index >= 0 && index < Aux::getNumPublics(amx)) {
			if (params != nullptr) {
				std::queue<cell> amxAddr;
				while (!params->empty()) {
					std::variant<cell, std::string> value = std::move(params->top());
					if (std::holds_alternative<cell>(value)) {
						amx_Push(amx, std::get<cell>(value));
					}
					else {
						cell tempAddr;
						amx_PushString(amx, &tempAddr, NULL, std::get<std::string>(value).data(), 0, 0);
						amxAddr.push(tempAddr);
					}
					params->pop();
				}
				handleExecError(amx, amx_Exec(amx, &ret, index));
				while (!amxAddr.empty())
					amx_Release(amx, amxAddr.front()), amxAddr.pop();
			}
			else {
				handleExecError(amx, amx_Exec(amx, &ret, index));
			}
		}

		return ret;
	}

	void Pool::execAll(const std::string & funcname, AmxArgs * params) {
		for (const auto& i : pool)
			this->exec(i.second.amx, funcname, params);
	}

	void Pool::onModInputText(const char * text) {
		for (const auto& i : pool) {
			int index;
			cell ret, amx_addr, *phys_addr;
			if (amx_FindPublic(i.second.amx, "onModInputText", &index) == AMX_ERR_NONE) {
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, text, 0, 0);
				handleExecError(i.second.amx, amx_Exec(i.second.amx, &ret, index));
				amx_Release(i.second.amx, amx_addr);

				if (ret == 1)
					break;
			}
		}
	}

	void Pool::onModInputCommand(const std::string & cmd, cell params) {
		for (const auto& i : pool) {
			int index;
			cell ret, amx_addr, *phys_addr;
			if (amx_FindPublic(i.second.amx, "onModInputCommand", &index) == AMX_ERR_NONE) {
				amx_Push(i.second.amx, params);
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, cmd.c_str(), 0, 0);
				handleExecError(i.second.amx, amx_Exec(i.second.amx, &ret, index));
				amx_Release(i.second.amx, amx_addr);

				if (ret == 1)
					break;
			}
		}
	}

	void Pool::handleExecError(AMX * amx,  int err) {
		if (err != AMX_ERR_NONE) {
			auto i = find(amx);
#if defined AMXDBG
			AMX_DBG amxdbg;
			FILE *fp = fopen(i->second.path.string().data(), "rb");
			if (fp) {
				if (dbg_LoadInfo(&amxdbg, fp) == AMX_ERR_NONE) {
					long line;
					const char *filename, *funcname;

					dbg_LookupFile(&amxdbg, amx->cip, &filename);
					dbg_LookupFunction(&amxdbg, amx->cip, &funcname);
					dbg_LookupLine(&amxdbg, amx->cip, &line);
					dbg_FreeInfo(&amxdbg);

					gLog->log("%s.amx: Error #%d \"%s\"", i->first, err, Aux::strError(err));
					gLog->log("Debug info: 0x%08lX in %s () at %s:%ld", (long)amx->cip, funcname, filename, line);
				}
				else {
					gLog->log("%s.amx: Error #%d \"%s\" on address 0x%08lX", i->first, err, Aux::strError(err), (long)amx->cip);
				}
			}
#else
			gLog->log("%s.amx: Error #%d \"%s\" on address 0x%08lX", i->first, err, Aux::strError(err), (long)amx->cip);
#endif
		}
	}
};