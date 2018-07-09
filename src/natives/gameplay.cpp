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
				MOD_DEFINE_NATIVE(getRandomInt)
				MOD_DEFINE_NATIVE(getRandomFloat)
				MOD_DEFINE_NATIVE(getDistanceBetweenPos)
				MOD_DEFINE_NATIVE(setPoliceRadarBlips)
				MOD_DEFINE_NATIVE(setPoliceIgnorePlayer)
				MOD_DEFINE_NATIVE(setEveryoneIgnorePlayer)
				MOD_DEFINE_NATIVE(setExplosiveAmmoThisFrame)
				MOD_DEFINE_NATIVE(setFireAmmoThisFrame)
				MOD_DEFINE_NATIVE(setExplosiveMeleeThisFrame)
				MOD_DEFINE_NATIVE(isPrevWeather)
				MOD_DEFINE_NATIVE(isNextWeather)
				MOD_DEFINE_NATIVE(setWeatherPersist)
				MOD_DEFINE_NATIVE(setWeatherNowPersist)
				MOD_DEFINE_NATIVE(setWeatherNow)
				MOD_DEFINE_NATIVE(setWeatherOverTime)
				MOD_DEFINE_NATIVE(setWeatherTransition)
				MOD_DEFINE_NATIVE(setOverrideWeather)
				MOD_DEFINE_NATIVE(setRandomWeather)
				MOD_DEFINE_NATIVE(getCurrWeather)
				MOD_DEFINE_NATIVE(getNextWeather)
				MOD_DEFINE_NATIVE(getWeatherTransition)
				MOD_DEFINE_NATIVE(clearWeatherPersist)
				MOD_DEFINE_NATIVE(clearOverrideWeather)

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
			
			MOD_NATIVE(getRandomInt) {
				if (!arguments(2))
					return 0;

				return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(params[1], params[2]);
			}
			
			MOD_NATIVE(getRandomFloat) {
				if (!arguments(2))
					return 0;

				float value = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(amx_ctof(params[1]), amx_ctof(params[2]));

				return amx_ftoc(value);
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
			
			MOD_NATIVE(getAngleBetween2dVectors) {
				if (!arguments(2))
					return 0;

				float vec1[2], vec2[2];
				if (!Utility::getFloatArrayFromParam(amx, params[1], vec1, 2) ||
					!Utility::getFloatArrayFromParam(amx, params[2], vec2, 2))
					return 0;

				float dist = GAMEPLAY::GET_ANGLE_BETWEEN_2D_VECTORS(vec1[0], vec1[1], vec2[0], vec2[1]);
				
				return amx_ftoc(dist);
			}
			
			MOD_NATIVE(getHeadingFromVector2d) {
				if (!arguments(2))
					return 0;

				float dist = GAMEPLAY::GET_HEADING_FROM_VECTOR_2D(amx_ctof(params[1]), amx_ctof(params[2]));
				
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

			MOD_NATIVE(setExplosiveAmmoThisFrame) {
				GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());

				return 1;
			}

			MOD_NATIVE(setFireAmmoThisFrame) {
				GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());

				return 1;
			}

			MOD_NATIVE(setExplosiveMeleeThisFrame) {
				GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());

				return 1;
			}

			MOD_NATIVE(isPrevWeather) {
				if (!arguments(1))
					return 0;

				return GAMEPLAY::IS_PREV_WEATHER_TYPE((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(isNextWeather) {
				if (!arguments(1))
					return 0;

				return GAMEPLAY::IS_NEXT_WEATHER_TYPE((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(setWeatherPersist) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WEATHER_TYPE_PERSIST((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setWeatherNowPersist) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setWeatherNow) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_WEATHER_TYPE_NOW((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setWeatherOverTime) {
				if (!arguments(2))
					return 0;

				GAMEPLAY::_SET_WEATHER_TYPE_OVER_TIME((char *)String::get(amx, params[1]).c_str(), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setWeatherTransition) {
				if (!arguments(3))
					return 0;

				GAMEPLAY::_SET_WEATHER_TYPE_TRANSITION(params[1], params[2], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setOverrideWeather) {
				if (!arguments(1))
					return 0;

				GAMEPLAY::SET_OVERRIDE_WEATHER((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setRandomWeather) {
				GAMEPLAY::SET_RANDOM_WEATHER_TYPE();

				return 1;
			}

			MOD_NATIVE(getCurrWeather) {
				GAMEPLAY::_GET_CURRENT_WEATHER_TYPE();

				return 1;
			}

			MOD_NATIVE(getNextWeather) {
				GAMEPLAY::_GET_NEXT_WEATHER_TYPE();

				return 1;
			}

			MOD_NATIVE(getWeatherTransition) {
				if (!arguments(3))
					return 0;
				
				cell * sourceWeather = Utility::getAddrFromParam(amx, params[1]),
					 * targetWeather = Utility::getAddrFromParam(amx, params[2]),
					 * transitionTime = Utility::getAddrFromParam(amx, params[3]);

				if (sourceWeather == nullptr || targetWeather == nullptr || transitionTime == nullptr)
					return 0;
				
				float time;
				GAMEPLAY::_GET_WEATHER_TYPE_TRANSITION((Any *)sourceWeather, (Any *)targetWeather, &time);

				*transitionTime = amx_ftoc(time);

				return 1;
			}

			MOD_NATIVE(clearWeatherPersist) {
				GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST();

				return 1;
			}

			MOD_NATIVE(clearOverrideWeather) {
				GAMEPLAY::CLEAR_OVERRIDE_WEATHER();

				return 1;
			}
		};
	};
};