#if defined __entity_inc__
  #endinput
#endif
#define __entity_inc__

native isEntityAPed(entity);
native isEntityAVehicle(entity);
native isEntityAObject(entity);
native isEntityDead(entity);
native isEntityInAir(entity);
native isEntityInWater(entity);
native isEntityInZone(entity, const zone[]);
native isEntityOnScreen(entity);
native isEntityTouchingEntity(entity, target);
native isEntityTouchingModel(entity, hash);
native isEntityVisible(entity);
native isEntityExist(entity);
native isEntityHaveDrawable(entity);
native isEntityHavePhysics(entity);/*
native isEntityAnimFinished(entity, const animDict[], const animName[]);
native isEntityDamagedByAnyObject(entity);
native isEntityDamagedByAnyPed(entity);
native isEntityDamagedByAnyVehicle(entity);
native isEntityDamagedByEntity(entity, target);
native isEntityCollidedWithAnything(entity);*/

native getEntityModel(entity);
native getEntityHealth(entity);
native getEntityMaxHealth(entity);
native Float:getEntitySpeed(entity);
native Float:getEntityPitch(entity);
native Float:getEntityHeight(entity, Float:coords[@Vector3], bool:atTop, bool:inWorldCoords);
native Float:getEntityHeightAboveGround(entity);
//native getEntityForwardVector(entity, Float:vector[3]);
native getEntityQuaternion(entity, &Float:x, &Float:y, &Float:z, &Float:w);
native getEntityPos(entity, Float:coords[@Vector3], bool:alive=true);

native setEntityHealth(entity, health);
native setEntityMaxHealth(entity, health);
native setEntityInvincible(entity, bool:toggle);
native setEntityMaxSpeed(entity, Float:speed);