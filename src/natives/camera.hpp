#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Camera {
			AMX_NATIVE(getRenderingCam);
			AMX_NATIVE(setCamFov);

			AMX_NATIVE_INFO list[];
		};
	};
};