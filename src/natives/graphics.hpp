#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Graphics {
			MOD_NATIVE(drawInt);
			MOD_NATIVE(drawFloat);
			MOD_NATIVE(drawString);
			MOD_NATIVE(drawCounter);
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
			MOD_NATIVE(setTextScale);
			MOD_NATIVE(setTextCentre);
			MOD_NATIVE(setTextFont);
			MOD_NATIVE(setTextJustification);
			MOD_NATIVE(setTextRightJustify);
			MOD_NATIVE(setTextEntry);
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
			MOD_NATIVE(showHelpMessage);
			MOD_NATIVE(showLoadingSpinner);
			MOD_NATIVE(hideLoadingSpinner);
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
			MOD_NATIVE(getTextureResolution);
			MOD_NATIVE(addTextComponentStr);
			MOD_NATIVE(addTextComponentInt);
			MOD_NATIVE(addTextComponentFloat);
			
			AMX_NATIVE_INFO list[];
		};
	};
};