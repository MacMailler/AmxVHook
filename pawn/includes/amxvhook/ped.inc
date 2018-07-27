#if defined __ped_inc__
  #endinput
#endif
#define __ped_inc__


enum ePedTypes {
	PED_TYPE_PLAYER_0,			// michael
	PED_TYPE_PLAYER_1,			// franklin
	PED_TYPE_NETWORK_PLAYER,	// mp character
	PED_TYPE_PLAYER_2,			// trevor
	PED_TYPE_CIVMALE,
	PED_TYPE_CIVFEMALE,
	PED_TYPE_COP,
	PED_TYPE_GANG_ALBANIAN,
	PED_TYPE_GANG_BIKER_1,
	PED_TYPE_GANG_BIKER_2,
	PED_TYPE_GANG_ITALIAN,
	PED_TYPE_GANG_RUSSIAN,
	PED_TYPE_GANG_RUSSIAN_2,
	PED_TYPE_GANG_IRISH,
	PED_TYPE_GANG_JAMAICAN,
	PED_TYPE_GANG_AFRICAN_AMERICAN,
	PED_TYPE_GANG_KOREAN,
	PED_TYPE_GANG_CHINESE_JAPANESE,
	PED_TYPE_GANG_PUERTO_RICAN,
	PED_TYPE_DEALER,
	PED_TYPE_MEDIC,
	PED_TYPE_FIREMAN,
	PED_TYPE_CRIMINAL,
	PED_TYPE_BUM,
	PED_TYPE_PROSTITUTE,
	PED_TYPE_SPECIAL,
	PED_TYPE_MISSION,
	PED_TYPE_SWAT,
	PED_TYPE_ANIMAL,
	PED_TYPE_ARMY
};


native createPed(type, hash, coords[@Vector3], Float:heading);
native createPedInVehicle(vehicle, type, hash, seat);
native createRandomPed(coords[@Vector3]);
native clonePed(ped, Float:heading);
native deletePed(ped);

native isPedMale(ped);
native isPedHuman(ped);
native isPedHurt(ped);
native isPedInjured(ped);
native isPedFatallyInjured(ped);
native isPedAPlayer(ped);
native isPedReloading(ped);
native isPedDead(ped);
native isPedArmed(ped, type);
native isPedSwimming(ped);
native isPedSwimmingUnderWater(ped);
native isPedTracked(ped);
native isPedRagdoll(ped);
native isPedStopped(ped);
native isPedShooting(ped);
native isPedFalling(ped);
native isPedJumping(ped);
native isPedClimbing(ped);
native isPedHearPlayer(ped);
native isPedVaulting(ped);
native isPedDiving(ped);
native isPedJacking(ped);
native isPedFleeing(ped);
native isPedJumpingOutOfVehicle(ped);
native isPedOnFoot(ped);
native isPedOnMount(ped);
native isPedOnVehicle(ped, vehicle);
native isPedOnAnyVehicle(ped);
native isPedOnAnyBike(ped);
native isPedInCover(ped);
native isPedInCombat(ped, targetPed);
native isPedInMeleeComabat(ped);
native isPedInAnyBoat(ped);
native isPedInAnyHeli(ped);
native isPedInAnyPlane(ped);
native isPedInAnyTaxi(ped);
native isPedInAnyTrain(ped);
native isPedInAnyVehicle(ped, bool:aGetIn);
native isPedInVehicle(ped, vehicle, bool:aGetIn);
native isPedSittingInAnyVehicle(ped);
native isPedInPoliceVehicle(ped);
native isPedInFlyingVehicle(ped);
native isPedFacingPed(ped, otherPed, Float:angle);
native isPedModel(ped, hash);
native isPedCurrentWeaponSilenced(ped);
native isPedWeaponReadyToShoot(ped);
native isPedBeenDamagedByWeapon(ped, weaponHash, weaponType);

native getPedType(ped);
native getPedKiller(ped);
native getPedCauseOfDeath(ped);
native getPedJacker(ped);
native getPedJackTarget(ped);
native getPedAccuracy(ped);
native getPedAlertness(ped);
native getPedParachuteState(ped);
native getPedParachuteLandingType(ped);
native getPedArmor(ped);
native getPedMaxHealth(ped, health);
native getPedVehicle(ped, bool:last=false);
native getPedCurrentWeapon(ped, &hash);
native getPedCurrentVehicleWeapon(ped, &hash);
native getPedMaxAmmo(ped, weaponHash, &ammo);
native getPedAmmoInClip(ped, weaponHash, &ammo);
native getPedMaxAmmoInClip(ped, weaponHash);
native getPedAmmoInWeapon(ped, weaponHash);
native getPedSelectedWeapon(ped);
native getPedBestWeapon(ped);
native getCurrentPedWeaponEntityIndex(ped);
native getPedWeaponTypeInSlot(ped, slotHash);
native Float:getPedMaxRangeOfCurrentWeapon(ped);

native setPedAsCop(ped, bool:toggle);
native setPedAsEnemy(ped, bool:toggle);
native setPedMaxHealth(ped, health);
native setPedArmor(ped, armor);
native setPedMaxTimeInWater(ped, Float:time);
native setPedMaxTimeUnderwater(ped, Float:time);
native setPedShootRate(ped, rate);
native setPedAlertness(ped, level);
native setPedAccuracy(ped, accuracy);
native setPedIntoVehicle(ped, vehicle, seatIndex);
native setPedAmmo(ped, weaponHash, ammo);
native setPedAmmoInClip(ped, weaponHash, ammo);
native setPedInfiniteAmmo(ped, weaponHash, bool:toggle);
native setPedInfiniteAmmoInClip(ped, bool:toggle);
native setPedCurrentWeapon(ped, weaponHash, bool:equip);
native setPedCurrentVehicleWeapon(ped, weaponHash);
native setPedCurrentWeaponVisible(ped, bool:visible, bool:deselectWeapon, bool:p3, bool:p4);
native setPedDropsWeaponsWhenDead(ped, bool:toggle);
native setPedHearingRange(ped, Float:range);
native setPedSeeingRange(ped, Float:range);
native setPedGravity(ped, bool:gravity);
native setPedDropsWeapon(ped);
native setPedDropsInventoryWeapon(ped, weaponHash, offset[@Vector3], ammoCount);

native addPedAmmo(ped, weaponHash, ammo);
native addPedArmor(ped, armor);

native givePedDamage(ped, amount, bool:armorFirst);
native givePedWeapon(ped, weaponHash, ammo, bool:equip=false);
native givePedDelayedWeapon(ped, weaponHash, time, bool:equip=false);
native removePedWeapon(ped, weaponHash);
native removePedWeapons(ped);

native clearPedLastWeaponDamage(ped);

native hidePedWeaponForCutscene(ped, bool:toggle);