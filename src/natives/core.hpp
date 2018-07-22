#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Core {
			MOD_NATIVE(log);
			MOD_NATIVE(logf);
			MOD_NATIVE(wait);
			MOD_NATIVE(format);
			MOD_NATIVE(isModLoaded);
			MOD_NATIVE(getFps);
			MOD_NATIVE(getVersion);
			MOD_NATIVE(getPoolSize);
			MOD_NATIVE(getTickCount);
			MOD_NATIVE(setVersionVisible);
			MOD_NATIVE(getAllPeds);
			MOD_NATIVE(getAllObjects);
			MOD_NATIVE(getAllPickups);
			MOD_NATIVE(getAllVehicles);
			MOD_NATIVE(callFunc);
			MOD_NATIVE(addTimer);
			MOD_NATIVE(dropTimer);
			MOD_NATIVE(stopTimer);
			MOD_NATIVE(isTimerExist);
			MOD_NATIVE(isTimerStopped);
			MOD_NATIVE(setTimerData);
			MOD_NATIVE(setTimerInterval);

			AMX_NATIVE_INFO list[];
		};
	};
};