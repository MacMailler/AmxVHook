#include "funcs.hpp"

namespace AmxVHook {
	namespace Funcs {
		int showNotify(std::string text, BOOL blink, BOOL showInBrief) {
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING((char *)text.c_str());
			return UI::_DRAW_NOTIFICATION(blink, showInBrief);
		}

		void showSubtitle(std::string text, int duration, BOOL drawImmediately) {
			UI::_SET_TEXT_ENTRY_2("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING((char *)text.c_str());
			UI::_DRAW_SUBTITLE_TIMED(duration, drawImmediately);
		}

		void drawText(char *text, float x, float y, float scale, int font, int r, int g, int b, int a) {
			UI::SET_TEXT_FONT(font);
			UI::SET_TEXT_SCALE(scale, scale);
			UI::SET_TEXT_COLOUR(r, g, b, a);
			UI::SET_TEXT_WRAP(0.0, 1.0);
			UI::SET_TEXT_CENTRE(0);
			UI::SET_TEXT_DROPSHADOW(2, 2, 0, 0, 0);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 205);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
			UI::_DRAW_TEXT(x, y);
		}

		void drawRect(float x, float y, float width, float height, int r, int g, int b, int a) {
			GRAPHICS::DRAW_RECT((x + (width * 0.5f)), (y + (height * 0.5f)), width, height, r, g, b, a);
		}

		void drawInt(int value, float x, float y) {
			UI::_SET_TEXT_ENTRY("NUMBER");
			UI::ADD_TEXT_COMPONENT_INTEGER(value);
			UI::_DRAW_TEXT(x, y);
		}

		void drawFloat(float value, DWORD decimal_places, float x, float y) {
			UI::_SET_TEXT_ENTRY("NUMBER");
			UI::ADD_TEXT_COMPONENT_FLOAT(value, decimal_places);
			UI::_DRAW_TEXT(x, y);
		}

		void drawString(std::string & data, float x, float y) {
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING((char *)data.c_str());
			UI::_DRAW_TEXT(x, y);
		}
	};

	namespace Utility {
		Color::Color() {
		}

		Color::Color(uint32_t color) :
			R(((color & 0xFF000000) >> 24)),
			G(((color & 0xFF0000) >> 16)),
			B(((color & 0xFF00) >> 8)),
			A((color & 0xFF)),
			RGBA(color) {
		}

		Color::Color(uint16_t r, uint16_t g, uint16_t b, uint16_t a) :
			R(r),
			G(g),
			B(b),
			A(a),
			RGBA((r << 24) | (g << 16) | (b << 8) | a) {
		}

		bool setVector3ToParam(AMX * amx, cell param, Vector3 & vec) {
			cell * addr;
			if (amx_GetAddr(amx, param, &addr) != AMX_ERR_NONE)
				return false;

			addr[0] = amx_ftoc(vec.x);
			addr[1] = amx_ftoc(vec.y);
			addr[2] = amx_ftoc(vec.z);

			return true;
		}

		bool setArrayToParam(AMX * amx, const cell param, cell * arr, int size) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return false;

			for (int i = 0; i < size; i++)
				ptr[i] = arr[i];

			return true;
		}

		bool getVector3FromParam(AMX * amx, cell param, Vector3 & vec) {
			cell * addr;
			if (amx_GetAddr(amx, param, &addr) != AMX_ERR_NONE)
				return false;

			vec.x = amx_ctof(addr[0]);
			vec.y = amx_ctof(addr[1]);
			vec.z = amx_ctof(addr[2]);

			return true;
		}

		cell * getAddrFromParam(AMX * amx, const cell param) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return nullptr;

			return ptr;
		}

		bool getArrayFromParam(AMX * amx, const cell param, cell * dest, int size) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return false;

			for (int i = 0; i < size; i++)
				dest[i] = ptr[i];

			return true;
		}

		bool getFloatArrayFromParam(AMX * amx, const cell param, float * dest, int size) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return false;

			for (int i = 0; i < size; i++)
				dest[i] = amx_ctof(ptr[i]);

			return true;
		}

		void convertParamsToStack(AMX * amx, const cell * params, std::string & format, std::stack<boost::variant<cell, std::string>> & stk, int index) {
			for (const auto& i : format) {
				cell * ptr = nullptr;

				switch (i) {
				case 'i':
				case 'd':
				case 'f': {
					ptr = Utility::getAddrFromParam(amx, params[index++]);
					if (ptr != nullptr)
						stk.push(*ptr);
					else
						stk.push(0);
				}
				break;

				case 's':
				case 'z': {
					stk.push(String::get(amx, params[index++]));
				}
				break;

				default:
					stk.push(std::string("NULL"));
				}
			}
		}

		namespace Amx {
			int load(AMX * amx, std::string & path, void * memblock) {
				std::ifstream file(path, std::ios::binary);

				if (!file.is_open())
					return AMX_ERR_NOTFOUND;

				AMX_HEADER hdr;
				file.read((char *)&hdr, sizeof hdr);

				amx_Align16(&hdr.magic);
				amx_Align32((uint32_t *)&hdr.size);
				amx_Align32((uint32_t *)&hdr.stp);

				if (hdr.magic != AMX_MAGIC) {
					file.close();
					return AMX_ERR_FORMAT;
				}

				bool didalloc = false;
				if (memblock == NULL) {
					if ((memblock = malloc(hdr.stp)) == NULL) {
						file.close();
						return AMX_ERR_MEMORY;
					}
					didalloc = true;
				}

				file.seekg(0);
				file.read((char *)memblock, (size_t)hdr.size);
				file.close();

				memset(amx, 0, sizeof *amx);
				int result = amx_Init(amx, memblock);

				if (result != AMX_ERR_NONE && didalloc) {
					free(memblock);
					amx->base = NULL;
				}

				return result;
			}

			int cleanup(AMX * amx) {
				if (amx->base != NULL) {
					amx_Cleanup(amx);
					free(amx->base);

					memset(amx, 0, sizeof AMX);
				}

				return AMX_ERR_NONE;
			}

			size_t getSize(std::string & path) {
				std::ifstream file(path, std::ios::binary);

				if (!file.is_open())
					return 0;

				AMX_HEADER hdr;
				file.read((char *)&hdr, sizeof hdr);
				file.close();

				amx_Align16(&hdr.magic);
				amx_Align32((uint32_t *)&hdr.stp);

				return (hdr.magic == AMX_MAGIC) ? (size_t)hdr.stp : 0;
			}

			char * errorToString(int err) {
				static char * errstr[] = {
					/* AMX_ERR_NONE      */ "(none)",
					/* AMX_ERR_EXIT      */ "Forced exit",
					/* AMX_ERR_ASSERT    */ "Assertion failed",
					/* AMX_ERR_STACKERR  */ "Stack/heap collision (insufficient stack size)",
					/* AMX_ERR_BOUNDS    */ "Array index out of bounds",
					/* AMX_ERR_MEMACCESS */ "Invalid memory access",
					/* AMX_ERR_INVINSTR  */ "Invalid instruction",
					/* AMX_ERR_STACKLOW  */ "Stack underflow",
					/* AMX_ERR_HEAPLOW   */ "Heap underflow",
					/* AMX_ERR_CALLBACK  */ "No (valid) native function callback",
					/* AMX_ERR_NATIVE    */ "Native function failed",
					/* AMX_ERR_DIVIDE    */ "Divide by zero",
					/* AMX_ERR_SLEEP     */ "(sleep mode)",
					/* 13 */                "(reserved)",
					/* 14 */                "(reserved)",
					/* 15 */                "(reserved)",
					/* AMX_ERR_MEMORY    */ "Out of memory",
					/* AMX_ERR_FORMAT    */ "Invalid/unsupported P-code file format",
					/* AMX_ERR_VERSION   */ "File is for a newer version of the AMX",
					/* AMX_ERR_NOTFOUND  */ "File or function is not found",
					/* AMX_ERR_INDEX     */ "Invalid index parameter (bad entry point)",
					/* AMX_ERR_DEBUG     */ "Debugger cannot run",
					/* AMX_ERR_INIT      */ "AMX not initialized (or doubly initialized)",
					/* AMX_ERR_USERDATA  */ "Unable to set user data field (table full)",
					/* AMX_ERR_INIT_JIT  */ "Cannot initialize the JIT",
					/* AMX_ERR_PARAMS    */ "Parameter error",
					/* AMX_ERR_DOMAIN    */ "Domain error, expression result does not fit in range",
					/* AMX_ERR_GENERAL   */ "General error (unknown or unspecific error)",
				};
				if (err < 0 || err >= sizeof errstr / sizeof errstr[0])
					return "(unknown)";

				return errstr[err];
			}

			const AMX_HEADER * getHeader(AMX * amx) {
				return reinterpret_cast<AMX_HEADER *>(amx->base);
			}

			const AMX_FUNCSTUBNT * getNatives(AMX * amx) {
				return reinterpret_cast<AMX_FUNCSTUBNT *>(getHeader(amx)->natives + amx->base);
			}

			const int getNumNatives(AMX * amx) {
				const AMX_HEADER * hdr = getHeader(amx);
				return (hdr->libraries - hdr->natives) / hdr->defsize;
			}
			
			const char * getNativeName(AMX * amx, cell offset) {
				return reinterpret_cast<char *>(amx->base + offset);
			}
		};
	};
};