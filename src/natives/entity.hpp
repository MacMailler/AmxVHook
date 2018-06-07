#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Entity {
			AMX_NATIVE(isEntityAPed);
			AMX_NATIVE(isEntityAVehicle);
			AMX_NATIVE(isEntityAObject);
			AMX_NATIVE(isEntityDead);
			AMX_NATIVE(isEntityInAir);
			AMX_NATIVE(isEntityInWater);
			AMX_NATIVE(isEntityInZone);
			AMX_NATIVE(isEntityOnScreen);
			AMX_NATIVE(isEntityTouchingEntity);
			AMX_NATIVE(isEntityTouchingModel);
			AMX_NATIVE(isEntityVisible);
			AMX_NATIVE(isEntityExist);
			AMX_NATIVE(isEntityHaveDrawable);
			AMX_NATIVE(isEntityHavePhysics);
			AMX_NATIVE(getEntityModel);
			AMX_NATIVE(getEntityHealth);
			AMX_NATIVE(getEntityMaxHealth);
			AMX_NATIVE(getEntitySpeed);
			AMX_NATIVE(getEntityPitch);
			AMX_NATIVE(getEntityHeight);
			AMX_NATIVE(getEntityHeightAboveGround);
			AMX_NATIVE(getEntityQuaternion);
			AMX_NATIVE(getEntityPos);
			AMX_NATIVE(setEntityHealth);
			AMX_NATIVE(setEntityMaxHealth);
			AMX_NATIVE(setEntityInvincible);
			AMX_NATIVE(setEntityMaxSpeed);

			AMX_NATIVE_INFO list[];
		};
	};
};