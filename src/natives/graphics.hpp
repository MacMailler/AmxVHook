#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Graphics {
			MOD_NATIVE(createTexture);
			MOD_NATIVE(drawTexture);
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
			MOD_NATIVE(setDrawPos);
			MOD_NATIVE(setDrawPosRatio);
			MOD_NATIVE(setDrawPosEnd);
			MOD_NATIVE(loadTextureDict);
			MOD_NATIVE(isTextureDictLoaded);
			MOD_NATIVE(unloadTextureDict);
			MOD_NATIVE(getTextureDictSize);
			MOD_NATIVE(addTextComponentStr);
			MOD_NATIVE(addTextComponentInt);
			MOD_NATIVE(addTextComponentFloat);
			
			AMX_NATIVE_INFO list[];
		};
	};
};