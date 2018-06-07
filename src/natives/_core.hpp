#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Core {
			AMX_NATIVE(log);
			AMX_NATIVE(getVersion);
			AMX_NATIVE(getPoolSize);
			AMX_NATIVE(getTickCount);
			AMX_NATIVE(setVersionVisible);
			AMX_NATIVE(getAllPeds);
			AMX_NATIVE(getAllObjects);
			AMX_NATIVE(getAllPickups);
			AMX_NATIVE(getAllVehicles);

			AMX_NATIVE_INFO list[];
		};
	};
};