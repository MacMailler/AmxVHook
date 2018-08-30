#include "player.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Player {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(getPlayerPed)
				MOD_DEFINE_NATIVE(getPlayerName)
				MOD_DEFINE_NATIVE(setPlayerLockOn)
				MOD_DEFINE_NATIVE(isPlayerPlaying)
				MOD_DEFINE_NATIVE(isPlayerDead)
				MOD_DEFINE_NATIVE(isPlayerClimbing)
				MOD_DEFINE_NATIVE(isPlayerBusted)
				MOD_DEFINE_NATIVE(isPlayerRidingTrain)
				MOD_DEFINE_NATIVE(isPlayerTargettingEntity)
				MOD_DEFINE_NATIVE(isPlayerTargettingAnything)
				MOD_DEFINE_NATIVE(isPlayerControlOn)
				MOD_DEFINE_NATIVE(isPlayerInvincible)
				MOD_DEFINE_NATIVE(reportPlayerCrime)
				MOD_DEFINE_NATIVE(setPlayerWantedLevel)
				MOD_DEFINE_NATIVE(setPlayerWantedLevelNoDrop)
				MOD_DEFINE_NATIVE(getPlayerWantedLevel)
				MOD_DEFINE_NATIVE(getPlayerWantedLevelThreshold)
				MOD_DEFINE_NATIVE(clearPlayerWantedLevel)
				MOD_DEFINE_NATIVE(getPlayerPos)
				MOD_DEFINE_NATIVE(getPlayerMaxArmor)
				MOD_DEFINE_NATIVE(getPlayerStealthNoise)
				MOD_DEFINE_NATIVE(setPlayerInvincible)
				MOD_DEFINE_NATIVE(getTimeSincePlayerLastArrest)
				MOD_DEFINE_NATIVE(getTimeSincePlayerLastDeath)
				MOD_DEFINE_NATIVE(getTimeSincePlayerHitVehicle)
				MOD_DEFINE_NATIVE(getTimeSincePlayerHitPed)
				MOD_DEFINE_NATIVE(getTSPlayerDroveOnPavement)
				MOD_DEFINE_NATIVE(getTSPlayerDroveAgainstTraffic)
				MOD_DEFINE_NATIVE(setPlayerModel)
				MOD_DEFINE_NATIVE(setPlayerSprint)
				MOD_DEFINE_NATIVE(setPlayerMaxArmor)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(getPlayerPed) {
				return PLAYER::PLAYER_PED_ID();
			}

			MOD_NATIVE(getPlayerName) {
				checkargs(2);

				cell *dest;
				if (amx_GetAddr(amx, params[1], &dest) != AMX_ERR_NONE)
					return 0;
				
				char * name = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());

				amx_SetString(dest, name, NULL, NULL, params[2]);

				return 1;
			}

			MOD_NATIVE(isPlayerPlaying) {
				return PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isPlayerDead) {
				return PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isPlayerTargettingEntity) {
				checkargs(1);

				return PLAYER::IS_PLAYER_TARGETTING_ENTITY(PLAYER::PLAYER_ID(), (::Entity)params[1]);
			}

			MOD_NATIVE(isPlayerTargettingAnything) {
				return PLAYER::IS_PLAYER_TARGETTING_ANYTHING(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isPlayerControlOn) {
				return PLAYER::IS_PLAYER_CONTROL_ON(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isPlayerClimbing) {
				return PLAYER::IS_PLAYER_CLIMBING(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isPlayerBusted) {
				checkargs(1);

				return PLAYER::IS_PLAYER_BEING_ARRESTED(PLAYER::PLAYER_ID(), params[1]);
			}

			MOD_NATIVE(isPlayerRidingTrain) {
				return PLAYER::IS_PLAYER_RIDING_TRAIN(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(setPlayerSprint) {
				checkargs(1);

				PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setPlayerLockOn) {
				checkargs(1);

				PLAYER::SET_PLAYER_LOCKON(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(reportPlayerCrime) {
				checkargs(2);

				PLAYER::REPORT_CRIME(PLAYER::PLAYER_ID(), params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPlayerWantedLevel) {
				checkargs(1);

				::Player player = PLAYER::PLAYER_ID();

				PLAYER::SET_PLAYER_WANTED_LEVEL(player, params[1], FALSE);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);

				return 1;
			}

			MOD_NATIVE(setPlayerWantedLevelNoDrop) {
				checkargs(1);

				::Player player = PLAYER::PLAYER_ID();

				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, params[1], FALSE);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);

				return 1;
			}

			MOD_NATIVE(getPlayerWantedLevelThreshold) {
				return PLAYER::GET_WANTED_LEVEL_THRESHOLD(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(getPlayerWantedLevel) {
				return PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			}
			
			MOD_NATIVE(clearPlayerWantedLevel) {
				PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
				return 1;
			}

			MOD_NATIVE(getPlayerMaxArmor) {
				return PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(getPlayerStealthNoise) {
				double noise = PLAYER::GET_PLAYER_CURRENT_STEALTH_NOISE(PLAYER::PLAYER_ID());
				return amx_ftoc(noise);
			}

			MOD_NATIVE(getPlayerTargetEntity) {
				checkargs(1);

				cell *entity;
				if (amx_GetAddr(amx, params[1], &entity) != AMX_ERR_NONE)
					return 0;;

				return PLAYER::GET_PLAYER_TARGET_ENTITY(PLAYER::PLAYER_ID(), (::Entity *)entity);
			}

			MOD_NATIVE(getTimeSincePlayerLastArrest) {
				return PLAYER::GET_TIME_SINCE_LAST_ARREST();
			}

			MOD_NATIVE(getTimeSincePlayerLastDeath) {
				return PLAYER::GET_TIME_SINCE_LAST_DEATH();
			}

			MOD_NATIVE(getTimeSincePlayerHitVehicle) {
				return PLAYER::GET_TIME_SINCE_PLAYER_HIT_VEHICLE(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(getTimeSincePlayerHitPed) {
				return PLAYER::GET_TIME_SINCE_PLAYER_HIT_PED(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(getTSPlayerDroveOnPavement) {
				return PLAYER::GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(getTSPlayerDroveAgainstTraffic) {
				return PLAYER::GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC(PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(getPlayerPos) {
				checkargs(2);

				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), params[2]);
				return Aux::setVector3(amx, params[1], coords);
			}

			MOD_NATIVE(setPlayerInvincible) {
				checkargs(1);

				ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()), params[1]);

				return 1;
			}

			MOD_NATIVE(isPlayerInvincible) {
				auto addr = getScriptHandleBaseAddress(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()));

				if (addr) {
					DWORD flag = *(DWORD *)(addr + 0x188);
					return ((flag & (1 << 8)) != 0) || ((flag & (1 << 9)) != 0);
				}

				return false;
			}

			MOD_NATIVE(setPlayerMaxArmor) {
				checkargs(1);

				PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), params[1]);

				return 1;
			}

			MOD_NATIVE(setPlayerModel) {
				checkargs(1);

				Hash model = GAMEPLAY::GET_HASH_KEY((char *)String::get(amx, params[1]).c_str());
				if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model)) {
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				}

				return 1;
			}
		};
	};
};