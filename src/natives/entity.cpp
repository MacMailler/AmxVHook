#include "entity.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Entity {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isEntityAPed)
				MOD_DEFINE_NATIVE(isEntityAVehicle)
				MOD_DEFINE_NATIVE(isEntityAObject)
				MOD_DEFINE_NATIVE(isEntityAMissionEntity)
				MOD_DEFINE_NATIVE(isEntityDead)
				MOD_DEFINE_NATIVE(isEntityInAir)
				MOD_DEFINE_NATIVE(isEntityInWater)
				MOD_DEFINE_NATIVE(isEntityInZone)
				MOD_DEFINE_NATIVE(isEntityOnScreen)
				MOD_DEFINE_NATIVE(isEntityTouchingEntity)
				MOD_DEFINE_NATIVE(isEntityTouchingModel)
				MOD_DEFINE_NATIVE(isEntityUpright)
				MOD_DEFINE_NATIVE(isEntityUpsidedown)
				MOD_DEFINE_NATIVE(isEntityOccluded)
				MOD_DEFINE_NATIVE(isEntityVisible)
				MOD_DEFINE_NATIVE(isEntityExist)
				MOD_DEFINE_NATIVE(isEntityAttached)
				MOD_DEFINE_NATIVE(isEntityAttachedToAnyObject)
				MOD_DEFINE_NATIVE(isEntityAttachedToAnyPed)
				MOD_DEFINE_NATIVE(isEntityAttachedToAnyVehicle)
				MOD_DEFINE_NATIVE(isEntityAttachedToEntity)
				MOD_DEFINE_NATIVE(isEntityHaveDrawable)
				MOD_DEFINE_NATIVE(isEntityHavePhysics)
				MOD_DEFINE_NATIVE(isEntityAnimFinished)
				MOD_DEFINE_NATIVE(isEntityDamagedByAnyObject)
				MOD_DEFINE_NATIVE(isEntityDamagedByAnyPed)
				MOD_DEFINE_NATIVE(isEntityDamagedByAnyVehicle)
				MOD_DEFINE_NATIVE(isEntityDamagedByEntity)
				MOD_DEFINE_NATIVE(isEntityCollidedWithAnything)
				MOD_DEFINE_NATIVE(isEntityBeenDamagedByWeapon)
				MOD_DEFINE_NATIVE(getEntityType)
				MOD_DEFINE_NATIVE(getEntityModel)
				MOD_DEFINE_NATIVE(getEntityHealth)
				MOD_DEFINE_NATIVE(getEntityMaxHealth)
				MOD_DEFINE_NATIVE(getEntitySpeed)
				MOD_DEFINE_NATIVE(getEntityPitch)
				MOD_DEFINE_NATIVE(getEntityHeight)
				MOD_DEFINE_NATIVE(getEntityHeightAboveGround)
				MOD_DEFINE_NATIVE(getEntityForwardVector)
				MOD_DEFINE_NATIVE(getEntityRoll)
				MOD_DEFINE_NATIVE(getEntityHeading)
				MOD_DEFINE_NATIVE(getEntityQuaternion)
				MOD_DEFINE_NATIVE(getEntityPos)
				MOD_DEFINE_NATIVE(getEntitySpeedVector)
				MOD_DEFINE_NATIVE(getOffsetFromEntityInWorldPos)
				MOD_DEFINE_NATIVE(setEntityHealth)
				MOD_DEFINE_NATIVE(setEntityMaxHealth)
				MOD_DEFINE_NATIVE(setEntityInvincible)
				MOD_DEFINE_NATIVE(setEntityMaxSpeed)
				MOD_DEFINE_NATIVE(setEntityQuaternion)
				MOD_DEFINE_NATIVE(setEntityVisible)
				MOD_DEFINE_NATIVE(setEntityVelocity)
				MOD_DEFINE_NATIVE(setEntityHasGravity)
				MOD_DEFINE_NATIVE(setEntityDynamic)
				MOD_DEFINE_NATIVE(setEntityCanBeDamaged)
				MOD_DEFINE_NATIVE(setEntityHeading)
				MOD_DEFINE_NATIVE(setEntityPos)
				MOD_DEFINE_NATIVE(deleteEntity)
				MOD_DEFINE_NATIVE(detachEntity)
				MOD_DEFINE_NATIVE(clearEntityLastWeaponDamage)

				{NULL, NULL}
			};

			MOD_NATIVE(isEntityAPed) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_A_PED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAVehicle) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_A_VEHICLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAObject) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_AN_OBJECT((::Entity)params[1]);
			}
			
			MOD_NATIVE(isEntityAMissionEntity) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_A_MISSION_ENTITY((::Entity)params[1]);
			}


			MOD_NATIVE(isEntityDead) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_DEAD((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityInAir) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_IN_AIR((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityInWater) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_IN_WATER((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityInZone) {
				if (!arguments(2))
					return 0;

				return ENTITY::IS_ENTITY_IN_ZONE((::Entity)params[1], (char *)String::get(amx, params[2]).c_str());
			}

			MOD_NATIVE(isEntityOnScreen) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_ON_SCREEN((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityTouchingEntity) {
				if (!arguments(2))
					return 0;

				return ENTITY::IS_ENTITY_TOUCHING_ENTITY((::Entity)params[1], params[2]);
			}

			MOD_NATIVE(isEntityTouchingModel) {
				if (!arguments(2))
					return 0;

				return ENTITY::IS_ENTITY_TOUCHING_MODEL((::Entity)params[1], params[2]);
			}
			
			MOD_NATIVE(isEntityUpright) {
				if (!arguments(2))
					return 0;

				return ENTITY::IS_ENTITY_UPRIGHT((::Entity)params[1], amx_ctof(params[2]));
			}
			
			MOD_NATIVE(isEntityUpsidedown) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_UPSIDEDOWN((::Entity)params[1]);
			}
			
			MOD_NATIVE(isEntityOccluded) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_OCCLUDED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityVisible) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_VISIBLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityExist) {
				if (!arguments(1))
					return 0;

				return ENTITY::DOES_ENTITY_EXIST((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAttached) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_ATTACHED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToAnyObject) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_OBJECT((::Object)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToAnyPed) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_PED((::Ped)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToAnyVehicle) {
				if (!arguments(1))
					return 0;

				return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_VEHICLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToEntity) {
				if (!arguments(2))
					return 0;

				return ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY((::Entity)params[1], (::Entity)params[2]);
			}

			MOD_NATIVE(isEntityHaveDrawable) {
				if (!arguments(1))
					return 0;

				return ENTITY::DOES_ENTITY_HAVE_DRAWABLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityHavePhysics) {
				if (!arguments(1))
					return 0;

				return ENTITY::DOES_ENTITY_HAVE_PHYSICS((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAnimFinished) {
				if (!arguments(3))
					return 0;

				return ENTITY::HAS_ENTITY_ANIM_FINISHED((::Entity)params[1], (char *)String::get(amx, params[2]).c_str(), (char *)String::get(amx, params[2]).c_str(), 3);
			}

			MOD_NATIVE(isEntityDamagedByAnyObject) {
				if (!arguments(1))
					return 0;

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityDamagedByAnyPed) {
				if (!arguments(1))
					return 0;

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityDamagedByAnyVehicle) {
				if (!arguments(1))
					return 0;

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityDamagedByEntity) {
				if (!arguments(2))
					return 0;

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY((::Entity)params[1], (::Entity)params[2], 1);
			}

			MOD_NATIVE(isEntityCollidedWithAnything) {
				if (!arguments(1))
					return 0;

				return ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING((::Entity)params[1]);
			}
			
			MOD_NATIVE(isEntityBeenDamagedByWeapon) {
				if (!arguments(3))
					return 0;

				return WEAPON::HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON((::Entity)params[1], params[2], params[3]);
			}

			MOD_NATIVE(getEntityType) {
				if (!arguments(1))
					return 0;

				return ENTITY::GET_ENTITY_TYPE((::Entity)params[1]);
			}
			
			MOD_NATIVE(getEntityModel) {
				if (!arguments(1))
					return 0;

				return ENTITY::GET_ENTITY_MODEL((::Entity)params[1]);
			}

			MOD_NATIVE(getEntityHealth) {
				if (!arguments(1))
					return 0;

				auto addr = getScriptHandleBaseAddress(params[1]);

				return amx_ftoc(*(float *)(addr + 0x280));
			}

			MOD_NATIVE(getEntityMaxHealth) {
				if (!arguments(1))
					return 0;

				return ENTITY::GET_ENTITY_MAX_HEALTH((::Entity)params[1]);
			}

			MOD_NATIVE(getEntitySpeed) {
				if (!arguments(1))
					return 0;

				float speed = ENTITY::GET_ENTITY_SPEED((::Entity)params[1]);
				return amx_ftoc(speed);
			}

			MOD_NATIVE(getEntityPitch) {
				if (!arguments(1))
					return 0;

				float pitch = ENTITY::GET_ENTITY_PITCH((::Entity)params[1]);
				return amx_ftoc(pitch);
			}

			MOD_NATIVE(getEntityHeight) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3))
					return 0;

				float height = ENTITY::GET_ENTITY_HEIGHT((::Entity)params[1], coords[0], coords[1], coords[2], params[3], params[4]);

				return amx_ftoc(height);
			}

			MOD_NATIVE(getEntityHeightAboveGround) {
				if (!arguments(1))
					return 0;

				float height = ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND((::Entity)params[1]);

				return amx_ftoc(height);
			}
			
			MOD_NATIVE(getEntityForwardVector) {
				if (!arguments(2))
					return 0;

				Vector3 vector = ENTITY::GET_ENTITY_FORWARD_VECTOR((::Entity)params[1]);

				return Utility::setVector3ToParam(amx, params[2], vector);
			}
			
			MOD_NATIVE(getEntityRoll) {
				if (!arguments(1))
					return 0;

				float roll = ENTITY::GET_ENTITY_ROLL((::Entity)params[1]);

				return amx_ftoc(roll);
			}
			
			MOD_NATIVE(getEntityHeading) {
				if (!arguments(1))
					return 0;

				float roll = ENTITY::GET_ENTITY_HEADING((::Entity)params[1]);

				return amx_ftoc(roll);
			}

			MOD_NATIVE(getEntityQuaternion) {
				if (!arguments(3))
					return 0;

				cell * w = Utility::getAddrFromParam(amx, params[3]);
				if (w == nullptr)
					return 0;

				float ww;
				Vector3 coords;
				ENTITY::GET_ENTITY_QUATERNION((::Entity)params[1], &coords.x, &coords.y, &coords.z, &ww);

				*w = amx_ftoc(ww);

				return Utility::setVector3ToParam(amx, params[2], coords);
			}

			MOD_NATIVE(getEntityPos) {
				if (!arguments(3))
					return 0;
				
				Vector3 coords = ENTITY::GET_ENTITY_COORDS((::Entity)params[1], params[3]);
				return Utility::setVector3ToParam(amx, params[2], coords);
			}

			MOD_NATIVE(getEntitySpeedVector) {
				if (!arguments(3))
					return 0;

				Vector3 vector = ENTITY::GET_ENTITY_SPEED_VECTOR((::Entity)params[1], params[3]);
				return Utility::setVector3ToParam(amx, params[2], vector);
			}
			
			MOD_NATIVE(getOffsetFromEntityInWorldPos) {
				if (!arguments(3))
					return 0;

				float offset[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], offset, 3))
					return 0;

				Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS((::Entity)params[1], offset[0], offset[1], offset[2]);
				return Utility::setVector3ToParam(amx, params[3], coords);
			}

			MOD_NATIVE(setEntityHealth) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_HEALTH((::Entity)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setEntityMaxHealth) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_MAX_HEALTH((::Entity)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setEntityInvincible) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_INVINCIBLE((::Entity)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setEntityMaxSpeed) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_MAX_SPEED((::Entity)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setEntityQuaternion) {
				if (!arguments(3))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3))
					return 0;

				ENTITY::SET_ENTITY_QUATERNION((::Entity)params[1], coords[0], coords[1], coords[2], amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(setEntityVisible) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_VISIBLE((::Entity)params[1], params[2], FALSE);

				return 1;
			}

			MOD_NATIVE(setEntityVelocity) {
				if (!arguments(2))
					return 0;

				float velocity[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], velocity, 3))
					return 0;

				ENTITY::SET_ENTITY_VELOCITY((::Entity)params[1], velocity[0], velocity[1], velocity[2]);

				return 1;
			}

			MOD_NATIVE(setEntityHasGravity) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_HAS_GRAVITY((::Entity)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setEntityDynamic) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_DYNAMIC((::Entity)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setEntityCanBeDamaged) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_CAN_BE_DAMAGED((::Entity)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setEntityHeading) {
				if (!arguments(2))
					return 0;

				ENTITY::SET_ENTITY_HEADING((::Entity)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setEntityPos) {
				if (!arguments(6))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3))
					return 0;

				ENTITY::SET_ENTITY_COORDS((::Entity)params[1], coords[0], coords[1], coords[2], params[3], params[4], params[5], params[6]);

				return 1;
			}

			MOD_NATIVE(deleteEntity) {
				if (!arguments(1))
					return 0;

				::Entity entity = params[1];
				ENTITY::DELETE_ENTITY(&entity);

				return 1;
			}

			MOD_NATIVE(detachEntity) {
				if (!arguments(1))
					return 0;

				ENTITY::DETACH_ENTITY((::Entity)params[1], FALSE, FALSE);

				return 1;
			}
			
			MOD_NATIVE(clearEntityLastWeaponDamage) {
				if (!arguments(1))
					return 0;

				WEAPON::CLEAR_ENTITY_LAST_WEAPON_DAMAGE((::Entity)params[1]);

				return 1;
			}
		};
	};
};