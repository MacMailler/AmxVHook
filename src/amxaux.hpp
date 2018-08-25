#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace Aux {
		int load(AMX * amx, std::string & path, void * memblock = NULL);
		int cleanup(AMX * amx);
		size_t getSize(std::string & path);
		char * strError(int err);

		const AMX_HEADER * getHeader(AMX * amx);
		const AMX_FUNCSTUBNT * getNatives(AMX * amx);
		const int getNumNatives(AMX * amx);
		const char * getNativeName(AMX * amx, cell offset);

		cell * getAddr(AMX * amx, const cell param);
		bool getArray(AMX * amx, cell param, cell * dest, int size);
		bool getFloatArray(AMX * amx, cell param, float * dest, int size);
		bool getVector3(AMX * amx, cell param, Vector3 & vec);
		bool setArray(AMX * amx, cell param, cell * arr, int size);
		bool setVector3(AMX * amx, cell param, Vector3 & vec);
		void toStack(AMX * amx, const cell * params, std::string & format, AmxArgs & stk, int index = 0);
	};
};