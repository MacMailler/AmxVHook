#include "ui.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace UI {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isHudHidden)
				MOD_DEFINE_NATIVE(isRadarHidden)
				MOD_DEFINE_NATIVE(isRadarEnabled)
				MOD_DEFINE_NATIVE(isWidescreen)
				MOD_DEFINE_NATIVE(isHudComponentActive)
				MOD_DEFINE_NATIVE(setHudVisible)
				MOD_DEFINE_NATIVE(setRadarVisible)
				MOD_DEFINE_NATIVE(setRadarZoom)
				MOD_DEFINE_NATIVE(getSafeZoneSize)
				MOD_DEFINE_NATIVE(getScreenSize)
				MOD_DEFINE_NATIVE(getScreenAspectRatio)
				MOD_DEFINE_NATIVE(getLabelText)
				MOD_DEFINE_NATIVE(showNotify)
				MOD_DEFINE_NATIVE(showSubtitle)
				MOD_DEFINE_NATIVE(showHelpMessage)
				MOD_DEFINE_NATIVE(showLoadingSpinner)
				MOD_DEFINE_NATIVE(showHudComponentThisFrame)
				MOD_DEFINE_NATIVE(showHud)
				MOD_DEFINE_NATIVE(showRadar)
				MOD_DEFINE_NATIVE(showCash)
				MOD_DEFINE_NATIVE(showAreaName)
				MOD_DEFINE_NATIVE(hideLoadingSpinner)
				MOD_DEFINE_NATIVE(hideHudAndRadarThisFrame)
				MOD_DEFINE_NATIVE(hideHudComponentThisFrame)
				MOD_DEFINE_NATIVE(removeNotify)
				MOD_DEFINE_NATIVE(activateFrontendMenu)
				MOD_DEFINE_NATIVE(restartFrontendMenu)
				MOD_DEFINE_NATIVE(getCurrentFrontendMenu)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(isHudHidden) {
				return ::UI::IS_HUD_HIDDEN();
			}

			MOD_NATIVE(isRadarHidden) {
				return ::UI::IS_RADAR_HIDDEN();
			}

			MOD_NATIVE(isRadarEnabled) {
				return ::UI::_0xAF754F20EB5CD51A();
			}

			MOD_NATIVE(isWidescreen) {
				return GRAPHICS::GET_IS_WIDESCREEN();
			}

			MOD_NATIVE(isHudComponentActive) {
				checkargs(1);

				return ::UI::IS_HUD_COMPONENT_ACTIVE(params[1]);
			}

			MOD_NATIVE(setHudVisible) {
				checkargs(1);

				::UI::DISPLAY_HUD((BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setRadarVisible) {
				checkargs(1);

				::UI::DISPLAY_RADAR((BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setRadarZoom) {
				checkargs(1);

				if (0 > params[1] || params[1] > 200)
					return 0;

				::UI::SET_RADAR_ZOOM(params[1]);

				return 1;
			}

			MOD_NATIVE(getSafeZoneSize) {
				double size = GRAPHICS::GET_SAFE_ZONE_SIZE();

				return amx_ftoc(size);
			}

			MOD_NATIVE(getScreenSize) {
				checkargs(2);

				cell *w, *h;
				if (amx_GetAddr(amx, params[1], &w) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &h) != AMX_ERR_NONE)
					return 0;

				GRAPHICS::_GET_SCREEN_ACTIVE_RESOLUTION(reinterpret_cast<int *>(w), reinterpret_cast<int *>(h));

				return 1;
			}
			
			MOD_NATIVE(getScreenAspectRatio) {
				checkargs(1);

				double ratio = GRAPHICS::_GET_SCREEN_ASPECT_RATIO(params[1]);

				return amx_ftoc(ratio);
			}

			MOD_NATIVE(getLabelText) {
				checkargs(3);

				char * out = ::UI::_GET_LABEL_TEXT((char *)String::get(amx, params[1]).c_str());
				String::set(amx, params[2], out, params[3]);

				return 1;
			}

			MOD_NATIVE(showNotify) {
				checkargs(3);

				return Funcs::showNotify(String::get(amx, params[1]), (BOOL)params[2], (BOOL)params[3]);
			}

			MOD_NATIVE(showSubtitle) {
				checkargs(3);

				Funcs::showSubtitle(String::get(amx, params[1]), params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(showHelpMessage) {
				checkargs(3);

				::UI::_SET_TEXT_COMPONENT_FORMAT("STRING");
				::UI::_ADD_TEXT_COMPONENT_STRING((char *)String::get(amx, params[1]).c_str());
				::UI::_DISPLAY_HELP_TEXT_FROM_STRING_LABEL(0, 0, params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(showLoadingSpinner) {
				checkargs(2);

				::UI::_0xABA17D7CE615ADBF("STRING");
				::UI::_ADD_TEXT_COMPONENT_STRING((char *)String::get(amx, params[1]).c_str());
				::UI::_0xBD12F8228410D9B4(params[2]);

				return 1;
			}

			MOD_NATIVE(showHudComponentThisFrame) {
				checkargs(1);

				::UI::SHOW_HUD_COMPONENT_THIS_FRAME(params[1]);

				return 1;
			}
			
			MOD_NATIVE(showHud) {
				checkargs(1);

				::UI::DISPLAY_HUD(params[1]);

				return 1;
			}
			
			MOD_NATIVE(showRadar) {
				checkargs(1);

				::UI::DISPLAY_RADAR(params[1]);

				return 1;
			}
			
			MOD_NATIVE(showCash) {
				checkargs(1);

				::UI::DISPLAY_CASH(params[1]);

				return 1;
			}
			
			MOD_NATIVE(showAreaName) {
				checkargs(1);

				::UI::DISPLAY_AREA_NAME(params[1]);

				return 1;
			}

			MOD_NATIVE(hideLoadingSpinner) {
				::UI::_0x10D373323E5B9C0D();
				return 1;
			}

			MOD_NATIVE(hideHudAndRadarThisFrame) {
				::UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
				return 1;
			}

			MOD_NATIVE(hideHudComponentThisFrame) {
				checkargs(1);

				::UI::HIDE_HUD_COMPONENT_THIS_FRAME(params[1]);

				return 1;
			}
			
			MOD_NATIVE(removeNotify) {
				checkargs(1);

				::UI::_REMOVE_NOTIFICATION(params[1]);

				return 1;
			}

			MOD_NATIVE(activateFrontendMenu) {
				checkargs(3);

				::UI::ACTIVATE_FRONTEND_MENU(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(restartFrontendMenu) {
				checkargs(1);

				::UI::RESTART_FRONTEND_MENU(params[1], -1);

				return 1;
			}

			MOD_NATIVE(getCurrentFrontendMenu) {
				checkargs(1);

				return ::UI::_0x2309595AD6145265();
			}
		};
	};
};