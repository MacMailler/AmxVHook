#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace String {
		void set(AMX *amx, cell param, std::string data, std::size_t size);
		std::string get(AMX * amx, cell param);
		int getArr(AMX* amx, cell param, char*& dest);
		bool is_dec(std::string &data);
		bool is_hex(std::string &data);
	};
};