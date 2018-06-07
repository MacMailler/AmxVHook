#include "ped.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Ped {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(createPed)
				AMX_DEFINE_NATIVE(createPedInVehicle)
				AMX_DEFINE_NATIVE(createRandomPed)
				AMX_DEFINE_NATIVE(clonePed)
				AMX_DEFINE_NATIVE(deletePed)
				AMX_DEFINE_NATIVE(isPedMale)
				AMX_DEFINE_NATIVE(isPedHuman)
				AMX_DEFINE_NATIVE(isPedHurt)
				AMX_DEFINE_NATIVE(isPedInjured)
				AMX_DEFINE_NATIVE(isPedFatallyInjured)
				AMX_DEFINE_NATIVE(isPedAPlayer)
				AMX_DEFINE_NATIVE(isPedReloading)
				AMX_DEFINE_NATIVE(isPedDead)
				AMX_DEFINE_NATIVE(isPedArmed)
				AMX_DEFINE_NATIVE(isPedSwimming)
				AMX_DEFINE_NATIVE(isPedSwimmingUnderWater)
				AMX_DEFINE_NATIVE(isPedTracked)
				AMX_DEFINE_NATIVE(isPedRagdoll)
				AMX_DEFINE_NATIVE(isPedStopped)
				AMX_DEFINE_NATIVE(isPedShooting)
				AMX_DEFINE_NATIVE(isPedFalling)
				AMX_DEFINE_NATIVE(isPedJumping)
				AMX_DEFINE_NATIVE(isPedClimbing)
				AMX_DEFINE_NATIVE(isPedHearPlayer)
				AMX_DEFINE_NATIVE(isPedVaulting)
				AMX_DEFINE_NATIVE(isPedDiving)
				AMX_DEFINE_NATIVE(isPedJacking)
				AMX_DEFINE_NATIVE(isPedFleeing)
				AMX_DEFINE_NATIVE(isPedJumpingOutOfVehicle)
				AMX_DEFINE_NATIVE(isPedOnFoot)
				AMX_DEFINE_NATIVE(isPedOnMount)
				AMX_DEFINE_NATIVE(isPedOnVehicle)
				AMX_DEFINE_NATIVE(isPedOnAnyVehicle)
				AMX_DEFINE_NATIVE(isPedOnAnyBike)
				AMX_DEFINE_NATIVE(isPedInCover)
				AMX_DEFINE_NATIVE(isPedInCombat)
				AMX_DEFINE_NATIVE(isPedInMeleeComabat)
				AMX_DEFINE_NATIVE(isPedInAnyBoat)
				AMX_DEFINE_NATIVE(isPedInAnyHeli)
				AMX_DEFINE_NATIVE(isPedInAnyPlane)
				AMX_DEFINE_NATIVE(isPedInAnyTaxi)
				AMX_DEFINE_NATIVE(isPedInAnyTrain)
				AMX_DEFINE_NATIVE(isPedInAnyVehicle)
				AMX_DEFINE_NATIVE(isPedInVehicle)
				AMX_DEFINE_NATIVE(isPedSittingInAnyVehicle)
				AMX_DEFINE_NATIVE(isPedInPoliceVehicle)
				AMX_DEFINE_NATIVE(isPedInFlyingVehicle)
				AMX_DEFINE_NATIVE(isPedFacingPed)
				AMX_DEFINE_NATIVE(isPedModel)
				AMX_DEFINE_NATIVE(isPedCurrentWeaponSilenced)
				AMX_DEFINE_NATIVE(isPedWeaponReadyToShoot)
				AMX_DEFINE_NATIVE(getPedType)
				AMX_DEFINE_NATIVE(getPedKiller)
				AMX_DEFINE_NATIVE(getPedCauseOfDeath)
				AMX_DEFINE_NATIVE(getPedJacker)
				AMX_DEFINE_NATIVE(getPedJackTarget)
				AMX_DEFINE_NATIVE(getPedAccuracy)
				AMX_DEFINE_NATIVE(getPedAlertness)
				AMX_DEFINE_NATIVE(getPedParachuteState)
				AMX_DEFINE_NATIVE(getPedParachuteLandingType)
				AMX_DEFINE_NATIVE(getPedArmor)
				AMX_DEFINE_NATIVE(getPedMaxHealth)
				AMX_DEFINE_NATIVE(getPedVehicle)
				AMX_DEFINE_NATIVE(getPedCurrentWeapon)
				AMX_DEFINE_NATIVE(getPedCurrentVehicleWeapon)
				AMX_DEFINE_NATIVE(getPedMaxAmmo)
				AMX_DEFINE_NATIVE(getPedAmmoInClip)
				AMX_DEFINE_NATIVE(getPedAmmoInWeapon)
				AMX_DEFINE_NATIVE(getPedSelectedWeapon)
				AMX_DEFINE_NATIVE(getPedBestWeapon)
				AMX_DEFINE_NATIVE(setPedArmor)
				AMX_DEFINE_NATIVE(setPedAsCop)
				AMX_DEFINE_NATIVE(setPedAsEnemy)
				AMX_DEFINE_NATIVE(setPedMaxHealth)
				AMX_DEFINE_NATIVE(setPedMaxTimeInWater)
				AMX_DEFINE_NATIVE(setPedMaxTimeUnderwater)
				AMX_DEFINE_NATIVE(setPedShootRate)
				AMX_DEFINE_NATIVE(setPedAlertness)
				AMX_DEFINE_NATIVE(setPedAccuracy)
				AMX_DEFINE_NATIVE(setPedIntoVehicle)
				AMX_DEFINE_NATIVE(setPedAmmo)
				AMX_DEFINE_NATIVE(setPedAmmoInClip)
				AMX_DEFINE_NATIVE(setPedInfiniteAmmo)
				AMX_DEFINE_NATIVE(setPedInfiniteAmmoInClip)
				AMX_DEFINE_NATIVE(setPedCurrentWeapon)
				AMX_DEFINE_NATIVE(setPedCurrentVehicleWeapon)
				AMX_DEFINE_NATIVE(setPedHearingRange)
				AMX_DEFINE_NATIVE(setPedSeeingRange)
				AMX_DEFINE_NATIVE(setPedGravity)
				AMX_DEFINE_NATIVE(addPedAmmo)
				AMX_DEFINE_NATIVE(addPedArmor)
				AMX_DEFINE_NATIVE(givePedWeapon)
				AMX_DEFINE_NATIVE(givePedDamage)
				AMX_DEFINE_NATIVE(removePedWeapon)
				AMX_DEFINE_NATIVE(removePedWeapons)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(createPed) {
				if (!arguments(4))
					return -1;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[3], &addr) != AMX_ERR_NONE)
					return 0;

				return PED::CREATE_PED(params[1], params[2], amx_ctof(addr[0]), amx_ctof(addr[1]), amx_ctof(addr[2]), amx_ctof(params[4]), FALSE, TRUE);
			}

			AMX_NATIVE(createPedInVehicle) {
				if (!arguments(4))
					return -1;

				return PED::CREATE_PED_INSIDE_VEHICLE((::Vehicle)params[1], params[2], params[3], params[4], FALSE, TRUE);
			}

			AMX_NATIVE(createRandomPed) {
				if (!arguments(1))
					return -1;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE)
					return 0;

				return PED::CREATE_RANDOM_PED(amx_ctof(addr[0]), amx_ctof(addr[1]), amx_ctof(addr[3]));
			}

			AMX_NATIVE(clonePed) {
				if (!arguments(2))
					return 0;

				return PED::CLONE_PED(params[1], amx_ctof(params[2]), FALSE, TRUE);
			}

			AMX_NATIVE(deletePed) {
				if (!arguments(2))
					return 0;

				::Ped ped = params[1];
				PED::DELETE_PED(&ped);

				return 1;
			}

			AMX_NATIVE(isPedMale) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_MALE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedHuman) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_HUMAN((::Ped)params[1]);
			}

			AMX_NATIVE(isPedHurt) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_HURT((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInjured) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_INJURED((::Ped)params[1]);
			}

			AMX_NATIVE(isPedFatallyInjured) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_FATALLY_INJURED((::Ped)params[1]);
			}

			AMX_NATIVE(isPedAPlayer) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_A_PLAYER((::Ped)params[1]);
			}

			AMX_NATIVE(isPedReloading) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_RELOADING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedDead) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_DEAD_OR_DYING((::Ped)params[1], TRUE);
			}

			AMX_NATIVE(isPedArmed) {
				if (!arguments(3))
					return 0;

				return WEAPON::IS_PED_ARMED((::Ped)params[1], params[2]);
			}

			AMX_NATIVE(isPedSwimming) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SWIMMING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedSwimmingUnderWater) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SWIMMING_UNDER_WATER((::Ped)params[1]);
			}

			AMX_NATIVE(isPedTracked) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_TRACKED((::Ped)params[1]);
			}

			AMX_NATIVE(isPedRagdoll) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_RAGDOLL((::Ped)params[1]);
			}

			AMX_NATIVE(isPedStopped) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_STOPPED((::Ped)params[1]);
			}

			AMX_NATIVE(isPedShooting) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SHOOTING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedFalling) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_FALLING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedClimbing) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_CLIMBING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedHearPlayer) {
				if (!arguments(1))
					return 0;

				return PLAYER::CAN_PED_HEAR_PLAYER(PLAYER::PLAYER_ID(), (::Ped)params[1]);
			}

			AMX_NATIVE(isPedVaulting) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_VAULTING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedDiving) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_DIVING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedJacking) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_JACKING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedFleeing) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_FLEEING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedJumping) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_JUMPING((::Ped)params[1]);
			}

			AMX_NATIVE(isPedJumpingOutOfVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_JUMPING_OUT_OF_VEHICLE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedOnFoot) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_FOOT((::Ped)params[1]);
			}

			AMX_NATIVE(isPedOnMount) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_MOUNT((::Ped)params[1]);
			}

			AMX_NATIVE(isPedOnVehicle) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_ON_SPECIFIC_VEHICLE((::Ped)params[1], (::Vehicle)params[2]);
			}

			AMX_NATIVE(isPedOnAnyVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_VEHICLE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedOnAnyBike) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_ON_ANY_BIKE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInAnyBoat) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_BOAT((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInAnyHeli) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_HELI((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInAnyTaxi) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_TAXI((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInAnyPlane) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_PLANE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInAnyTrain) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_TRAIN((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInAnyVehicle) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_IN_ANY_VEHICLE((::Ped)params[1], params[2]);
			}

			AMX_NATIVE(isPedSittingInAnyVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_SITTING_IN_ANY_VEHICLE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInFlyingVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_FLYING_VEHICLE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInVehicle) {
				if (!arguments(3))
					return 0;

				return PED::IS_PED_IN_VEHICLE((::Ped)params[1], (::Vehicle)params[2], params[3]);
			}

			AMX_NATIVE(isPedInPoliceVehicle) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_ANY_POLICE_VEHICLE((::Ped)params[1]);
			}

			AMX_NATIVE(isPedInCombat) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_IN_COMBAT((::Ped)params[1], (::Ped)params[2]);
			}

			AMX_NATIVE(isPedInCover) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_COVER((::Ped)params[1], 0);
			}

			AMX_NATIVE(isPedInMeleeComabat) {
				if (!arguments(1))
					return 0;

				return PED::IS_PED_IN_MELEE_COMBAT((::Ped)params[1]);
			}

			AMX_NATIVE(isPedFacingPed) {
				if (!arguments(3))
					return 0;

				return PED::IS_PED_FACING_PED((::Ped)params[1], (::Ped)params[2], amx_ctof(params[3]));
			}

			AMX_NATIVE(isPedModel) {
				if (!arguments(2))
					return 0;

				return PED::IS_PED_MODEL((::Ped)params[1], params[2]);
			}

			AMX_NATIVE(isPedCurrentWeaponSilenced) {
				if (!arguments(1))
					return 0;

				return WEAPON::IS_PED_CURRENT_WEAPON_SILENCED((::Ped)params[1]);
			}
			
			AMX_NATIVE(isPedWeaponReadyToShoot) {
				if (!arguments(1))
					return 0;

				return WEAPON::IS_PED_WEAPON_READY_TO_SHOOT((::Ped)params[1]);
			}

			AMX_NATIVE(getPedType) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_TYPE((::Ped)params[1]);
			}

			AMX_NATIVE(getPedKiller) {
				if (!arguments(1))
					return 0;

				return PED::_GET_PED_KILLER((::Ped)params[1]);
			}

			AMX_NATIVE(getPedCauseOfDeath) {
				if (!arguments(1))
					return 0;

				return PED::_GET_PED_KILLER((::Ped)params[1]);
			}

			AMX_NATIVE(getPedJacker) {
				if (!arguments(1))
					return 0;

				return PED::GET_PEDS_JACKER((::Ped)params[1]);
			}

			AMX_NATIVE(getPedJackTarget) {
				if (!arguments(1))
					return 0;

				return PED::GET_JACK_TARGET((::Ped)params[1]);
			}

			AMX_NATIVE(getPedAccuracy) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_ACCURACY((::Ped)params[1]);
			}

			AMX_NATIVE(getPedAlertness) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_ALERTNESS((::Ped)params[1]);
			}

			AMX_NATIVE(getPedParachuteState) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_PARACHUTE_STATE((::Ped)params[1]);
			}

			AMX_NATIVE(getPedParachuteLandingType) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_PARACHUTE_LANDING_TYPE((::Ped)params[1]);
			}

			AMX_NATIVE(getPedArmor) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_ARMOUR((::Ped)params[1]);
			}

			AMX_NATIVE(getPedMaxHealth) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_MAX_HEALTH((::Ped)params[1]);
			}

			AMX_NATIVE(getPedMoney) {
				if (!arguments(1))
					return 0;

				return PED::GET_PED_MONEY((::Ped)params[1]);
			}

			AMX_NATIVE(getPedBoneIndex) {
				if (!arguments(2))
					return 0;

				return PED::GET_PED_BONE_INDEX((::Ped)params[1], params[2]);
			}

			AMX_NATIVE(getPedVehicle) {
				if (!arguments(2))
					return 0;

				return PED::GET_VEHICLE_PED_IS_IN((::Ped)params[1], (BOOL)params[2]);
			}

			AMX_NATIVE(getPedMaxAmmo) {
				if (!arguments(2))
					return 0;

				cell * ammo = nullptr;
				if (amx_GetAddr(amx, params[3], &ammo) != AMX_ERR_NONE || ammo == nullptr)
					return 0;

				return WEAPON::GET_MAX_AMMO((::Ped)params[1], (Hash)params[2], (int *)ammo);
			}

			AMX_NATIVE(getPedAmmoInClip) {
				if (!arguments(3))
					return 0;

				cell * ammo = nullptr;
				if (amx_GetAddr(amx, params[3], &ammo) != AMX_ERR_NONE || ammo == nullptr)
					return 0;

				return WEAPON::GET_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], (int *)ammo);
			}

			AMX_NATIVE(getPedCurrentWeapon) {
				if (!arguments(2))
					return 0;

				cell * weapon = nullptr;
				if (amx_GetAddr(amx, params[2], &weapon) != AMX_ERR_NONE || weapon == nullptr)
					return 0;

				return WEAPON::GET_CURRENT_PED_WEAPON((::Ped)params[1], (Hash *)weapon, 1);
			}

			AMX_NATIVE(getPedCurrentVehicleWeapon) {
				if (!arguments(2))
					return 0;

				cell * weapon = nullptr;
				if (amx_GetAddr(amx, params[2], &weapon) != AMX_ERR_NONE || weapon == nullptr)
					return 0;

				return WEAPON::GET_CURRENT_PED_VEHICLE_WEAPON((::Ped)params[1], (Hash *)weapon);
			}

			AMX_NATIVE(getPedAmmoInWeapon) {
				if (!arguments(2))
					return 0;

				return WEAPON::GET_AMMO_IN_PED_WEAPON((::Ped)params[1], (Hash)params[2]);
			}

			AMX_NATIVE(getPedSelectedWeapon) {
				if (!arguments(1))
					return 0;

				return WEAPON::GET_SELECTED_PED_WEAPON((::Ped)params[1]);
			}

			AMX_NATIVE(getPedBestWeapon) {
				if (!arguments(1))
					return 0;

				return WEAPON::GET_BEST_PED_WEAPON((::Ped)params[1], FALSE);
			}

			AMX_NATIVE(setPedArmor) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_ARMOUR((::Ped)params[1], params[2]);
				return 1;
			}

			AMX_NATIVE(setPedAsCop) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_AS_COP((::Ped)params[1], (BOOL)params[2]);
				return 1;
			}

			AMX_NATIVE(setPedAsEnemy) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_AS_ENEMY((::Ped)params[1], (BOOL)params[2]);
				return 1;
			}


			AMX_NATIVE(setPedMaxHealth) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_MAX_HEALTH((::Ped)params[1], params[2]);
				return 1;
			}

			AMX_NATIVE(setPedMaxTimeInWater) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_MAX_TIME_IN_WATER((::Ped)params[1], amx_ctof(params[2]));
				return 1;
			}

			AMX_NATIVE(setPedMaxTimeUnderwater) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_MAX_TIME_UNDERWATER((::Ped)params[1], amx_ctof(params[2]));
				return 1;
			}

			AMX_NATIVE(setPedIntoVehicle) {
				if (!arguments(3))
					return 0;

				PED::SET_PED_INTO_VEHICLE((::Ped)params[1], (::Vehicle)params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(setPedShootRate) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_SHOOT_RATE((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setPedAccuracy) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_ACCURACY((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setPedAlertness) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_ALERTNESS((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setPedAmmo) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_PED_AMMO((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(setPedAmmoInClip) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_AMMO_IN_CLIP((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(setPedInfiniteAmmo) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_PED_INFINITE_AMMO((::Ped)params[1], (Hash)params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(setPedInfiniteAmmoInClip) {
				if (!arguments(2))
					return 0;

				WEAPON::SET_PED_INFINITE_AMMO_CLIP((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(setPedCurrentWeapon) {
				if (!arguments(3))
					return 0;

				WEAPON::SET_CURRENT_PED_WEAPON((::Ped)params[1], (Hash)params[2], params[3]);
				
				return 1;
			}

			AMX_NATIVE(setPedCurrentVehicleWeapon) {
				if (!arguments(2))
					return 0;

				return WEAPON::SET_CURRENT_PED_VEHICLE_WEAPON((::Ped)params[1], (Hash)params[2]);
			}

			AMX_NATIVE(setPedHearingRange) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_HEARING_RANGE((::Ped)params[1], amx_ctof(params[2]));

				return 1;
			}

			AMX_NATIVE(setPedSeeingRange) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_SEEING_RANGE((::Ped)params[1], amx_ctof(params[2]));

				return 1;
			}

			AMX_NATIVE(setPedGravity) {
				if (!arguments(2))
					return 0;

				PED::SET_PED_GRAVITY((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(addPedAmmo) {
				if (!arguments(3))
					return 0;

				WEAPON::ADD_AMMO_TO_PED((::Ped)params[1], params[2], params[3]);

				return 1;
			}


			AMX_NATIVE(addPedArmor) {
				if (!arguments(2))
					return 0;

				PED::ADD_ARMOUR_TO_PED((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(givePedWeapon) {
				if (!arguments(4))
					return 0;

				WEAPON::GIVE_WEAPON_TO_PED((::Ped)params[1], params[2], params[3], 0, params[4]);

				return 1;
			}


			AMX_NATIVE(givePedDamage) {
				if (!arguments(3))
					return 0;

				PED::APPLY_DAMAGE_TO_PED((::Ped)params[1], params[2], params[3]);

				return 1;
			}

			AMX_NATIVE(removePedWeapon) {
				if (!arguments(2))
					return 0;

				WEAPON::REMOVE_WEAPON_FROM_PED((::Ped)params[1], params[2]);

				return 1;
			}

			AMX_NATIVE(removePedWeapons) {
				if (!arguments(1))
					return 0;

				WEAPON::REMOVE_ALL_PED_WEAPONS((::Ped)params[1], FALSE);

				return 1;
			}
		};
	};
};