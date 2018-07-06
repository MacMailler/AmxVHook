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
		boost::filesystem::path location;

		cell loadAmx(AMX * amx, boost::filesystem::path & path);

	public:
		Pool();
		~Pool();
		
		void make();
		void clear();
		void remake();

		std::unordered_map<std::string, Mod>::iterator find(std::string & name);
		bool contains(std::string & name);
		size_t size();

		cell loadMod(boost::filesystem::path & path);
		bool unloadMod(std::string & name);
		bool reloadMod(std::string & name);

		void setLocation(boost::filesystem::path & dir);
		void setNatives(std::list<AMX_NATIVE_INFO *> n);

		boost::filesystem::path getLocation();

		cell exec(AMX * amx, const std::string & funcname, std::stack<boost::variant<cell, std::string>> * params = nullptr);
		void execAll(const std::string & funcname, std::stack<boost::variant<cell, std::string>> * params = nullptr);

		void onModInputText(char * text);
		void onModInputCommand(char * cmd, cell params);
	};
};