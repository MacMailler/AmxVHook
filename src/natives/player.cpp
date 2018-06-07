#include "player.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Player {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(getPlayerPed)
				AMX_DEFINE_NATIVE(getPlayerName)
				AMX_DEFINE_NATIVE(setPlayerLockOn)
				AMX_DEFINE_NATIVE(isPlayerPlaying)
				AMX_DEFINE_NATIVE(isPlayerDead)
				AMX_DEFINE_NATIVE(isPlayerClimbing)
				AMX_DEFINE_NATIVE(isPlayerBusted)
				AMX_DEFINE_NATIVE(isPlayerRidingTrain)
				AMX_DEFINE_NATIVE(isPlayerTargettingEntity)
				AMX_DEFINE_NATIVE(isPlayerTargettingAnything)
				AMX_DEFINE_NATIVE(isPlayerControlOn)
				AMX_DEFINE_NATIVE(reportPlayerCrime)
				AMX_DEFINE_NATIVE(setPlayerWantedLevel)
				AMX_DEFINE_NATIVE(setPlayerWantedLevelNoDrop)
				AMX_DEFINE_NATIVE(getPlayerWantedLevel)
				AMX_DEFINE_NATIVE(getPlayerWantedLevelThreshold)
				AMX_DEFINE_NATIVE(getPlayerPos)
				AMX_DEFINE_NATIVE(getPlayerMaxArmor)
				AMX_DEFINE_NATIVE(getPlayerStealthNoise)
				AMX_DEFINE_NATIVE(setPlayerInvincible)
				AMX_DEFINE_NATIVE(getPlayerInvincible)
				AMX_DEFINE_NATIVE(getTimeSincePlayerLastArrest)
				AMX_DEFINE_NATIVE(getTimeSincePlayerLastDeath)
				AMX_DEFINE_NATIVE(getTimeSincePlayerHitVehicle)
				AMX_DEFINE_NATIVE(getTimeSincePlayerHitPed)
				AMX_DEFINE_NATIVE(getTSPlayerDroveOnPavement)
				AMX_DEFINE_NATIVE(getTSPlayerDroveAgainstTraffic)
				AMX_DEFINE_NATIVE(setPlayerModel)
				AMX_DEFINE_NATIVE(setPlayerSprint)
				AMX_DEFINE_NATIVE(setPlayerMaxArmor)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(getPlayerPed) {
				return PLAYER::PLAYER_PED_ID();
			}

			AMX_NATIVE(getPlayerName) {
				if (!arguments(2))
					return 0;

				cell * dest = NULL;
				char * name = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());

				amx_GetAddr(amx, params[1], &dest);
				amx_SetString(dest, name, NULL, NULL, params[2]);

				return 1;
			}

			AMX_NATIVE(isPlayerPlaying) {
				return PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(isPlayerDead) {
				return PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(isPlayerTargettingEntity) {
				if (arguments(1))
					return 0;

				return PLAYER::IS_PLAYER_TARGETTING_ENTITY(PLAYER::PLAYER_ID(), (::Entity)params[1]);
			}

			AMX_NATIVE(isPlayerTargettingAnything) {
				return PLAYER::IS_PLAYER_TARGETTING_ANYTHING(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(isPlayerControlOn) {
				return PLAYER::IS_PLAYER_CONTROL_ON(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(isPlayerClimbing) {
				return PLAYER::IS_PLAYER_CLIMBING(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(isPlayerBusted) {
				if (arguments(1))
					return 0;

				return PLAYER::IS_PLAYER_BEING_ARRESTED(PLAYER::PLAYER_ID(), params[1]);
			}

			AMX_NATIVE(isPlayerRidingTrain) {
				return PLAYER::IS_PLAYER_RIDING_TRAIN(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(setPlayerSprint) {
				if (arguments(1))
					return 0;

				PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			AMX_NATIVE(setPlayerLockOn) {
				if (arguments(1))
					return 0;

				PLAYER::SET_PLAYER_LOCKON(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			AMX_NATIVE(reportPlayerCrime) {
				if (!arguments(2))
					return 0;

				PLAYER::REPORT_CRIME(PLAYER::PLAYER_ID(), params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setPlayerWantedLevel) {
				if (!arguments(1))
					return 0;

				::Player player = PLAYER::PLAYER_ID();

				PLAYER::SET_PLAYER_WANTED_LEVEL(player, params[1], FALSE);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);

				return 1;
			}

			AMX_NATIVE(setPlayerWantedLevelNoDrop) {
				if (!arguments(1))
					return 0;

				::Player player = PLAYER::PLAYER_ID();

				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, params[1], FALSE);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);

				return 1;
			}

			AMX_NATIVE(getPlayerWantedLevel) {
				if (!arguments(1))
					return -1;

				return PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(getPlayerWantedLevelThreshold) {
				if (!arguments(1))
					return -1;

				return PLAYER::GET_WANTED_LEVEL_THRESHOLD(params[1]);
			}

			AMX_NATIVE(getPlayerMaxArmor) {
				return PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(getPlayerStealthNoise) {
				float noise = PLAYER::GET_PLAYER_CURRENT_STEALTH_NOISE(PLAYER::PLAYER_ID());
				return amx_ftoc(noise);
			}

			AMX_NATIVE(getPlayerTargetEntity) {
				if (!arguments(1))
					return 0;

				cell *entity = nullptr;
				if (amx_GetAddr(amx, params[1], &entity) != AMX_ERR_NONE || entity == nullptr)
					return 0;

				return PLAYER::GET_PLAYER_TARGET_ENTITY(PLAYER::PLAYER_ID(), (::Entity *)entity);
			}

			AMX_NATIVE(getTimeSincePlayerLastArrest) {
				return PLAYER::GET_TIME_SINCE_LAST_ARREST();
			}

			AMX_NATIVE(getTimeSincePlayerLastDeath) {
				return PLAYER::GET_TIME_SINCE_LAST_DEATH();
			}

			AMX_NATIVE(getTimeSincePlayerHitVehicle) {
				return PLAYER::GET_TIME_SINCE_PLAYER_HIT_VEHICLE(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(getTimeSincePlayerHitPed) {
				return PLAYER::GET_TIME_SINCE_PLAYER_HIT_PED(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(getTSPlayerDroveOnPavement) {
				return PLAYER::GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(getTSPlayerDroveAgainstTraffic) {
				return PLAYER::GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC(PLAYER::PLAYER_ID());
			}

			AMX_NATIVE(getPlayerPos) {
				if (!arguments(2))
					return 0;

				cell *addr = nullptr;

				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), params[2]);
				Funcs::vector3ToCellArray(addr, &coords);

				return 1;
			}

			AMX_NATIVE(setPlayerInvincible) {
				if (!arguments(2))
					return 0;

				PLAYER::SET_PLAYER_INVINCIBLE(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(getPlayerInvincible) {
				if (!arguments(1))
					return 0;

				return PLAYER::GET_PLAYER_INVINCIBLE(params[1]);
			}

			AMX_NATIVE(setPlayerMaxArmor) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), params[1]);

				return 1;
			}

			AMX_NATIVE(setPlayerModel) {
				if (!arguments(1))
					return 0;

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