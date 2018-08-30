#include "misc.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Misc {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(getHashKey)
				MOD_DEFINE_NATIVE(getGameTimer)
				MOD_DEFINE_NATIVE(getFrameTime)
				MOD_DEFINE_NATIVE(getFrameCount)
				MOD_DEFINE_NATIVE(getRandomInt)
				MOD_DEFINE_NATIVE(getRandomFloat)
				MOD_DEFINE_NATIVE(getDistanceBetweenPos)
				MOD_DEFINE_NATIVE(getAngleBetween2dVectors)
				MOD_DEFINE_NATIVE(getHeadingFromVector2d)
				MOD_DEFINE_NATIVE(world3DToScreen2D)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(getHashKey) {
				checkargs(1);

				return GAMEPLAY::GET_HASH_KEY((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(getGameTimer) {
				return GAMEPLAY::GET_GAME_TIMER();
			}

			MOD_NATIVE(getFrameTime) {
				double time = GAMEPLAY::GET_FRAME_TIME();

				return amx_ftoc(time);
			}

			MOD_NATIVE(getFrameCount) {
				return GAMEPLAY::GET_FRAME_COUNT();
			}

			MOD_NATIVE(getRandomInt) {
				checkargs(2);

				return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(params[1], params[2]);
			}

			MOD_NATIVE(getRandomFloat) {
				checkargs(2);

				double value = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(amx_ctof(params[1]), amx_ctof(params[2]));

				return amx_ftoc(value);
			}

			MOD_NATIVE(getDistanceBetweenPos) {
				checkargs(3);

				cell *coords1, *coords2;
				if (amx_GetAddr(amx, params[1], &coords1) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &coords2) != AMX_ERR_NONE)
					return 0;

				double dist = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(
					amx_ctof(coords1[0]), amx_ctof(coords1[1]), amx_ctof(coords1[1]),
					amx_ctof(coords2[0]), amx_ctof(coords2[1]), amx_ctof(coords2[1]),
					params[3]
				);

				return amx_ftoc(dist);
			}

			MOD_NATIVE(getAngleBetween2dVectors) {
				checkargs(2);

				cell *vec1, *vec2;
				if (amx_GetAddr(amx, params[1], &vec1) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &vec2) != AMX_ERR_NONE)
					return 0;

				double dist = GAMEPLAY::GET_ANGLE_BETWEEN_2D_VECTORS(
					amx_ctof(vec1[0]), amx_ctof(vec1[1]),
					amx_ctof(vec2[0]), amx_ctof(vec2[1])
				);

				return amx_ftoc(dist);
			}

			MOD_NATIVE(getHeadingFromVector2d) {
				checkargs(2);

				double dist = GAMEPLAY::GET_HEADING_FROM_VECTOR_2D(amx_ctof(params[1]), amx_ctof(params[2]));

				return amx_ftoc(dist);
			}

			MOD_NATIVE(world3DToScreen2D) {
				checkargs(3);

				cell *sx, *sy, *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &sx) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &sy) != AMX_ERR_NONE)
					return 0;

				float sx2, sy2;
				BOOL ret = GRAPHICS::_WORLD3D_TO_SCREEN2D(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), &sx2, &sy2);
				
				double sx3 = static_cast<double>(sx2);
				double sy3 = static_cast<double>(sy2);

				*sx = amx_ftoc(sx3);
				*sy = amx_ftoc(sy3);

				return ret;
			}
		};
	};
};