#include "graphics.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;

	namespace Natives {
		namespace Graphics {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(drawInt)
				MOD_DEFINE_NATIVE(drawFloat)
				MOD_DEFINE_NATIVE(drawString)
				MOD_DEFINE_NATIVE(drawRect)
				MOD_DEFINE_NATIVE(drawText)
				MOD_DEFINE_NATIVE(drawLine)
				MOD_DEFINE_NATIVE(drawPoly)
				MOD_DEFINE_NATIVE(drawBox)
				MOD_DEFINE_NATIVE(drawMarker)
				MOD_DEFINE_NATIVE(drawSprite)
				MOD_DEFINE_NATIVE(drawSpotLight)
				MOD_DEFINE_NATIVE(drawSpotLightWithShadow)
				MOD_DEFINE_NATIVE(drawLightWithRange)
				MOD_DEFINE_NATIVE(drawLightWithRangeAndShadow)
				MOD_DEFINE_NATIVE(setTextDropShadow)
				MOD_DEFINE_NATIVE(setTextEdge)
				MOD_DEFINE_NATIVE(setTextWrap)
				MOD_DEFINE_NATIVE(setTextColor)
				MOD_DEFINE_NATIVE(setUILayer)
				MOD_DEFINE_NATIVE(setDrawPosition)
				MOD_DEFINE_NATIVE(setDrawPositionRatio)
				MOD_DEFINE_NATIVE(setDrawPositionEnd)
				MOD_DEFINE_NATIVE(setHudVisible)
				MOD_DEFINE_NATIVE(setRadarVisible)
				MOD_DEFINE_NATIVE(setRadarZoom)
				MOD_DEFINE_NATIVE(getSafeZoneSize)
				MOD_DEFINE_NATIVE(getScreenSize)
				MOD_DEFINE_NATIVE(showNotify)
				MOD_DEFINE_NATIVE(showSubtitle)
				MOD_DEFINE_NATIVE(isWidescreen)
				MOD_DEFINE_NATIVE(isHudComponentActive)
				MOD_DEFINE_NATIVE(hideHudAndRadarThisFrame)
				MOD_DEFINE_NATIVE(hideHudComponentThisFrame)
				MOD_DEFINE_NATIVE(showHudComponentThisFrame)
				MOD_DEFINE_NATIVE(world3DToScreen2D)
				MOD_DEFINE_NATIVE(activateFrontendMenu)
				MOD_DEFINE_NATIVE(restartFrontendMenu)
				MOD_DEFINE_NATIVE(getCurrentFrontendMenu)
				MOD_DEFINE_NATIVE(requestStreamedTextureDict)
				MOD_DEFINE_NATIVE(isStreamedTextureDictLoaded)
				MOD_DEFINE_NATIVE(setStreamedTDictAsNoLongerNeeded)

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

			MOD_NATIVE(drawInt) {
				if (!arguments(3))
					return 0;

				Funcs::drawInt(params[1], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawFloat) {
				if (!arguments(4))
					return 0;

				Funcs::drawFloat(amx_ctof(params[1]), params[4], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawString) {
				if (!arguments(3))
					return 0;

				Funcs::drawString(String::get(amx, params[1]), amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
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

			MOD_NATIVE(drawBox) {
				if (!arguments(3))
					return 0;

				float point1[3], point2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], point1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point2, 3))
					return 0;

				Utility::Color color(params[3]);
				GRAPHICS::DRAW_BOX(point1[0], point1[1], point1[2], point2[0], point2[1], point2[2], color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawLine) {
				if (!arguments(3))
					return 0;

				float point1[3], point2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], point1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point2, 3))
					return 0;

				Utility::Color color(params[3]);
				GRAPHICS::DRAW_LINE(point1[0], point1[1], point1[2], point2[0], point2[1], point2[2], color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawPoly) {
				if (!arguments(4))
					return 0;

				float point1[3], point2[3], point3[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], point1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point2, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point3, 3))
					return 0;

				Utility::Color color(params[3]);
				GRAPHICS::DRAW_POLY(point1[0], point1[1], point1[2], point2[0], point2[1], point2[2], point3[0], point3[1], point3[2], color.R, color.G, color.B, color.A);

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

			MOD_NATIVE(drawSpotLight) {
				if (!arguments(8))
					return 0;

				float coords[3], dir[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], dir, 3))
					return 0;

				Utility::Color color(params[8]);

				GRAPHICS::DRAW_SPOT_LIGHT(
					coords[0], coords[1], coords[2],
					dir[0], dir[1], dir[2],
					color.R, color.G, color.B,
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7])
				);

				return 1;
			}

			MOD_NATIVE(drawSpotLightWithShadow) {
				if (!arguments(9))
					return 0;

				float coords[3], dir[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], dir, 3))
					return 0;

				Utility::Color color(params[9]);

				GRAPHICS::_DRAW_SPOT_LIGHT_WITH_SHADOW(
					coords[0], coords[1], coords[2],
					dir[0], dir[1], dir[2],
					color.R, color.G, color.B,
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7]), params[8]
				);

				return 1;
			}
			
			MOD_NATIVE(drawLightWithRange) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				Utility::Color color(params[4]);

				GRAPHICS::DRAW_LIGHT_WITH_RANGE(
					coords[0], coords[1], coords[2],
					color.R, color.G, color.B, amx_ctof(params[2]), amx_ctof(params[3])
				);

				return 1;
			}

			MOD_NATIVE(drawLightWithRangeAndShadow) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				Utility::Color color(params[5]);

				GRAPHICS::_DRAW_LIGHT_WITH_RANGE_WITH_SHADOW(
					coords[0], coords[1], coords[2],
					color.R, color.G, color.B, amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4])
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

			MOD_NATIVE(setTextColor) {
				if (!arguments(1))
					return 0;

				Utility::Color color(params[1]);
				::UI::SET_TEXT_COLOUR(color.R, color.G, color.B, color.A);

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
			
			MOD_NATIVE(showNotify) {
				if (!arguments(3))
					return 0;

				return Funcs::showNotify(String::get(amx, params[1]), (BOOL)params[2], (BOOL)params[3]);
			}

			MOD_NATIVE(showSubtitle) {
				if (!arguments(3))
					return 0;

				Funcs::showSubtitle(String::get(amx, params[1]), params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setHudVisible) {
				if (!arguments(1))
					return 0;

				::UI::DISPLAY_HUD((BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setRadarVisible) {
				if (!arguments(1))
					return 0;

				::UI::DISPLAY_RADAR((BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setRadarZoom) {
				if (!arguments(1))
					return 0;

				if (0 > params[1] || params[1] > 200)
					return 0;

				::UI::SET_RADAR_ZOOM(params[1]);

				return 1;
			}

			MOD_NATIVE(isHudComponentActive) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_HUD_COMPONENT_ACTIVE(params[1]);
			}

			MOD_NATIVE(hideHudAndRadarThisFrame) {
				::UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
				return 1;
			}
			
			MOD_NATIVE(hideHudComponentThisFrame) {
				if (!arguments(1))
					return 0;

				::UI::HIDE_HUD_COMPONENT_THIS_FRAME(params[1]);

				return 1;
			}

			MOD_NATIVE(showHudComponentThisFrame) {
				if (!arguments(1))
					return 0;

				::UI::SHOW_HUD_COMPONENT_THIS_FRAME(params[1]);

				return 1;
			}

			MOD_NATIVE(activateFrontendMenu) {
				if (!arguments(3))
					return 0;

				::UI::ACTIVATE_FRONTEND_MENU(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(restartFrontendMenu) {
				if (!arguments(1))
					return 0;

				::UI::RESTART_FRONTEND_MENU(params[1], -1);

				return 1;
			}

			MOD_NATIVE(getCurrentFrontendMenu) {
				if (!arguments(1))
					return 0;

				return ::UI::_0x2309595AD6145265();
			}
			
			MOD_NATIVE(requestStreamedTextureDict) {
				if (!arguments(1))
					return 0;

				GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char *)String::get(amx, params[1]).c_str(), TRUE);

				return 1;
			}
			
			MOD_NATIVE(isStreamedTextureDictLoaded) {
				if (!arguments(1))
					return 0;

				return GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char *)String::get(amx, params[1]).c_str());
			}
			
			MOD_NATIVE(setStreamedTDictAsNoLongerNeeded) {
				if (!arguments(1))
					return 0;

				GRAPHICS::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
		};
	};
};