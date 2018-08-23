#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	struct Mod {
		AMX * amx;
		Fs::path path;
	};

	class Pool : NonCopy {
	private:
		std::unordered_map<std::string, Mod> pool;
		std::list<AMX_NATIVE_INFO *> natives;
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

		std::unordered_map<std::string, Mod>::iterator find(std::string & name);
		std::unordered_map<std::string, Mod>::iterator find(AMX * amx);

		bool contains(std::string & name);
		size_t size();

		cell loadMod(Fs::path & path);
		bool unloadMod(std::string & name);
		bool reloadMod(std::string & name);

		void setLocation(Fs::path & dir);
		void setNatives(std::list<AMX_NATIVE_INFO *> n);

		Fs::path getLocation();

		cell exec(AMX * amx, const std::string & funcname, std::stack<std::variant<cell, std::string>> * params = nullptr);
		void execAll(const std::string & funcname, std::stack<std::variant<cell, std::string>> * params = nullptr);

		void onModInputText(const char * text);
		void onModInputCommand(const std::string & cmd, cell params);
	};
};