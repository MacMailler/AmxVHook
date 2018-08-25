#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	struct Mod {
		AMX * amx;
		Fs::path path;
	};
	
	class Pool : NonCopy {
	private:
		ModPool pool;
		NativeList natives;
		Fs::path location;

		cell loadAmx(AMX * amx, Fs::path & path);
		void handleExecError(AMX * amx, int err);

	public:
		Pool();
		Pool(const std::string & dir);
		~Pool();
		
		void make();
		void clear();
		void remake();

		ModPool::iterator find(std::string & name);
		ModPool::iterator find(AMX * amx);

		bool contains(std::string & name);
		size_t size();

		cell loadMod(Fs::path & path);
		bool unloadMod(std::string & name);
		bool reloadMod(std::string & name);

		void setLocation(Fs::path & dir);
		void setNatives(NativeList n);

		Fs::path getLocation();

		cell exec(AMX * amx, const std::string & funcname, AmxArgs * params = nullptr);
		void execAll(const std::string & funcname, AmxArgs * params = nullptr);

		void onModInputText(const char * text);
		void onModInputCommand(const std::string & cmd, cell params);
	};
};