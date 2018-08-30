#include "string.hpp"

namespace AmxVHook {
	namespace String {
		void tokenize(const std::string & str, std::vector<std::string> & tokens, const std::string & delims) {
			size_t pos, lastPos = 0, length = str.length();

			while (lastPos < length + 1) {
				pos = str.find_first_of(delims, lastPos);
				if (pos == std::string::npos)
					pos = length;

				if (pos != lastPos)
					tokens.emplace_back(str.data() + lastPos, pos - lastPos);

				lastPos = pos + 1;
			}
		}

		void vformat(const char * format, std::string & out, va_list args) {
			const size_t maxBufSize = 1024 * 1000;
			size_t length = vsnprintf(NULL, NULL, format, args);

			char * buffer = (char *)alloca(++length > maxBufSize ? maxBufSize : length);
			vsnprintf(buffer, length, format, args);

			out.reserve(length);
			out.assign(buffer);
		}

		void format(AMX * amx, const cell * params, cell * f, std::string & out) {
			const size_t bufMaxLen = 64;
			char buf[bufMaxLen];
			cell index = 0, *ptr = nullptr;
	
			while (*f != '\0') {
				switch (*f) {
				case '%': {
					switch (*(++f)) {
					case 'i':
					case 'd': {
						if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
							#if PAWN_CELL_SIZE == 64
								sprintf_s(buf, bufMaxLen, "%lld", *ptr);
							#else
								sprintf_s(buf, bufMaxLen, "%d", *ptr);
							#endif
							out.append(buf);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case 'c': {
						if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
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
						if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
							#if PAWN_CELL_SIZE == 64
								sprintf_s(buf, bufMaxLen, *f == 'x' ? "%llx" : "%llX", *ptr);
							#else
								sprintf_s(buf, bufMaxLen, *f == 'x' ? "%x" : "%X", *ptr);
							#endif
							out.append(buf);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					#ifdef FLOATPOINT
					case 'f': {
						if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
							sprintf_s(buf, bufMaxLen, "%f", amx_ctof(*ptr));
							out.append(buf);
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case '.': {
						std::string fstr("%.");
						while (*(++f) >= '0' && '9' >= *f)
							fstr.push_back((char)*f);

						fstr.push_back((char)*f);

						if (*f == 'f') {
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								sprintf_s(buf, bufMaxLen, fstr.c_str(), amx_ctof(*ptr));
								out.append(buf);
							}
							else {
								out.append("(null)");
							}
						}
						else {
							out.append(fstr);
						}
						f++;
					}
					break;
					#endif

					case 'b': {
						if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
							out.append(*ptr == 0 ? "false" : "true");
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case 's': {
						if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
							while (*ptr != '\0')
								out.push_back(*(ptr++));
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
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								#if PAWN_CELL_SIZE == 64
									fstr.append({ 'l', 'l', (char)*f });
								#else
									fstr.push_back((char)*f);
								#endif
								sprintf_s(buf, bufMaxLen, fstr.c_str(), *ptr);
								out.append(buf);
							}
							else {
								out.append("(null)");
							}
							f++;
						}
						break;
						
						case 'x':
						case 'X': {
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								#if PAWN_CELL_SIZE == 64
									fstr.append({ 'l', 'l', (char)*f });
								#else
									fstr.push_back((char)*f);
								#endif
								sprintf_s(buf, bufMaxLen, fstr.c_str(), *ptr);
								out.append(buf);
							}
							else {
								out.append("(null)");
							}
							f++;
						}
						break;

						case 's':
						case 'S': {
							if (fstr.length() > 2) {
								if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
									for (int len = std::stoi(&fstr[2]), i = 0; i < len && *ptr != '\0'; i++)
										out.push_back((char)*(ptr++));
								}
								else {
									out.append("(null)");
								}
							}
							else {
								out.append(fstr);
							}
							f++;
						}
						break;

						#ifdef FLOATPOINT
						case 'f': {
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								fstr.push_back((char)*f);
								sprintf_s(buf, bufMaxLen, fstr.c_str(), amx_ctof(*ptr));
								out.append(buf);
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
								if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
									fstr.push_back((char)*f);
									sprintf_s(buf, bufMaxLen, fstr.c_str(), amx_ctof(*ptr));
									out.append(buf);
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
				return { dest };

			return { "" };
		}

		bool is_dec(std::string & data) {
			for (int i = 0; i < data.size(); i++) {
				if ((i == 0) && (data[i] == '-'))
					continue;

				if (!isdigit(data[i]))
					return false;
			}
			return true;
		}

		bool is_hex(std::string & data) {
			for (int i = 0; i < data.size(); i++) {
				if (!isxdigit(data[i]))
					return false;
			}
			return true;
		}
	};
};