#include "gameplay.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Gameplay {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isMissionFlag)
				MOD_DEFINE_NATIVE(setWind)
				MOD_DEFINE_NATIVE(setWindSpeed)
				MOD_DEFINE_NATIVE(getWindSpeed)
				MOD_DEFINE_NATIVE(setWindDirection)
				MOD_DEFINE_NATIVE(getWindDirection)
				MOD_DEFINE_NATIVE(setRainIntensity)
				MOD_DEFINE_NATIVE(createLightningThunder)
				MOD_DEFINE_NATIVE(getGameTimer)
				MOD_DEFINE_NATIVE(getFrameTime)
				MOD_DEFINE_NATIVE(getFrameCount)
				MOD_DEFINE_NATIVE(getHashKey)
				MOD_DEFINE_NATIVE(getDistanceBetweenPos)
				MOD_DEFINE_NATIVE(setPoliceRadarBlips)
				MOD_DEFINE_NATIVE(setPoliceIgnorePlayer)
				MOD_DEFINE_NATIVE(setEveryoneIgnorePlayer)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(isMissionFlag) {
				return GAMEPLAY::GET_MISSION_FLAG();
			}

			MOD_NATIVE(setWind) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WIND(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(setWindSpeed) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WIND_SPEED(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(setWindDirection) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WIND_DIRECTION(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(getWindSpeed) {
				float speed = GAMEPLAY::GET_WIND_SPEED();
				return amx_ftoc(speed);
			}

			MOD_NATIVE(getWindDirection) {
				float speed = GAMEPLAY::GET_WIND_SPEED();
				return amx_ftoc(speed);
			}

			MOD_NATIVE(setRainIntensity) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::_SET_RAIN_FX_INTENSITY(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(createLightningThunder) {
				GAMEPLAY::_CREATE_LIGHTNING_THUNDER();
				return 1;
			}

			MOD_NATIVE(getGameTimer) {
				return GAMEPLAY::GET_GAME_TIMER();
			}

			MOD_NATIVE(getFrameTime) {
				float time = GAMEPLAY::GET_FRAME_TIME();
				return amx_ftoc(time);
			}

			MOD_NATIVE(getFrameCount) {
				return GAMEPLAY::GET_FRAME_COUNT();
			}

			MOD_NATIVE(getHashKey) {
				if (!arguments(1))
					return 0;

				return GAMEPLAY::GET_HASH_KEY((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(getDistanceBetweenPos) {
				if (!arguments(3))
					return 0;

				float coords[3], coords2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], coords2, 3))
					return 0;

				float dist = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(
					coords[0], coords[1], coords[2],
					coords2[0], coords2[1], coords2[2],
					params[3]
				);
				
				return amx_ftoc(dist);
			}

			MOD_NATIVE(setPoliceRadarBlips) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_POLICE_RADAR_BLIPS((BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setPoliceIgnorePlayer) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setEveryoneIgnorePlayer) {
				if (!arguments(1))
					return 0;

				PLAYER::SET_EVERYONE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}
		};
	};
};