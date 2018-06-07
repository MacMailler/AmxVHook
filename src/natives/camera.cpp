#include "camera.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Camera {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(getRenderingCam)
				AMX_DEFINE_NATIVE(setCamFov)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(getRenderingCam) {
				return CAM::GET_RENDERING_CAM();
			}

			AMX_NATIVE(setCamFov) {
				if (arguments(2))
					return 0;

				CAM::SET_CAM_FOV((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}
		};
	};
};