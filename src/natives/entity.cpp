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
				checkargs(1);

				return ENTITY::IS_ENTITY_A_PED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAVehicle) {
				checkargs(1);

				return ENTITY::IS_ENTITY_A_VEHICLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAObject) {
				checkargs(1);

				return ENTITY::IS_ENTITY_AN_OBJECT((::Entity)params[1]);
			}
			
			MOD_NATIVE(isEntityAMissionEntity) {
				checkargs(1);

				return ENTITY::IS_ENTITY_A_MISSION_ENTITY((::Entity)params[1]);
			}


			MOD_NATIVE(isEntityDead) {
				checkargs(1);

				return ENTITY::IS_ENTITY_DEAD((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityInAir) {
				checkargs(1);

				return ENTITY::IS_ENTITY_IN_AIR((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityInWater) {
				checkargs(1);

				return ENTITY::IS_ENTITY_IN_WATER((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityInZone) {
				checkargs(2);

				return ENTITY::IS_ENTITY_IN_ZONE((::Entity)params[1], (char *)String::get(amx, params[2]).c_str());
			}

			MOD_NATIVE(isEntityOnScreen) {
				checkargs(1);

				return ENTITY::IS_ENTITY_ON_SCREEN((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityTouchingEntity) {
				checkargs(2);

				return ENTITY::IS_ENTITY_TOUCHING_ENTITY((::Entity)params[1], params[2]);
			}

			MOD_NATIVE(isEntityTouchingModel) {
				checkargs(2);

				return ENTITY::IS_ENTITY_TOUCHING_MODEL((::Entity)params[1], params[2]);
			}
			
			MOD_NATIVE(isEntityUpright) {
				checkargs(2);

				return ENTITY::IS_ENTITY_UPRIGHT((::Entity)params[1], amx_ctof(params[2]));
			}
			
			MOD_NATIVE(isEntityUpsidedown) {
				checkargs(1);

				return ENTITY::IS_ENTITY_UPSIDEDOWN((::Entity)params[1]);
			}
			
			MOD_NATIVE(isEntityOccluded) {
				checkargs(1);

				return ENTITY::IS_ENTITY_OCCLUDED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityVisible) {
				checkargs(1);

				return ENTITY::IS_ENTITY_VISIBLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityExist) {
				checkargs(1);

				return ENTITY::DOES_ENTITY_EXIST((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAttached) {
				checkargs(1);

				return ENTITY::IS_ENTITY_ATTACHED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToAnyObject) {
				checkargs(1);

				return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_OBJECT((::Object)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToAnyPed) {
				checkargs(1);

				return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_PED((::Ped)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToAnyVehicle) {
				checkargs(1);

				return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_VEHICLE((::Vehicle)params[1]);
			}

			MOD_NATIVE(isEntityAttachedToEntity) {
				checkargs(2);

				return ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY((::Entity)params[1], (::Entity)params[2]);
			}

			MOD_NATIVE(isEntityHaveDrawable) {
				checkargs(1);

				return ENTITY::DOES_ENTITY_HAVE_DRAWABLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityHavePhysics) {
				checkargs(1);

				return ENTITY::DOES_ENTITY_HAVE_PHYSICS((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityAnimFinished) {
				checkargs(3);

				return ENTITY::HAS_ENTITY_ANIM_FINISHED((::Entity)params[1], (char *)String::get(amx, params[2]).c_str(), (char *)String::get(amx, params[2]).c_str(), 3);
			}

			MOD_NATIVE(isEntityDamagedByAnyObject) {
				checkargs(1);

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityDamagedByAnyPed) {
				checkargs(1);

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityDamagedByAnyVehicle) {
				checkargs(1);

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE((::Entity)params[1]);
			}

			MOD_NATIVE(isEntityDamagedByEntity) {
				checkargs(2);

				return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY((::Entity)params[1], (::Entity)params[2], 1);
			}

			MOD_NATIVE(isEntityCollidedWithAnything) {
				checkargs(1);

				return ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING((::Entity)params[1]);
			}
			
			MOD_NATIVE(isEntityBeenDamagedByWeapon) {
				checkargs(3);

				return WEAPON::HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON((::Entity)params[1], params[2], params[3]);
			}

			MOD_NATIVE(getEntityType) {
				checkargs(1);

				return ENTITY::GET_ENTITY_TYPE((::Entity)params[1]);
			}
			
			MOD_NATIVE(getEntityModel) {
				checkargs(1);

				return ENTITY::GET_ENTITY_MODEL((::Entity)params[1]);
			}

			MOD_NATIVE(getEntityHealth) {
				checkargs(1);

				auto addr = getScriptHandleBaseAddress(params[1]);

				return amx_ftoc(*(float *)(addr + 0x280));
			}

			MOD_NATIVE(getEntityMaxHealth) {
				checkargs(1);

				return ENTITY::GET_ENTITY_MAX_HEALTH((::Entity)params[1]);
			}

			MOD_NATIVE(getEntitySpeed) {
				checkargs(1);

				float speed = ENTITY::GET_ENTITY_SPEED((::Entity)params[1]);
				return amx_ftoc(speed);
			}

			MOD_NATIVE(getEntityPitch) {
				checkargs(1);

				float pitch = ENTITY::GET_ENTITY_PITCH((::Entity)params[1]);
				return amx_ftoc(pitch);
			}

			MOD_NATIVE(getEntityHeight) {
				checkargs(4);

				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				float height = ENTITY::GET_ENTITY_HEIGHT((::Entity)params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), params[3], params[4]);

				return amx_ftoc(height);
			}

			MOD_NATIVE(getEntityHeightAboveGround) {
				checkargs(1);

				float height = ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND((::Entity)params[1]);

				return amx_ftoc(height);
			}
			
			MOD_NATIVE(getEntityForwardVector) {
				checkargs(2);

				Vector3 vector = ENTITY::GET_ENTITY_FORWARD_VECTOR((::Entity)params[1]);

				return Aux::setVector3(amx, params[2], vector);
			}
			
			MOD_NATIVE(getEntityRoll) {
				checkargs(1);

				float roll = ENTITY::GET_ENTITY_ROLL((::Entity)params[1]);

				return amx_ftoc(roll);
			}
			
			MOD_NATIVE(getEntityHeading) {
				checkargs(1);

				float roll = ENTITY::GET_ENTITY_HEADING((::Entity)params[1]);

				return amx_ftoc(roll);
			}

			MOD_NATIVE(getEntityQuaternion) {
				checkargs(3);

				cell * w;
				if (amx_GetAddr(amx, params[1], &w) != AMX_ERR_NONE)
					return 0;

				float ww;
				Vector3 coords;
				ENTITY::GET_ENTITY_QUATERNION((::Entity)params[1], &coords.x, &coords.y, &coords.z, &ww);

				*w = amx_ftoc(ww);

				return Aux::setVector3(amx, params[2], coords);
			}

			MOD_NATIVE(getEntityPos) {
				checkargs(3);
				
				Vector3 coords = ENTITY::GET_ENTITY_COORDS((::Entity)params[1], params[3]);
				return Aux::setVector3(amx, params[2], coords);
			}

			MOD_NATIVE(getEntitySpeedVector) {
				checkargs(3);

				Vector3 vector = ENTITY::GET_ENTITY_SPEED_VECTOR((::Entity)params[1], params[3]);
				return Aux::setVector3(amx, params[2], vector);
			}
			
			MOD_NATIVE(getOffsetFromEntityInWorldPos) {
				checkargs(3);

				cell *offset;
				if (amx_GetAddr(amx, params[2], &offset) != AMX_ERR_NONE)
					return 0;

				Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS((::Entity)params[1], amx_ctof(offset[0]), amx_ctof(offset[1]), amx_ctof(offset[2]));
				return Aux::setVector3(amx, params[3], coords);
			}

			MOD_NATIVE(setEntityHealth) {
				checkargs(2);

				ENTITY::SET_ENTITY_HEALTH((::Entity)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setEntityMaxHealth) {
				checkargs(2);

				ENTITY::SET_ENTITY_MAX_HEALTH((::Entity)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setEntityInvincible) {
				checkargs(2);

				ENTITY::SET_ENTITY_INVINCIBLE((::Entity)params[1], params[2]);

				return 1;
			}
			
			MOD_NATIVE(setEntityMaxSpeed) {
				checkargs(2);

				ENTITY::SET_ENTITY_MAX_SPEED((::Entity)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setEntityQuaternion) {
				checkargs(3);
				
				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				ENTITY::SET_ENTITY_QUATERNION((::Entity)params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(setEntityVisible) {
				checkargs(2);

				ENTITY::SET_ENTITY_VISIBLE((::Entity)params[1], params[2], FALSE);

				return 1;
			}

			MOD_NATIVE(setEntityVelocity) {
				checkargs(2);

				cell *velocity;
				if (amx_GetAddr(amx, params[2], &velocity) != AMX_ERR_NONE)
					return 0;

				ENTITY::SET_ENTITY_VELOCITY((::Entity)params[1], amx_ctof(velocity[0]), amx_ctof(velocity[1]), amx_ctof(velocity[2]));

				return 1;
			}

			MOD_NATIVE(setEntityHasGravity) {
				checkargs(2);

				ENTITY::SET_ENTITY_HAS_GRAVITY((::Entity)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setEntityDynamic) {
				checkargs(2);

				ENTITY::SET_ENTITY_DYNAMIC((::Entity)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setEntityCanBeDamaged) {
				checkargs(2);

				ENTITY::SET_ENTITY_CAN_BE_DAMAGED((::Entity)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setEntityHeading) {
				checkargs(2);

				ENTITY::SET_ENTITY_HEADING((::Entity)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setEntityPos) {
				checkargs(6);

				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				ENTITY::SET_ENTITY_COORDS((::Entity)params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), params[3], params[4], params[5], params[6]);

				return 1;
			}

			MOD_NATIVE(deleteEntity) {
				checkargs(1);

				::Entity entity = params[1];
				ENTITY::DELETE_ENTITY(&entity);

				return 1;
			}

			MOD_NATIVE(detachEntity) {
				checkargs(1);

				ENTITY::DETACH_ENTITY((::Entity)params[1], FALSE, FALSE);

				return 1;
			}
			
			MOD_NATIVE(clearEntityLastWeaponDamage) {
				checkargs(1);

				WEAPON::CLEAR_ENTITY_LAST_WEAPON_DAMAGE((::Entity)params[1]);

				return 1;
			}
		};
	};
};