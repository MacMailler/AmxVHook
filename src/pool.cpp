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
				registerPublics(amx);
				execByIndex(amx, publics[amx].def.onModLoad);
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
		publics.clear();

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

		auto i = pool.find(name);

		if (i == pool.end())
			return false;

		execByIndex(i->second.amx, publics[i->second.amx].def.onModUnload);

		amx_StringCleanup(i->second.amx);
		amx_FloatCleanup(i->second.amx);
		amx_CoreCleanup(i->second.amx);
		Aux::cleanup(i->second.amx);

		delete i->second.amx;

		pool.erase(i);
		publics.erase(i->second.amx);

		return true;
	}

	bool Pool::reloadMod(std::string & name) {
		gLog->log("Unloading mod '%s.amx'...", name);

		auto i = pool.find(name);

		if (i == pool.end())
			return false;

		execByIndex(i->second.amx, publics[i->second.amx].def.onModUnload);

		amx_StringCleanup(i->second.amx);
		amx_FloatCleanup(i->second.amx);
		amx_CoreCleanup(i->second.amx);
		Aux::cleanup(i->second.amx);

		publics.erase(i->second.amx);

		gLog->log("Mod '%s.amx' unloaded!", name);

		if (this->loadAmx(i->second.amx, i->second.path) == AMX_ERR_NONE)
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

	cell Pool::exec(AMX* amx, const std::string & funcname, AmxArgs* params) {
		auto i = publics[amx].usr.find(funcname);
		if (i != publics[amx].usr.end())
			return execByIndex(amx, i->second, params);

		return 0;
	}

	cell Pool::execByIndex(AMX* amx, const int index, AmxArgs* params) {
		cell ret;

		if (index >= 0 && index < Aux::getNumPublics(amx)) {
			if (params != nullptr) {
				cell amxAddr = -1;
				while (!params->empty()) {
					std::variant<cell, std::string> value = std::move(params->top());
					if (std::holds_alternative<cell>(value)) {
						amx_Push(amx, std::get<cell>(value));
					}
					else {
						cell tempAddr;
						amx_PushString(amx, &tempAddr, NULL, std::get<std::string>(value).data(), 0, 0);
						if (amxAddr < NULL)
							amxAddr = tempAddr;
					}
					params->pop();
				}
				handleExecError(amx, amx_Exec(amx, &ret, index));
				if (amxAddr >= NULL)
					amx_Release(amx, amxAddr);
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

	void Pool::onModUpdate() {
		for (const auto& i : pool)
			execByIndex(i.second.amx, publics[i.second.amx].def.onModUpdate);
	}

	void Pool::onModInputText(const char * text) {
		for (const auto& i : pool) {
			cell ret, amx_addr, *phys_addr;
			if (publics[i.second.amx].def.onModInputText != -1) {
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, text, 0, 0);
				handleExecError(i.second.amx, amx_Exec(i.second.amx, &ret, publics[i.second.amx].def.onModInputText));
				amx_Release(i.second.amx, amx_addr);

				if (ret == 1)
					break;
			}
		}
	}

	void Pool::onModInputCommand(const std::string & cmd, cell params) {
		for (const auto& i : pool) {
			cell ret, amx_addr, *phys_addr;
			if (publics[i.second.amx].def.onModInputCommand != -1) {
				amx_Push(i.second.amx, params);
				amx_PushString(i.second.amx, &amx_addr, &phys_addr, cmd.c_str(), 0, 0);
				handleExecError(i.second.amx, amx_Exec(i.second.amx, &ret, publics[i.second.amx].def.onModInputCommand));
				amx_Release(i.second.amx, amx_addr);

				if (ret == 1)
					break;
			}
		}
	}

	void Pool::onModInputAborted() {
		for (const auto& i : pool)
			execByIndex(i.second.amx, publics[i.second.amx].def.onModInputAborted);
	}

	void Pool::registerPublics(AMX * amx) {
		const AMX_FUNCSTUBNT * pubs = Aux::getPublics(amx);
		const int count = Aux::getNumPublics(amx);
		
		auto i = publics.insert({ amx, { {-1}, {} } });

		i.first->second.def.onModLoad			= Aux::getPublicIndex(amx, "onModLoad");
		i.first->second.def.onModUnload			= Aux::getPublicIndex(amx, "onModUnload");
		i.first->second.def.onModUpdate			= Aux::getPublicIndex(amx, "onModUpdate");
		i.first->second.def.onModInputText		= Aux::getPublicIndex(amx, "onModInputText");
		i.first->second.def.onModInputCommand	= Aux::getPublicIndex(amx, "onModInputCommand");
		i.first->second.def.onModInputAborted	= Aux::getPublicIndex(amx, "onModInputAborted");

		for (int j = 0; j < count; j++)
			i.first->second.usr.insert({ Aux::getPublicName(amx, pubs[j].nameofs), j });
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
					gLog->log("Debug info: 0x%08lX in %s () at %s:%ld", (ucell)amx->cip, funcname, filename, line);
				}
				else {
					gLog->log("%s.amx: Error #%d \"%s\" on address 0x%016lX", i->first, err, Aux::strError(err), (ucell)amx->cip);
				}
			}
		#else
			gLog->log("%s.amx: Error #5 \"%s\" on address 0x%016lX", i->first, err, Aux::strError(err), (ucell)amx->cip);
		#endif
		}
	}
};