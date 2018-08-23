#include "blip.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Blip {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(addBlip)
				MOD_DEFINE_NATIVE(addBlipForRadius)
				MOD_DEFINE_NATIVE(addBlipForEntity)
				MOD_DEFINE_NATIVE(addBlipForPickup)
				MOD_DEFINE_NATIVE(removeBlip)
				MOD_DEFINE_NATIVE(isBlipExist)
				MOD_DEFINE_NATIVE(isBlipFlashing)
				MOD_DEFINE_NATIVE(isBlipOnMinimap)
				MOD_DEFINE_NATIVE(isBlipShortRange)
				MOD_DEFINE_NATIVE(setBlipPos)
				MOD_DEFINE_NATIVE(setBlipAlpha)
				MOD_DEFINE_NATIVE(setBlipFade)
				MOD_DEFINE_NATIVE(setBlipSprite)
				MOD_DEFINE_NATIVE(setBlipColor)
				MOD_DEFINE_NATIVE(setBlipSecondaryColor)
				MOD_DEFINE_NATIVE(setBlipScale)
				MOD_DEFINE_NATIVE(setBlipCategory)
				MOD_DEFINE_NATIVE(setBlipRoute)
				MOD_DEFINE_NATIVE(setBlipRouteColor)
				MOD_DEFINE_NATIVE(setBlipRotation)
				MOD_DEFINE_NATIVE(setBlipFlashTimer)
				MOD_DEFINE_NATIVE(setBlipFlashes)
				MOD_DEFINE_NATIVE(setBlipFlashesAlternate)
				MOD_DEFINE_NATIVE(setBlipPriority)
				MOD_DEFINE_NATIVE(setBlipDisplay)
				MOD_DEFINE_NATIVE(setBlipAsShortRange)
				MOD_DEFINE_NATIVE(setBlipAsFriendly)
				MOD_DEFINE_NATIVE(setBlipBright)
				MOD_DEFINE_NATIVE(setBlipShowCone)
				MOD_DEFINE_NATIVE(getBlipPos)
				MOD_DEFINE_NATIVE(getBlipSprite)
				MOD_DEFINE_NATIVE(getBlipColor)
				MOD_DEFINE_NATIVE(getBlipHudColour)
				MOD_DEFINE_NATIVE(getBlipInfoIdDisplay)
				MOD_DEFINE_NATIVE(getBlipInfoIdType)
				MOD_DEFINE_NATIVE(getBlipInfoIdPos)
				MOD_DEFINE_NATIVE(getBlipInfoIdEntityIndex)
				MOD_DEFINE_NATIVE(getBlipFromEntity)
				MOD_DEFINE_NATIVE(getNumberOfActiveBlips)
				MOD_DEFINE_NATIVE(getNextBlipInfoId)
				MOD_DEFINE_NATIVE(getFirstBlipInfoId)
				MOD_DEFINE_NATIVE(showTickOnBlip)
				MOD_DEFINE_NATIVE(showNumberOnBlip)
				MOD_DEFINE_NATIVE(hideNumberOnBlip)
				MOD_DEFINE_NATIVE(showHeadingIndicatorOnBlip)
				MOD_DEFINE_NATIVE(pulseBlip)
				MOD_DEFINE_NATIVE(isWaypointActive)
				MOD_DEFINE_NATIVE(setWaypointOff)
				MOD_DEFINE_NATIVE(refreshWaypoint)
				MOD_DEFINE_NATIVE(setNewWaypoint)
				
				{NULL, NULL} // terminator
			};
			
			MOD_NATIVE(addBlip) {
				checkargs(1);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				return ::UI::ADD_BLIP_FOR_COORD(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]));
			}

			MOD_NATIVE(addBlipForRadius) {
				checkargs(2);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				return ::UI::ADD_BLIP_FOR_RADIUS(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), amx_ctof(params[2]));
			}

			MOD_NATIVE(addBlipForEntity) {
				checkargs(1);

				return ::UI::ADD_BLIP_FOR_ENTITY((::Entity)params[1]);
			}

			MOD_NATIVE(addBlipForPickup) {
				checkargs(1);

				return ::UI::ADD_BLIP_FOR_PICKUP((::Pickup)params[1]);
			}

			MOD_NATIVE(setBlipPos) {
				checkargs(2);

				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				::UI::SET_BLIP_COORDS((::Blip)params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]));

				return 1;
			}

			MOD_NATIVE(getBlipPos) {
				checkargs(2);
				
				Vector3 coords = ::UI::GET_BLIP_COORDS((::Blip)params[1]);

				return Aux::setVector3(amx, params[2], coords);
			}

			MOD_NATIVE(setBlipSprite) {
				checkargs(2);

				::UI::SET_BLIP_SPRITE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipSprite) {
				checkargs(1);

				return ::UI::GET_BLIP_SPRITE((::Blip)params[1]);
			}

			MOD_NATIVE(setBlipAlpha) {
				checkargs(2);

				::UI::SET_BLIP_ALPHA((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipAlpha) {
				checkargs(1);

				return ::UI::GET_BLIP_ALPHA((::Blip)params[1]);
			}

			MOD_NATIVE(setBlipFade) {
				checkargs(3);

				::UI::SET_BLIP_FADE((::Blip)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setBlipRotation) {
				checkargs(2);

				::UI::SET_BLIP_ROTATION((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipColor) {
				checkargs(2);

				::UI::SET_BLIP_COLOUR((::Blip)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setBlipSecondaryColor) {
				checkargs(2);

				Color color(params[2]);
				::UI::SET_BLIP_SECONDARY_COLOUR((::Blip)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(getBlipColor) {
				checkargs(1);

				return ::UI::GET_BLIP_COLOUR((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipHudColour) {
				checkargs(1);

				return ::UI::GET_BLIP_HUD_COLOUR((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipInfoIdDisplay) {
				checkargs(1);

				return ::UI::GET_BLIP_INFO_ID_DISPLAY((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipInfoIdType) {
				checkargs(1);

				return ::UI::GET_BLIP_INFO_ID_TYPE((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipInfoIdPos) {
				checkargs(2);

				Vector3 coords = ::UI::GET_BLIP_INFO_ID_COORD((::Blip)params[1]);

				return Aux::setVector3(amx, params[2], coords);
			}

			MOD_NATIVE(getBlipInfoIdEntityIndex) {
				checkargs(1);

				return ::UI::GET_BLIP_INFO_ID_ENTITY_INDEX((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipFromEntity) {
				checkargs(1);

				return ::UI::GET_BLIP_FROM_ENTITY((::Blip)params[1]);
			}

			MOD_NATIVE(getNumberOfActiveBlips) {
				return ::UI::GET_NUMBER_OF_ACTIVE_BLIPS();
			}

			MOD_NATIVE(getNextBlipInfoId) {
				checkargs(1);

				return ::UI::GET_NEXT_BLIP_INFO_ID((::Blip)params[1]);
			}

			MOD_NATIVE(getFirstBlipInfoId) {
				checkargs(1);

				return ::UI::GET_FIRST_BLIP_INFO_ID((::Blip)params[1]);
			}

			MOD_NATIVE(setBlipScale) {
				checkargs(2);

				::UI::SET_BLIP_SCALE((::Blip)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setBlipCategory) {
				checkargs(2);

				::UI::SET_BLIP_CATEGORY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipRoute) {
				checkargs(2);

				::UI::SET_BLIP_ROUTE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipRouteColor) {
				checkargs(2);

				::UI::SET_BLIP_ROUTE_COLOUR((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipPriority) {
				checkargs(2);

				::UI::SET_BLIP_PRIORITY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashes) {
				checkargs(2);

				::UI::SET_BLIP_FLASHES((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashesAlternate) {
				checkargs(2);

				::UI::SET_BLIP_FLASHES_ALTERNATE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashTimer) {
				checkargs(2);

				::UI::SET_BLIP_FLASH_TIMER((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashInerval) {
				checkargs(2);

				::UI::SET_BLIP_FLASH_INTERVAL((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipDisplay) {
				checkargs(2);

				::UI::SET_BLIP_DISPLAY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipAsShortRange) {
				checkargs(2);

				::UI::SET_BLIP_AS_SHORT_RANGE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipAsFriendly) {
				checkargs(2);

				::UI::SET_BLIP_AS_FRIENDLY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipBright) {
				checkargs(2);

				::UI::SET_BLIP_BRIGHT((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipShowCone) {
				checkargs(2);

				::UI::SET_BLIP_SHOW_CONE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(isBlipExist) {
				checkargs(1);

				return ::UI::DOES_BLIP_EXIST((::Blip)params[1]);
			}

			MOD_NATIVE(isBlipFlashing) {
				checkargs(1);

				return ::UI::IS_BLIP_FLASHING((::Blip)params[1]);
			}

			MOD_NATIVE(isBlipOnMinimap) {
				checkargs(1);

				return ::UI::IS_BLIP_ON_MINIMAP((::Blip)params[1]);
			}
			
			MOD_NATIVE(isBlipShortRange) {
				checkargs(1);

				return ::UI::IS_BLIP_SHORT_RANGE((::Blip)params[1]);
			}

			MOD_NATIVE(removeBlip) {
				checkargs(1);
				::Blip blip = params[1];
				::UI::REMOVE_BLIP(&blip);

				return 1;
			}

			MOD_NATIVE(showTickOnBlip) {
				checkargs(2);

				::UI::_0x74513EA3E505181E((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(showNumberOnBlip) {
				checkargs(2);

				::UI::SHOW_NUMBER_ON_BLIP((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(hideNumberOnBlip) {
				checkargs(1);

				::UI::HIDE_NUMBER_ON_BLIP((::Blip)params[1]);

				return 1;
			}

			MOD_NATIVE(showHeadingIndicatorOnBlip) {
				checkargs(2);

				::UI::_SET_BLIP_SHOW_HEADING_INDICATOR((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(pulseBlip) {
				checkargs(1);

				::UI::PULSE_BLIP((::Blip)params[1]);

				return 1;
			}

			MOD_NATIVE(isWaypointActive) {
				return ::UI::IS_WAYPOINT_ACTIVE();
			}

			MOD_NATIVE(setWaypointOff) {
				::UI::SET_WAYPOINT_OFF();

				return 1;
			}

			MOD_NATIVE(refreshWaypoint) {
				::UI::REFRESH_WAYPOINT();

				return 1;
			}
			MOD_NATIVE(setNewWaypoint) {
				checkargs(2);

				::UI::SET_NEW_WAYPOINT(amx_ctof(params[1]), amx_ctof(params[2]));
				return 1;
			}
		};
	};
};