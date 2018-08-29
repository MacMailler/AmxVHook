#include "amxaux.hpp"

namespace AmxVHook {
	namespace Aux {
		int load(AMX * amx, std::string & path) {
			std::ifstream ifs(path, std::ios::binary);

			if (!ifs.is_open())
				return AMX_ERR_NOTFOUND;

			void *pcode = NULL;
			int err = AMX_ERR_FORMAT;

			AMX_HEADER hdr;
			ifs.read((char *)&hdr, sizeof hdr);

			amx_Align16(&hdr.magic);
			if (hdr.magic != AMX_MAGIC)
				goto fail;

			err = AMX_ERR_MEMORY;
			amx_Align32((uint32_t *)&hdr.size);
			amx_Align32((uint32_t *)&hdr.stp);

			if ((pcode = valloc((size_t)hdr.stp)) == NULL)
				goto fail;

			ifs.seekg(std::ios::beg);
			ifs.read((char *)pcode, (size_t)hdr.size);
			ifs.close();

			std::memset(amx, 0, sizeof *amx);

			if ((err = amx_Init(amx, pcode)) != AMX_ERR_NONE)
				goto fail;

			return AMX_ERR_NONE;

		fail:
			ifs.close();
	
			if (pcode != NULL)
				vfree(pcode);

			std::memset(amx, 0, sizeof *amx);

			return err;
		}

		int cleanup(AMX * amx) {
			if (amx->base != NULL) {
				amx_Cleanup(amx);
				vfree(amx->base);
				std::memset(amx, 0, sizeof *amx);
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

		const AMX_FUNCSTUBNT * getPublics(AMX * amx) {
			return reinterpret_cast<AMX_FUNCSTUBNT*>(getHeader(amx)->publics + amx->base);
		}

		const AMX_FUNCSTUBNT * getNatives(AMX * amx) {
			return reinterpret_cast<AMX_FUNCSTUBNT *>(getHeader(amx)->natives + amx->base);
		}

		const int getNumPublics(AMX * amx) {
			const AMX_HEADER *hdr = getHeader(amx);
			return (hdr->natives - hdr->publics) / hdr->defsize;
		}

		const int getNumNatives(AMX * amx) {
			const AMX_HEADER *hdr = getHeader(amx);
			return (hdr->libraries - hdr->natives) / hdr->defsize;
		}

		const char * getNativeName(AMX * amx, cell offset) {
			return reinterpret_cast<char *>(amx->base + offset);
		}

		const char * getPublicName(AMX * amx, uint32_t offset) {
			return reinterpret_cast<char*>(amx->base + offset);
		}

		int getPublicIndex(AMX * amx, const std::string & funcname) {
			int n = getNumPublics(amx);
			const AMX_FUNCSTUBNT *publics = getPublics(amx);

			for (int i = 0; i < n; i++)
				if (!funcname.compare(getPublicName(amx, publics[i].nameofs)))
					return i;

			return -1;
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

		void toStack(AMX * amx, const cell * params, std::string & format, AmxArgs & stk, int index) {
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

		void * valloc(size_t size , bool code) {
			void *memblk;
			#if defined __WIN32__
				memblk = VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, code ? PAGE_EXECUTE_READWRITE : PAGE_READWRITE);
			#elif LINUX
				memblk = malloc(size);
				if (memblk)
					mprotect(memblk, size, code ? PROT_READ | PROT_WRITE | PROT_EXEC : PROT_READ | PROT_WRITE);
			#else
				memblk = malloc(size);
			#endif
			return memblk;
		}

		void vfree(void * memblk) {
			#if defined __WIN32__
				VirtualFree(memblk, 0, MEM_RELEASE);
			#else
				free(memblk);
			#endif
		}
	};
};