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
				if (!arguments(1))
					return 0;

				return GAMEPLAY::GET_HASH_KEY((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(getGameTimer) {
				return GAMEPLAY::GET_GAME_TIMER();
			}

			MOD_NATIVE(getFrameTime) {
				float time = GAMEPLAY::GET_FRAME_TIME();
				return amx_ftoc(time);
			}

			MOD_NATIVE(getFrameCount) {
				return GAMEPLAY::GET_FRAME_COUNT();
			}

			MOD_NATIVE(getRandomInt) {
				if (!arguments(2))
					return 0;

				return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(params[1], params[2]);
			}

			MOD_NATIVE(getRandomFloat) {
				if (!arguments(2))
					return 0;

				float value = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(amx_ctof(params[1]), amx_ctof(params[2]));

				return amx_ftoc(value);
			}

			MOD_NATIVE(getDistanceBetweenPos) {
				if (!arguments(3))
					return 0;

				float coords[3], coords2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], coords2, 3))
					return 0;

				float dist = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(
					coords[0], coords[1], coords[2],
					coords2[0], coords2[1], coords2[2],
					params[3]
				);

				return amx_ftoc(dist);
			}

			MOD_NATIVE(getAngleBetween2dVectors) {
				if (!arguments(2))
					return 0;

				float vec1[2], vec2[2];
				if (!Utility::getFloatArrayFromParam(amx, params[1], vec1, 2) ||
					!Utility::getFloatArrayFromParam(amx, params[2], vec2, 2))
					return 0;

				float dist = GAMEPLAY::GET_ANGLE_BETWEEN_2D_VECTORS(vec1[0], vec1[1], vec2[0], vec2[1]);

				return amx_ftoc(dist);
			}

			MOD_NATIVE(getHeadingFromVector2d) {
				if (!arguments(2))
					return 0;

				float dist = GAMEPLAY::GET_HEADING_FROM_VECTOR_2D(amx_ctof(params[1]), amx_ctof(params[2]));

				return amx_ftoc(dist);
			}

			MOD_NATIVE(world3DToScreen2D) {
				if (!arguments(3))
					return 0;

				float coords[3];
				cell * sx = Utility::getAddrFromParam(amx, params[2]),
					 * sy = Utility::getAddrFromParam(amx, params[3]);

				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					sx == nullptr || sy == nullptr)
					return 0;

				float sx2, sy2;
				BOOL ret = GRAPHICS::_WORLD3D_TO_SCREEN2D(coords[0], coords[1], coords[2], &sx2, &sy2);

				*sx = amx_ftoc(sx2);
				*sy = amx_ftoc(sy2);

				return ret;
			}
		};
	};
};