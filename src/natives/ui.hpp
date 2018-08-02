#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace UI {
			MOD_NATIVE(isHudHidden);
			MOD_NATIVE(isRadarHidden);
			MOD_NATIVE(isRadarEnabled);
			MOD_NATIVE(isWidescreen);
			MOD_NATIVE(isHudComponentActive);
			MOD_NATIVE(setHudVisible);
			MOD_NATIVE(setRadarVisible);
			MOD_NATIVE(setRadarZoom);
			MOD_NATIVE(getSafeZoneSize);
			MOD_NATIVE(getScreenSize);
			MOD_NATIVE(getScreenAspectRatio);
			MOD_NATIVE(getLabelText);
			MOD_NATIVE(showNotify);
			MOD_NATIVE(showSubtitle);
			MOD_NATIVE(showHelpMessage);
			MOD_NATIVE(showLoadingSpinner);
			MOD_NATIVE(showHudComponentThisFrame);
			MOD_NATIVE(showHud);
			MOD_NATIVE(showRadar);
			MOD_NATIVE(showCash);
			MOD_NATIVE(showAreaName);
			MOD_NATIVE(hideLoadingSpinner);
			MOD_NATIVE(hideHudAndRadarThisFrame);
			MOD_NATIVE(hideHudComponentThisFrame);
			MOD_NATIVE(removeNotify);
			MOD_NATIVE(activateFrontendMenu);
			MOD_NATIVE(restartFrontendMenu);
			MOD_NATIVE(getCurrentFrontendMenu);

			AMX_NATIVE_INFO list[];
		};
	};
};