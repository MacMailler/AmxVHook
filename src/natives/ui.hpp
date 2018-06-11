#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace UI {
			MOD_NATIVE(showNotify);
			MOD_NATIVE(showSubtitle);
			MOD_NATIVE(setHudVisible);
			MOD_NATIVE(setRadarVisible);
			MOD_NATIVE(setRadarZoom);
			MOD_NATIVE(isHudComponentActive);
			MOD_NATIVE(hideHudAndRadar);
			MOD_NATIVE(hideHudAndRadarThisFrame);

			AMX_NATIVE_INFO list[];
		};
	};
};