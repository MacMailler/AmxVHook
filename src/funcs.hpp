#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace Funcs {
		int showNotify(std::string text, BOOL blink, BOOL showInBrief);
		void showSubtitle(std::string text, int duration, BOOL drawImmediately);
		void setupDraw(int font = 0, float scale = 0.4f, int r = 255, int b = 255, int g = 255, int a = 255);

		void drawRect(float x, float y, float width, float height, int r = 255, int g = 255, int b = 255, int a = 255);
		void drawText(char *text, float x, float y, float scale = 1.0, int font = 0, int r = 255, int g = 255, int b = 255, int a = 255);

		void drawString(std::string value, float x, float y);
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

			Color(uint32_t);
			Color(uint16_t, uint16_t, uint16_t, uint16_t);
		};

		bool setVector3ToParam(AMX * amx, cell param, Vector3 & vec);
		bool getVector3FromParam(AMX * amx, cell param, Vector3 & vec);

		bool getArrayFromParam(AMX * amx, cell param, cell * addr, int size);
		bool getFloatArrayFromParam(AMX * amx, cell param, float * addr, int size);
	};
};