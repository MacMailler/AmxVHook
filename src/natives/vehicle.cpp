#include "vehicle.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Vehicle {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createVehicle)
				MOD_DEFINE_NATIVE(deleteVehicle)
				MOD_DEFINE_NATIVE(isVehicleModel)
				MOD_DEFINE_NATIVE(isVehicleStopped)
				MOD_DEFINE_NATIVE(isVehicleTaxiLightsOn)
				MOD_DEFINE_NATIVE(isVehicleStuckOnRoof)
				MOD_DEFINE_NATIVE(isVehicleStoppedAtTrafficLights)
				MOD_DEFINE_NATIVE(isVehicleDriveable)
				MOD_DEFINE_NATIVE(isVehicleWindowIntact)
				MOD_DEFINE_NATIVE(isVehicleAnyWindowIntact)
				MOD_DEFINE_NATIVE(isVehicleAnySeatsFree)
				MOD_DEFINE_NATIVE(isAnyVehicleNearPoint)
				MOD_DEFINE_NATIVE(isVehicleHighDetail)
				MOD_DEFINE_NATIVE(isVehicleAssetLoaded)
				MOD_DEFINE_NATIVE(isVehicleInBurnout)
				MOD_DEFINE_NATIVE(isVehicleSearchlightOn)
				MOD_DEFINE_NATIVE(isVehicleModLoadDone)
				MOD_DEFINE_NATIVE(isVehicleToggleModOn)
				MOD_DEFINE_NATIVE(isVehicleLeftHeadlightDamaged)
				MOD_DEFINE_NATIVE(isVehicleRightHeadlightDamaged)
				MOD_DEFINE_NATIVE(isVehicleEngineOn)
				MOD_DEFINE_NATIVE(isVehicleVisible)
				MOD_DEFINE_NATIVE(isVehicleShopResprayAllowed)
				MOD_DEFINE_NATIVE(isVehiclePropellersUndamaged)
				MOD_DEFINE_NATIVE(isVehicleStolen)
				MOD_DEFINE_NATIVE(isVehicleHaveWeapons)
				MOD_DEFINE_NATIVE(isVehicleNeonLightEnabled)
				MOD_DEFINE_NATIVE(isVehicleOnAllWheels)
				MOD_DEFINE_NATIVE(isVehicleAttachedToCargobob)
				MOD_DEFINE_NATIVE(isVehicleBumperBrokenOff)
				MOD_DEFINE_NATIVE(isVehicleDoorDamaged)
				MOD_DEFINE_NATIVE(isVehicleBig)
				MOD_DEFINE_NATIVE(isVehicleHaveRoof)
				MOD_DEFINE_NATIVE(isVehicleDoorFullyOpen)
				MOD_DEFINE_NATIVE(isVehicleDamaged)
				MOD_DEFINE_NATIVE(isVehicleModelAboat)
				MOD_DEFINE_NATIVE(isVehicleModelASubmersible)
				MOD_DEFINE_NATIVE(isVehicleModelAPlane)
				MOD_DEFINE_NATIVE(isVehicleModelAHeli)
				MOD_DEFINE_NATIVE(isVehicleModelACar)
				MOD_DEFINE_NATIVE(isVehicleModelATrain)
				MOD_DEFINE_NATIVE(isVehicleModelABike)
				MOD_DEFINE_NATIVE(isVehicleModelABicycle)
				MOD_DEFINE_NATIVE(isVehicleModelAQuadbike)
				MOD_DEFINE_NATIVE(isVehicleAlarmActivated)
				MOD_DEFINE_NATIVE(isVehicleTyresCanBurst)
				MOD_DEFINE_NATIVE(isVehicleSeatFree)
				MOD_DEFINE_NATIVE(isVehicleSirenOn)
				MOD_DEFINE_NATIVE(isVehicleSirenSoundOn)
				MOD_DEFINE_NATIVE(isVehicleBoatAnchor)
				MOD_DEFINE_NATIVE(isVehiclePrimaryColorCustom)
				MOD_DEFINE_NATIVE(isVehicleSecondaryColorCustom)
				MOD_DEFINE_NATIVE(isVehicleInGarageArea)
				MOD_DEFINE_NATIVE(isVehicleDoorsLockedForPlayer)
				MOD_DEFINE_NATIVE(isCargobobHookActive)
				MOD_DEFINE_NATIVE(isCargobobMagnetActive)
				MOD_DEFINE_NATIVE(isCopVehicleInArea3d)
				MOD_DEFINE_NATIVE(isPreloadModsFinished)
				MOD_DEFINE_NATIVE(setVehicleColor)
				MOD_DEFINE_NATIVE(setVehicleDoorsLocked)
				MOD_DEFINE_NATIVE(setVehicleTaxiLights)
				MOD_DEFINE_NATIVE(setVehicleFixed)
				MOD_DEFINE_NATIVE(setVehicleDeformationFixed)
				MOD_DEFINE_NATIVE(setVehicleDamage)
				MOD_DEFINE_NATIVE(setVehicleBodyHealth)
				MOD_DEFINE_NATIVE(setVehicleEngineHealth)
				MOD_DEFINE_NATIVE(setVehiclePetrolTankHealth)
				MOD_DEFINE_NATIVE(setVehicleLivery)
				MOD_DEFINE_NATIVE(setVehicleIndicatorLights)
				MOD_DEFINE_NATIVE(setVehicleCanBreak)
				MOD_DEFINE_NATIVE(setVehicleBrakeLights)
				MOD_DEFINE_NATIVE(setVehicleHandbrake)
				MOD_DEFINE_NATIVE(setVehicleResistantToExp)
				MOD_DEFINE_NATIVE(setVehicleBurnout)
				MOD_DEFINE_NATIVE(setVehicleRudderBroken)
				MOD_DEFINE_NATIVE(setVehicleSearchlight)
				MOD_DEFINE_NATIVE(setVehicleModKit)
				MOD_DEFINE_NATIVE(setVehicleWheelType)
				MOD_DEFINE_NATIVE(setVehicleModColor)
				MOD_DEFINE_NATIVE(setVehicleMod)
				MOD_DEFINE_NATIVE(setVehicleTyreSmokeColor)
				MOD_DEFINE_NATIVE(setVehicleNeonLightsColor)
				MOD_DEFINE_NATIVE(setVehicleWindowTint)
				MOD_DEFINE_NATIVE(setVehicleEnginePowerMult)
				MOD_DEFINE_NATIVE(setVehicleEngineTorqueMult)
				MOD_DEFINE_NATIVE(setVehicleIsWanted)
				MOD_DEFINE_NATIVE(setVehicleShootAtTarget)
				MOD_DEFINE_NATIVE(setVehicleLodMult)
				MOD_DEFINE_NATIVE(setVehicleLightMult)
				MOD_DEFINE_NATIVE(setVehicleLights)
				MOD_DEFINE_NATIVE(setVehicleLightsMode)
				MOD_DEFINE_NATIVE(setVehicleStrong)
				MOD_DEFINE_NATIVE(setVehicleSiren)
				MOD_DEFINE_NATIVE(setVehicleBoatAnchor)
				MOD_DEFINE_NATIVE(setVehicleForceHd)
				MOD_DEFINE_NATIVE(setVehicleGravity)
				MOD_DEFINE_NATIVE(setVehicleInteriorLight)
				MOD_DEFINE_NATIVE(setVehicleEngineCanDegrade)
				MOD_DEFINE_NATIVE(setVehicleStolen)
				MOD_DEFINE_NATIVE(setVehicleJetEngineOn)
				MOD_DEFINE_NATIVE(setVehicleAlarm)
				MOD_DEFINE_NATIVE(setVehicleCanBeUsedFleeingPeds)
				MOD_DEFINE_NATIVE(setVehicleNeonLightEnabled)
				MOD_DEFINE_NATIVE(setVehicleColorCombination)
				MOD_DEFINE_NATIVE(setVehicleExtraColors)
				MOD_DEFINE_NATIVE(setVehicleDoorCanBreak)
				MOD_DEFINE_NATIVE(setVehicleDoorShut)
				MOD_DEFINE_NATIVE(setVehicleDoorBroken)
				MOD_DEFINE_NATIVE(setVehicleDoorLatched)
				MOD_DEFINE_NATIVE(setVehicleDoorControl)
				MOD_DEFINE_NATIVE(setVehicleDoorOpen)
				MOD_DEFINE_NATIVE(setVehicleDoorsShut)
				MOD_DEFINE_NATIVE(setVehicleWheelsCanBreak)
				MOD_DEFINE_NATIVE(setVehicleTyresCanBurst)
				MOD_DEFINE_NATIVE(setVehicleTyreBurst)
				MOD_DEFINE_NATIVE(setVehicleUndriveable)
				MOD_DEFINE_NATIVE(setVehicleProvidesCover)
				MOD_DEFINE_NATIVE(setVehicleDoorsLockedForPlayer)
				MOD_DEFINE_NATIVE(setVehicleEngineOn)
				MOD_DEFINE_NATIVE(setVehicleDirtLevel)
				MOD_DEFINE_NATIVE(setVehicleCanBeVisiblyDamaged)
				MOD_DEFINE_NATIVE(setVehicleCanBeTargetted)
				MOD_DEFINE_NATIVE(setVehicleModelSuppressed)
				MOD_DEFINE_NATIVE(setVehicleNumberPlateText)
				MOD_DEFINE_NATIVE(setVehicleNumberPlateTextIndex)
				MOD_DEFINE_NATIVE(setVehicleTyreFixed)
				MOD_DEFINE_NATIVE(setVehicleForwardSpeed)
				MOD_DEFINE_NATIVE(setVehicleHalt)
				MOD_DEFINE_NATIVE(setVehicleCustomPrimaryColor)
				MOD_DEFINE_NATIVE(setVehicleCustomSecondaryColor)
				MOD_DEFINE_NATIVE(setBikeLeanAngle)
				MOD_DEFINE_NATIVE(setPlaneMinHeightAboveTerrain)
				MOD_DEFINE_NATIVE(setCargobobHookPos)
				MOD_DEFINE_NATIVE(setCargobobMagnetActive)
				MOD_DEFINE_NATIVE(setCargobobMagnetStrength)
				MOD_DEFINE_NATIVE(setHeliBladesSpeed)
				MOD_DEFINE_NATIVE(getVehiclePassengers)
				MOD_DEFINE_NATIVE(getVehicleMaxPassengers)
				MOD_DEFINE_NATIVE(getVehicleModelNumberOfSeats)
				MOD_DEFINE_NATIVE(getDisplayNameFromVehicleModel)
				MOD_DEFINE_NATIVE(getClosestVehicle)
				MOD_DEFINE_NATIVE(getRandomVehicleInSphere)
				MOD_DEFINE_NATIVE(getVehiclePedInSeat)
				MOD_DEFINE_NATIVE(getVehicleLastPedInSeat)
				MOD_DEFINE_NATIVE(getVehicleLightsState)
				MOD_DEFINE_NATIVE(getVehicleNumberPlateText)
				MOD_DEFINE_NATIVE(getVehicleClass)
				MOD_DEFINE_NATIVE(getVehicleClassFromModel)
				MOD_DEFINE_NATIVE(getVehicleMod)
				MOD_DEFINE_NATIVE(getVehicleModVariation)
				MOD_DEFINE_NATIVE(getVehicleNumMods)
				MOD_DEFINE_NATIVE(getVehicleModKit)
				MOD_DEFINE_NATIVE(getVehicleModKitType)
				MOD_DEFINE_NATIVE(getVehicleNumModKits)
				MOD_DEFINE_NATIVE(getVehicleNumModColors)
				MOD_DEFINE_NATIVE(getVehicleModColor)
				MOD_DEFINE_NATIVE(getVehicleModColorName)
				MOD_DEFINE_NATIVE(getVehicleModTextLabel)
				MOD_DEFINE_NATIVE(getVehicleModData)
				MOD_DEFINE_NATIVE(getVehicleLiveryName)
				MOD_DEFINE_NATIVE(getVehicleWheelType)
				MOD_DEFINE_NATIVE(getVehicleLivery)
				MOD_DEFINE_NATIVE(getVehicleLiveryCount)
				MOD_DEFINE_NATIVE(getVehicleTrailer)
				MOD_DEFINE_NATIVE(getVehicleTyreSmokeColor)
				MOD_DEFINE_NATIVE(getVehicleWindowTint)
				MOD_DEFINE_NATIVE(getVehicleNumWindowTints)
				MOD_DEFINE_NATIVE(getVehicleColor)
				MOD_DEFINE_NATIVE(getVehicleColors)
				MOD_DEFINE_NATIVE(getVehicleNeonLightsColor)
				MOD_DEFINE_NATIVE(getVehicleCauseOfDestruction)
				MOD_DEFINE_NATIVE(getVehicleOwner)
				MOD_DEFINE_NATIVE(getVehiclePlateType)
				MOD_DEFINE_NATIVE(getVehicleColorCombination)
				MOD_DEFINE_NATIVE(getVehicleNumberColors)
				MOD_DEFINE_NATIVE(getVehicleExtraColors)
				MOD_DEFINE_NATIVE(getVehicleDoorLockStatus)
				MOD_DEFINE_NATIVE(getVehiclePedUsingDoor)
				MOD_DEFINE_NATIVE(getVehicleNumberPlateTextIndex)
				MOD_DEFINE_NATIVE(getVehicleAttachedToCargobob)
				MOD_DEFINE_NATIVE(getVehicleAttachedToEntity)
				MOD_DEFINE_NATIVE(getVehicleCustomPrimaryColor)
				MOD_DEFINE_NATIVE(getVehicleCustomSecondaryColor)
				MOD_DEFINE_NATIVE(getVehicleBodyHealth)
				MOD_DEFINE_NATIVE(getVehicleEngineHealth)
				MOD_DEFINE_NATIVE(getVehiclePetrolTankHealth)
				MOD_DEFINE_NATIVE(getVehicleMaxSpeed)
				MOD_DEFINE_NATIVE(getVehicleMaxBraking)
				MOD_DEFINE_NATIVE(getVehicleMaxTraction)
				MOD_DEFINE_NATIVE(getVehicleAcceleration)
				MOD_DEFINE_NATIVE(getVehicleModelMaxSpeed)
				MOD_DEFINE_NATIVE(getVehicleModelMaxBraking)
				MOD_DEFINE_NATIVE(getVehicleModelMaxTraction)
				MOD_DEFINE_NATIVE(getVehicleModelMaxKnots)
				MOD_DEFINE_NATIVE(getVehicleModelAcceleration)
				MOD_DEFINE_NATIVE(getVehicleModelHandBrake)
				MOD_DEFINE_NATIVE(getVehicleModelDownForce)
				MOD_DEFINE_NATIVE(getVehicleModelMoveResistance)
				MOD_DEFINE_NATIVE(getVehicleClassMaxSpeed)
				MOD_DEFINE_NATIVE(getVehicleClassMaxTraction)
				MOD_DEFINE_NATIVE(getVehicleClassMaxBraking)
				MOD_DEFINE_NATIVE(getVehicleClassMaxAgility)
				MOD_DEFINE_NATIVE(getVehicleClassMaxAcceleration)
				MOD_DEFINE_NATIVE(getVehicleModModifierValue)
				MOD_DEFINE_NATIVE(getVehicleDoorAngleRatio)
				MOD_DEFINE_NATIVE(getVehicleDirtLevel)
				MOD_DEFINE_NATIVE(removeVehicleMod)
				MOD_DEFINE_NATIVE(resetVehicleWheels)
				MOD_DEFINE_NATIVE(requestVehicleHighDetailModel)
				MOD_DEFINE_NATIVE(removeVehicleHighDetailModel)
				MOD_DEFINE_NATIVE(requestVehicleAsset)
				MOD_DEFINE_NATIVE(removeVehicleAsset)
				MOD_DEFINE_NATIVE(rollUpWindow)
				MOD_DEFINE_NATIVE(rollDownWindow)
				MOD_DEFINE_NATIVE(rollDownWindows)
				MOD_DEFINE_NATIVE(smashVehicleWindow)
				MOD_DEFINE_NATIVE(fixVehicleWindow)
				MOD_DEFINE_NATIVE(removeVehicleWindow)
				MOD_DEFINE_NATIVE(releasePreloadMods)
				MOD_DEFINE_NATIVE(reloadVehicleMod)
				MOD_DEFINE_NATIVE(toggleVehicleMod)
				MOD_DEFINE_NATIVE(clearVehicleCustomPrimaryColor)
				MOD_DEFINE_NATIVE(clearVehicleCustomSecondColor)
				MOD_DEFINE_NATIVE(enableCargobobHook)
				MOD_DEFINE_NATIVE(retractCargobobHook)
				MOD_DEFINE_NATIVE(attachVehicleToCargobob)
				MOD_DEFINE_NATIVE(detachVehicleFromCargobob)
				MOD_DEFINE_NATIVE(detachVehicleFromAnyCargobob)
				MOD_DEFINE_NATIVE(requestVehicleScaleformMovie)
				MOD_DEFINE_NATIVE(startVehicleAlarm)
				MOD_DEFINE_NATIVE(explodeVehicle)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createVehicle) {
				if (!arguments(3))
					return -1;
				
				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3))
					return 0;

				::Vehicle vehicle = -1;
				if (STREAMING::IS_MODEL_IN_CDIMAGE((::Hash)params[1]) && STREAMING::IS_MODEL_A_VEHICLE((::Hash)params[1])) {
					STREAMING::REQUEST_MODEL((::Hash)params[1]);
					while (!STREAMING::HAS_MODEL_LOADED((::Hash)params[1])) WAIT(0);
					vehicle = VEHICLE::CREATE_VEHICLE(params[1], coords[0], coords[1], coords[2], amx_ctof(params[3]), FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((::Hash)params[1]);
				}
				return vehicle;
			}


			MOD_NATIVE(deleteVehicle) {
				if (!arguments(1))
					return 0;

				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(params[1], true, true);
				VEHICLE::DELETE_VEHICLE(&(::Vehicle)params[1]);

				return 1;
			}


			MOD_NATIVE(isVehicleModel) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_MODEL((::Vehicle)params[1], (::Hash)params[2]);
			}
			
			MOD_NATIVE(isVehicleStopped) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_STOPPED((::Vehicle)params[1]);
			}
			
			MOD_NATIVE(isVehicleTaxiLightsOn) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_TAXI_LIGHT_ON((::Vehicle)params[1]);
			}
			
			MOD_NATIVE(isVehicleStuckOnRoof) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_STUCK_ON_ROOF((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleStoppedAtTrafficLights) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_STOPPED_AT_TRAFFIC_LIGHTS((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleDriveable) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_DRIVEABLE((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleWindowIntact) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_WINDOW_INTACT((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleAnyWindowIntact) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_ARE_ALL_VEHICLE_WINDOWS_INTACT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAnySeatsFree) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_ANY_VEHICLE_SEAT_EMPTY((::Vehicle)params[1]);
			}

			MOD_NATIVE(isAnyVehicleNearPoint) {
				if (!arguments(2))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				return VEHICLE::IS_ANY_VEHICLE_NEAR_POINT(coords[0], coords[1], coords[2], amx_ctof(params[2]));
			}

			MOD_NATIVE(isVehicleHighDetail) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_HIGH_DETAIL((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAssetLoaded) {
				if (!arguments(1))
					return 0;

				return VEHICLE::HAS_VEHICLE_ASSET_LOADED(params[1]);
			}

			MOD_NATIVE(isVehicleInBurnout) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_IN_BURNOUT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleSearchlightOn) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_ARE_ALL_VEHICLE_WINDOWS_INTACT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModLoadDone) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_0x9A83F5F9963775EF((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleToggleModOn) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_TOGGLE_MOD_ON((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleLeftHeadlightDamaged) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_HEADLIGHT_L_BROKEN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleRightHeadlightDamaged) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_HEADLIGHT_R_BROKEN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleEngineOn) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_VEHICLE_ENGINE_ON((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleVisible) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_VISIBLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleShopResprayAllowed) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_0x8D474C8FAEFF6CDE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehiclePropellersUndamaged) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_0x755D6D5267CBBD7E((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleStolen) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_STOLEN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleHaveWeapons) {
				if (!arguments(1))
					return 0;

				return VEHICLE::DOES_VEHICLE_HAVE_WEAPONS((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleNeonLightEnabled) {
				if (!arguments(2))
					return 0;

				return VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleOnAllWheels) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_ON_ALL_WHEELS((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAttachedToCargobob) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_ATTACHED_TO_CARGOBOB((::Vehicle)params[1], (::Vehicle)params[2]);
			}

			MOD_NATIVE(isVehicleBumperBrokenOff) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_BUMPER_BROKEN_OFF((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleDoorDamaged) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_DOOR_DAMAGED((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleBig) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_BIG_VEHICLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleHaveRoof) {
				if (!arguments(1))
					return 0;

				return VEHICLE::DOES_VEHICLE_HAVE_ROOF((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleDoorFullyOpen) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_DOOR_FULLY_OPEN((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleDamaged) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_VEHICLE_DAMAGED((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAboat) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_BOAT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelASubmersible) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_THIS_MODEL_A_SUBMERSIBLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAPlane) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_PLANE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAHeli) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_HELI((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelACar) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_CAR((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelATrain) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_TRAIN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelABike) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_BIKE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelABicycle) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_BICYCLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAQuadbike) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_THIS_MODEL_A_QUADBIKE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAlarmActivated) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_ALARM_ACTIVATED((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleTyresCanBurst) {
				if (!arguments(3))
					return 0;

				return VEHICLE::IS_VEHICLE_TYRE_BURST((::Vehicle)params[1], params[2], params[3]);
			}

			MOD_NATIVE(isVehicleSeatFree) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_SEAT_FREE((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleSirenOn) {
				if (!arguments(1))
					return 0;

				return VEHICLE::IS_VEHICLE_SIREN_ON((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleSirenSoundOn) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_0xB5CC40FBCB586380((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleBoatAnchor) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_GET_BOAT_ANCHOR((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehiclePrimaryColorCustom) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_IS_VEHICLE_PRIMARY_COLOUR_CUSTOM((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleSecondaryColorCustom) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleInGarageArea) {
				if (!arguments(2))
					return 0;

				return VEHICLE::IS_VEHICLE_IN_GARAGE_AREA((char *)String::get(amx, params[2]).c_str(), (::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleDoorsLockedForPlayer) {
				return VEHICLE::GET_VEHICLE_DOORS_LOCKED_FOR_PLAYER((::Vehicle)params[1], PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isCargobobHookActive) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_CARGOBOB_HOOK_ACTIVE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isCargobobMagnetActive) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_IS_CARGOBOB_MAGNET_ACTIVE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isCopVehicleInArea3d) {
				if (!arguments(2))
					return 0;

				float coords1[3], coords2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], coords1, 3))
					return 0;

				return VEHICLE::IS_COP_VEHICLE_IN_AREA_3D(coords1[0], coords2[0], coords1[1], coords2[1], coords1[2], coords2[2]);
			}

			MOD_NATIVE(isPreloadModsFinished) {
				if (!arguments(1))
					return 0;

				return VEHICLE::HAS_PRELOAD_MODS_FINISHED(params[1]);
			}
			
			MOD_NATIVE(setVehicleFixed) {
				if (!arguments(1))
					return 0;

				VEHICLE::SET_VEHICLE_FIXED((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(setVehicleDeformationFixed) {
				if (!arguments(1))
					return 0;

				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(setVehicleDamage) {
				if (!arguments(5))
					return 0;

				float offset[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], offset, 3))
					return 0;

				VEHICLE::SET_VEHICLE_DAMAGE((::Vehicle)params[1], offset[0], offset[1], offset[2], amx_ctof(params[3]), amx_ctof(params[4]), params[5]);

				return 1;
			}

			MOD_NATIVE(setVehicleBodyHealth) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_BODY_HEALTH((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleEngineHealth) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_ENGINE_HEALTH((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehiclePetrolTankHealth) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLivery) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_LIVERY((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleIndicatorLights) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleCanBreak) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_CAN_BREAK((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleBrakeLights) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_BRAKE_LIGHTS((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleHandbrake) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_HANDBRAKE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleResistantToExp) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleBurnout) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_BURNOUT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleRudderBroken) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_RUDDER_BROKEN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleSearchlight) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_SEARCHLIGHT((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleModKit) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_MOD_KIT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleWheelType) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_WHEEL_TYPE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleModColor) {
				if (!arguments(4))
					return 0;

				switch (params[2]) {
				case 1 :
					VEHICLE::SET_VEHICLE_MOD_COLOR_1((::Vehicle)params[1], params[3], params[4], NULL);
					break;

				case 2 :
					VEHICLE::SET_VEHICLE_MOD_COLOR_2((::Vehicle)params[1], params[3], params[4]);
					break;

				default:
					VEHICLE::SET_VEHICLE_MOD_COLOR_1((::Vehicle)params[1], params[3], params[4], NULL);
				}

				return 1;
			}

			MOD_NATIVE(setVehicleMod) {
				if (!arguments(4))
					return 0;

				VEHICLE::SET_VEHICLE_MOD((::Vehicle)params[1], params[2], params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyreSmokeColor) {
				if (!arguments(2))
					return 0;
				
				Utility::Color color(params[2]);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setVehicleNeonLightsColor) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setVehicleWindowTint) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_WINDOW_TINT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleEnginePowerMult) {
				if (!arguments(2))
					return 0;

				VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleEngineTorqueMult) {
				if (!arguments(2))
					return 0;

				VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleIsWanted) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_IS_WANTED((::Vehicle)params[1], params[1]);

				return 1;
			}

			MOD_NATIVE(setVehicleShootAtTarget) {
				if (!arguments(3))
					return 0;

				float target[3];
				if (!Utility::getFloatArrayFromParam(amx, params[3], target, 3))
					return 0;

				VEHICLE::SET_VEHICLE_SHOOT_AT_TARGET((::Ped)params[1], params[2], target[0], target[1], target[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleLodMult) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_LOD_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLightMult) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLights) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_LIGHTS((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleLightsMode) {
				if (!arguments(2))
					return 0;

				VEHICLE::_0xC45C27EF50F36ADC((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleStrong) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_STRONG((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleSiren) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_SIREN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleBoatAnchor) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_BOAT_ANCHOR((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleForceHd) {
				if (!arguments(2))
					return 0;

				VEHICLE::_0x97CE68CB032583F0((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleGravity) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_GRAVITY((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleInteriorLight) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_INTERIORLIGHT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleEngineCanDegrade) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleStolen) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_IS_STOLEN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleJetEngineOn) {
				if (!arguments(2))
					return 0;

				VEHICLE::_0xB8FBC8B1330CA9B4((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleAlarm) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_ALARM((::Vehicle)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setVehicleCanBeUsedFleeingPeds) {
				if (!arguments(2))
					return 0;

				VEHICLE::_0x300504B23BD3B711((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleNeonLightEnabled) {
				if (!arguments(3))
					return 0;

				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleColorCombination) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_COLOUR_COMBINATION((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleExtraColors) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_EXTRA_COLOURS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorCanBreak) {
				if (!arguments(3))
					return 0;

				VEHICLE::_SET_VEHICLE_DOOR_BREAKABLE((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorShut) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_DOOR_SHUT((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorBroken) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_DOOR_BROKEN((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorLatched) {
				if (!arguments(5))
					return 0;

				VEHICLE::SET_VEHICLE_DOOR_LATCHED((::Vehicle)params[1], params[2], params[3], params[4], params[5]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorControl) {
				if (!arguments(4))
					return 0;

				VEHICLE::SET_VEHICLE_DOOR_CONTROL((::Vehicle)params[1], params[2], params[3], amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setVehicleDoorOpen) {
				if (!arguments(4))
					return 0;

				VEHICLE::SET_VEHICLE_DOOR_OPEN((::Vehicle)params[1], params[2], params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorsShut) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_DOORS_SHUT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleWheelsCanBreak) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyresCanBurst) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyreBurst) {
				if (!arguments(4))
					return 0;

				VEHICLE::SET_VEHICLE_TYRE_BURST((::Vehicle)params[1], params[2], params[3], amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setVehicleUndriveable) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_UNDRIVEABLE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleProvidesCover) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_PROVIDES_COVER((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorsLockedForPlayer) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER((::Vehicle)params[1], PLAYER::PLAYER_ID(), params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleEngineOn) {
				if (!arguments(4))
					return 0;

				VEHICLE::SET_VEHICLE_ENGINE_ON((::Vehicle)params[1], params[2], params[3], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDirtLevel) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_DIRT_LEVEL((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleCanBeVisiblyDamaged) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleCanBeTargetted) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_CAN_BE_TARGETTED((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleModelSuppressed) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_MODEL_IS_SUPPRESSED((::Hash)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleNumberPlateText) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT((::Vehicle)params[1], (char *)String::get(amx, params[2]).c_str());

				return 1;
			}

			MOD_NATIVE(setVehicleNumberPlateTextIndex) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyreFixed) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_TYRE_FIXED((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleForwardSpeed) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_FORWARD_SPEED((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleHalt) {
				if (!arguments(4))
					return 0;

				VEHICLE::_TASK_BRING_VEHICLE_TO_HALT((::Vehicle)params[1], amx_ctof(params[2]), params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(setVehicleCustomPrimaryColor) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setVehicleCustomSecondaryColor) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setBikeLeanAngle) {
				if (!arguments(3))
					return 0;

				VEHICLE::_SET_BIKE_LEAN_ANGLE((::Vehicle)params[1], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(setPlaneMinHeightAboveTerrain) {
				if (!arguments(2))
					return 0;

				VEHICLE::_SET_PLANE_MIN_HEIGHT_ABOVE_TERRAIN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setCargobobHookPos) {
				if (!arguments(4))
					return 0;

				VEHICLE::_0x877C1EAEAC531023((::Vehicle)params[1], amx_ctof(params[2]), amx_ctof(params[3]), params[4]);

				return 1;
			}

			MOD_NATIVE(setCargobobMagnetActive) {
				if (!arguments(2))
					return 0;

				VEHICLE::_CARGOBOB_MAGNET_GRAB_VEHICLE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setCargobobMagnetStrength) {
				if (!arguments(2))
					return 0;

				VEHICLE::_0xBCBFCD9D1DAC19E2((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setHeliBladesSpeed) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_HELI_BLADES_SPEED((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleColor) {
				if (!arguments(3))
					return 0;

				VEHICLE::SET_VEHICLE_COLOURS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}
			
			MOD_NATIVE(setVehicleDoorsLocked) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_VEHICLE_DOORS_LOCKED((::Vehicle)params[1], (BOOL)params[2]);

				return 1;
			}
			
			MOD_NATIVE(setVehicleTaxiLights) {
				if (!arguments(2))
					return 0;

				VEHICLE::SET_TAXI_LIGHTS((::Vehicle)params[1], (BOOL)params[2]);

				return 1;
			}

			MOD_NATIVE(getClosestVehicle) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				return VEHICLE::GET_CLOSEST_VEHICLE(coords[0], coords[1], coords[2], amx_ctof(params[2]), params[3], params[4]);
			}

			MOD_NATIVE(getRandomVehicleInSphere) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				return VEHICLE::GET_RANDOM_VEHICLE_IN_SPHERE(coords[0], coords[1], coords[2], amx_ctof(params[2]), params[3], params[4]);
			}

			MOD_NATIVE(getVehiclePedInSeat) {
				if (!arguments(2))
					return 0;

				return VEHICLE::GET_PED_IN_VEHICLE_SEAT((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleLastPedInSeat) {
				if (!arguments(2))
					return 0;

				return VEHICLE::GET_LAST_PED_IN_VEHICLE_SEAT((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleLightsState) {
				if (!arguments(3))
					return 0;

				cell * lightsOn = Utility::getAddrFromParam(amx, params[2]),
					 * highbeamsOn = Utility::getAddrFromParam(amx, params[3]);

				if (lightsOn == nullptr || highbeamsOn == nullptr)
					return 0;

				return VEHICLE::GET_VEHICLE_LIGHTS_STATE((::Vehicle)params[1], lightsOn, highbeamsOn);
			}

			MOD_NATIVE(getVehicleNumberPlateText) {
				if (!arguments(1))
					return 0;

				String::set(amx, params[2], VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT((::Vehicle)params[1]), params[3]);

				return 1;
			}

			MOD_NATIVE(getVehicleClass) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_CLASS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleClassFromModel) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_CLASS_FROM_NAME((::Hash)params[1]);
			}

			MOD_NATIVE(getVehicleMod) {
				if (!arguments(2))
					return 0;

				return VEHICLE::GET_VEHICLE_MOD((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleModVariation) {
				if (!arguments(2))
					return 0;

				return VEHICLE::GET_VEHICLE_MOD_VARIATION((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleNumMods) {
				if (!arguments(2))
					return 0;

				return VEHICLE::GET_NUM_VEHICLE_MODS((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleModKit) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_MOD_KIT((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleModKitType) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_MOD_KIT_TYPE((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumModKits) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_NUM_MOD_KITS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumModColors) {
				if (!arguments(2))
					return 0;

				return VEHICLE::GET_NUM_MOD_COLORS((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleModColor) {
				if (!arguments(5))
					return 0;

				cell * paintType = Utility::getAddrFromParam(amx, params[3]),
					 * color = Utility::getAddrFromParam(amx, params[4]),
					 * pearlescentColor = Utility::getAddrFromParam(amx, params[5]);

				if (paintType == nullptr || color == nullptr || pearlescentColor == nullptr)
					return 0;

				if (params[2] == 1)
					VEHICLE::GET_VEHICLE_MOD_COLOR_1((::Vehicle)params[1], paintType, color, pearlescentColor);
				else
					VEHICLE::GET_VEHICLE_MOD_COLOR_2((::Vehicle)params[1], paintType, color);

				return 1;
			}

			MOD_NATIVE(getVehicleModColorName) {
				if (!arguments(2))
					return 0;

				return 1;
			}

			MOD_NATIVE(getVehicleModTextLabel) {
				if (!arguments(5))
					return 0;

				String::set(amx, params[4], VEHICLE::GET_MOD_TEXT_LABEL((::Vehicle)params[1], params[2], params[3]), params[5]);

				return 1;
			}

			MOD_NATIVE(getVehicleModData) {
				if (!arguments(5))
					return 0;

				return VEHICLE::_0x4593CF82AA179706((::Vehicle)params[1], params[2], params[3]);
			}

			MOD_NATIVE(getVehicleLiveryName) {
				if (!arguments(4))
					return 0;

				String::set(amx, params[3], VEHICLE::GET_LIVERY_NAME((::Vehicle)params[1], params[2]), params[4]);

				return 1;
			}

			MOD_NATIVE(getVehicleWheelType) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_WHEEL_TYPE((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleLivery) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_LIVERY((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleLiveryCount) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_LIVERY_COUNT((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleTrailer) {
				if (!arguments(1))
					return 0;

				cell * vehicle = Utility::getAddrFromParam(amx, params[3]);
				if (vehicle == nullptr)
					return 0;

				return VEHICLE::GET_VEHICLE_TRAILER_VEHICLE((::Vehicle)params[1], vehicle);
			}

			MOD_NATIVE(getVehicleTyreSmokeColor) {
				if (!arguments(1))
					return 0;
				
				int r, g, b;
				VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR((::Vehicle)params[1], &r, &g, &b);

				return Utility::Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleWindowTint) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_WINDOW_TINT((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumWindowTints) {
				return VEHICLE::GET_NUM_VEHICLE_WINDOW_TINTS();
			}

			MOD_NATIVE(getVehicleColor) {
				if (!arguments(1))
					return 0;

				int r, g, b;
				VEHICLE::GET_VEHICLE_COLOR((::Vehicle)params[1], &r, &g, &b);

				return Utility::Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleColors) {
				if (!arguments(3))
					return 0;

				cell * primary = Utility::getAddrFromParam(amx, params[2]),
					 * secondary = Utility::getAddrFromParam(amx, params[3]);
				if (primary == nullptr || secondary == nullptr)
					return 0;

				VEHICLE::GET_VEHICLE_COLOURS((::Vehicle)params[1], primary, secondary);

				return 1;
			}

			MOD_NATIVE(getVehicleNeonLightsColor) {
				if (!arguments(1))
					return 0;

				int r, g, b;
				VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR((::Vehicle)params[1], &r, &g, &b);

				return Utility::Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleCauseOfDestruction) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_CAUSE_OF_DESTRUCTION((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleOwner) {
				if (!arguments(2))
					return 0;

				cell * entity = Utility::getAddrFromParam(amx, params[2]);
				if (entity == nullptr)
					return 0;

				return VEHICLE::_GET_VEHICLE_OWNER((::Vehicle)params[1], (::Entity *)entity);
			}

			MOD_NATIVE(getVehiclePlateType) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_PLATE_TYPE((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleColorCombination) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_COLOUR_COMBINATION((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumberColors) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_NUMBER_OF_VEHICLE_COLOURS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleExtraColors) {
				if (!arguments(3))
					return 0;

				cell * pearlescentColor = Utility::getAddrFromParam(amx, params[2]),
					 * wheelColor = Utility::getAddrFromParam(amx, params[3]);
				if (pearlescentColor == nullptr || wheelColor == nullptr)
					return 0;

				VEHICLE::GET_VEHICLE_EXTRA_COLOURS((::Vehicle)params[1], pearlescentColor, wheelColor);

				return 1;
			}

			MOD_NATIVE(getVehicleDoorLockStatus) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_DOOR_LOCK_STATUS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehiclePedUsingDoor) {
				if (!arguments(2))
					return 0;

				return VEHICLE::_GET_PED_USING_VEHICLE_DOOR((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleNumberPlateTextIndex) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleAttachedToCargobob) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_ATTACHED_TO_CARGOBOB((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleAttachedToEntity) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_0x375E7FC44F21C8AB((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleCustomPrimaryColor) {
				if (!arguments(1))
					return 0;

				int r, g, b;
				VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR((::Vehicle)params[1], &r, &g, &b);

				return Utility::Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleCustomSecondaryColor) {
				if (!arguments(1))
					return 0;

				int r, g, b;
				VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR((::Vehicle)params[1], &r, &g, &b);

				return Utility::Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleBodyHealth) {
				if (!arguments(1))
					return 0;

				float health = VEHICLE::GET_VEHICLE_BODY_HEALTH((::Vehicle)params[1]);

				return amx_ftoc(health);
			}

			MOD_NATIVE(getVehicleEngineHealth) {
				if (!arguments(1))
					return 0;

				float health = VEHICLE::GET_VEHICLE_ENGINE_HEALTH((::Vehicle)params[1]);

				return amx_ftoc(health);
			}

			MOD_NATIVE(getVehiclePetrolTankHealth) {
				if (!arguments(1))
					return 0;

				float health = VEHICLE::GET_VEHICLE_PETROL_TANK_HEALTH((::Vehicle)params[1]);

				return amx_ftoc(health);
			}

			MOD_NATIVE(getVehicleMaxSpeed) {
				if (!arguments(1))
					return 0;

				float speed = VEHICLE::_GET_VEHICLE_MAX_SPEED((::Vehicle)params[1]);

				return amx_ftoc(speed);
			}

			MOD_NATIVE(getVehicleMaxBraking) {
				if (!arguments(1))
					return 0;

				float braking = VEHICLE::GET_VEHICLE_MAX_BRAKING((::Vehicle)params[1]);

				return amx_ftoc(braking);
			}

			MOD_NATIVE(getVehicleMaxTraction) {
				if (!arguments(1))
					return 0;

				float traction = VEHICLE::GET_VEHICLE_MAX_TRACTION((::Vehicle)params[1]);

				return amx_ftoc(traction);
			}

			MOD_NATIVE(getVehicleAcceleration) {
				if (!arguments(1))
					return 0;

				float accel = VEHICLE::GET_VEHICLE_ACCELERATION((::Vehicle)params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleModelMaxSpeed) {
				if (!arguments(1))
					return 0;

				float speed = VEHICLE::_GET_VEHICLE_MAX_SPEED((::Vehicle)params[1]);

				return amx_ftoc(speed);
			}

			MOD_NATIVE(getVehicleModelMaxBraking) {
				if (!arguments(1))
					return 0;

				float braking = VEHICLE::GET_VEHICLE_MODEL_MAX_BRAKING((::Hash)params[1]);

				return amx_ftoc(braking);
			}

			MOD_NATIVE(getVehicleModelMaxTraction) {
				if (!arguments(1))
					return 0;

				float traction = VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION((::Hash)params[1]);

				return amx_ftoc(traction);
			}

			MOD_NATIVE(getVehicleModelMaxKnots) {
				if (!arguments(1))
					return 0;

				float knots = VEHICLE::_0xC6AD107DDC9054CC((::Hash)params[1]);

				return amx_ftoc(knots);
			}

			MOD_NATIVE(getVehicleModelAcceleration) {
				if (!arguments(1))
					return 0;

				float accel = VEHICLE::GET_VEHICLE_MODEL_ACCELERATION((::Hash)params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleModelHandBrake) {
				if (!arguments(1))
					return 0;

				float handbrake = VEHICLE::_0xBFBA3BA79CFF7EBF((::Hash)params[1]);

				return amx_ftoc(handbrake);
			}

			MOD_NATIVE(getVehicleModelDownForce) {
				if (!arguments(1))
					return 0;

				float downForce = VEHICLE::_0x53409B5163D5B846((::Hash)params[1]);

				return amx_ftoc(downForce);
			}

			MOD_NATIVE(getVehicleModelMoveResistance) {
				if (!arguments(1))
					return 0;

				float resist = VEHICLE::_0x5AA3F878A178C4FC((::Hash)params[1]);

				return amx_ftoc(resist);
			}

			MOD_NATIVE(getVehicleClassMaxSpeed) {
				if (!arguments(1))
					return 0;

				float accel = VEHICLE::_0x00C09F246ABEDD82(params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleClassMaxTraction) {
				if (!arguments(1))
					return 0;

				float traction = VEHICLE::GET_VEHICLE_CLASS_MAX_TRACTION(params[1]);

				return amx_ftoc(traction);
			}

			MOD_NATIVE(getVehicleClassMaxBraking) {
				if (!arguments(1))
					return 0;

				float braking = VEHICLE::GET_VEHICLE_CLASS_MAX_BRAKING(params[1]);

				return amx_ftoc(braking);
			}

			MOD_NATIVE(getVehicleClassMaxAgility) {
				if (!arguments(1))
					return 0;

				float agility = VEHICLE::GET_VEHICLE_CLASS_MAX_AGILITY(params[1]);

				return amx_ftoc(agility);
			}

			MOD_NATIVE(getVehicleClassMaxAcceleration) {
				if (!arguments(1))
					return 0;

				float accel = VEHICLE::GET_VEHICLE_CLASS_MAX_ACCELERATION(params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleModModifierValue) {
				if (!arguments(3))
					return 0;

				float value = VEHICLE::GET_VEHICLE_MOD_MODIFIER_VALUE((::Vehicle)params[1], params[2], params[3]);

				return amx_ftoc(value);
			}

			MOD_NATIVE(getVehicleDoorAngleRatio) {
				if (!arguments(2))
					return 0;

				float ratio = VEHICLE::GET_VEHICLE_DOOR_ANGLE_RATIO((::Vehicle)params[1], params[2]);

				return amx_ftoc(ratio);
			}

			MOD_NATIVE(getVehicleDirtLevel) {
				if (!arguments(1))
					return 0;

				float level = VEHICLE::GET_VEHICLE_DIRT_LEVEL((::Vehicle)params[1]);

				return amx_ftoc(level);
			}

			MOD_NATIVE(getVehiclePassengers) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_NUMBER_OF_PASSENGERS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleMaxPassengers) {
				if (!arguments(1))
					return 0;

				return VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS((::Vehicle)params[1]);
			}
			
			MOD_NATIVE(getVehicleModelNumberOfSeats) {
				if (!arguments(1))
					return 0;

				return VEHICLE::_GET_VEHICLE_MODEL_MAX_NUMBER_OF_PASSENGERS((::Hash)params[1]);
			}
			
			MOD_NATIVE(getDisplayNameFromVehicleModel) {
				if (!arguments(3))
					return 0;

				cell * dest = Utility::getAddrFromParam(amx, params[2]);
				if (dest == nullptr)
					return 0;

				amx_SetString(dest, VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((::Hash)params[1]), NULL, NULL, params[3]);

				return 1;
			}

			MOD_NATIVE(removeVehicleMod) {
				if (!arguments(2))
					return 0;

				VEHICLE::REMOVE_VEHICLE_MOD((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(resetVehicleWheels) {
				if (!arguments(2))
					return 0;

				VEHICLE::RESET_VEHICLE_WHEELS((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(requestVehicleHighDetailModel) {
				if (!arguments(1))
					return 0;

				VEHICLE::REQUEST_VEHICLE_HIGH_DETAIL_MODEL((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(removeVehicleHighDetailModel) {
				if (!arguments(1))
					return 0;

				VEHICLE::REMOVE_VEHICLE_HIGH_DETAIL_MODEL((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(requestVehicleAsset) {
				if (!arguments(2))
					return 0;

				VEHICLE::REQUEST_VEHICLE_ASSET((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(removeVehicleAsset) {
				if (!arguments(1))
					return 0;

				VEHICLE::REMOVE_VEHICLE_ASSET((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(rollUpWindow) {
				if (!arguments(2))
					return 0;

				VEHICLE::ROLL_UP_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(rollDownWindow) {
				if (!arguments(2))
					return 0;

				VEHICLE::ROLL_DOWN_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(rollDownWindows) {
				if (!arguments(1))
					return 0;

				VEHICLE::ROLL_DOWN_WINDOWS((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(smashVehicleWindow) {
				if (!arguments(2))
					return 0;

				VEHICLE::SMASH_VEHICLE_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(fixVehicleWindow) {
				if (!arguments(2))
					return 0;

				VEHICLE::FIX_VEHICLE_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(removeVehicleWindow) {
				if (!arguments(2))
					return 0;

				VEHICLE::REMOVE_VEHICLE_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(releasePreloadMods) {
				if (!arguments(1))
					return 0;

				VEHICLE::RELEASE_PRELOAD_MODS((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(reloadVehicleMod) {
				if (!arguments(3))
					return 0;

				VEHICLE::PRELOAD_VEHICLE_MOD((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(toggleVehicleMod) {
				if (!arguments(3))
					return 0;

				VEHICLE::TOGGLE_VEHICLE_MOD((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(clearVehicleCustomPrimaryColor) {
				if (!arguments(1))
					return 0;

				VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(clearVehicleCustomSecondColor) {
				if (!arguments(1))
					return 0;

				VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(enableCargobobHook) {
				if (!arguments(2))
					return 0;

				VEHICLE::_ENABLE_CARGOBOB_HOOK((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(retractCargobobHook) {
				if (!arguments(1))
					return 0;

				VEHICLE::_RETRACT_CARGOBOB_HOOK((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(attachVehicleToCargobob) {
				if (!arguments(4))
					return 0;
				
				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[4], coords, 3))
					return 0;

				VEHICLE::ATTACH_VEHICLE_TO_CARGOBOB((::Vehicle)params[1], params[2], params[3], coords[0], coords[1], coords[2]);

				return 1;
			}

			MOD_NATIVE(detachVehicleFromCargobob) {
				if (!arguments(2))
					return 0;

				VEHICLE::DETACH_VEHICLE_FROM_CARGOBOB((::Vehicle)params[1], (::Vehicle)params[2]);

				return 1;
			}

			MOD_NATIVE(detachVehicleFromAnyCargobob) {
				if (!arguments(1))
					return 0;

				VEHICLE::DETACH_VEHICLE_FROM_ANY_CARGOBOB((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(requestVehicleScaleformMovie) {
				if (!arguments(1))
					return 0;

				VEHICLE::_0xDBA3C090E3D74690((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(startVehicleAlarm) {
				if (!arguments(1))
					return 0;

				VEHICLE::START_VEHICLE_ALARM((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(explodeVehicle) {
				if (!arguments(3))
					return 0;

				VEHICLE::EXPLODE_VEHICLE((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}
		};
	};
};