#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Entity {
			MOD_NATIVE(isEntityAPed);
			MOD_NATIVE(isEntityAVehicle);
			MOD_NATIVE(isEntityAObject);
			MOD_NATIVE(isEntityDead);
			MOD_NATIVE(isEntityInAir);
			MOD_NATIVE(isEntityInWater);
			MOD_NATIVE(isEntityInZone);
			MOD_NATIVE(isEntityOnScreen);
			MOD_NATIVE(isEntityTouchingEntity);
			MOD_NATIVE(isEntityTouchingModel);
			MOD_NATIVE(isEntityVisible);
			MOD_NATIVE(isEntityExist);
			MOD_NATIVE(isEntityHaveDrawable);
			MOD_NATIVE(isEntityHavePhysics);
			MOD_NATIVE(getEntityModel);
			MOD_NATIVE(getEntityHealth);
			MOD_NATIVE(getEntityMaxHealth);
			MOD_NATIVE(getEntitySpeed);
			MOD_NATIVE(getEntityPitch);
			MOD_NATIVE(getEntityHeight);
			MOD_NATIVE(getEntityHeightAboveGround);
			MOD_NATIVE(getEntityQuaternion);
			MOD_NATIVE(getEntityPos);
			MOD_NATIVE(setEntityHealth);
			MOD_NATIVE(setEntityMaxHealth);
			MOD_NATIVE(setEntityInvincible);
			MOD_NATIVE(setEntityMaxSpeed);

			AMX_NATIVE_INFO list[];
		};
	};
};