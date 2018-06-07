#include "gameplay.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Gameplay {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(isMissionFlag)
				AMX_DEFINE_NATIVE(setWind)
				AMX_DEFINE_NATIVE(setWindSpeed)
				AMX_DEFINE_NATIVE(getWindSpeed)
				AMX_DEFINE_NATIVE(setWindDirection)
				AMX_DEFINE_NATIVE(getWindDirection)
				AMX_DEFINE_NATIVE(setRainIntensity)
				AMX_DEFINE_NATIVE(createLightningThunder)
				AMX_DEFINE_NATIVE(getGameTimer)
				AMX_DEFINE_NATIVE(getFrameTime)
				AMX_DEFINE_NATIVE(getFrameCount)
				AMX_DEFINE_NATIVE(getHashKey)
				AMX_DEFINE_NATIVE(getDistanceBetweenPos)
				AMX_DEFINE_NATIVE(setPoliceRadarBlips)
				AMX_DEFINE_NATIVE(setPoliceIgnorePlayer)
				AMX_DEFINE_NATIVE(setEveryoneIgnorePlayer)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(isMissionFlag) {
				return GAMEPLAY::GET_MISSION_FLAG();
			}

			AMX_NATIVE(setWind) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WIND(amx_ctof(params[1]));

				return 1;
			}

			AMX_NATIVE(setWindSpeed) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WIND_SPEED(amx_ctof(params[1]));

				return 1;
			}

			AMX_NATIVE(setWindDirection) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WIND_DIRECTION(amx_ctof(params[1]));

				return 1;
			}

			AMX_NATIVE(getWindSpeed) {
				float speed = GAMEPLAY::GET_WIND_SPEED();
				return amx_ftoc(speed);
			}

			AMX_NATIVE(getWindDirection) {
				float speed = GAMEPLAY::GET_WIND_SPEED();
				return amx_ftoc(speed);
			}

			AMX_NATIVE(setRainIntensity) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::_SET_RAIN_FX_INTENSITY(amx_ctof(params[1]));

				return 1;
			}

			AMX_NATIVE(createLightningThunder) {
				GAMEPLAY::_CREATE_LIGHTNING_THUNDER();
				return 1;
			}

			AMX_NATIVE(getGameTimer) {
				return GAMEPLAY::GET_GAME_TIMER();
			}

			AMX_NATIVE(getFrameTime) {
				float time = GAMEPLAY::GET_FRAME_TIME();
				return amx_ftoc(time);
			}

			AMX_NATIVE(getFrameCount) {
				return GAMEPLAY::GET_FRAME_COUNT();
			}

			AMX_NATIVE(getHashKey) {
				if (!arguments(1))
					return 0;

				return GAMEPLAY::GET_HASH_KEY((char *)String::get(amx, params[1]).c_str());
			}

			AMX_NATIVE(getDistanceBetweenPos) {
				if (!arguments(3))
					return 0;

				cell * vec1 = nullptr, *vec2 = nullptr;
				if ((amx_GetAddr(amx, params[1], &vec1) != AMX_ERR_NONE) ||
					(amx_GetAddr(amx, params[2], &vec2) != AMX_ERR_NONE))
					return 0;

				float dist = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(
					amx_ctof(vec1[0]), amx_ctof(vec1[1]), amx_ctof(vec1[2]),
					amx_ctof(vec2[0]), amx_ctof(vec2[1]), amx_ctof(vec2[2]),
					params[3]
				);
				
				return amx_ftoc(dist);
			}

			AMX_NATIVE(setPoliceRadarBlips) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_POLICE_RADAR_BLIPS((BOOL)params[1]);

				return 1;
			}

			AMX_NATIVE(setPoliceIgnorePlayer) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			AMX_NATIVE(setEveryoneIgnorePlayer) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_EVERYONE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}
		};
	};
};