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

		template<typename T1, typename T2>
		inline void cpy(T1* dst, T2* src, size_t len) {
			while (len--)
				*(dst++) = *(src++);
		}

		template<typename R>
		static inline R invoke(UINT64 hash, AMX * amx, const cell * params, cell * f) {
			nativeInit(hash);

			cell *val;

			while (*f != '\0') {
				switch (*(f++)) {
				case 'i':
				case 'd': {
					amx_GetAddr(amx, *(params++), &val);
					nativePush(*val);
				}
				break;

				case 'p': {
					amx_GetAddr(amx, *(params++), &val);
					nativePush(val);
				}
				break;

				case 'f': {
					amx_GetAddr(amx, *(params++), &val);
					nativePush(amx_ctof(*val));
				}
				break;

				case 's': {
					char * dest = NULL;
					amx_StrParam(amx, *(params++), dest);

					if (dest != NULL)
						nativePush(dest);
				}
				break;
				}
			}

			return *reinterpret_cast<R *>(nativeCall());
		}
	};

	class Color {
	public:
		uint8_t R = 255u;
		uint8_t G = 255u;
		uint8_t B = 255u;
		uint8_t A = 255u;

		int32_t RGBA = 0xFFFFFFFF;

		Color();
		Color(int32_t);
		Color(uint8_t, uint8_t, uint8_t, uint8_t);
	};
};