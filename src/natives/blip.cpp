#include "blip.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Blip {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(addBlip)
				MOD_DEFINE_NATIVE(setBlipPos)
				MOD_DEFINE_NATIVE(getBlipPos)
				MOD_DEFINE_NATIVE(setBlipSprite)
				MOD_DEFINE_NATIVE(getBlipSprite)
				MOD_DEFINE_NATIVE(setBlipAlpha)
				MOD_DEFINE_NATIVE(setBlipFade)
				MOD_DEFINE_NATIVE(setBlipColor)
				MOD_DEFINE_NATIVE(getBlipColor)
				MOD_DEFINE_NATIVE(setBlipScale)
				MOD_DEFINE_NATIVE(setBlipCategory)
				MOD_DEFINE_NATIVE(isBlipExist)
				MOD_DEFINE_NATIVE(isBlipFlashing)
				MOD_DEFINE_NATIVE(isBlipOnMinimap)
				MOD_DEFINE_NATIVE(removeBlip)
				MOD_DEFINE_NATIVE(setBlipRoute)
				MOD_DEFINE_NATIVE(setBlipRouteColor)
				MOD_DEFINE_NATIVE(setBlipRotation)
				MOD_DEFINE_NATIVE(setBlipFlashTimer)
				MOD_DEFINE_NATIVE(setBlipFlashes)
				MOD_DEFINE_NATIVE(setBlipFlashesAlternate)
				MOD_DEFINE_NATIVE(setBlipPriority)
				
				{NULL, NULL} // terminator
			};
			
			MOD_NATIVE(addBlip) {
				if (!arguments(3))
					return 0;

				return ::UI::ADD_BLIP_FOR_COORD(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
			}

			MOD_NATIVE(setBlipPos) {
				if (!arguments(4))
					return 0;

				::UI::SET_BLIP_COORDS(params[1], amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(getBlipPos) {
				if (!arguments(4))
					return 0;

				cell *x = nullptr, *y = nullptr, *z = nullptr;

				if ((amx_GetAddr(amx, params[1], &x) != AMX_ERR_NONE || x == nullptr)
					|| (amx_GetAddr(amx, params[2], &y) != AMX_ERR_NONE || y == nullptr)
					|| (amx_GetAddr(amx, params[3], &z) != AMX_ERR_NONE || z == nullptr))
					return 0;

				Vector3 pos = ::UI::GET_BLIP_COORDS(params[1]);

				*x = amx_ftoc(pos.x);
				*y = amx_ftoc(pos.y);
				*z = amx_ftoc(pos.z);

				return 1;
			}

			MOD_NATIVE(setBlipSprite) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SPRITE(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipSprite) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_SPRITE(params[1]);
			}

			MOD_NATIVE(setBlipAlpha) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ALPHA(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipAlpha) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_ALPHA(params[1]);
			}

			MOD_NATIVE(setBlipFade) {
				if (!arguments(3))
					return 0;

				::UI::SET_BLIP_FADE(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setBlipRotation) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROTATION(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipColor) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_COLOUR(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipColor) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_COLOUR(params[1]);
			}

			MOD_NATIVE(setBlipScale) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SCALE(params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setBlipCategory) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_CATEGORY(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipRoute) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROUTE(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipRouteColor) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROUTE_COLOUR(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipPriority) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_PRIORITY(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashes) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASHES(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashesAlternate) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASHES_ALTERNATE(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashTimer) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASH_TIMER(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashInerval) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASH_INTERVAL(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(isBlipExist) {
				if (!arguments(1))
					return 0;

				return ::UI::DOES_BLIP_EXIST((::Blip)params[1]);
			}

			MOD_NATIVE(isBlipFlashing) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_BLIP_FLASHING((::Blip)params[1]);
			}

			MOD_NATIVE(isBlipOnMinimap) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_BLIP_ON_MINIMAP((::Blip)params[1]);
			}

			MOD_NATIVE(removeBlip) {
				if (!arguments(1))
					return 0;
				::Blip blip = params[1];
				::UI::REMOVE_BLIP(&blip);

				return 1;
			}
		};
	};
};