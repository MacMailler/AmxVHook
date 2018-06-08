#include "string.hpp"

namespace AmxVHook {
	namespace String {
		void set(AMX * amx, cell param, std::string data, std::size_t size) {
			cell *dest = NULL;

			amx_GetAddr(amx, param, &dest);
			amx_SetString(dest, data.c_str(), NULL, NULL, size);
		}

		std::string get(AMX * amx, cell param) {
			char * dest = NULL;

			getArr(amx, param, dest);
			std::string ret(dest);

			free(dest);

			return ret;
		}

		int getArr(AMX* amx, cell param, char*& dest) {
			cell *ptr;
			int len;
			amx_GetAddr(amx, param, &ptr);
			amx_StrLen(ptr, &len);
			dest = (char *)malloc((len * sizeof(char)) + 1);
			amx_GetString(dest, ptr, 0, UNLIMITED);
			dest[len] = '\0';
			return len;
		}

		bool is_dec(std::string &data) {
			for (int i = 0; i < data.size(); i++) {
				if ((i == 0) && (data[i] == '-'))
					continue;

				if (!isdigit(data[i]))
					return false;
			}
			return true;
		}

		bool is_hex(std::string &data) {
			for (int i = 0; i < data.size(); i++) {
				if (!isxdigit(data[i]))
					return false;
			}
			return true;
		}
	};
};