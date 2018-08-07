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
				if (!arguments(4))
					return -1;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[3], coords, 3))
					return 0;

				return PED::CREATE_PED(params[1], params[2], coords[0], coords[1], coords[2], amx_ctof(params[4]), FALSE, TRUE);
			}

			MOD_NATIVE(createPedInVehicle) {
				if (!arguments(4))
					return -1;

				return PED::CREATE_PED_INSIDE_VEHICLE((::Vehicle)params[1], params[2], params[3], params[4], FALSE, TRUE);
			}

			MOD_NATIVE(createRandomPed) {
				if (!arguments(1))
					return -1;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				return PED::CREATE_RANDOM_PED(coords[0], coords[1], coords[2]);
			}

			MOD_NATIVE(clonePed) {
				if (!arguments(2))
					return 0;

				return PED::CLONE_PED(params[1], amx_ctof(params[2]), FALSE, TRUE);
			}

			MOD_NATIVE(deletePed) {
				if (!arguments(1))
					return 0;

				::Ped ped = params[1];
				PED::DELETE_PED(&ped);

				return 1;
			}

			MOD_NATIVE(isPedMale) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_MALE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedHuman) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_HUMAN((::Ped)params[1]);
			}

			MOD_NATIVE(isPedHurt) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_HURT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInjured) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_INJURED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFatallyInjured) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_FATALLY_INJURED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedAPlayer) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_A_PLAYER((::Ped)params[1]);
			}

			MOD_NATIVE(isPedReloading) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_RELOADING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedDead) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_DEAD_OR_DYING((::Ped)params[1], TRUE);
			}

			MOD_NATIVE(isPedArmed) {
				if (!arguments(3))
					return 0;

				return WEAPON::IS_PED_ARMED((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(isPedSwimming) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SWIMMING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedSwimmingUnderWater) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SWIMMING_UNDER_WATER((::Ped)params[1]);
			}

			MOD_NATIVE(isPedTracked) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_TRACKED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedRagdoll) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_RAGDOLL((::Ped)params[1]);
			}

			MOD_NATIVE(isPedStopped) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_STOPPED((::Ped)params[1]);
			}

			MOD_NATIVE(isPedShooting) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SHOOTING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFalling) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_FALLING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedClimbing) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_CLIMBING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedHearPlayer) {
				if (!arguments(1))
					return 0;

				return PLAYER::CAN_PED_HEAR_PLAYER(PLAYER::PLAYER_ID(), (::Ped)params[1]);
			}

			MOD_NATIVE(isPedVaulting) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_VAULTING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedDiving) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_DIVING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedJacking) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_JACKING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFleeing) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_FLEEING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedJumping) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_JUMPING((::Ped)params[1]);
			}

			MOD_NATIVE(isPedJumpingOutOfVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_JUMPING_OUT_OF_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnFoot) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_FOOT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnMount) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_MOUNT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnVehicle) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_ON_SPECIFIC_VEHICLE((::Ped)params[1], (::Vehicle)params[2]);
			}

			MOD_NATIVE(isPedOnAnyVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedOnAnyBike) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_ANY_BIKE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyBoat) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_BOAT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyHeli) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_HELI((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyTaxi) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_TAXI((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyPlane) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_PLANE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyTrain) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_TRAIN((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInAnyVehicle) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_IN_ANY_VEHICLE((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(isPedSittingInAnyVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SITTING_IN_ANY_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInFlyingVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_FLYING_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInVehicle) {
				if (!arguments(3))
					return 0;

				return PED::IS_PED_IN_VEHICLE((::Ped)params[1], (::Vehicle)params[2], params[3]);
			}

			MOD_NATIVE(isPedInPoliceVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_POLICE_VEHICLE((::Ped)params[1]);
			}

			MOD_NATIVE(isPedInCombat) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_IN_COMBAT((::Ped)params[1], (::Ped)params[2]);
			}

			MOD_NATIVE(isPedInCover) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_COVER((::Ped)params[1], 0);
			}

			MOD_NATIVE(isPedInMeleeComabat) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_MELEE_COMBAT((::Ped)params[1]);
			}

			MOD_NATIVE(isPedFacingPed) {
				if (!arguments(3))
					return 0;

				return PED::IS_PED_FACING_PED((::Ped)params[1], (::Ped)params[2], amx_ctof(params[3]));
			}

			MOD_NATIVE(isPedModel) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_MODEL((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(isPedCurrentWeaponSilenced) {
				if (!arguments(1))
					return 0;

				return WEAPON::IS_PED_CURRENT_WEAPON_SILENCED((::Ped)params[1]);
			}
			
			MOD_NATIVE(isPedWeaponReadyToShoot) {
				if (!arguments(1))
					return 0;

				return WEAPON::IS_PED_WEAPON_READY_TO_SHOOT((::Ped)params[1]);
			}
			
			MOD_NATIVE(isPedBeenDamagedByWeapon) {
				if (!arguments(3))
					return 0;

				return WEAPON::HAS_PED_BEEN_DAMAGED_BY_WEAPON((::Ped)params[1], params[2], params[3]);
			}
			
			MOD_NATIVE(isPedRunningRagdollTask) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_RUNNING_RAGDOLL_TASK((::Ped)params[1]);
			}
			
			MOD_NATIVE(isPedRunningMobilePhoneTask) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_RUNNING_MOBILE_PHONE_TASK((::Ped)params[1]);
			}

			MOD_NATIVE(getPedType) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_TYPE((::Ped)params[1]);
			}

			MOD_NATIVE(getPedKiller) {
				if (!arguments(1))
					return 0;

				return PED::_GET_PED_KILLER((::Ped)params[1]);
			}

			MOD_NATIVE(getPedCauseOfDeath) {
				if (!arguments(1))
					return 0;

				return PED::_GET_PED_KILLER((::Ped)params[1]);
			}

			MOD_NATIVE(getPedJacker) {
				if (!arguments(1))
					return 0;

				return PED::GET_PEDS_JACKER((::Ped)params[1]);
			}

			MOD_NATIVE(getPedJackTarget) {
				if (!arguments(1))
					return 0;

				return PED::GET_JACK_TARGET((::Ped)params[1]);
			}

			MOD_NATIVE(getPedAccuracy) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_ACCURACY((::Ped)params[1]);
			}

			MOD_NATIVE(getPedAlertness) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_ALERTNESS((::Ped)params[1]);
			}

			MOD_NATIVE(getPedParachuteState) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_PARACHUTE_STATE((::Ped)params[1]);
			}

			MOD_NATIVE(getPedParachuteLandingType) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_PARACHUTE_LANDING_TYPE((::Ped)params[1]);
			}

			MOD_NATIVE(getPedArmor) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_ARMOUR((::Ped)params[1]);
			}

			MOD_NATIVE(getPedMaxHealth) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_MAX_HEALTH((::Ped)params[1]);
			}

			MOD_NATIVE(getPedMoney) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_MONEY((::Ped)params[1]);
			}

			MOD_NATIVE(getPedBoneIndex) {
				if (!arguments(2))
					return 0;

				return PED::GET_PED_BONE_INDEX((::Ped)params[1], params[2]);
			}

			MOD_NATIVE(getPedVehicle) {
				if (!arguments(2))
					return 0;

				return PED::GET_VEHICLE_PED_IS_IN((::Ped)params[1], (BOOL)params[2]);
			}

			MOD_NATIVE(getPedMaxAmmo) {
				if (!arguments(2))
					return 0;

				cell * ammo = Utility::getAddrFromParam(amx, params[3]);
				if (ammo == nullptr)
					return 0;

				return WEAPON::GET_MAX_AMMO((::Ped)params[1], (Hash)params[2], (int *)ammo);
			}

			MOD_NATIVE(getPedAmmoInClip) {
				if (!arguments(3))
					return 0;

				cell * ammo = Utility::getAddrFromParam(amx, params[3]);
				if (ammo == nullptr)
					return 0;

				return WEAPON::GET_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], (int *)ammo);
			}
			
			MOD_NATIVE(getPedMaxAmmoInClip) {
				if (!arguments(2))
					return 0;

				return WEAPON::GET_MAX_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], TRUE);
			}

			MOD_NATIVE(getPedCurrentWeapon) {
				if (!arguments(2))
					return 0;

				cell * weapon = Utility::getAddrFromParam(amx, params[2]);
				if (weapon == nullptr)
					return 0;

				return WEAPON::GET_CURRENT_PED_WEAPON((::Ped)params[1], (Hash *)weapon, 1);
			}

			MOD_NATIVE(getPedCurrentVehicleWeapon) {
				if (!arguments(2))
					return 0;

				cell * weapon = Utility::getAddrFromParam(amx, params[2]);
				if (weapon == nullptr)
					return 0;

				return WEAPON::GET_CURRENT_PED_VEHICLE_WEAPON((::Ped)params[1], (Hash *)weapon);
			}

			MOD_NATIVE(getPedAmmoInWeapon) {
				if (!arguments(2))
					return 0;

				return WEAPON::GET_AMMO_IN_PED_WEAPON((::Ped)params[1], (Hash)params[2]);
			}

			MOD_NATIVE(getPedSelectedWeapon) {
				if (!arguments(1))
					return 0;

				return WEAPON::GET_SELECTED_PED_WEAPON((::Ped)params[1]);
			}

			MOD_NATIVE(getPedBestWeapon) {
				if (!arguments(1))
					return 0;

				return WEAPON::GET_BEST_PED_WEAPON((::Ped)params[1], FALSE);
			}
			
			MOD_NATIVE(getCurrentPedWeaponEntityIndex) {
				if (!arguments(1))
					return 0;

				return WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX((::Ped)params[1]);
			}
			
			MOD_NATIVE(getPedWeaponTypeInSlot) {
				if (!arguments(2))
					return 0;

				return WEAPON::GET_PED_WEAPONTYPE_IN_SLOT((::Ped)params[1], params[2]);
			}
			
			MOD_NATIVE(getPedMaxRangeOfCurrentWeapon) {
				if (!arguments(1))
					return 0;

				float range = WEAPON::GET_MAX_RANGE_OF_CURRENT_PED_WEAPON((::Ped)params[1]);

				return amx_ftoc(range);
			}

			MOD_NATIVE(setPedArmor) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_ARMOUR((::Ped)params[1], params[2]);
				return 1;
			}

			MOD_NATIVE(setPedAsCop) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_AS_COP((::Ped)params[1], (BOOL)params[2]);
				return 1;
			}

			MOD_NATIVE(setPedAsEnemy) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_AS_ENEMY((::Ped)params[1], (BOOL)params[2]);
				return 1;
			}


			MOD_NATIVE(setPedMaxHealth) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_MAX_HEALTH((::Ped)params[1], params[2]);
				return 1;
			}

			MOD_NATIVE(setPedMaxTimeInWater) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_MAX_TIME_IN_WATER((::Ped)params[1], amx_ctof(params[2]));
				return 1;
			}

			MOD_NATIVE(setPedMaxTimeUnderwater) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_MAX_TIME_UNDERWATER((::Ped)params[1], amx_ctof(params[2]));
				return 1;
			}

			MOD_NATIVE(setPedIntoVehicle) {
				if (!arguments(3))
					return 0;

				PED::SET_PED_INTO_VEHICLE((::Ped)params[1], (::Vehicle)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedShootRate) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_SHOOT_RATE((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedAccuracy) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_ACCURACY((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedAlertness) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_ALERTNESS((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedAmmo) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_PED_AMMO((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedAmmoInClip) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedInfiniteAmmo) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_PED_INFINITE_AMMO((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(setPedInfiniteAmmoInClip) {
				if (!arguments(2))
					return 0;

				WEAPON::SET_PED_INFINITE_AMMO_CLIP((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedCurrentWeapon) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_CURRENT_PED_WEAPON((::Ped)params[1], (Hash)params[2], params[3]);
				
				return 1;
			}

			MOD_NATIVE(setPedCurrentVehicleWeapon) {
				if (!arguments(2))
					return 0;

				return WEAPON::SET_CURRENT_PED_VEHICLE_WEAPON((::Ped)params[1], (Hash)params[2]);
			}

			MOD_NATIVE(setPedCurrentWeaponVisible) {
				if (!arguments(5))
					return 0;

				WEAPON::SET_PED_CURRENT_WEAPON_VISIBLE((::Ped)params[1], params[2], params[3], params[4], params[5]);

				return 1;
			}
			
			MOD_NATIVE(setPedDropsWeaponsWhenDead) {
				if (!arguments(2))
					return 0;

				WEAPON::SET_PED_DROPS_WEAPONS_WHEN_DEAD((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setPedHearingRange) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_HEARING_RANGE((::Ped)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setPedSeeingRange) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_SEEING_RANGE((::Ped)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setPedGravity) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_GRAVITY((::Ped)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setPedDropsWeapon) {
				if (!arguments(1))
					return 0;

				WEAPON::SET_PED_DROPS_WEAPON((::Ped)params[1]);

				return 1;
			}
			
			MOD_NATIVE(setPedDropsInventoryWeapon) {
				if (!arguments(4))
					return 0;

				float offset[3];
				if (!Utility::getFloatArrayFromParam(amx, params[3], offset, 3))
					return 0;

				WEAPON::SET_PED_DROPS_INVENTORY_WEAPON((::Ped)params[1], params[2], offset[0], offset[1], offset[2], params[3]);

				return 1;
			}

			MOD_NATIVE(addPedAmmo) {
				if (!arguments(3))
					return 0;

				WEAPON::ADD_AMMO_TO_PED((::Ped)params[1], params[2], params[3]);

				return 1;
			}


			MOD_NATIVE(addPedArmor) {
				if (!arguments(2))
					return 0;

				PED::ADD_ARMOUR_TO_PED((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(givePedWeapon) {
				if (!arguments(4))
					return 0;

				WEAPON::GIVE_WEAPON_TO_PED((::Ped)params[1], params[2], params[3], 0, params[4]);

				return 1;
			}
			
			MOD_NATIVE(givePedDelayedWeapon) {
				if (!arguments(4))
					return 0;

				WEAPON::GIVE_DELAYED_WEAPON_TO_PED((::Ped)params[1], params[2], params[3], params[4]);

				return 1;
			}

			MOD_NATIVE(givePedDamage) {
				if (!arguments(3))
					return 0;

				PED::APPLY_DAMAGE_TO_PED((::Ped)params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(removePedWeapon) {
				if (!arguments(2))
					return 0;

				WEAPON::REMOVE_WEAPON_FROM_PED((::Ped)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(removePedWeapons) {
				if (!arguments(1))
					return 0;

				WEAPON::REMOVE_ALL_PED_WEAPONS((::Ped)params[1], FALSE);

				return 1;
			}
			
			MOD_NATIVE(clearPedLastWeaponDamage) {
				if (!arguments(1))
					return 0;

				WEAPON::CLEAR_PED_LAST_WEAPON_DAMAGE((::Ped)params[1]);

				return 1;
			}

			MOD_NATIVE(hidePedWeaponForCutscene) {
				if (!arguments(2))
					return 0;

				WEAPON::HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE((::Ped)params[1], params[2]);

				return 1;
			}
		};
	};
};