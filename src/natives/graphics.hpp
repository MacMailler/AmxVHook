#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Graphics {
			AMX_NATIVE(drawRect);
			AMX_NATIVE(drawText);
			AMX_NATIVE(drawMarker);
			AMX_NATIVE(setUILayer);
			AMX_NATIVE(setDrawPosition);
			AMX_NATIVE(setDrawPositionRatio);
			AMX_NATIVE(setDrawPositionEnd);
			AMX_NATIVE(getSafeZoneSize);
			AMX_NATIVE(isWidescreen);
			AMX_NATIVE(getScreenSize);
			AMX_NATIVE(world3DToScreen2D);
		
			AMX_NATIVE_INFO list[];
		};
	};
};