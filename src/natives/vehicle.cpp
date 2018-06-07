#include "vehicle.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Vehicle {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(createVehicle)
				AMX_DEFINE_NATIVE(deleteVehicle)
				AMX_DEFINE_NATIVE(isVehicleModel)
				AMX_DEFINE_NATIVE(isVehicleStopped)
				AMX_DEFINE_NATIVE(isVehicleTaxiLightsOn)
				AMX_DEFINE_NATIVE(isVehicleStuckOnRoof)
				AMX_DEFINE_NATIVE(setVehicleColor)
				AMX_DEFINE_NATIVE(setVehicleDoorsLocked)
				AMX_DEFINE_NATIVE(setVehicleTaxiLights)
				AMX_DEFINE_NATIVE(getVehiclePassengers)
				AMX_DEFINE_NATIVE(getVehicleMaxPassengers)
				AMX_DEFINE_NATIVE(getVehicleModelNumberOfSeats)
				AMX_DEFINE_NATIVE(getDisplayNameFromVehicleModel)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(createVehicle) {
				if (!arguments(3))
					return -1;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[2], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				Vector3 vec = Funcs::cellArrayToVector3(addr);
				::Vehicle vehicle = -1;
				if (STREAMING::IS_MODEL_IN_CDIMAGE((::Hash)params[1]) && STREAMING::IS_MODEL_A_VEHICLE((::Hash)params[1])) {
					STREAMING::REQUEST_MODEL((::Hash)params[1]);
					while (!STREAMING::HAS_MODEL_LOADED((::Hash)params[1])) WAIT(0);
					vehicle = VEHICLE::CREATE_VEHICLE(params[1], vec.x, vec.y, vec.z, amx_ctof(params[3]), FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((::Hash)params[1]);
				}
				return vehicle;
			}


			AMX_NATIVE(deleteVehicle) {
				if (!arguments(1))
					return 0;

				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(params[1], true, true);
				VEHICLE::DELETE_VEHICLE(&(::Vehicle)params[1]);

				return 1;
			}


			AMX_NATIVE(isVehicleModel) {
				if (!arguments(2))
					return 0;

				VEHICLE::IS_VEHICLE_MODEL((::Vehicle)params[1], (::Hash)params[2]);

				return 1;
			}
			
			AMX_NATIVE(isVehicleStopped) {
				if (!arguments(1))
					return 0;

				VEHICLE::IS_VEHICLE_STOPPED((::Vehicle)params[1]);

				return 1;
			}
			
			AMX_NATIVE(isVehicleTaxiLightsOn) {
				if (!arguments(1))
					return 0;

				VEHICLE::IS_TAXI_LIGHT_ON((::Vehicle)params[1]);

				return 1;
			}
			
			AMX_NATIVE(isVehicleStuckOnRoof) {
				if (!arguments(1))
					return 0;

				VEHICLE::IS_VEHICLE_STUCK_ON_ROOF((::Vehicle)params[1]);

				return 1;
			}
			
			AMX_NATIVE(setVehicleColor) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_COLOURS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}
			
			AMX_NATIVE(setVehicleDoorsLocked) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_DOORS_LOCKED((::Vehicle)params[1], (BOOL)params[2]);

				return 1;
			}
			
			AMX_NATIVE(setVehicleTaxiLights) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_TAXI_LIGHTS((::Vehicle)params[1], (BOOL)params[2]);

				return 1;
			}

			AMX_NATIVE(getVehiclePassengers) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_NUMBER_OF_PASSENGERS((::Vehicle)params[1]);
			}

			AMX_NATIVE(getVehicleMaxPassengers) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS((::Vehicle)params[1]);
			}
			
			AMX_NATIVE(getVehicleModelNumberOfSeats) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_GET_VEHICLE_MODEL_MAX_NUMBER_OF_PASSENGERS((::Hash)params[1]);
			}
			
			AMX_NATIVE(getDisplayNameFromVehicleModel) {
				if (!arguments(3))
					return 0;

				cell *dest = NULL;
				amx_GetAddr(amx, params[2], &dest);
				amx_SetString(dest, VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(params[1]), NULL, NULL, params[3]);

				return 1;
			}
		};
	};
};