#include "amxaux.hpp"

namespace AmxVHook {
	namespace Aux {
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

			std::memset(amx, 0, sizeof *amx);
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

				std::memset(amx, 0, sizeof AMX);
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

		char * strError(int err) {
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

		cell * getAddr(AMX * amx, const cell param) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return nullptr;

			return ptr;
		}

		bool getArray(AMX * amx, const cell param, cell * dest, int size) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return false;

			std::memcpy(dest, ptr, size * sizeof(cell));

			return true;
		}

		bool getFloatArray(AMX * amx, const cell param, float * dest, int size) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return false;

			for (int i = 0; i < size; i++)
				dest[i] = amx_ctof(ptr[i]);

			return true;
		}

		bool getVector3(AMX * amx, cell param, Vector3 & vec) {
			cell * addr;
			if (amx_GetAddr(amx, param, &addr) != AMX_ERR_NONE)
				return false;

			vec.x = amx_ctof(addr[0]);
			vec.y = amx_ctof(addr[1]);
			vec.z = amx_ctof(addr[2]);

			return true;
		}

		bool setArray(AMX * amx, const cell param, cell * arr, int size) {
			cell * ptr;
			if (amx_GetAddr(amx, param, &ptr) != AMX_ERR_NONE)
				return false;

			std::memcpy(ptr, arr, size * sizeof(cell));

			return true;
		}

		bool setVector3(AMX * amx, cell param, Vector3 & vec) {
			cell * addr;
			if (amx_GetAddr(amx, param, &addr) != AMX_ERR_NONE)
				return false;

			addr[0] = amx_ftoc(vec.x);
			addr[1] = amx_ftoc(vec.y);
			addr[2] = amx_ftoc(vec.z);

			return true;
		}

		void toStack(AMX * amx, const cell * params, std::string & format, std::stack<std::variant<cell, std::string>> & stk, int index) {
			for (const auto& i : format) {
				cell * addr;

				switch (i) {
				case 'i':
				case 'd':
				case 'f': {
					if (amx_GetAddr(amx, params[index++], &addr) == AMX_ERR_NONE)
						stk.push(*addr);
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
	};
};