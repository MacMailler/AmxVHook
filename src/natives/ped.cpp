#include "ped.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Ped {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createPed)
				MOD_DEFINE_NATIVE(createPedInVehicle)
				MOD_DEFINE_NATIVE(createRandomPed)
				MOD_DEFINE_NATIVE(clonePed)
				MOD_DEFINE_NATIVE(deletePed)
				MOD_DEFINE_NATIVE(isPedMale)
				MOD_DEFINE_NATIVE(isPedHuman)
				MOD_DEFINE_NATIVE(isPedHurt)
				MOD_DEFINE_NATIVE(isPedInjured)
				MOD_DEFINE_NATIVE(isPedFatallyInjured)
				MOD_DEFINE_NATIVE(isPedAPlayer)
				MOD_DEFINE_NATIVE(isPedReloading)
				MOD_DEFINE_NATIVE(isPedDead)
				MOD_DEFINE_NATIVE(isPedArmed)
				MOD_DEFINE_NATIVE(isPedSwimming)
				MOD_DEFINE_NATIVE(isPedSwimmingUnderWater)
				MOD_DEFINE_NATIVE(isPedTracked)
				MOD_DEFINE_NATIVE(isPedRagdoll)
				MOD_DEFINE_NATIVE(isPedStopped)
				MOD_DEFINE_NATIVE(isPedShooting)
				MOD_DEFINE_NATIVE(isPedFalling)
				MOD_DEFINE_NATIVE(isPedJumping)
				MOD_DEFINE_NATIVE(isPedClimbing)
				MOD_DEFINE_NATIVE(isPedHearPlayer)
				MOD_DEFINE_NATIVE(isPedVaulting)
				MOD_DEFINE_NATIVE(isPedDiving)
				MOD_DEFINE_NATIVE(isPedJacking)
				MOD_DEFINE_NATIVE(isPedFleeing)
				MOD_DEFINE_NATIVE(isPedJumpingOutOfVehicle)
				MOD_DEFINE_NATIVE(isPedOnFoot)
				MOD_DEFINE_NATIVE(isPedOnMount)
				MOD_DEFINE_NATIVE(isPedOnVehicle)
				MOD_DEFINE_NATIVE(isPedOnAnyVehicle)
				MOD_DEFINE_NATIVE(isPedOnAnyBike)
				MOD_DEFINE_NATIVE(isPedInCover)
				MOD_DEFINE_NATIVE(isPedInCombat)
				MOD_DEFINE_NATIVE(isPedInMeleeComabat)
				MOD_DEFINE_NATIVE(isPedInAnyBoat)
				MOD_DEFINE_NATIVE(isPedInAnyHeli)
				MOD_DEFINE_NATIVE(isPedInAnyPlane)
				MOD_DEFINE_NATIVE(isPedInAnyTaxi)
				MOD_DEFINE_NATIVE(isPedInAnyTrain)
				MOD_DEFINE_NATIVE(isPedInAnyVehicle)
				MOD_DEFINE_NATIVE(isPedInVehicle)
				MOD_DEFINE_NATIVE(isPedSittingInAnyVehicle)
				MOD_DEFINE_NATIVE(isPedInPoliceVehicle)
				MOD_DEFINE_NATIVE(isPedInFlyingVehicle)
				MOD_DEFINE_NATIVE(isPedFacingPed)
				MOD_DEFINE_NATIVE(isPedModel)
				MOD_DEFINE_NATIVE(isPedCurrentWeaponSilenced)
				MOD_DEFINE_NATIVE(isPedWeaponReadyToShoot)
				MOD_DEFINE_NATIVE(isPedBeenDamagedByWeapon)
				MOD_DEFINE_NATIVE(isPedRunningRagdollTask)
				MOD_DEFINE_NATIVE(isPedRunningMobilePhoneTask)
				MOD_DEFINE_NATIVE(getPedType)
				MOD_DEFINE_NATIVE(getPedKiller)
				MOD_DEFINE_NATIVE(getPedCauseOfDeath)
				MOD_DEFINE_NATIVE(getPedJacker)
				MOD_DEFINE_NATIVE(getPedJackTarget)
				MOD_DEFINE_NATIVE(getPedAccuracy)
				MOD_DEFINE_NATIVE(getPedAlertness)
				MOD_DEFINE_NATIVE(getPedParachuteState)
				MOD_DEFINE_NATIVE(getPedParachuteLandingType)
				MOD_DEFINE_NATIVE(getPedArmor)
				MOD_DEFINE_NATIVE(getPedMaxHealth)
				MOD_DEFINE_NATIVE(getPedVehicle)
				MOD_DEFINE_NATIVE(getPedCurrentWeapon)
				MOD_DEFINE_NATIVE(getPedCurrentVehicleWeapon)
				MOD_DEFINE_NATIVE(getPedMaxAmmo)
				MOD_DEFINE_NATIVE(getPedAmmoInClip)
				MOD_DEFINE_NATIVE(getPedMaxAmmoInClip)
				MOD_DEFINE_NATIVE(getPedAmmoInWeapon)
				MOD_DEFINE_NATIVE(getPedSelectedWeapon)
				MOD_DEFINE_NATIVE(getPedBestWeapon)
				MOD_DEFINE_NATIVE(getCurrentPedWeaponEntityIndex)
				MOD_DEFINE_NATIVE(getPedWeaponTypeInSlot)
				MOD_DEFINE_NATIVE(getPedMaxRangeOfCurrentWeapon)
				MOD_DEFINE_NATIVE(setPedArmor)
				MOD_DEFINE_NATIVE(setPedAsCop)
				MOD_DEFINE_NATIVE(setPedAsEnemy)
				MOD_DEFINE_NATIVE(setPedMaxHealth)
				MOD_DEFINE_NATIVE(setPedMaxTimeInWater)
				MOD_DEFINE_NATIVE(setPedMaxTimeUnderwater)
				MOD_DEFINE_NATIVE(setPedShootRate)
				MOD_DEFINE_NATIVE(setPedAlertness)
				MOD_DEFINE_NATIVE(setPedAccuracy)
				MOD_DEFINE_NATIVE(setPedIntoVehicle)
				MOD_DEFINE_NATIVE(setPedAmmo)
				MOD_DEFINE_NATIVE(setPedAmmoInClip)
				MOD_DEFINE_NATIVE(setPedInfiniteAmmo)
				MOD_DEFINE_NATIVE(setPedInfiniteAmmoInClip)
				MOD_DEFINE_NATIVE(setPedCurrentWeapon)
				MOD_DEFINE_NATIVE(setPedCurrentVehicleWeapon)
				MOD_DEFINE_NATIVE(setPedCurrentWeaponVisible)
				MOD_DEFINE_NATIVE(setPedDropsWeaponsWhenDead)
				MOD_DEFINE_NATIVE(setPedHearingRange)
				MOD_DEFINE_NATIVE(setPedSeeingRange)
				MOD_DEFINE_NATIVE(setPedGravity)
				MOD_DEFINE_NATIVE(setPedDropsWeapon)
				MOD_DEFINE_NATIVE(setPedDropsInventoryWeapon)
				MOD_DEFINE_NATIVE(addPedAmmo)
				MOD_DEFINE_NATIVE(addPedArmor)
				MOD_DEFINE_NATIVE(givePedWeapon)
				MOD_DEFINE_NATIVE(givePedDelayedWeapon)
				MOD_DEFINE_NATIVE(givePedDamage)
				MOD_DEFINE_NATIVE(removePedWeapon)
				MOD_DEFINE_NATIVE(removePedWeapons)
				MOD_DEFINE_NATIVE(clearPedLastWeaponDamage)
				MOD_DEFINE_NATIVE(hidePedWeaponForCutscene)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createPed) {
				checkargs(4);

				cell *coords;
				if (amx_GetAddr(amx, params[3], &coords) != AMX_ERR_NONE)
					return 0;

				return PED::CREATE_PED(
					params[1], params[2],
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					amx_ctof(params[4]),
					FALSE, TRUE
				);
			}

			MOD_NATIVE(createPedInVehicle) {
				checkargs(4);

				return PED::CREATE_PED_INSIDE_VEHICLE((::Vehicle)params[1], params[2], params[3], params[4], FALSE, TRUE);
			}

			MOD_NATIVE(createRandomPed) {
				checkargs(1);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				return PED::CREATE_RANDOM_PED(amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]));
			}

			MOD_NATIVE(clonePed) {
				checkargs(2);

				return PED::CLONE_PED(params[1], amx_ctof(params[2]), FALSE, TRUE);
			}

			MOD_NATIVE(deletePed) {
				checkargs(1);

				::Ped ped = params[1];
				PED::DELETE_PED(&ped);

				return 1;
			}

			MOD_NATIVE(isPedMale) {
				checkargs(1);

				return PED::IS_PED_MALE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedHuman) {
				checkargs(1);

				return PED::IS_PED_HUMAN((::Ped)params[1]);
			}

			MOD_NATIVE(isPedHurt) {
				checkargs(1);

				return PED::IS_PED_HURT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInjured) {
				checkargs(1);

				return PED::IS_PED_INJURED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFatallyInjured) {
				checkargs(1);

				return PED::IS_PED_FATALLY_INJURED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedAPlayer) {
				checkargs(1);

				return PED::IS_PED_A_PLAYER((::Ped)params[1]);
			}

			MOD_NATIVE(isPedReloading) {
				checkargs(1);

				return PED::IS_PED_RELOADING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedDead) {
				checkargs(1);

				return PED::IS_PED_DEAD_OR_DYING((::Ped)params[1], TRUE);
			}

			MOD_NATIVE(isPedArmed) {
				checkargs(3);

				return WEAPON::IS_PED_ARMED((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(isPedSwimming) {
				checkargs(1);

				return PED::IS_PED_SWIMMING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedSwimmingUnderWater) {
				checkargs(1);

				return PED::IS_PED_SWIMMING_UNDER_WATER((::Ped)params[1]);
			}

			MOD_NATIVE(isPedTracked) {
				checkargs(1);

				return PED::IS_PED_TRACKED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedRagdoll) {
				checkargs(1);

				return PED::IS_PED_RAGDOLL((::Ped)params[1]);
			}

			MOD_NATIVE(isPedStopped) {
				checkargs(1);

				return PED::IS_PED_STOPPED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedShooting) {
				checkargs(1);

				return PED::IS_PED_SHOOTING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFalling) {
				checkargs(1);

				return PED::IS_PED_FALLING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedClimbing) {
				checkargs(1);

				return PED::IS_PED_CLIMBING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedHearPlayer) {
				checkargs(1);

				return PLAYER::CAN_PED_HEAR_PLAYER(PLAYER::PLAYER_ID(), (::Ped)params[1]);
			}

			MOD_NATIVE(isPedVaulting) {
				checkargs(1);

				return PED::IS_PED_VAULTING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedDiving) {
				checkargs(1);

				return PED::IS_PED_DIVING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedJacking) {
				checkargs(1);

				return PED::IS_PED_JACKING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFleeing) {
				checkargs(1);

				return PED::IS_PED_FLEEING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedJumping) {
				checkargs(1);

				return PED::IS_PED_JUMPING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedJumpingOutOfVehicle) {
				checkargs(1);

				return PED::IS_PED_JUMPING_OUT_OF_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnFoot) {
				checkargs(1);

				return PED::IS_PED_ON_FOOT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnMount) {
				checkargs(1);

				return PED::IS_PED_ON_MOUNT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnVehicle) {
				checkargs(2);

				return PED::IS_PED_ON_SPECIFIC_VEHICLE((::Ped)params[1], (::Vehicle)params[2]);
			}

			MOD_NATIVE(isPedOnAnyVehicle) {
				checkargs(1);

				return PED::IS_PED_ON_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnAnyBike) {
				checkargs(1);

				return PED::IS_PED_ON_ANY_BIKE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyBoat) {
				checkargs(1);

				return PED::IS_PED_IN_ANY_BOAT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyHeli) {
				checkargs(1);

				return PED::IS_PED_IN_ANY_HELI((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyTaxi) {
				checkargs(1);

				return PED::IS_PED_IN_ANY_TAXI((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyPlane) {
				checkargs(1);

				return PED::IS_PED_IN_ANY_PLANE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyTrain) {
				checkargs(1);

				return PED::IS_PED_IN_ANY_TRAIN((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyVehicle) {
				checkargs(2);

				return PED::IS_PED_IN_ANY_VEHICLE((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(isPedSittingInAnyVehicle) {
				checkargs(1);

				return PED::IS_PED_SITTING_IN_ANY_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInFlyingVehicle) {
				checkargs(1);

				return PED::IS_PED_IN_FLYING_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInVehicle) {
				checkargs(3);

				return PED::IS_PED_IN_VEHICLE((::Ped)params[1], (::Vehicle)params[2], params[3]);
			}

			MOD_NATIVE(isPedInPoliceVehicle) {
				checkargs(1);

				return PED::IS_PED_IN_ANY_POLICE_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInCombat) {
				checkargs(2);

				return PED::IS_PED_IN_COMBAT((::Ped)params[1], (::Ped)params[2]);
			}

			MOD_NATIVE(isPedInCover) {
				checkargs(1);

				return PED::IS_PED_IN_COVER((::Ped)params[1], 0);
			}

			MOD_NATIVE(isPedInMeleeComabat) {
				checkargs(1);

				return PED::IS_PED_IN_MELEE_COMBAT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFacingPed) {
				checkargs(3);

				return PED::IS_PED_FACING_PED((::Ped)params[1], (::Ped)params[2], amx_ctof(params[3]));
			}

			MOD_NATIVE(isPedModel) {
				checkargs(2);

				return PED::IS_PED_MODEL((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(isPedCurrentWeaponSilenced) {
				checkargs(1);

				return WEAPON::IS_PED_CURRENT_WEAPON_SILENCED((::Ped)params[1]);
			}
			
			MOD_NATIVE(isPedWeaponReadyToShoot) {
				checkargs(1);

				return WEAPON::IS_PED_WEAPON_READY_TO_SHOOT((::Ped)params[1]);
			}
			
			MOD_NATIVE(isPedBeenDamagedByWeapon) {
				checkargs(3);

				return WEAPON::HAS_PED_BEEN_DAMAGED_BY_WEAPON((::Ped)params[1], params[2], params[3]);
			}
			
			MOD_NATIVE(isPedRunningRagdollTask) {
				checkargs(1);

				return PED::IS_PED_RUNNING_RAGDOLL_TASK((::Ped)params[1]);
			}
			
			MOD_NATIVE(isPedRunningMobilePhoneTask) {
				checkargs(1);

				return PED::IS_PED_RUNNING_MOBILE_PHONE_TASK((::Ped)params[1]);
			}

			MOD_NATIVE(getPedType) {
				checkargs(1);

				return PED::GET_PED_TYPE((::Ped)params[1]);
			}

			MOD_NATIVE(getPedKiller) {
				checkargs(1);

				return PED::_GET_PED_KILLER((::Ped)params[1]);
			}

			MOD_NATIVE(getPedCauseOfDeath) {
				checkargs(1);

				return PED::_GET_PED_KILLER((::Ped)params[1]);
			}

			MOD_NATIVE(getPedJacker) {
				checkargs(1);

				return PED::GET_PEDS_JACKER((::Ped)params[1]);
			}

			MOD_NATIVE(getPedJackTarget) {
				checkargs(1);

				return PED::GET_JACK_TARGET((::Ped)params[1]);
			}

			MOD_NATIVE(getPedAccuracy) {
				checkargs(1);

				return PED::GET_PED_ACCURACY((::Ped)params[1]);
			}

			MOD_NATIVE(getPedAlertness) {
				checkargs(1);

				return PED::GET_PED_ALERTNESS((::Ped)params[1]);
			}

			MOD_NATIVE(getPedParachuteState) {
				checkargs(1);

				return PED::GET_PED_PARACHUTE_STATE((::Ped)params[1]);
			}

			MOD_NATIVE(getPedParachuteLandingType) {
				checkargs(1);

				return PED::GET_PED_PARACHUTE_LANDING_TYPE((::Ped)params[1]);
			}

			MOD_NATIVE(getPedArmor) {
				checkargs(1);

				return PED::GET_PED_ARMOUR((::Ped)params[1]);
			}

			MOD_NATIVE(getPedMaxHealth) {
				checkargs(1);

				return PED::GET_PED_MAX_HEALTH((::Ped)params[1]);
			}

			MOD_NATIVE(getPedMoney) {
				checkargs(1);

				return PED::GET_PED_MONEY((::Ped)params[1]);
			}

			MOD_NATIVE(getPedBoneIndex) {
				checkargs(2);

				return PED::GET_PED_BONE_INDEX((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(getPedVehicle) {
				checkargs(2);

				return PED::GET_VEHICLE_PED_IS_IN((::Ped)params[1], (BOOL)params[2]);
			}

			MOD_NATIVE(getPedMaxAmmo) {
				checkargs(2);

				cell * ammo;
				if (amx_GetAddr(amx, params[3], &ammo) != AMX_ERR_NONE)
					return 0;

				return WEAPON::GET_MAX_AMMO((::Ped)params[1], (Hash)params[2], (int *)ammo);
			}

			MOD_NATIVE(getPedAmmoInClip) {
				checkargs(3);

				cell * ammo;
				if (amx_GetAddr(amx, params[3], &ammo) != AMX_ERR_NONE)
					return 0;
				
				return WEAPON::GET_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], (int *)ammo);
			}
			
			MOD_NATIVE(getPedMaxAmmoInClip) {
				checkargs(2);

				return WEAPON::GET_MAX_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], TRUE);
			}

			MOD_NATIVE(getPedCurrentWeapon) {
				checkargs(2);

				cell * weapon;
				if (amx_GetAddr(amx, params[2], &weapon) != AMX_ERR_NONE)
					return 0;

				return WEAPON::GET_CURRENT_PED_WEAPON((::Ped)params[1], (Hash *)weapon, 1);
			}

			MOD_NATIVE(getPedCurrentVehicleWeapon) {
				checkargs(2);

				cell * weapon;
				if (amx_GetAddr(amx, params[2], &weapon) != AMX_ERR_NONE)
					return 0;

				return WEAPON::GET_CURRENT_PED_VEHICLE_WEAPON((::Ped)params[1], (Hash *)weapon);
			}

			MOD_NATIVE(getPedAmmoInWeapon) {
				checkargs(2);

				return WEAPON::GET_AMMO_IN_PED_WEAPON((::Ped)params[1], (Hash)params[2]);
			}

			MOD_NATIVE(getPedSelectedWeapon) {
				checkargs(1);

				return WEAPON::GET_SELECTED_PED_WEAPON((::Ped)params[1]);
			}

			MOD_NATIVE(getPedBestWeapon) {
				checkargs(1);

				return WEAPON::GET_BEST_PED_WEAPON((::Ped)params[1], FALSE);
			}
			
			MOD_NATIVE(getCurrentPedWeaponEntityIndex) {
				checkargs(1);

				return WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX((::Ped)params[1]);
			}
			
			MOD_NATIVE(getPedWeaponTypeInSlot) {
				checkargs(2);

				return WEAPON::GET_PED_WEAPONTYPE_IN_SLOT((::Ped)params[1], params[2]);
			}
			
			MOD_NATIVE(getPedMaxRangeOfCurrentWeapon) {
				checkargs(1);

				float range = WEAPON::GET_MAX_RANGE_OF_CURRENT_PED_WEAPON((::Ped)params[1]);

				return amx_ftoc(range);
			}

			MOD_NATIVE(setPedArmor) {
				checkargs(2);

				PED::SET_PED_ARMOUR((::Ped)params[1], params[2]);
				return 1;
			}

			MOD_NATIVE(setPedAsCop) {
				checkargs(2);

				PED::SET_PED_AS_COP((::Ped)params[1], (BOOL)params[2]);
				return 1;
			}

			MOD_NATIVE(setPedAsEnemy) {
				checkargs(2);

				PED::SET_PED_AS_ENEMY((::Ped)params[1], (BOOL)params[2]);
				return 1;
			}


			MOD_NATIVE(setPedMaxHealth) {
				checkargs(2);

				PED::SET_PED_MAX_HEALTH((::Ped)params[1], params[2]);
				return 1;
			}

			MOD_NATIVE(setPedMaxTimeInWater) {
				checkargs(2);

				PED::SET_PED_MAX_TIME_IN_WATER((::Ped)params[1], amx_ctof(params[2]));
				return 1;
			}

			MOD_NATIVE(setPedMaxTimeUnderwater) {
				checkargs(2);

				PED::SET_PED_MAX_TIME_UNDERWATER((::Ped)params[1], amx_ctof(params[2]));
				return 1;
			}

			MOD_NATIVE(setPedIntoVehicle) {
				checkargs(3);

				PED::SET_PED_INTO_VEHICLE((::Ped)params[1], (::Vehicle)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedShootRate) {
				checkargs(2);

				PED::SET_PED_SHOOT_RATE((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedAccuracy) {
				checkargs(2);

				PED::SET_PED_ACCURACY((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedAlertness) {
				checkargs(2);

				PED::SET_PED_ALERTNESS((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedAmmo) {
				checkargs(3);

				WEAPON::SET_PED_AMMO((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedAmmoInClip) {
				checkargs(3);

				WEAPON::SET_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedInfiniteAmmo) {
				checkargs(3);

				WEAPON::SET_PED_INFINITE_AMMO((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedInfiniteAmmoInClip) {
				checkargs(2);

				WEAPON::SET_PED_INFINITE_AMMO_CLIP((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedCurrentWeapon) {
				checkargs(3);

				WEAPON::SET_CURRENT_PED_WEAPON((::Ped)params[1], (Hash)params[2], params[3]);
				
				return 1;
			}

			MOD_NATIVE(setPedCurrentVehicleWeapon) {
				checkargs(2);

				return WEAPON::SET_CURRENT_PED_VEHICLE_WEAPON((::Ped)params[1], (Hash)params[2]);
			}

			MOD_NATIVE(setPedCurrentWeaponVisible) {
				checkargs(5);

				WEAPON::SET_PED_CURRENT_WEAPON_VISIBLE((::Ped)params[1], params[2], params[3], params[4], params[5]);

				return 1;
			}
			
			MOD_NATIVE(setPedDropsWeaponsWhenDead) {
				checkargs(2);

				WEAPON::SET_PED_DROPS_WEAPONS_WHEN_DEAD((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedHearingRange) {
				checkargs(2);

				PED::SET_PED_HEARING_RANGE((::Ped)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setPedSeeingRange) {
				checkargs(2);

				PED::SET_PED_SEEING_RANGE((::Ped)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setPedGravity) {
				checkargs(2);

				PED::SET_PED_GRAVITY((::Ped)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setPedDropsWeapon) {
				checkargs(1);

				WEAPON::SET_PED_DROPS_WEAPON((::Ped)params[1]);

				return 1;
			}
			
			MOD_NATIVE(setPedDropsInventoryWeapon) {
				checkargs(4);

				cell *offset;
				if (amx_GetAddr(amx, params[3], &offset) != AMX_ERR_NONE)
					return 0;

				WEAPON::SET_PED_DROPS_INVENTORY_WEAPON(
					(::Ped)params[1], params[2],
					amx_ctof(offset[0]), amx_ctof(offset[1]), amx_ctof(offset[2]),
					params[4]
				);

				return 1;
			}

			MOD_NATIVE(addPedAmmo) {
				checkargs(3);

				WEAPON::ADD_AMMO_TO_PED((::Ped)params[1], params[2], params[3]);

				return 1;
			}


			MOD_NATIVE(addPedArmor) {
				checkargs(2);

				PED::ADD_ARMOUR_TO_PED((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(givePedWeapon) {
				checkargs(4);

				WEAPON::GIVE_WEAPON_TO_PED((::Ped)params[1], params[2], params[3], 0, params[4]);

				return 1;
			}
			
			MOD_NATIVE(givePedDelayedWeapon) {
				checkargs(4);

				WEAPON::GIVE_DELAYED_WEAPON_TO_PED((::Ped)params[1], params[2], params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(givePedDamage) {
				checkargs(3);

				PED::APPLY_DAMAGE_TO_PED((::Ped)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(removePedWeapon) {
				checkargs(2);

				WEAPON::REMOVE_WEAPON_FROM_PED((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(removePedWeapons) {
				checkargs(1);

				WEAPON::REMOVE_ALL_PED_WEAPONS((::Ped)params[1], FALSE);

				return 1;
			}
			
			MOD_NATIVE(clearPedLastWeaponDamage) {
				checkargs(1);

				WEAPON::CLEAR_PED_LAST_WEAPON_DAMAGE((::Ped)params[1]);

				return 1;
			}

			MOD_NATIVE(hidePedWeaponForCutscene) {
				checkargs(2);

				WEAPON::HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE((::Ped)params[1], params[2]);

				return 1;
			}
		};
	};
};