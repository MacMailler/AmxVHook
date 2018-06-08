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
			GRAPHICS::DRAW_RECT(x, y, width, height, r, g, b, a);
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

		void setupDraw(int font, float scale, int r, int b, int g, int a) {
			UI::SET_TEXT_FONT(font);
			UI::SET_TEXT_SCALE(scale, scale);
			UI::SET_TEXT_COLOUR(r, b, g, a);
			UI::SET_TEXT_WRAP(0.0f, 1.0f);
			UI::SET_TEXT_CENTRE(0);
			UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
			UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
			UI::SET_TEXT_OUTLINE();
		}

		void vector3ToCellArray(cell * addr, Vector3 * vec) {
			addr[0] = amx_ftoc(vec->x);
			addr[1] = amx_ftoc(vec->y);
			addr[2] = amx_ftoc(vec->z);
		}

		Vector3 cellArrayToVector3(cell * addr) {
			Vector3 vec;

			vec.x = amx_ctof(addr[0]);
			vec.y = amx_ctof(addr[1]);
			vec.z = amx_ctof(addr[2]);

			return vec;
		}
	};
};