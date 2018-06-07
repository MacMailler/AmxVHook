#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Player {
			AMX_NATIVE(getPlayerPed);
			AMX_NATIVE(getPlayerName);
			AMX_NATIVE(setPlayerLockOn);
			AMX_NATIVE(isPlayerPlaying);
			AMX_NATIVE(isPlayerDead);
			AMX_NATIVE(isPlayerClimbing);
			AMX_NATIVE(isPlayerBusted);
			AMX_NATIVE(isPlayerRidingTrain);
			AMX_NATIVE(isPlayerTargettingEntity);
			AMX_NATIVE(isPlayerTargettingAnything);
			AMX_NATIVE(isPlayerControlOn);
			AMX_NATIVE(reportPlayerCrime);
			AMX_NATIVE(setPlayerWantedLevel);
			AMX_NATIVE(setPlayerWantedLevelNoDrop);
			AMX_NATIVE(getPlayerWantedLevel);
			AMX_NATIVE(getPlayerWantedLevelThreshold);
			AMX_NATIVE(getPlayerPos);
			AMX_NATIVE(getPlayerMaxArmor);
			AMX_NATIVE(getPlayerStealthNoise);
			AMX_NATIVE(setPlayerInvincible);
			AMX_NATIVE(getPlayerInvincible);
			AMX_NATIVE(getTimeSincePlayerLastArrest);
			AMX_NATIVE(getTimeSincePlayerLastDeath);
			AMX_NATIVE(getTimeSincePlayerHitVehicle);
			AMX_NATIVE(getTimeSincePlayerHitPed);
			AMX_NATIVE(getTSPlayerDroveOnPavement);
			AMX_NATIVE(getTSPlayerDroveAgainstTraffic);
			AMX_NATIVE(setPlayerModel);
			AMX_NATIVE(setPlayerSprint);
			AMX_NATIVE(setPlayerMaxArmor);
			
			AMX_NATIVE_INFO list[];
		};
	};
};