#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Core {
			MOD_NATIVE(log);
			MOD_NATIVE(logf);
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

			AMX_NATIVE_INFO list[];
		};
	};
};