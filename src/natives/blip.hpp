#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Blip {	
			MOD_NATIVE(addBlip);
			MOD_NATIVE(addBlipForRadius);
			MOD_NATIVE(addBlipForEntity);
			MOD_NATIVE(addBlipForPickup);
			MOD_NATIVE(removeBlip);
			MOD_NATIVE(isBlipExist);
			MOD_NATIVE(isBlipFlashing);
			MOD_NATIVE(isBlipOnMinimap);
			MOD_NATIVE(isBlipShortRange);
			MOD_NATIVE(setBlipPos);
			MOD_NATIVE(setBlipSprite);
			MOD_NATIVE(setBlipAlpha);
			MOD_NATIVE(setBlipFade);
			MOD_NATIVE(setBlipColor);
			MOD_NATIVE(setBlipScale);
			MOD_NATIVE(setBlipCategory);
			MOD_NATIVE(setBlipRoute);
			MOD_NATIVE(setBlipRouteColor);
			MOD_NATIVE(setBlipRotation);
			MOD_NATIVE(setBlipFlashTimer);
			MOD_NATIVE(setBlipFlashes);
			MOD_NATIVE(setBlipFlashesAlternate);
			MOD_NATIVE(setBlipPriority);
			MOD_NATIVE(setBlipBright);
			MOD_NATIVE(setBlipShowCone);
			MOD_NATIVE(setBlipDisplay);
			MOD_NATIVE(setBlipAsShortRange);
			MOD_NATIVE(setBlipAsFriendly);
			MOD_NATIVE(getBlipPos);
			MOD_NATIVE(getBlipSprite);
			MOD_NATIVE(getBlipColor);
			MOD_NATIVE(getBlipHudColour);
			MOD_NATIVE(getBlipInfoIdDisplay);
			MOD_NATIVE(getBlipInfoIdType);
			MOD_NATIVE(getBlipInfoIdPos);
			MOD_NATIVE(getBlipInfoIdEntityIndex);
			MOD_NATIVE(getBlipFromEntity);
			MOD_NATIVE(getNumberOfActiveBlips);
			MOD_NATIVE(getNextBlipInfoId);
			MOD_NATIVE(getFirstBlipInfoId);
			MOD_NATIVE(showTickOnBlip);
			MOD_NATIVE(showNumberOnBlip);
			MOD_NATIVE(hideNumberOnBlip);
			MOD_NATIVE(showHeadingIndicatorOnBlip);
			MOD_NATIVE(pulseBlip);
			MOD_NATIVE(isWaypointActive);
			MOD_NATIVE(setWaypointOff);
			MOD_NATIVE(refreshWaypoint);
			MOD_NATIVE(setNewWaypoint);

			AMX_NATIVE_INFO list[];
		};
	};
};