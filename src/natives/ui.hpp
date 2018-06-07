#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace UI {
			AMX_NATIVE(showNotify);
			AMX_NATIVE(showSubtitle);
			AMX_NATIVE(setHudVisible);
			AMX_NATIVE(setRadarVisible);
			AMX_NATIVE(setRadarZoom);
			AMX_NATIVE(isHudComponentActive);
			AMX_NATIVE(hideHudAndRadar);
			AMX_NATIVE(hideHudAndRadarThisFrame);

			AMX_NATIVE_INFO list[];
		};
	};
};