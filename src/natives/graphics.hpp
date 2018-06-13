#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Graphics {
			MOD_NATIVE(drawRect);
			MOD_NATIVE(drawText);
			MOD_NATIVE(drawMarker);
			MOD_NATIVE(setTextDropShadow);
			MOD_NATIVE(setTextEdge);
			MOD_NATIVE(setTextWrap);
			MOD_NATIVE(setUILayer);
			MOD_NATIVE(setDrawPosition);
			MOD_NATIVE(setDrawPositionRatio);
			MOD_NATIVE(setDrawPositionEnd);
			MOD_NATIVE(getSafeZoneSize);
			MOD_NATIVE(isWidescreen);
			MOD_NATIVE(getScreenSize);
			MOD_NATIVE(world3DToScreen2D);
		
			AMX_NATIVE_INFO list[];
		};
	};
};