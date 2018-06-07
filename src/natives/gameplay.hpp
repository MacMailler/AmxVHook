#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Gameplay {
			AMX_NATIVE(isMissionFlag);
			AMX_NATIVE(setWind);
			AMX_NATIVE(setWindSpeed);
			AMX_NATIVE(setWindDirection);
			AMX_NATIVE(getWindSpeed);
			AMX_NATIVE(getWindDirection);
			AMX_NATIVE(setRainIntensity);
			AMX_NATIVE(createLightningThunder);
			AMX_NATIVE(getGameTimer);
			AMX_NATIVE(getFrameTime);
			AMX_NATIVE(getFrameCount);
			AMX_NATIVE(getHashKey);
			AMX_NATIVE(getDistanceBetweenPos);
			AMX_NATIVE(setPoliceRadarBlips);
			AMX_NATIVE(setPoliceIgnorePlayer);
			AMX_NATIVE(setEveryoneIgnorePlayer);
			
			AMX_NATIVE_INFO list[];
		};
	};
};
