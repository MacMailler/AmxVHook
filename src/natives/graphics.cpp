#include "graphics.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;

	namespace Natives {
		namespace Graphics {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(drawRect)
				MOD_DEFINE_NATIVE(drawText)
				MOD_DEFINE_NATIVE(drawMarker)
				MOD_DEFINE_NATIVE(setTextDropShadow)
				MOD_DEFINE_NATIVE(setTextEdge)
				MOD_DEFINE_NATIVE(setTextWrap)
				MOD_DEFINE_NATIVE(setUILayer)
				MOD_DEFINE_NATIVE(setDrawPosition)
				MOD_DEFINE_NATIVE(setDrawPositionRatio)
				MOD_DEFINE_NATIVE(setDrawPositionEnd)
				MOD_DEFINE_NATIVE(getSafeZoneSize)
				MOD_DEFINE_NATIVE(isWidescreen)
				MOD_DEFINE_NATIVE(getScreenSize)
				MOD_DEFINE_NATIVE(world3DToScreen2D)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(getScreenSize) {
				if (!arguments(2))
					return 0;

				int w, h;
				GRAPHICS::_GET_SCREEN_ACTIVE_RESOLUTION(&w, &h);

				cell *w_addr = nullptr, *h_addr = nullptr;
				if ((amx_GetAddr(amx, params[1], &w_addr) != AMX_ERR_NONE || w_addr == nullptr)
					|| (amx_GetAddr(amx, params[2], &h_addr) != AMX_ERR_NONE || h_addr == nullptr))
					return 0;

				*w_addr = (cell)w;
				*h_addr = (cell)h;

				return 1;
			}

			MOD_NATIVE(world3DToScreen2D) {
				if (!arguments(3))
					return 0;

				cell * vec = nullptr, *sx = nullptr, *sy = nullptr;
				if ((amx_GetAddr(amx, params[1], &vec) != AMX_ERR_NONE) ||
					(amx_GetAddr(amx, params[2], &sx) != AMX_ERR_NONE) ||
					(amx_GetAddr(amx, params[3], &sy) != AMX_ERR_NONE))
					return 0;

				float sx2, sy2;

				BOOL ret = GRAPHICS::_WORLD3D_TO_SCREEN2D(amx_ctof(vec[0]), amx_ctof(vec[1]), amx_ctof(vec[2]), &sx2, &sy2);
				*sx = amx_ftoc(sx2);
				*sy = amx_ftoc(sy2);

				return ret;
			}

			MOD_NATIVE(drawText) {
				if (!arguments(7))
					return 0;

				Utility::Color color(params[6]);

				::UI::SET_TEXT_FONT(params[5]);
				::UI::SET_TEXT_SCALE(amx_ctof(params[4]), amx_ctof(params[4]));
				::UI::SET_TEXT_COLOUR(color.R, color.G, color.B, color.A);
				::UI::SET_TEXT_CENTRE(params[7]);
				::UI::_SET_TEXT_ENTRY("STRING");
				::UI::_ADD_TEXT_COMPONENT_STRING((char *)String::get(amx, params[1]).c_str());
				::UI::_DRAW_TEXT(amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawRect) {
				if (!arguments(5))
					return 0;

				Utility::Color color(params[5]);
				Funcs::drawRect(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawMarker) {
				if (!arguments(9))
					return 0;

				float coords[3], dir[3], rot[3], scale[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[3], dir, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[4], rot, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[5], scale, 3))
					return 0;

				Utility::Color color(params[6]);

				GRAPHICS::DRAW_MARKER(
					params[1],
					coords[0], coords[1], coords[2], // x y z
					dir[0], dir[1], dir[2], // dx dy dz
					rot[0], rot[1], rot[2], // rx ry rz
					scale[0], scale[1], scale[2], // sx sy sz
					color.R, color.G, color.B, color.A, // r b g a
					params[7], params[8], 2, FALSE, NULL, NULL, params[9]
				);

				return 1;
			}

			MOD_NATIVE(drawSprite) {
				if (!arguments(8))
					return 0;

				Utility::Color color(params[8]);

				GRAPHICS::DRAW_SPRITE(
					(char *)String::get(amx, params[1]).c_str(),
					(char *)String::get(amx, params[2]).c_str(),
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7]),
					color.R, color.G, color.B, color.A
				);

				return 1;
			}

			MOD_NATIVE(setTextDropShadow) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				::UI::SET_TEXT_DROPSHADOW(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextEdge) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				::UI::SET_TEXT_EDGE(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextWrap) {
				if (!arguments(2))
					return 0;

				::UI::SET_TEXT_WRAP(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setUILayer) {
				if (!arguments(1))
					return 0;

				GRAPHICS::_0x61BB1D9B3A95D802(params[1]);

				return 1;
			}

			MOD_NATIVE(setDrawPosition) {
				if (!arguments(2))
					return 0;

				GRAPHICS::_SET_SCREEN_DRAW_POSITION(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setDrawPositionRatio) {
				if (!arguments(4))
					return 0;

				GRAPHICS::_0xF5A2C681787E579D(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setDrawPositionEnd) {
				GRAPHICS::_0xE3A3DB414A373DAB();

				return 1;
			}

			MOD_NATIVE(getSafeZoneSize) {
				float size = GRAPHICS::GET_SAFE_ZONE_SIZE();

				return amx_ftoc(size);
			}

			MOD_NATIVE(isWidescreen) {
				return GRAPHICS::GET_IS_WIDESCREEN();
			}
		};
	};
};