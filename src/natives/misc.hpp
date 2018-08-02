#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Misc {
			MOD_NATIVE(getHashKey);
			MOD_NATIVE(getGameTimer);
			MOD_NATIVE(getFrameTime);
			MOD_NATIVE(getFrameCount);
			MOD_NATIVE(getRandomInt);
			MOD_NATIVE(getRandomFloat);
			MOD_NATIVE(getDistanceBetweenPos);
			MOD_NATIVE(getAngleBetween2dVectors);
			MOD_NATIVE(getHeadingFromVector2d);
			MOD_NATIVE(world3DToScreen2D);

			AMX_NATIVE_INFO list[];
		};
	};
};