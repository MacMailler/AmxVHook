#include "checkpoint.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Checkpoint {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createCP)
				MOD_DEFINE_NATIVE(setCPScale)
				MOD_DEFINE_NATIVE(setCPCylinderHeight)
				MOD_DEFINE_NATIVE(setCPColor)
				MOD_DEFINE_NATIVE(setCPIconColor)
				MOD_DEFINE_NATIVE(deleteCP)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createCP) {
				if (!arguments(6))
					return 0;

				float coords[3], next[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[3], next, 3))
					return 0;

				Utility::Color color(params[5]);

				return GRAPHICS::CREATE_CHECKPOINT(
					params[1],
					coords[0], coords[1], coords[2],
					next[0], next[1], next[2],
					amx_ctof(params[4]),
					color.R, color.G, color.B, color.A, params[6]
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
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				GRAPHICS::SET_CHECKPOINT_RGBA(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setCPIconColor) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				GRAPHICS::_SET_CHECKPOINT_ICON_RGBA(params[1], color.R, color.G, color.B, color.A);
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