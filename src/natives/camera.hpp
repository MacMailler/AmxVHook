#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Camera {
			MOD_NATIVE(getRenderingCam);
			MOD_NATIVE(setCamFov);

			AMX_NATIVE_INFO list[];
		};
	};
};