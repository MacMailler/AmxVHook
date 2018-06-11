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
			MOD_NATIVE(getDistanceBetweenPos);
			MOD_NATIVE(setPoliceRadarBlips);
			MOD_NATIVE(setPoliceIgnorePlayer);
			MOD_NATIVE(setEveryoneIgnorePlayer);
			
			AMX_NATIVE_INFO list[];
		};
	};
};
