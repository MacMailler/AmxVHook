#if defined __vehicle_inc__
  #endinput
#endif
#define __vehicle_inc__

native createVehicle(modelHash, Float:coords[@Vector3], Float:heading);
native deleteVehicle(vehicle);

native isVehicleModel(vehicle, modelHash);
native isVehicleStopped(vehicle);
native isVehicleTaxiLightsOn(vehicle);
native isVehicleStuckOnRoof(vehicle);

native setVehicleColor(vehicle, color1, color2);
native setVehicleDoorsLocked(vehicle, bool:locked);
native setVehicleTaxiLights(vehicle, bool:toggle);

native getVehiclePassengers(vehicle);
native getVehicleMaxPassengers(vehicle);
native getVehicleModelNumberOfSeats(modelHash);
native getDisplayNameFromVehicleModel(modelHash, name[], len = sizeof name);