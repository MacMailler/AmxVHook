#include "checkpoint.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Checkpoint {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createCheckpoint)
				MOD_DEFINE_NATIVE(setCheckpointScale)
				MOD_DEFINE_NATIVE(setCheckpointCylinderHeight)
				MOD_DEFINE_NATIVE(setCheckpointColor)
				MOD_DEFINE_NATIVE(setCheckpointIconColor)
				MOD_DEFINE_NATIVE(deleteCheckpoint)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createCheckpoint) {
				checkargs(6);

				cell *coords, *next;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &next) != AMX_ERR_NONE)
					return 0;
					
				Color color(params[5]);

				return GRAPHICS::CREATE_CHECKPOINT(
					params[1],
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					amx_ctof(next[0]), amx_ctof(next[1]), amx_ctof(next[2]),
					amx_ctof(params[4]),
					color.R, color.G, color.B, color.A,
					params[6]
				);
			}

			MOD_NATIVE(setCheckpointScale) {
				checkargs(2);

				GRAPHICS::_0x4B5B4DA5D79F1943(params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCheckpointCylinderHeight) {
				checkargs(4);
				
				GRAPHICS::SET_CHECKPOINT_CYLINDER_HEIGHT(params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setCheckpointColor) {
				checkargs(2);

				Color color(params[2]);
				GRAPHICS::SET_CHECKPOINT_RGBA(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setCheckpointIconColor) {
				checkargs(2);

				Color color(params[2]);
				GRAPHICS::_SET_CHECKPOINT_ICON_RGBA(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(deleteCheckpoint) {
				checkargs(1);
				
				GRAPHICS::DELETE_CHECKPOINT(params[1]);

				return 1;
			}
		};
	};
};