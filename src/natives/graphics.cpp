#include "graphics.hpp"

namespace AmxVHook {
	extern boost::shared_ptr<Debug> gDebug;
	namespace Natives {
		namespace Graphics {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(drawRect)
				AMX_DEFINE_NATIVE(drawText)
				AMX_DEFINE_NATIVE(drawMarker)
				AMX_DEFINE_NATIVE(setUILayer)
				AMX_DEFINE_NATIVE(setDrawPosition)
				AMX_DEFINE_NATIVE(setDrawPositionRatio)
				AMX_DEFINE_NATIVE(setDrawPositionEnd)
				AMX_DEFINE_NATIVE(getSafeZoneSize)
				AMX_DEFINE_NATIVE(isWidescreen)
				AMX_DEFINE_NATIVE(getScreenSize)
				AMX_DEFINE_NATIVE(world3DToScreen2D)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(getScreenSize) {
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

			AMX_NATIVE(world3DToScreen2D) {
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

			AMX_NATIVE(drawText) {
				if (!arguments(6))
					return 0;

				cell * color = nullptr;
				if (amx_GetAddr(amx, params[6], &color) != AMX_ERR_NONE)
					return 0;

				::UI::SET_TEXT_FONT(params[5]);
				::UI::SET_TEXT_SCALE(amx_ctof(params[4]), amx_ctof(params[4]));
				::UI::SET_TEXT_COLOUR(color[0], color[1], color[2], color[3]);
				::UI::SET_TEXT_WRAP(0.0, 1.0);
				::UI::SET_TEXT_CENTRE(0);
				::UI::SET_TEXT_DROPSHADOW(2, 2, 0, 0, 0);
				::UI::SET_TEXT_EDGE(1, 0, 0, 0, 205);
				::UI::_SET_TEXT_ENTRY("STRING");
				::UI::_ADD_TEXT_COMPONENT_STRING((char *)String::get(amx, params[1]).c_str());
				::UI::_DRAW_TEXT(amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			AMX_NATIVE(drawRect) {
				if (!arguments(5))
					return 0;

				cell * color = nullptr;
				if (amx_GetAddr(amx, params[5], &color) != AMX_ERR_NONE)
					return 0;

				Funcs::drawRect(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), color[0], color[1], color[2], color[3]);
				return 1;
			}

			AMX_NATIVE(drawMarker) {
				if (!arguments(9))
					return 0;

				cell * addr[4] = { nullptr };
				Vector3 vec[4];

				amxAddrToVector3(amx, params, 2, 4);

				cell * color = nullptr;
				if (amx_GetAddr(amx, params[6], &color) != AMX_ERR_NONE)
					return 0;

				GRAPHICS::DRAW_MARKER(
					params[1],
					vec[0].x, vec[0].y, vec[0].z, // x y z
					vec[1].x, vec[1].y, vec[1].z, // dx dy dz
					vec[2].x, vec[2].y, vec[2].z, // rx ry rz
					vec[3].x, vec[3].y, vec[3].z, // sx sy sz
					color[0], color[1], color[2], color[3], // r b g a
					params[7], params[8], 2, FALSE, NULL, NULL, params[9]
				);

				return 1;
			}

			AMX_NATIVE(drawSprite) {
				if (!arguments(8))
					return 0;

				cell * color = nullptr;
				if (amx_GetAddr(amx, params[8], &color) != AMX_ERR_NONE)
					return 0;

				GRAPHICS::DRAW_SPRITE(
					(char *)String::get(amx, params[1]).c_str(),
					(char *)String::get(amx, params[2]).c_str(),
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7]),
					color[0], color[1], color[2], color[3]
				);

				return 1;
			}

			AMX_NATIVE(setUILayer) {
				if (!arguments(1))
					return 0;

				GRAPHICS::_0x61BB1D9B3A95D802(params[1]);

				return 1;
			}

			AMX_NATIVE(setDrawPosition) {
				if (!arguments(2))
					return 0;

				GRAPHICS::_SET_SCREEN_DRAW_POSITION(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			AMX_NATIVE(setDrawPositionRatio) {
				if (!arguments(4))
					return 0;

				GRAPHICS::_0xF5A2C681787E579D(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));

				return 1;
			}

			AMX_NATIVE(setDrawPositionEnd) {
				GRAPHICS::_0xE3A3DB414A373DAB();

				return 1;
			}

			AMX_NATIVE(getSafeZoneSize) {
				float size = GRAPHICS::GET_SAFE_ZONE_SIZE();

				return amx_ftoc(size);
			}

			AMX_NATIVE(isWidescreen) {
				return GRAPHICS::GET_IS_WIDESCREEN();
			}
		};
	};
};