#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Vehicle {
			AMX_NATIVE(createVehicle);
			AMX_NATIVE(deleteVehicle);
			AMX_NATIVE(isVehicleModel);
			AMX_NATIVE(isVehicleStopped);
			AMX_NATIVE(isVehicleTaxiLightsOn);
			AMX_NATIVE(isVehicleStuckOnRoof);
			AMX_NATIVE(setVehicleColor);
			AMX_NATIVE(setVehicleDoorsLocked);
			AMX_NATIVE(setVehicleTaxiLights);
			AMX_NATIVE(getVehiclePassengers);
			AMX_NATIVE(getVehicleMaxPassengers);
			AMX_NATIVE(getVehicleModelNumberOfSeats);
			AMX_NATIVE(getDisplayNameFromVehicleModel);
			
			AMX_NATIVE_INFO list[];
		};
	};
};
