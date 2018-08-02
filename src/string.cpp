#include "string.hpp"

namespace AmxVHook {
	namespace String {
		void format(AMX * amx, const cell * params, cell * f, std::string & out) {
			cell index = 0;

			while (*f != '\0') {
				char buff[32];
				cell * ptr = nullptr;

				switch (*f) {
				case '%': {
					f++;
					switch (*f) {
					case 'i':
					case 'd': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							sprintf_s(buff, "%i", *ptr);
							out.append(buff);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case 'c': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							out.push_back(*ptr);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case 'x':
					case 'X': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							sprintf_s(buff, *f == 'x' ? "%x" : "%X", *ptr);
							out.append(buff);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					#ifdef FLOATPOINT
					case 'f': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							sprintf_s(buff, "%f", amx_ctof(*ptr));
							out.append(buff);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case '.': {
						char fstr[] = { '%', '.', (char)*(++f), 'f', '\0' };

						if (*(++f) == 'f') {
							ptr = Utility::getAddrFromParam(amx, params[index++]);
							if (ptr != nullptr) {
								sprintf(buff, fstr, amx_ctof(*ptr));
								out.append(buff);
							}
							else {
								out.append("(null)");
							}
						}
						else {
							out.append({ '%', '.', fstr[2] });
						}
						f++;
					}
					break;
					#endif

					case 'b': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							out.append(*ptr == 0 ? "false" : "true");
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case 's': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							while (*ptr != '\0') {
								out.push_back(*ptr);
								ptr++;
							}
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case '0': {
						char fstr[] = { '%', '0', (char)*(++f), 'i', '\0' };

						switch (*(++f)) {
						case 'i':
						case 'd': {
							ptr = Utility::getAddrFromParam(amx, params[index++]);
							if (ptr != nullptr) {
								sprintf(buff, fstr, *ptr);
								out.append(buff);
							}
							else {
								out.append("(null)");
							}
						}
						break;

						case 'x':
						case 'X': {
							fstr[3] = (char)*f;
							ptr = Utility::getAddrFromParam(amx, params[index++]);
							if (ptr != nullptr) {
								sprintf_s(buff, fstr, *ptr);
								out.append(buff);
							}
							else {
								out.append("(null)");
							}
						}
						break;

						default:
							out.append({ '%', '0', (char)*f });
						}
						f++;
					}
					break;

					default:
						out.push_back(*f), f++;
					}
				}
				break;

				default:
					out.push_back(*f), f++;
				}
			}
		}

		void set(AMX * amx, cell param, std::string data, std::size_t size, bool pack) {
			cell *dest = NULL;

			amx_GetAddr(amx, param, &dest);
			amx_SetString(dest, data.c_str(), pack, NULL, size);
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