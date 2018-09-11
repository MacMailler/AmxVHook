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

		void drawText(char *text, float x, float y, float scale, int font, Color& color) {
			UI::SET_TEXT_FONT(font);
			UI::SET_TEXT_SCALE(scale, scale);
			UI::SET_TEXT_COLOUR(color.R, color.G, color.B, color.A);
			UI::SET_TEXT_WRAP(0.0, 1.0);
			UI::SET_TEXT_CENTRE(0);
			UI::SET_TEXT_DROPSHADOW(2, 2, 0, 0, 0);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 205);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
			UI::_DRAW_TEXT(x, y);
		}

		void drawRect(float x, float y, float width, float height, Color& color) {
			GRAPHICS::DRAW_RECT((x + (width * 0.5f)), (y + (height * 0.5f)), width, height, color.R, color.G, color.B, color.A);
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

	Color::Color() {
	}

	Color::Color(int32_t color) :
		R((color >> 24) & 0xFF),
		G((color >> 16) & 0xFF),
		B((color >> 8) & 0xFF),
		A((color & 0xFF)),
		RGBA(color) {
	}

	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
		R(r),
		G(g),
		B(b),
		A(a),
		RGBA((r << 24) | (g << 16) | (b << 8) | a) {
	}
};