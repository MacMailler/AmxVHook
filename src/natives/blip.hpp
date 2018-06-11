#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Blip {	
			MOD_NATIVE(addBlip);
			MOD_NATIVE(removeBlip);
			MOD_NATIVE(setBlipPos);
			MOD_NATIVE(getBlipPos);
			MOD_NATIVE(setBlipSprite);
			MOD_NATIVE(getBlipSprite);
			MOD_NATIVE(setBlipAlpha);
			MOD_NATIVE(setBlipFade);
			MOD_NATIVE(setBlipColor);
			MOD_NATIVE(getBlipColor);
			MOD_NATIVE(setBlipScale);
			MOD_NATIVE(setBlipCategory);
			MOD_NATIVE(isBlipExist);
			MOD_NATIVE(isBlipFlashing);
			MOD_NATIVE(isBlipOnMinimap);
			MOD_NATIVE(setBlipRoute);
			MOD_NATIVE(setBlipRouteColor);
			MOD_NATIVE(setBlipRotation);
			MOD_NATIVE(setBlipFlashTimer);
			MOD_NATIVE(setBlipFlashes);
			MOD_NATIVE(setBlipFlashesAlternate);
			MOD_NATIVE(setBlipPriority);
			
			AMX_NATIVE_INFO list[];
		};
	};
};