#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace Funcs {
		int showNotify(std::string text, BOOL blink, BOOL showInBrief);
		void showSubtitle(std::string text, int duration, BOOL drawImmediately);

		void drawRect(float x, float y, float width, float height, int r, int g, int b, int a);
		void drawText(char *text, float x, float y, float scale, int font, int r, int g, int b, int a);

		void drawString(std::string & data, float x, float y);
		void drawInt(int value, float x, float y);
		void drawFloat(float value, DWORD decimal_places, float x, float y);
	};

	namespace Utility {
		class Color {
		public:
			uint16_t R = 255;
			uint16_t G = 255;
			uint16_t B = 255;
			uint16_t A = 255;
			uint32_t RGBA = 0xFFFFFFFF;

			Color();
			Color(uint32_t);
			Color(uint16_t, uint16_t, uint16_t, uint16_t);
		};

		bool setVector3ToParam(AMX * amx, cell param, Vector3 & vec);
		bool getVector3FromParam(AMX * amx, cell param, Vector3 & vec);

		cell * getAddrFromParam(AMX * amx, const cell param);
		bool setArrayToParam(AMX * amx, cell param, cell * arr, int size);
		bool getArrayFromParam(AMX * amx, cell param, cell * dest, int size);
		bool getFloatArrayFromParam(AMX * amx, cell param, float * dest, int size);
		void convertParamsToStack(AMX * amx, const cell * params, std::string & format, std::stack<boost::variant<cell, std::string>> & stk, int index = 0);

		namespace Amx {
			int load(AMX * amx, std::string & path, void * memblock = NULL);
			int cleanup(AMX * amx);
			size_t getSize(std::string & path);
			char * errorToString(int err);

			const AMX_HEADER * getHeader(AMX * amx);
			const AMX_FUNCSTUBNT * getNatives(AMX * amx);
			const int getNumNatives(AMX * amx);
			const char * getNativeName(AMX * amx, cell offset);
		};
	};
};