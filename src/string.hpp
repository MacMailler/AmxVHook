#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace String {
		void tokenize(const std::string & str, std::vector<std::string> & tokens, const std::string & delims = " ");
		void vformat(const char * format, std::string & out, va_list args);
		void format(AMX * amx, const cell * params, cell * f, std::string & out);
		void set(AMX * amx, cell param, std::string data, std::size_t size, bool pack = false);
		std::string get(AMX * amx, cell param);
		bool is_dec(std::string & data);
		bool is_hex(std::string & data);
	};
};