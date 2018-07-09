#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Gameplay {
			MOD_NATIVE(isMissionFlag);
			MOD_NATIVE(setWind);
			MOD_NATIVE(setWindSpeed);
			MOD_NATIVE(setWindDirection);
			MOD_NATIVE(getWindSpeed);
			MOD_NATIVE(getWindDirection);
			MOD_NATIVE(setRainIntensity);
			MOD_NATIVE(createLightningThunder);
			MOD_NATIVE(getGameTimer);
			MOD_NATIVE(getFrameTime);
			MOD_NATIVE(getFrameCount);
			MOD_NATIVE(getHashKey);
			MOD_NATIVE(getRandomInt);
			MOD_NATIVE(getRandomFloat);
			MOD_NATIVE(getDistanceBetweenPos);
			MOD_NATIVE(setPoliceRadarBlips);
			MOD_NATIVE(setPoliceIgnorePlayer);
			MOD_NATIVE(setEveryoneIgnorePlayer);
			MOD_NATIVE(setExplosiveAmmoThisFrame);
			MOD_NATIVE(setFireAmmoThisFrame);
			MOD_NATIVE(setExplosiveMeleeThisFrame);
			MOD_NATIVE(isPrevWeather);
			MOD_NATIVE(isNextWeather);
			MOD_NATIVE(setWeatherPersist);
			MOD_NATIVE(setWeatherNowPersist);
			MOD_NATIVE(setWeatherNow);
			MOD_NATIVE(setWeatherOverTime);
			MOD_NATIVE(setWeatherTransition);
			MOD_NATIVE(setOverrideWeather);
			MOD_NATIVE(setRandomWeather);
			MOD_NATIVE(getCurrWeather);
			MOD_NATIVE(getNextWeather);
			MOD_NATIVE(getWeatherTransition);
			MOD_NATIVE(clearWeatherPersist);
			MOD_NATIVE(clearOverrideWeather);
			
			AMX_NATIVE_INFO list[];
		};
	};
};
