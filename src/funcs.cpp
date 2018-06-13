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

		void drawText(char *text, float x, float y, float scale, int font, int r, int b, int g, int a) {
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

		void drawRect(float x, float y, float width, float height, int r, int b, int g, int a) {
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

		void drawString(std::string value, float x, float y) {
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING((char *)value.c_str());
			UI::_DRAW_TEXT(x, y);
		}
	};

	namespace Utility {
		Color::Color() {
			this->R = 255;
			this->G = 255;
			this->B = 255;
			this->A = 255;
			this->RGBA = 0xFFFFFFFF;
		}

		Color::Color(uint32_t color) {
			this->R = ((color & 0xFF000000) >> 24);
			this->G = ((color & 0xFF0000) >> 16);
			this->B = ((color & 0xFF00) >> 8);
			this->A = (color & 0xFF);
			this->RGBA = color;
		}

		Color::Color(uint16_t r, uint16_t g, uint16_t b, uint16_t a) {
			this->R = r;
			this->G = g;
			this->B = b;
			this->A = a;
			this->RGBA = ((r << 24) | (g << 16) | (b << 8) | a);
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

		bool getVector3FromParam(AMX * amx, cell param, Vector3 & vec) {
			cell * addr;
			if (amx_GetAddr(amx, param, &addr) != AMX_ERR_NONE)
				return false;

			vec.x = amx_ctof(addr[0]);
			vec.y = amx_ctof(addr[1]);
			vec.z = amx_ctof(addr[2]);

			return true;
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
	};
};