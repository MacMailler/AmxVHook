#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Graphics {
			MOD_NATIVE(drawInt);
			MOD_NATIVE(drawFloat);
			MOD_NATIVE(drawString);
			MOD_NATIVE(drawRect);
			MOD_NATIVE(drawText);
			MOD_NATIVE(drawLine);
			MOD_NATIVE(drawPoly);
			MOD_NATIVE(drawBox);
			MOD_NATIVE(drawMarker);
			MOD_NATIVE(drawSprite);
			MOD_NATIVE(drawSpotLight);
			MOD_NATIVE(drawSpotLightWithShadow);
			MOD_NATIVE(drawLightWithRange);
			MOD_NATIVE(drawLightWithRangeAndShadow);
			MOD_NATIVE(setTextDropShadow);
			MOD_NATIVE(setTextEdge);
			MOD_NATIVE(setTextWrap);
			MOD_NATIVE(setTextColor);
			MOD_NATIVE(setUILayer);
			MOD_NATIVE(setDrawPosition);
			MOD_NATIVE(setDrawPositionRatio);
			MOD_NATIVE(setDrawPositionEnd);
			MOD_NATIVE(setHudVisible);
			MOD_NATIVE(setRadarVisible);
			MOD_NATIVE(setRadarZoom);
			MOD_NATIVE(getSafeZoneSize);
			MOD_NATIVE(getScreenSize);
			MOD_NATIVE(showNotify);
			MOD_NATIVE(showSubtitle);
			MOD_NATIVE(isWidescreen);
			MOD_NATIVE(isHudComponentActive);
			MOD_NATIVE(hideHudAndRadarThisFrame);
			MOD_NATIVE(hideHudComponentThisFrame);
			MOD_NATIVE(showHudComponentThisFrame);
			MOD_NATIVE(world3DToScreen2D);
			MOD_NATIVE(activateFrontendMenu);
			MOD_NATIVE(restartFrontendMenu);
			MOD_NATIVE(getCurrentFrontendMenu);
			MOD_NATIVE(requestStreamedTextureDict);
			MOD_NATIVE(isStreamedTextureDictLoaded);
			MOD_NATIVE(setStreamedTextureDictNoNeeded);
			
			AMX_NATIVE_INFO list[];
		};
	};
};