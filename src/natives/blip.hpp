#pragma once

#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Blip {	
			AMX_NATIVE(addBlip);
			AMX_NATIVE(removeBlip);
			AMX_NATIVE(setBlipPos);
			AMX_NATIVE(getBlipPos);
			AMX_NATIVE(setBlipSprite);
			AMX_NATIVE(getBlipSprite);
			AMX_NATIVE(setBlipAlpha);
			AMX_NATIVE(setBlipFade);
			AMX_NATIVE(setBlipColor);
			AMX_NATIVE(getBlipColor);
			AMX_NATIVE(setBlipScale);
			AMX_NATIVE(setBlipCategory);
			AMX_NATIVE(isBlipExist);
			AMX_NATIVE(isBlipFlashing);
			AMX_NATIVE(isBlipOnMinimap);
			AMX_NATIVE(setBlipRoute);
			AMX_NATIVE(setBlipRouteColor);
			AMX_NATIVE(setBlipRotation);
			AMX_NATIVE(setBlipFlashTimer);
			AMX_NATIVE(setBlipFlashes);
			AMX_NATIVE(setBlipFlashesAlternate);
			AMX_NATIVE(setBlipPriority);
			
			AMX_NATIVE_INFO list[];
		};
	};
};