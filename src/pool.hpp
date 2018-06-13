#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	struct Mod {
		AMX * amx;
		boost::filesystem::path path;
	};

	class Pool : boost::noncopyable {
	private:
		std::unordered_map<std::string, Mod> pool;
		std::list<AMX_NATIVE_INFO *> natives;
		std::string location;

		cell loadAmx(AMX * amx, char * path, const char * name);

	public:
		Pool();
		~Pool();
		
		void make();
		void clear();
		void remake();

		std::unordered_map<std::string, Mod>::iterator find(std::string & name);
		size_t size();

		cell loadMod(boost::filesystem::path path);
		bool unloadMod(std::string & name);
		bool reloadMod(std::string & name);

		void setLocation(std::string dir);
		void setNatives(std::list<AMX_NATIVE_INFO *> n);

		cell exec(AMX * amx, const char * funcname);
		cell execAll(const char * funcname);

		void onModInputText(char * text);
		void onModInputCommand(char * cmd, cell params);
	};
};