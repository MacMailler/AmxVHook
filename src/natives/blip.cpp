#include "blip.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Blip {

			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(addBlip)
				AMX_DEFINE_NATIVE(setBlipPos)
				AMX_DEFINE_NATIVE(getBlipPos)
				AMX_DEFINE_NATIVE(setBlipSprite)
				AMX_DEFINE_NATIVE(getBlipSprite)
				AMX_DEFINE_NATIVE(setBlipAlpha)
				AMX_DEFINE_NATIVE(setBlipFade)
				AMX_DEFINE_NATIVE(setBlipColor)
				AMX_DEFINE_NATIVE(getBlipColor)
				AMX_DEFINE_NATIVE(setBlipScale)
				AMX_DEFINE_NATIVE(setBlipCategory)
				AMX_DEFINE_NATIVE(isBlipExist)
				AMX_DEFINE_NATIVE(isBlipFlashing)
				AMX_DEFINE_NATIVE(isBlipOnMinimap)
				AMX_DEFINE_NATIVE(removeBlip)
				AMX_DEFINE_NATIVE(setBlipRoute)
				AMX_DEFINE_NATIVE(setBlipRouteColor)
				AMX_DEFINE_NATIVE(setBlipRotation)
				AMX_DEFINE_NATIVE(setBlipFlashTimer)
				AMX_DEFINE_NATIVE(setBlipFlashes)
				AMX_DEFINE_NATIVE(setBlipFlashesAlternate)
				AMX_DEFINE_NATIVE(setBlipPriority)
				
				{NULL, NULL} // terminator
			};
			
			AMX_NATIVE(addBlip) {
				if (!arguments(3))
					return 0;

				return ::UI::ADD_BLIP_FOR_COORD(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
			}

			AMX_NATIVE(setBlipPos) {
				if (!arguments(4))
					return 0;

				::UI::SET_BLIP_COORDS(params[1], amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			AMX_NATIVE(getBlipPos) {
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

			AMX_NATIVE(setBlipSprite) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SPRITE(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(getBlipSprite) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_SPRITE(params[1]);
			}

			AMX_NATIVE(setBlipAlpha) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ALPHA(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(getBlipAlpha) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_ALPHA(params[1]);
			}

			AMX_NATIVE(setBlipFade) {
				if (!arguments(3))
					return 0;

				::UI::SET_BLIP_FADE(params[1], params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(setBlipRotation) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROTATION(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipColor) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_COLOUR(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(getBlipColor) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_COLOUR(params[1]);
			}

			AMX_NATIVE(setBlipScale) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SCALE(params[1], amx_ctof(params[2]));

				return 1;
			}

			AMX_NATIVE(setBlipCategory) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_CATEGORY(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipRoute) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROUTE(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipRouteColor) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROUTE_COLOUR(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipPriority) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_PRIORITY(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipFlashes) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASHES(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipFlashesAlternate) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASHES_ALTERNATE(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipFlashTimer) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASH_TIMER(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setBlipFlashInerval) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASH_INTERVAL(params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(isBlipExist) {
				if (!arguments(1))
					return 0;

				return ::UI::DOES_BLIP_EXIST((::Blip)params[1]);
			}

			AMX_NATIVE(isBlipFlashing) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_BLIP_FLASHING((::Blip)params[1]);
			}

			AMX_NATIVE(isBlipOnMinimap) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_BLIP_ON_MINIMAP((::Blip)params[1]);
			}

			AMX_NATIVE(removeBlip) {
				if (!arguments(1))
					return 0;
				::Blip blip = params[1];
				::UI::REMOVE_BLIP(&blip);

				return 1;
			}
		};
	};
};