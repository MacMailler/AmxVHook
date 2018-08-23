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
				checkargs(3);
				
				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				::Vehicle vehicle = -1;
				if (STREAMING::IS_MODEL_IN_CDIMAGE((::Hash)params[1]) && STREAMING::IS_MODEL_A_VEHICLE((::Hash)params[1])) {
					STREAMING::REQUEST_MODEL((::Hash)params[1]);
					while (!STREAMING::HAS_MODEL_LOADED((::Hash)params[1])) WAIT(0);
					vehicle = VEHICLE::CREATE_VEHICLE(params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), amx_ctof(params[3]), FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((::Hash)params[1]);
				}
				return vehicle;
			}


			MOD_NATIVE(deleteVehicle) {
				checkargs(1);

				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(params[1], true, true);
				VEHICLE::DELETE_VEHICLE(&(::Vehicle)params[1]);

				return 1;
			}


			MOD_NATIVE(isVehicleModel) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_MODEL((::Vehicle)params[1], (::Hash)params[2]);
			}
			
			MOD_NATIVE(isVehicleStopped) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_STOPPED((::Vehicle)params[1]);
			}
			
			MOD_NATIVE(isVehicleTaxiLightsOn) {
				checkargs(1);

				return VEHICLE::IS_TAXI_LIGHT_ON((::Vehicle)params[1]);
			}
			
			MOD_NATIVE(isVehicleStuckOnRoof) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_STUCK_ON_ROOF((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleStoppedAtTrafficLights) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_STOPPED_AT_TRAFFIC_LIGHTS((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleDriveable) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_DRIVEABLE((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleWindowIntact) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_WINDOW_INTACT((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleAnyWindowIntact) {
				checkargs(1);

				return VEHICLE::_ARE_ALL_VEHICLE_WINDOWS_INTACT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAnySeatsFree) {
				checkargs(1);

				return VEHICLE::_IS_ANY_VEHICLE_SEAT_EMPTY((::Vehicle)params[1]);
			}

			MOD_NATIVE(isAnyVehicleNearPoint) {
				checkargs(2);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				return VEHICLE::IS_ANY_VEHICLE_NEAR_POINT(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), amx_ctof(params[2]));
			}

			MOD_NATIVE(isVehicleHighDetail) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_HIGH_DETAIL((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAssetLoaded) {
				checkargs(1);

				return VEHICLE::HAS_VEHICLE_ASSET_LOADED(params[1]);
			}

			MOD_NATIVE(isVehicleInBurnout) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_IN_BURNOUT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleSearchlightOn) {
				checkargs(1);

				return VEHICLE::_ARE_ALL_VEHICLE_WINDOWS_INTACT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModLoadDone) {
				checkargs(1);

				return VEHICLE::_0x9A83F5F9963775EF((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleToggleModOn) {
				checkargs(2);

				return VEHICLE::IS_TOGGLE_MOD_ON((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleLeftHeadlightDamaged) {
				checkargs(1);

				return VEHICLE::_IS_HEADLIGHT_L_BROKEN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleRightHeadlightDamaged) {
				checkargs(1);

				return VEHICLE::_IS_HEADLIGHT_R_BROKEN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleEngineOn) {
				checkargs(1);

				return VEHICLE::_IS_VEHICLE_ENGINE_ON((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleVisible) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_VISIBLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleShopResprayAllowed) {
				checkargs(1);

				return VEHICLE::_0x8D474C8FAEFF6CDE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehiclePropellersUndamaged) {
				checkargs(1);

				return VEHICLE::_0x755D6D5267CBBD7E((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleStolen) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_STOLEN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleHaveWeapons) {
				checkargs(1);

				return VEHICLE::DOES_VEHICLE_HAVE_WEAPONS((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleNeonLightEnabled) {
				checkargs(2);

				return VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleOnAllWheels) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_ON_ALL_WHEELS((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAttachedToCargobob) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_ATTACHED_TO_CARGOBOB((::Vehicle)params[1], (::Vehicle)params[2]);
			}

			MOD_NATIVE(isVehicleBumperBrokenOff) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_BUMPER_BROKEN_OFF((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleDoorDamaged) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_DOOR_DAMAGED((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleBig) {
				checkargs(1);

				return VEHICLE::IS_BIG_VEHICLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleHaveRoof) {
				checkargs(1);

				return VEHICLE::DOES_VEHICLE_HAVE_ROOF((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleDoorFullyOpen) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_DOOR_FULLY_OPEN((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleDamaged) {
				checkargs(1);

				return VEHICLE::_IS_VEHICLE_DAMAGED((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAboat) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_BOAT((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelASubmersible) {
				checkargs(1);

				return VEHICLE::_IS_THIS_MODEL_A_SUBMERSIBLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAPlane) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_PLANE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAHeli) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_HELI((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelACar) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_CAR((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelATrain) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_TRAIN((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelABike) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_BIKE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelABicycle) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_BICYCLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleModelAQuadbike) {
				checkargs(1);

				return VEHICLE::IS_THIS_MODEL_A_QUADBIKE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleAlarmActivated) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_ALARM_ACTIVATED((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleTyresCanBurst) {
				checkargs(3);

				return VEHICLE::IS_VEHICLE_TYRE_BURST((::Vehicle)params[1], params[2], params[3]);
			}

			MOD_NATIVE(isVehicleSeatFree) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_SEAT_FREE((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(isVehicleSirenOn) {
				checkargs(1);

				return VEHICLE::IS_VEHICLE_SIREN_ON((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleSirenSoundOn) {
				checkargs(1);

				return VEHICLE::_0xB5CC40FBCB586380((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleBoatAnchor) {
				checkargs(1);

				return VEHICLE::_GET_BOAT_ANCHOR((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehiclePrimaryColorCustom) {
				checkargs(1);

				return VEHICLE::GET_IS_VEHICLE_PRIMARY_COLOUR_CUSTOM((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleSecondaryColorCustom) {
				checkargs(1);

				return VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM((::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleInGarageArea) {
				checkargs(2);

				return VEHICLE::IS_VEHICLE_IN_GARAGE_AREA((char *)String::get(amx, params[2]).c_str(), (::Vehicle)params[1]);
			}

			MOD_NATIVE(isVehicleDoorsLockedForPlayer) {
				return VEHICLE::GET_VEHICLE_DOORS_LOCKED_FOR_PLAYER((::Vehicle)params[1], PLAYER::PLAYER_ID());
			}

			MOD_NATIVE(isCargobobHookActive) {
				checkargs(1);

				return VEHICLE::_IS_CARGOBOB_HOOK_ACTIVE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isCargobobMagnetActive) {
				checkargs(1);

				return VEHICLE::_IS_CARGOBOB_MAGNET_ACTIVE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isCopVehicleInArea3d) {
				checkargs(2);

				cell *coords1, *coords2;
				if (amx_GetAddr(amx, params[1], &coords1) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &coords2) != AMX_ERR_NONE)
					return 0;

				return VEHICLE::IS_COP_VEHICLE_IN_AREA_3D(
					amx_ctof(coords1[0]), amx_ctof(coords1[1]), amx_ctof(coords1[2]),
					amx_ctof(coords2[0]), amx_ctof(coords2[1]), amx_ctof(coords2[2])
				);
			}

			MOD_NATIVE(isPreloadModsFinished) {
				checkargs(1);

				return VEHICLE::HAS_PRELOAD_MODS_FINISHED(params[1]);
			}
			
			MOD_NATIVE(setVehicleFixed) {
				checkargs(1);

				VEHICLE::SET_VEHICLE_FIXED((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(setVehicleDeformationFixed) {
				checkargs(1);

				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(setVehicleDamage) {
				checkargs(5);

				cell *offest;
				if (amx_GetAddr(amx, params[2], &offest) != AMX_ERR_NONE)
					return 0;

				VEHICLE::SET_VEHICLE_DAMAGE(
					(::Vehicle)params[1],
					amx_ctof(offest[0]), amx_ctof(offest[1]), amx_ctof(offest[2]),
					amx_ctof(params[3]), amx_ctof(params[4]),
					params[5]
				);

				return 1;
			}

			MOD_NATIVE(setVehicleBodyHealth) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_BODY_HEALTH((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleEngineHealth) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_ENGINE_HEALTH((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehiclePetrolTankHealth) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLivery) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_LIVERY((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleIndicatorLights) {
				checkargs(3);

				VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleCanBreak) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_CAN_BREAK((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleBrakeLights) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_BRAKE_LIGHTS((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleHandbrake) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_HANDBRAKE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleResistantToExp) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleBurnout) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_BURNOUT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleRudderBroken) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_RUDDER_BROKEN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleSearchlight) {
				checkargs(3);

				VEHICLE::SET_VEHICLE_SEARCHLIGHT((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleModKit) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_MOD_KIT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleWheelType) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_WHEEL_TYPE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleModColor) {
				checkargs(4);

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
				checkargs(4);

				VEHICLE::SET_VEHICLE_MOD((::Vehicle)params[1], params[2], params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyreSmokeColor) {
				checkargs(2);
				
				Color color(params[2]);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setVehicleNeonLightsColor) {
				checkargs(2);

				Color color(params[2]);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setVehicleWindowTint) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_WINDOW_TINT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleEnginePowerMult) {
				checkargs(2);

				VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleEngineTorqueMult) {
				checkargs(2);

				VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleIsWanted) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_IS_WANTED((::Vehicle)params[1], params[1]);

				return 1;
			}

			MOD_NATIVE(setVehicleShootAtTarget) {
				checkargs(3);

				cell *target;
				if (amx_GetAddr(amx, params[3], &target) != AMX_ERR_NONE)
					return 0;

				VEHICLE::SET_VEHICLE_SHOOT_AT_TARGET((::Ped)params[1], params[2], amx_ctof(target[0]), amx_ctof(target[1]), amx_ctof(target[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLodMult) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_LOD_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLightMult) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleLights) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_LIGHTS((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleLightsMode) {
				checkargs(2);

				VEHICLE::_0xC45C27EF50F36ADC((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleStrong) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_STRONG((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleSiren) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_SIREN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleBoatAnchor) {
				checkargs(2);

				VEHICLE::SET_BOAT_ANCHOR((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleForceHd) {
				checkargs(2);

				VEHICLE::_0x97CE68CB032583F0((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleGravity) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_GRAVITY((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleInteriorLight) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_INTERIORLIGHT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleEngineCanDegrade) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleStolen) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_IS_STOLEN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleJetEngineOn) {
				checkargs(2);

				VEHICLE::_0xB8FBC8B1330CA9B4((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleAlarm) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_ALARM((::Vehicle)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setVehicleCanBeUsedFleeingPeds) {
				checkargs(2);

				VEHICLE::_0x300504B23BD3B711((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleNeonLightEnabled) {
				checkargs(3);

				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleColorCombination) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_COLOUR_COMBINATION((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleExtraColors) {
				checkargs(3);

				VEHICLE::SET_VEHICLE_EXTRA_COLOURS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorCanBreak) {
				checkargs(3);

				VEHICLE::_SET_VEHICLE_DOOR_BREAKABLE((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorShut) {
				checkargs(3);

				VEHICLE::SET_VEHICLE_DOOR_SHUT((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorBroken) {
				checkargs(3);

				VEHICLE::SET_VEHICLE_DOOR_BROKEN((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorLatched) {
				checkargs(5);

				VEHICLE::SET_VEHICLE_DOOR_LATCHED((::Vehicle)params[1], params[2], params[3], params[4], params[5]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorControl) {
				checkargs(4);

				VEHICLE::SET_VEHICLE_DOOR_CONTROL((::Vehicle)params[1], params[2], params[3], amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setVehicleDoorOpen) {
				checkargs(4);

				VEHICLE::SET_VEHICLE_DOOR_OPEN((::Vehicle)params[1], params[2], params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorsShut) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_DOORS_SHUT((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleWheelsCanBreak) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyresCanBurst) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyreBurst) {
				checkargs(4);

				VEHICLE::SET_VEHICLE_TYRE_BURST((::Vehicle)params[1], params[2], params[3], amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setVehicleUndriveable) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_UNDRIVEABLE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleProvidesCover) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_PROVIDES_COVER((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleDoorsLockedForPlayer) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER((::Vehicle)params[1], PLAYER::PLAYER_ID(), params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleEngineOn) {
				checkargs(4);

				VEHICLE::SET_VEHICLE_ENGINE_ON((::Vehicle)params[1], params[2], params[3], params[3]);

				return 1;
			}

			MOD_NATIVE(setVehicleDirtLevel) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_DIRT_LEVEL((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleCanBeVisiblyDamaged) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleCanBeTargetted) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_CAN_BE_TARGETTED((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleModelSuppressed) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_MODEL_IS_SUPPRESSED((::Hash)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleNumberPlateText) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT((::Vehicle)params[1], (char *)String::get(amx, params[2]).c_str());

				return 1;
			}

			MOD_NATIVE(setVehicleNumberPlateTextIndex) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleTyreFixed) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_TYRE_FIXED((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setVehicleForwardSpeed) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_FORWARD_SPEED((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleHalt) {
				checkargs(4);

				VEHICLE::_TASK_BRING_VEHICLE_TO_HALT((::Vehicle)params[1], amx_ctof(params[2]), params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(setVehicleCustomPrimaryColor) {
				checkargs(2);

				Color color(params[2]);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setVehicleCustomSecondaryColor) {
				checkargs(2);

				Color color(params[2]);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR((::Vehicle)params[1], color.R, color.G, color.B);

				return 1;
			}

			MOD_NATIVE(setBikeLeanAngle) {
				checkargs(3);

				VEHICLE::_SET_BIKE_LEAN_ANGLE((::Vehicle)params[1], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(setPlaneMinHeightAboveTerrain) {
				checkargs(2);

				VEHICLE::_SET_PLANE_MIN_HEIGHT_ABOVE_TERRAIN((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setCargobobHookPos) {
				checkargs(4);

				VEHICLE::_0x877C1EAEAC531023((::Vehicle)params[1], amx_ctof(params[2]), amx_ctof(params[3]), params[4]);

				return 1;
			}

			MOD_NATIVE(setCargobobMagnetActive) {
				checkargs(2);

				VEHICLE::_CARGOBOB_MAGNET_GRAB_VEHICLE((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setCargobobMagnetStrength) {
				checkargs(2);

				VEHICLE::_0xBCBFCD9D1DAC19E2((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setHeliBladesSpeed) {
				checkargs(2);

				VEHICLE::SET_HELI_BLADES_SPEED((::Vehicle)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setVehicleColor) {
				checkargs(3);

				VEHICLE::SET_VEHICLE_COLOURS((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}
			
			MOD_NATIVE(setVehicleDoorsLocked) {
				checkargs(2);

				VEHICLE::SET_VEHICLE_DOORS_LOCKED((::Vehicle)params[1], (BOOL)params[2]);

				return 1;
			}
			
			MOD_NATIVE(setVehicleTaxiLights) {
				checkargs(2);

				VEHICLE::SET_TAXI_LIGHTS((::Vehicle)params[1], (BOOL)params[2]);

				return 1;
			}

			MOD_NATIVE(getClosestVehicle) {
				checkargs(4);
				
				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				return VEHICLE::GET_CLOSEST_VEHICLE(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), amx_ctof(params[2]), params[3], params[4]);
			}

			MOD_NATIVE(getRandomVehicleInSphere) {
				checkargs(4);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				return VEHICLE::GET_RANDOM_VEHICLE_IN_SPHERE(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), amx_ctof(params[2]), params[3], params[4]);
			}

			MOD_NATIVE(getVehiclePedInSeat) {
				checkargs(2);

				return VEHICLE::GET_PED_IN_VEHICLE_SEAT((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleLastPedInSeat) {
				checkargs(2);

				return VEHICLE::GET_LAST_PED_IN_VEHICLE_SEAT((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleLightsState) {
				checkargs(3);
				
				cell *lightsOn, *highbeamsOn;
				if (amx_GetAddr(amx, params[2], &lightsOn) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &highbeamsOn) != AMX_ERR_NONE)
					return 0;


				return VEHICLE::GET_VEHICLE_LIGHTS_STATE((::Vehicle)params[1], lightsOn, highbeamsOn);
			}

			MOD_NATIVE(getVehicleNumberPlateText) {
				checkargs(1);

				String::set(amx, params[2], VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT((::Vehicle)params[1]), params[3]);

				return 1;
			}

			MOD_NATIVE(getVehicleClass) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_CLASS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleClassFromModel) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_CLASS_FROM_NAME((::Hash)params[1]);
			}

			MOD_NATIVE(getVehicleMod) {
				checkargs(2);

				return VEHICLE::GET_VEHICLE_MOD((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleModVariation) {
				checkargs(2);

				return VEHICLE::GET_VEHICLE_MOD_VARIATION((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleNumMods) {
				checkargs(2);

				return VEHICLE::GET_NUM_VEHICLE_MODS((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleModKit) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_MOD_KIT((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleModKitType) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_MOD_KIT_TYPE((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumModKits) {
				checkargs(1);

				return VEHICLE::GET_NUM_MOD_KITS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumModColors) {
				checkargs(2);

				return VEHICLE::GET_NUM_MOD_COLORS((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleModColor) {
				checkargs(5);

				cell *paintType, *color, *pearlescentColor;
				if (amx_GetAddr(amx, params[3], &paintType) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[4], &color) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[5], &pearlescentColor) != AMX_ERR_NONE)
					return 0;
					
				if (params[2] == 1)
					VEHICLE::GET_VEHICLE_MOD_COLOR_1((::Vehicle)params[1], paintType, color, pearlescentColor);
				else
					VEHICLE::GET_VEHICLE_MOD_COLOR_2((::Vehicle)params[1], paintType, color);

				return 1;
			}

			MOD_NATIVE(getVehicleModColorName) {
				checkargs(2);

				return 1;
			}

			MOD_NATIVE(getVehicleModTextLabel) {
				checkargs(5);

				String::set(amx, params[4], VEHICLE::GET_MOD_TEXT_LABEL((::Vehicle)params[1], params[2], params[3]), params[5]);

				return 1;
			}

			MOD_NATIVE(getVehicleModData) {
				checkargs(5);

				return VEHICLE::_0x4593CF82AA179706((::Vehicle)params[1], params[2], params[3]);
			}

			MOD_NATIVE(getVehicleLiveryName) {
				checkargs(4);

				String::set(amx, params[3], VEHICLE::GET_LIVERY_NAME((::Vehicle)params[1], params[2]), params[4]);

				return 1;
			}

			MOD_NATIVE(getVehicleWheelType) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_WHEEL_TYPE((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleLivery) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_LIVERY((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleLiveryCount) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_LIVERY_COUNT((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleTrailer) {
				checkargs(1);

				cell *vehicle;
				if (amx_GetAddr(amx, params[3], &vehicle) != AMX_ERR_NONE)
					return 0;

				return VEHICLE::GET_VEHICLE_TRAILER_VEHICLE((::Vehicle)params[1], vehicle);
			}

			MOD_NATIVE(getVehicleTyreSmokeColor) {
				checkargs(1);
				
				int r, g, b;
				VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR((::Vehicle)params[1], &r, &g, &b);

				return Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleWindowTint) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_WINDOW_TINT((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumWindowTints) {
				return VEHICLE::GET_NUM_VEHICLE_WINDOW_TINTS();
			}

			MOD_NATIVE(getVehicleColor) {
				checkargs(1);

				int r, g, b;
				VEHICLE::GET_VEHICLE_COLOR((::Vehicle)params[1], &r, &g, &b);

				return Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleColors) {
				checkargs(3);

				cell *primary, *secondary;
				if (amx_GetAddr(amx, params[2], &primary) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &secondary) != AMX_ERR_NONE)
					return 0;

				VEHICLE::GET_VEHICLE_COLOURS((::Vehicle)params[1], primary, secondary);

				return 1;
			}

			MOD_NATIVE(getVehicleNeonLightsColor) {
				checkargs(1);

				int r, g, b;
				VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR((::Vehicle)params[1], &r, &g, &b);

				return Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleCauseOfDestruction) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_CAUSE_OF_DESTRUCTION((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleOwner) {
				checkargs(2);

				cell *entity;
				if (amx_GetAddr(amx, params[2], &entity) != AMX_ERR_NONE)
					return 0;

				return VEHICLE::_GET_VEHICLE_OWNER((::Vehicle)params[1], (::Entity *)entity);
			}

			MOD_NATIVE(getVehiclePlateType) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_PLATE_TYPE((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleColorCombination) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_COLOUR_COMBINATION((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleNumberColors) {
				checkargs(1);

				return VEHICLE::GET_NUMBER_OF_VEHICLE_COLOURS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleExtraColors) {
				checkargs(3);

				cell *pearlescentColor, *wheelColor;
				if (amx_GetAddr(amx, params[2], &pearlescentColor) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &wheelColor) != AMX_ERR_NONE)
					return 0;

				VEHICLE::GET_VEHICLE_EXTRA_COLOURS((::Vehicle)params[1], pearlescentColor, wheelColor);

				return 1;
			}

			MOD_NATIVE(getVehicleDoorLockStatus) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_DOOR_LOCK_STATUS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehiclePedUsingDoor) {
				checkargs(2);

				return VEHICLE::_GET_PED_USING_VEHICLE_DOOR((::Vehicle)params[1], params[2]);
			}

			MOD_NATIVE(getVehicleNumberPlateTextIndex) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleAttachedToCargobob) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_ATTACHED_TO_CARGOBOB((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleAttachedToEntity) {
				checkargs(1);

				return VEHICLE::_0x375E7FC44F21C8AB((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleCustomPrimaryColor) {
				checkargs(1);

				int r, g, b;
				VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR((::Vehicle)params[1], &r, &g, &b);

				return Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleCustomSecondaryColor) {
				checkargs(1);

				int r, g, b;
				VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR((::Vehicle)params[1], &r, &g, &b);

				return Color(r, g, b, 255).RGBA;
			}

			MOD_NATIVE(getVehicleBodyHealth) {
				checkargs(1);

				float health = VEHICLE::GET_VEHICLE_BODY_HEALTH((::Vehicle)params[1]);

				return amx_ftoc(health);
			}

			MOD_NATIVE(getVehicleEngineHealth) {
				checkargs(1);

				float health = VEHICLE::GET_VEHICLE_ENGINE_HEALTH((::Vehicle)params[1]);

				return amx_ftoc(health);
			}

			MOD_NATIVE(getVehiclePetrolTankHealth) {
				checkargs(1);

				float health = VEHICLE::GET_VEHICLE_PETROL_TANK_HEALTH((::Vehicle)params[1]);

				return amx_ftoc(health);
			}

			MOD_NATIVE(getVehicleMaxSpeed) {
				checkargs(1);

				float speed = VEHICLE::_GET_VEHICLE_MAX_SPEED((::Vehicle)params[1]);

				return amx_ftoc(speed);
			}

			MOD_NATIVE(getVehicleMaxBraking) {
				checkargs(1);

				float braking = VEHICLE::GET_VEHICLE_MAX_BRAKING((::Vehicle)params[1]);

				return amx_ftoc(braking);
			}

			MOD_NATIVE(getVehicleMaxTraction) {
				checkargs(1);

				float traction = VEHICLE::GET_VEHICLE_MAX_TRACTION((::Vehicle)params[1]);

				return amx_ftoc(traction);
			}

			MOD_NATIVE(getVehicleAcceleration) {
				checkargs(1);

				float accel = VEHICLE::GET_VEHICLE_ACCELERATION((::Vehicle)params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleModelMaxSpeed) {
				checkargs(1);

				float speed = VEHICLE::_GET_VEHICLE_MAX_SPEED((::Vehicle)params[1]);

				return amx_ftoc(speed);
			}

			MOD_NATIVE(getVehicleModelMaxBraking) {
				checkargs(1);

				float braking = VEHICLE::GET_VEHICLE_MODEL_MAX_BRAKING((::Hash)params[1]);

				return amx_ftoc(braking);
			}

			MOD_NATIVE(getVehicleModelMaxTraction) {
				checkargs(1);

				float traction = VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION((::Hash)params[1]);

				return amx_ftoc(traction);
			}

			MOD_NATIVE(getVehicleModelMaxKnots) {
				checkargs(1);

				float knots = VEHICLE::_0xC6AD107DDC9054CC((::Hash)params[1]);

				return amx_ftoc(knots);
			}

			MOD_NATIVE(getVehicleModelAcceleration) {
				checkargs(1);

				float accel = VEHICLE::GET_VEHICLE_MODEL_ACCELERATION((::Hash)params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleModelHandBrake) {
				checkargs(1);

				float handbrake = VEHICLE::_0xBFBA3BA79CFF7EBF((::Hash)params[1]);

				return amx_ftoc(handbrake);
			}

			MOD_NATIVE(getVehicleModelDownForce) {
				checkargs(1);

				float downForce = VEHICLE::_0x53409B5163D5B846((::Hash)params[1]);

				return amx_ftoc(downForce);
			}

			MOD_NATIVE(getVehicleModelMoveResistance) {
				checkargs(1);

				float resist = VEHICLE::_0x5AA3F878A178C4FC((::Hash)params[1]);

				return amx_ftoc(resist);
			}

			MOD_NATIVE(getVehicleClassMaxSpeed) {
				checkargs(1);

				float accel = VEHICLE::_0x00C09F246ABEDD82(params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleClassMaxTraction) {
				checkargs(1);

				float traction = VEHICLE::GET_VEHICLE_CLASS_MAX_TRACTION(params[1]);

				return amx_ftoc(traction);
			}

			MOD_NATIVE(getVehicleClassMaxBraking) {
				checkargs(1);

				float braking = VEHICLE::GET_VEHICLE_CLASS_MAX_BRAKING(params[1]);

				return amx_ftoc(braking);
			}

			MOD_NATIVE(getVehicleClassMaxAgility) {
				checkargs(1);

				float agility = VEHICLE::GET_VEHICLE_CLASS_MAX_AGILITY(params[1]);

				return amx_ftoc(agility);
			}

			MOD_NATIVE(getVehicleClassMaxAcceleration) {
				checkargs(1);

				float accel = VEHICLE::GET_VEHICLE_CLASS_MAX_ACCELERATION(params[1]);

				return amx_ftoc(accel);
			}

			MOD_NATIVE(getVehicleModModifierValue) {
				checkargs(3);

				float value = VEHICLE::GET_VEHICLE_MOD_MODIFIER_VALUE((::Vehicle)params[1], params[2], params[3]);

				return amx_ftoc(value);
			}

			MOD_NATIVE(getVehicleDoorAngleRatio) {
				checkargs(2);

				float ratio = VEHICLE::GET_VEHICLE_DOOR_ANGLE_RATIO((::Vehicle)params[1], params[2]);

				return amx_ftoc(ratio);
			}

			MOD_NATIVE(getVehicleDirtLevel) {
				checkargs(1);

				float level = VEHICLE::GET_VEHICLE_DIRT_LEVEL((::Vehicle)params[1]);

				return amx_ftoc(level);
			}

			MOD_NATIVE(getVehiclePassengers) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_NUMBER_OF_PASSENGERS((::Vehicle)params[1]);
			}

			MOD_NATIVE(getVehicleMaxPassengers) {
				checkargs(1);

				return VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS((::Vehicle)params[1]);
			}
			
			MOD_NATIVE(getVehicleModelNumberOfSeats) {
				checkargs(1);

				return VEHICLE::_GET_VEHICLE_MODEL_MAX_NUMBER_OF_PASSENGERS((::Hash)params[1]);
			}
			
			MOD_NATIVE(getDisplayNameFromVehicleModel) {
				checkargs(3);

				cell *dest;
				if (amx_GetAddr(amx, params[2], &dest) != AMX_ERR_NONE)
					return 0;
				
				amx_SetString(dest, VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((::Hash)params[1]), NULL, NULL, params[3]);

				return 1;
			}

			MOD_NATIVE(removeVehicleMod) {
				checkargs(2);

				VEHICLE::REMOVE_VEHICLE_MOD((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(resetVehicleWheels) {
				checkargs(2);

				VEHICLE::RESET_VEHICLE_WHEELS((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(requestVehicleHighDetailModel) {
				checkargs(1);

				VEHICLE::REQUEST_VEHICLE_HIGH_DETAIL_MODEL((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(removeVehicleHighDetailModel) {
				checkargs(1);

				VEHICLE::REMOVE_VEHICLE_HIGH_DETAIL_MODEL((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(requestVehicleAsset) {
				checkargs(2);

				VEHICLE::REQUEST_VEHICLE_ASSET((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(removeVehicleAsset) {
				checkargs(1);

				VEHICLE::REMOVE_VEHICLE_ASSET((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(rollUpWindow) {
				checkargs(2);

				VEHICLE::ROLL_UP_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(rollDownWindow) {
				checkargs(2);

				VEHICLE::ROLL_DOWN_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(rollDownWindows) {
				checkargs(1);

				VEHICLE::ROLL_DOWN_WINDOWS((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(smashVehicleWindow) {
				checkargs(2);

				VEHICLE::SMASH_VEHICLE_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(fixVehicleWindow) {
				checkargs(2);

				VEHICLE::FIX_VEHICLE_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(removeVehicleWindow) {
				checkargs(2);

				VEHICLE::REMOVE_VEHICLE_WINDOW((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(releasePreloadMods) {
				checkargs(1);

				VEHICLE::RELEASE_PRELOAD_MODS((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(reloadVehicleMod) {
				checkargs(3);

				VEHICLE::PRELOAD_VEHICLE_MOD((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(toggleVehicleMod) {
				checkargs(3);

				VEHICLE::TOGGLE_VEHICLE_MOD((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(clearVehicleCustomPrimaryColor) {
				checkargs(1);

				VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(clearVehicleCustomSecondColor) {
				checkargs(1);

				VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(enableCargobobHook) {
				checkargs(2);

				VEHICLE::_ENABLE_CARGOBOB_HOOK((::Vehicle)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(retractCargobobHook) {
				checkargs(1);

				VEHICLE::_RETRACT_CARGOBOB_HOOK((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(attachVehicleToCargobob) {
				checkargs(4);
				
				cell *coords;
				if (amx_GetAddr(amx, params[4], &coords) != AMX_ERR_NONE)
					return 0;

				VEHICLE::ATTACH_VEHICLE_TO_CARGOBOB((::Vehicle)params[1], params[2], params[3], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]));

				return 1;
			}

			MOD_NATIVE(detachVehicleFromCargobob) {
				checkargs(2);

				VEHICLE::DETACH_VEHICLE_FROM_CARGOBOB((::Vehicle)params[1], (::Vehicle)params[2]);

				return 1;
			}

			MOD_NATIVE(detachVehicleFromAnyCargobob) {
				checkargs(1);

				VEHICLE::DETACH_VEHICLE_FROM_ANY_CARGOBOB((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(requestVehicleScaleformMovie) {
				checkargs(1);

				VEHICLE::_0xDBA3C090E3D74690((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(startVehicleAlarm) {
				checkargs(1);

				VEHICLE::START_VEHICLE_ALARM((::Vehicle)params[1]);

				return 1;
			}

			MOD_NATIVE(explodeVehicle) {
				checkargs(3);

				VEHICLE::EXPLODE_VEHICLE((::Vehicle)params[1], params[2], params[3]);

				return 1;
			}
		};
	};
};