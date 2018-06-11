#include "checkpoint.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Checkpoint {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createCP)
				MOD_DEFINE_NATIVE(setCPScale)
				MOD_DEFINE_NATIVE(setCPCylinderHeight)
				MOD_DEFINE_NATIVE(setCPColor)
				MOD_DEFINE_NATIVE(deleteCP)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createCP) {
				if (!arguments(8))
					return 0;

				cell * addr1 = nullptr, * addr2 = nullptr;
				if ((amx_GetAddr(amx, params[2], &addr1) != AMX_ERR_NONE || addr1 == nullptr) ||
					(amx_GetAddr(amx, params[3], &addr2) != AMX_ERR_NONE || addr2 == nullptr))
					return 0;

				Vector3 vec1 = Funcs::cellArrayToVector3(addr1);
				Vector3 vec2 = Funcs::cellArrayToVector3(addr2);

				return GRAPHICS::CREATE_CHECKPOINT(
					params[1],
					vec1.x, vec1.y, vec1.z,
					vec2.x, vec2.y, vec2.z,
					amx_ctof(params[4]),
					params[5], params[6], params[7], params[8], 0
				);
			}

			MOD_NATIVE(setCPScale) {
				if (!arguments(2))
					return 0;

				GRAPHICS::_0x4B5B4DA5D79F1943(params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCPCylinderHeight) {
				if (!arguments(4))
					return 0;
				
				GRAPHICS::SET_CHECKPOINT_CYLINDER_HEIGHT(params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setCPColor) {
				if (!arguments(6))
					return 0;

				switch (params[6]) {
				case 1:
					GRAPHICS::_SET_CHECKPOINT_ICON_RGBA(params[1], params[2], params[3], params[4], params[5]);
					break;
				case 2:
					GRAPHICS::_SET_CHECKPOINT_ICON_RGBA(params[1], params[2], params[3], params[4], params[5]);
					GRAPHICS::SET_CHECKPOINT_RGBA(params[1], params[2], params[3], params[4], params[5]);
					break;
				default:
					GRAPHICS::SET_CHECKPOINT_RGBA(params[1], params[2], params[3], params[4], params[5]);
					break;
				}

				return 1;
			}

			MOD_NATIVE(deleteCP) {
				if (!arguments(1))
					return 0;
				
				GRAPHICS::DELETE_CHECKPOINT(params[1]);

				return 1;
			}
		};
	};
};