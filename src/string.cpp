#include "string.hpp"

namespace AmxVHook {
	namespace String {
		void format(AMX * amx, const cell * params, cell * f, std::string & out) {
			cell index = 0, *ptr = nullptr;
			char buff[32];
	
			while (*f != '\0') {
				switch (*f) {
				case '%': {
					switch (*(++f)) {
					case 'i':
					case 'd': {
						ptr = Utility::getAddrFromParam(amx, params[index++]);
						if (ptr != nullptr) {
							#if PAWN_CELL_SIZE == 64
								sprintf_s(buff, "%lld", *ptr);
							#else
								sprintf_s(buff, "%d", *ptr);
							#endif
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
							#if PAWN_CELL_SIZE == 64
								sprintf_s(buff, *f == 'x' ? "%llx" : "%llX", *ptr);
							#else
								sprintf_s(buff, *f == 'x' ? "%x" : "%X", *ptr);
							#endif
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
						std::string fstr("%0");
						while (*(++f) >= '0' && '9' >= *f)
							fstr.push_back((char)*f);

						switch (*f) {
						case 'i':
						case 'd': {
							ptr = Utility::getAddrFromParam(amx, params[index++]);
							if (ptr != nullptr) {
								#if PAWN_CELL_SIZE == 64
									fstr.append({ 'l', 'l', (char)*f });
								#else
									fstr.push_back((char)*f);
								#endif
								sprintf(buff, fstr.c_str(), *ptr);
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
								fstr.push_back((char)*f);
								sprintf(buff, fstr.c_str(), amx_ctof(*ptr));
								out.append(buff);
							}
							else {
								out.append("(null)");
							}
							f++;
						}
						break;

						case '.': {
							fstr.push_back((char)*f);

							while (*(++f) >= '0' && '9' >= *f)
								fstr.push_back((char)*f);

							if (*f == 'f') {
								ptr = Utility::getAddrFromParam(amx, params[index++]);
								if (ptr != nullptr) {
									fstr.push_back((char)*f);
									sprintf(buff, fstr.c_str(), amx_ctof(*ptr));
									out.append(buff);
								}
								else {
									out.append("(null)");
								}
							}
							else {
								fstr.push_back((char)*f);
								out.append(fstr);
							}
							f++;
						}
						break;
						#endif

						case 'x':
						case 'X': {
							ptr = Utility::getAddrFromParam(amx, params[index++]);
							if (ptr != nullptr) {
								#if PAWN_CELL_SIZE == 64
									fstr.append({'l', 'l', (char)*f});
								#else
									fstr.push_back((char)*f);
								#endif

								sprintf_s(buff, fstr.c_str(), *ptr);
								out.append(buff);
							}
							else {
								out.append("(null)");
							}
							f++;
						}
						break;

						default:
							out.append(fstr);
						}
					}
					break;

					default:
						out.push_back(*(f++));
					}
				}
				break;

				default:
					out.push_back(*(f++));
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
			amx_StrParam(amx, param, dest);
			
			if (dest != NULL)
				return std::string(dest);

			return std::string("");
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