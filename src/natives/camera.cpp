#include "camera.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Camera {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(getRenderingCam)
				MOD_DEFINE_NATIVE(setCamFov)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(getRenderingCam) {
				return CAM::GET_RENDERING_CAM();
			}

			MOD_NATIVE(setCamFov) {
				if (arguments(2))
					return 0;

				CAM::SET_CAM_FOV((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}
		};
	};
};