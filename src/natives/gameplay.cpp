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
				checkargs(1);

				GAMEPLAY::SET_WIND(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(setWindSpeed) {
				checkargs(1);

				GAMEPLAY::SET_WIND_SPEED(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(setWindDirection) {
				checkargs(1);

				GAMEPLAY::SET_WIND_DIRECTION(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(getWindSpeed) {
				double speed = GAMEPLAY::GET_WIND_SPEED();
				
				return amx_ftoc(speed);
			}

			MOD_NATIVE(getWindDirection) {
				double speed = GAMEPLAY::GET_WIND_SPEED();
				
				return amx_ftoc(speed);
			}

			MOD_NATIVE(setRainIntensity) {
				checkargs(1);

				GAMEPLAY::_SET_RAIN_FX_INTENSITY(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(createLightningThunder) {
				GAMEPLAY::_CREATE_LIGHTNING_THUNDER();
				return 1;
			}

			MOD_NATIVE(setPoliceRadarBlips) {
				checkargs(1);

				PLAYER::SET_POLICE_RADAR_BLIPS((BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setPoliceIgnorePlayer) {
				checkargs(1);

				PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), (BOOL)params[1]);

				return 1;
			}

			MOD_NATIVE(setEveryoneIgnorePlayer) {
				checkargs(1);

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
				checkargs(1);

				return GAMEPLAY::IS_PREV_WEATHER_TYPE((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(isNextWeather) {
				checkargs(1);

				return GAMEPLAY::IS_NEXT_WEATHER_TYPE((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(setWeatherPersist) {
				checkargs(1);

				GAMEPLAY::SET_WEATHER_TYPE_PERSIST((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setWeatherNowPersist) {
				checkargs(1);

				GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setWeatherNow) {
				checkargs(1);

				GAMEPLAY::SET_WEATHER_TYPE_NOW((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(setWeatherOverTime) {
				checkargs(2);

				GAMEPLAY::_SET_WEATHER_TYPE_OVER_TIME((char *)String::get(amx, params[1]).c_str(), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setWeatherTransition) {
				checkargs(3);

				GAMEPLAY::_SET_WEATHER_TYPE_TRANSITION(params[1], params[2], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setOverrideWeather) {
				checkargs(1);

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
				checkargs(3);
				
				cell *sourceWeather, *targetWeather, *transitionTime;
				if (amx_GetAddr(amx, params[1], &sourceWeather) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &targetWeather) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &transitionTime) != AMX_ERR_NONE)
					return 0;
				
				float time;
				GAMEPLAY::_GET_WEATHER_TYPE_TRANSITION((Any *)sourceWeather, (Any *)targetWeather, &time);

				double ttime = static_cast<double>(time);
				
				*transitionTime = amx_ftoc(ttime);

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