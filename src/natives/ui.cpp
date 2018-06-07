#include "ui.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace UI {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(showNotify)
				AMX_DEFINE_NATIVE(showSubtitle)
				AMX_DEFINE_NATIVE(setHudVisible)
				AMX_DEFINE_NATIVE(setRadarVisible)
				AMX_DEFINE_NATIVE(setRadarZoom)
				AMX_DEFINE_NATIVE(isHudComponentActive)
				AMX_DEFINE_NATIVE(hideHudAndRadarThisFrame)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(showNotify) {
				if (!arguments(3))
					return 0;

				return Funcs::showNotify(String::get(amx, params[1]), (BOOL)params[2], (BOOL)params[3]);
			}

			AMX_NATIVE(showSubtitle) {
				if (!arguments(3))
					return 0;

				Funcs::showSubtitle(String::get(amx, params[1]), params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(setHudVisible) {
				if (!arguments(1))
					return 0;

				::UI::DISPLAY_HUD((BOOL)params[1]);

				return 1;
			}

			AMX_NATIVE(setRadarVisible) {
				if (!arguments(1))
					return 0;

				::UI::DISPLAY_RADAR((BOOL)params[1]);

				return 1;
			}

			AMX_NATIVE(setRadarZoom) {
				if (!arguments(1))
					return 0;

				if (0 > params[1] || params[1] > 200)
					return 0;

				::UI::SET_RADAR_ZOOM(params[1]);

				return 1;
			}

			AMX_NATIVE(isHudComponentActive) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_HUD_COMPONENT_ACTIVE(params[1]);
			}

			AMX_NATIVE(hideHudAndRadarThisFrame) {
				::UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
				return 1;
			}
		};
	};
};