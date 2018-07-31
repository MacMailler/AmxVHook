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
				if (!arguments(1))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				return ::UI::ADD_BLIP_FOR_COORD(coords[0], coords[1], coords[2]);
			}

			MOD_NATIVE(addBlipForRadius) {
				if (!arguments(2))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				return ::UI::ADD_BLIP_FOR_RADIUS(coords[0], coords[1], coords[2], amx_ctof(params[2]));
			}

			MOD_NATIVE(addBlipForEntity) {
				if (!arguments(1))
					return 0;

				return ::UI::ADD_BLIP_FOR_ENTITY((::Entity)params[1]);
			}

			MOD_NATIVE(addBlipForPickup) {
				if (!arguments(1))
					return 0;

				return ::UI::ADD_BLIP_FOR_PICKUP((::Pickup)params[1]);
			}

			MOD_NATIVE(setBlipPos) {
				if (!arguments(2))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3))
					return 0;

				::UI::SET_BLIP_COORDS((::Blip)params[1], coords[0], coords[1], coords[2]);

				return 1;
			}

			MOD_NATIVE(getBlipPos) {
				if (!arguments(2))
					return 0;

				cell * addr = Utility::getAddrFromParam(amx, params[2]);

				if (addr == nullptr)
					return 0;

				Vector3 coords = ::UI::GET_BLIP_COORDS((::Blip)params[1]);

				return Utility::setVector3ToParam(amx, params[2], coords);
			}

			MOD_NATIVE(setBlipSprite) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SPRITE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipSprite) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_SPRITE((::Blip)params[1]);
			}

			MOD_NATIVE(setBlipAlpha) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ALPHA((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipAlpha) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_ALPHA((::Blip)params[1]);
			}

			MOD_NATIVE(setBlipFade) {
				if (!arguments(3))
					return 0;

				::UI::SET_BLIP_FADE((::Blip)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setBlipRotation) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROTATION((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipColor) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_COLOUR((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(getBlipColor) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_COLOUR((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipHudColour) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_HUD_COLOUR((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipInfoIdDisplay) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_INFO_ID_DISPLAY((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipInfoIdType) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_INFO_ID_TYPE((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipInfoIdPos) {
				if (!arguments(2))
					return 0;

				Vector3 coords = ::UI::GET_BLIP_INFO_ID_COORD((::Blip)params[1]);

				return Utility::setVector3ToParam(amx, params[2], coords);
			}

			MOD_NATIVE(getBlipInfoIdEntityIndex) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_INFO_ID_ENTITY_INDEX((::Blip)params[1]);
			}

			MOD_NATIVE(getBlipFromEntity) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_BLIP_FROM_ENTITY((::Blip)params[1]);
			}

			MOD_NATIVE(getNumberOfActiveBlips) {
				return ::UI::GET_NUMBER_OF_ACTIVE_BLIPS();
			}

			MOD_NATIVE(getNextBlipInfoId) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_NEXT_BLIP_INFO_ID((::Blip)params[1]);
			}

			MOD_NATIVE(getFirstBlipInfoId) {
				if (!arguments(1))
					return 0;

				return ::UI::GET_FIRST_BLIP_INFO_ID((::Blip)params[1]);
			}

			MOD_NATIVE(setBlipScale) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SCALE((::Blip)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setBlipCategory) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_CATEGORY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipRoute) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROUTE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipRouteColor) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_ROUTE_COLOUR((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipPriority) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_PRIORITY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashes) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASHES((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashesAlternate) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASHES_ALTERNATE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashTimer) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASH_TIMER((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipFlashInerval) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_FLASH_INTERVAL((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipDisplay) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_DISPLAY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipAsShortRange) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_AS_SHORT_RANGE((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipAsFriendly) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_AS_FRIENDLY((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipBright) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_BRIGHT((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setBlipShowCone) {
				if (!arguments(2))
					return 0;

				::UI::SET_BLIP_SHOW_CONE((::Blip)params[1], params[2]);

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
			
			MOD_NATIVE(isBlipShortRange) {
				if (!arguments(1))
					return 0;

				return ::UI::IS_BLIP_SHORT_RANGE((::Blip)params[1]);
			}

			MOD_NATIVE(removeBlip) {
				if (!arguments(1))
					return 0;
				::Blip blip = params[1];
				::UI::REMOVE_BLIP(&blip);

				return 1;
			}

			MOD_NATIVE(showTickOnBlip) {
				if (!arguments(2))
					return 0;

				::UI::_0x74513EA3E505181E((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(showNumberOnBlip) {
				if (!arguments(2))
					return 0;

				::UI::SHOW_NUMBER_ON_BLIP((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(hideNumberOnBlip) {
				if (!arguments(1))
					return 0;

				::UI::HIDE_NUMBER_ON_BLIP((::Blip)params[1]);

				return 1;
			}

			MOD_NATIVE(showHeadingIndicatorOnBlip) {
				if (!arguments(2))
					return 0;

				::UI::_SET_BLIP_SHOW_HEADING_INDICATOR((::Blip)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(pulseBlip) {
				if (!arguments(1))
					return 0;

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
				if (!arguments(2))
					return 0;

				::UI::SET_NEW_WAYPOINT(amx_ctof(params[1]), amx_ctof(params[2]));
				return 1;
			}
		};
	};
};