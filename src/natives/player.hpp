#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Player {
			MOD_NATIVE(getPlayerPed);
			MOD_NATIVE(getPlayerName);
			MOD_NATIVE(setPlayerLockOn);
			MOD_NATIVE(isPlayerPlaying);
			MOD_NATIVE(isPlayerDead);
			MOD_NATIVE(isPlayerClimbing);
			MOD_NATIVE(isPlayerBusted);
			MOD_NATIVE(isPlayerRidingTrain);
			MOD_NATIVE(isPlayerTargettingEntity);
			MOD_NATIVE(isPlayerTargettingAnything);
			MOD_NATIVE(isPlayerControlOn);
			MOD_NATIVE(isPlayerInvincible);
			MOD_NATIVE(reportPlayerCrime);
			MOD_NATIVE(setPlayerWantedLevel);
			MOD_NATIVE(setPlayerWantedLevelNoDrop);
			MOD_NATIVE(getPlayerWantedLevel);
			MOD_NATIVE(getPlayerWantedLevelThreshold);
			MOD_NATIVE(clearPlayerWantedLevel);
			MOD_NATIVE(getPlayerPos);
			MOD_NATIVE(getPlayerMaxArmor);
			MOD_NATIVE(getPlayerStealthNoise);
			MOD_NATIVE(setPlayerInvincible);
			MOD_NATIVE(getTimeSincePlayerLastArrest);
			MOD_NATIVE(getTimeSincePlayerLastDeath);
			MOD_NATIVE(getTimeSincePlayerHitVehicle);
			MOD_NATIVE(getTimeSincePlayerHitPed);
			MOD_NATIVE(getTSPlayerDroveOnPavement);
			MOD_NATIVE(getTSPlayerDroveAgainstTraffic);
			MOD_NATIVE(setPlayerModel);
			MOD_NATIVE(setPlayerSprint);
			MOD_NATIVE(setPlayerMaxArmor);

			AMX_NATIVE_INFO list[];
		};
	};
};