#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Entity {
			MOD_NATIVE(isEntityAPed);
			MOD_NATIVE(isEntityAVehicle);
			MOD_NATIVE(isEntityAObject);
			MOD_NATIVE(isEntityAMissionEntity);
			MOD_NATIVE(isEntityDead);
			MOD_NATIVE(isEntityInAir);
			MOD_NATIVE(isEntityInWater);
			MOD_NATIVE(isEntityInZone);
			MOD_NATIVE(isEntityOnScreen);
			MOD_NATIVE(isEntityTouchingEntity);
			MOD_NATIVE(isEntityTouchingModel);
			MOD_NATIVE(isEntityUpright);
			MOD_NATIVE(isEntityUpsidedown);
			MOD_NATIVE(isEntityOccluded);
			MOD_NATIVE(isEntityVisible);
			MOD_NATIVE(isEntityExist);
			MOD_NATIVE(isEntityAttached);
			MOD_NATIVE(isEntityAttachedToAnyObject);
			MOD_NATIVE(isEntityAttachedToAnyPed);
			MOD_NATIVE(isEntityAttachedToAnyVehicle);
			MOD_NATIVE(isEntityAttachedToEntity);
			MOD_NATIVE(isEntityHaveDrawable);
			MOD_NATIVE(isEntityHavePhysics);
			MOD_NATIVE(isEntityAnimFinished);
			MOD_NATIVE(isEntityDamagedByAnyObject);
			MOD_NATIVE(isEntityDamagedByAnyPed);
			MOD_NATIVE(isEntityDamagedByAnyVehicle);
			MOD_NATIVE(isEntityDamagedByEntity);
			MOD_NATIVE(isEntityCollidedWithAnything);
			MOD_NATIVE(getEntityType);
			MOD_NATIVE(getEntityModel);
			MOD_NATIVE(getEntityHealth);
			MOD_NATIVE(getEntityMaxHealth);
			MOD_NATIVE(getEntitySpeed);
			MOD_NATIVE(getEntityPitch);
			MOD_NATIVE(getEntityHeight);
			MOD_NATIVE(getEntityHeightAboveGround);
			MOD_NATIVE(getEntityForwardVector);
			MOD_NATIVE(getEntityRoll);
			MOD_NATIVE(getEntityQuaternion);
			MOD_NATIVE(getEntityPos);
			MOD_NATIVE(getEntitySpeedVector);
			MOD_NATIVE(setEntityHealth);
			MOD_NATIVE(setEntityMaxHealth);
			MOD_NATIVE(setEntityInvincible);
			MOD_NATIVE(setEntityMaxSpeed);
			MOD_NATIVE(deleteEntity);
			MOD_NATIVE(detachEntity);

			AMX_NATIVE_INFO list[];
		};
	};
};