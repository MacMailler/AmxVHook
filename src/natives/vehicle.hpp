#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Vehicle {
			MOD_NATIVE(createVehicle);
			MOD_NATIVE(deleteVehicle);
			MOD_NATIVE(isVehicleModel);
			MOD_NATIVE(isVehicleStopped);
			MOD_NATIVE(isVehicleTaxiLightsOn);
			MOD_NATIVE(isVehicleStuckOnRoof);
			MOD_NATIVE(setVehicleColor);
			MOD_NATIVE(setVehicleDoorsLocked);
			MOD_NATIVE(setVehicleTaxiLights);
			MOD_NATIVE(getVehiclePassengers);
			MOD_NATIVE(getVehicleMaxPassengers);
			MOD_NATIVE(getVehicleModelNumberOfSeats);
			MOD_NATIVE(getDisplayNameFromVehicleModel);
			
			AMX_NATIVE_INFO list[];
		};
	};
};
