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
			const size_t maxBufSize = 512;
			char * buffer = (char *)alloca(maxBufSize);
			vsnprintf(buffer, maxBufSize, format, args);

			out.reserve(maxBufSize + 1);
			out.assign(buffer);
		}

		void format(AMX * amx, const cell * params, cell * f, std::string & out) {
			const size_t bufMaxLen = 64;
			cell index = 0, *ptr = nullptr;

			char buf[bufMaxLen];
			std::string cache;

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
							out.push_back((char)*ptr);
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
						cache.assign("%.");
						while (*(++f) >= '0' && '9' >= *f)
							cache.push_back((char)*f);

						cache.push_back((char)*f);

						if (*f == 'f') {
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								sprintf_s(buf, bufMaxLen, cache.c_str(), amx_ctof(*ptr));
								out.append(buf);
							}
							else {
								out.append("(null)");
							}
						}
						else {
							out.append(cache);
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
								out.push_back((char)*(ptr++));
						}
						else {
							out.append("(null)");
						}
						f++;
					}
					break;

					case '0': {
						cache.assign("%0");
						while (*(++f) >= '0' && '9' >= *f)
							cache.push_back((char)*f);

						switch (*f) {
						case 'i':
						case 'd': {
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								#if PAWN_CELL_SIZE == 64
									cache.append({ 'l', 'l', (char)*f });
								#else
									cache.push_back((char)*f);
								#endif
								sprintf_s(buf, bufMaxLen, cache.c_str(), *ptr);
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
									cache.append({ 'l', 'l', (char)*f });
								#else
									cache.push_back((char)*f);
								#endif
								sprintf_s(buf, bufMaxLen, cache.c_str(), *ptr);
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
							if (cache.length() > 2) {
								if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
									for (int len = std::stoi(&cache[2]), i = 0; i < len && *ptr != '\0'; i++)
										out.push_back((char)*(ptr++));
								}
								else {
									out.append("(null)");
								}
							}
							else {
								out.append(cache);
							}
							f++;
						}
						break;

						#ifdef FLOATPOINT
						case 'f': {
							if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
								cache.push_back((char)*f);
								sprintf_s(buf, bufMaxLen, cache.c_str(), amx_ctof(*ptr));
								out.append(buf);
							}
							else {
								out.append("(null)");
							}
							f++;
						}
						break;

						case '.': {
							cache.push_back((char)*f);

							while (*(++f) >= '0' && '9' >= *f)
								cache.push_back((char)*f);

							if (*f == 'f') {
								if (amx_GetAddr(amx, params[index++], &ptr) == AMX_ERR_NONE) {
									cache.push_back((char)*f);
									sprintf_s(buf, bufMaxLen, cache.c_str(), amx_ctof(*ptr));
									out.append(buf);
								}
								else {
									out.append("(null)");
								}
							}
							else {
								cache.push_back((char)*f);
								out.append(cache);
							}
							f++;
						}
						break;
						#endif

						default:
							out.append(cache);
						}
					}
					break;

					default:
						out.push_back((char)*(f++));
					}
				}
				break;

				default:
					out.push_back((char)*(f++));
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