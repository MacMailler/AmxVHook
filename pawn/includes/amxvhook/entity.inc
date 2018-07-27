#if defined __entity_inc__
  #endinput
#endif
#define __entity_inc__

native isEntityAPed(entity);
native isEntityAVehicle(entity);
native isEntityAObject(entity);
native isEntityAMissionEntity(entity);
native isEntityDead(entity);
native isEntityInAir(entity);
native isEntityInWater(entity);
native isEntityInZone(entity, const zone[]);
native isEntityOnScreen(entity);
native isEntityTouchingEntity(entity, target);
native isEntityTouchingModel(entity, hash);
native isEntityUpright(entity, Float:angle);
native isEntityUpsidedown(entity);
native isEntityOccluded(entity);
native isEntityVisible(entity);
native isEntityExist(entity);
native isEntityAttached(entity);
native isEntityAttachedToAnyObject(entity);
native isEntityAttachedToAnyPed(entity);
native isEntityAttachedToAnyVehicle(entity);
native isEntityAttachedToEntity(entity, targetEntity);
native isEntityHaveDrawable(entity);
native isEntityHavePhysics(entity);
native isEntityAnimFinished(entity, const animDict[], const animName[]);
native isEntityDamagedByAnyObject(entity);
native isEntityDamagedByAnyPed(entity);
native isEntityDamagedByAnyVehicle(entity);
native isEntityDamagedByEntity(entity, target);
native isEntityCollidedWithAnything(entity);
native isEntityBeenDamagedByWeapon(entity, weaponHash, weaponType);

native getEntityType(entity);
native getEntityModel(entity);
native getEntityMaxHealth(entity);
native Float:getEntityHealth(entity);
native Float:getEntitySpeed(entity);
native Float:getEntityPitch(entity);
native Float:getEntityHeight(entity, coords[@Vector3], bool:atTop, bool:inWorldCoords);
native Float:getEntityHeightAboveGround(entity);
native Float:getEntityRoll(entity);
native Float:getEntityHeading(entity);
native getEntityForwardVector(entity, vector[@Vector3]);
native getEntityQuaternion(entity, coords[@Vector3], &Float:w);
native getEntityPos(entity, coords[@Vector3], bool:alive=true);
native getEntitySpeedVector(entity, vector[@Vector3], bool:relative);
native getOffsetFromEntityInWorldPos(entity, offset[@Vector3], coords[@Vector3]);

native setEntityHealth(entity, health);
native setEntityMaxHealth(entity, health);
native setEntityMaxSpeed(entity, Float:speed);
native setEntityInvincible(entity, bool:toggle);
native setEntityQuaternion(entity, coords[@Vector3], &Float:w);
native setEntityVisible(entity, bool:visible);
native setEntityVelocity(entity, velocity[@Vector3]);
native setEntityHasGravity(entity, bool:toggle);
native setEntityDynamic(entity, bool:toggle);
native setEntityCanBeDamaged(entity, bool:toggle);
native setEntityHeading(entity, Float:heading);
native setEntityPos(entity, coords[@Vector3], bool:xAxis, bool:yAxis, bool:zAxis, bool:clearArea);

native deleteEntity(entity);
native detachEntity(entity);

native clearEntityLastWeaponDamage(entity);