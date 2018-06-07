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

		void vector3ToCellArray(cell * addr, Vector3 * vec);
		Vector3 cellArrayToVector3(cell *addr);
	};
};