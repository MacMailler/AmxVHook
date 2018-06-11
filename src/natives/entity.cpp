#include "entity.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Entity {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isEntityAPed)
				MOD_DEFINE_NATIVE(isEntityAVehicle)
				MOD_DEFINE_NATIVE(isEntityAObject)
				MOD_DEFINE_NATIVE(isEntityDead)
				MOD_DEFINE_NATIVE(isEntityInAir)
				MOD_DEFINE_NATIVE(isEntityInWater)
				MOD_DEFINE_NATIVE(isEntityInZone)
				MOD_DEFINE_NATIVE(isEntityOnScreen)
				MOD_DEFINE_NATIVE(isEntityTouchingEntity)
				MOD_DEFINE_NATIVE(isEntityTouchingModel)
				MOD_DEFINE_NATIVE(isEntityVisible)
				MOD_DEFINE_NATIVE(isEntityExist)
				MOD_DEFINE_NATIVE(isEntityHaveDrawable)
				MOD_DEFINE_NATIVE(isEntityHavePhysics)
				MOD_DEFINE_NATIVE(getEntityModel)
				MOD_DEFINE_NATIVE(getEntityHealth)
				MOD_DEFINE_NATIVE(getEntityMaxHealth)
				MOD_DEFINE_NATIVE(getEntitySpeed)
				MOD_DEFINE_NATIVE(getEntityPitch)
				MOD_DEFINE_NATIVE(getEntityHeight)
				MOD_DEFINE_NATIVE(getEntityHeightAboveGround)
				MOD_DEFINE_NATIVE(getEntityQuaternion)
				MOD_DEFINE_NATIVE(getEntityPos)
				MOD_DEFINE_NATIVE(setEntityHealth)
				MOD_DEFINE_NATIVE(setEntityMaxHealth)
				MOD_DEFINE_NATIVE(setEntityInvincible)
				MOD_DEFINE_NATIVE(setEntityMaxSpeed)

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

				cell * addr;
				if (amx_GetAddr(amx, params[2], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				float height = ENTITY::GET_ENTITY_HEIGHT((::Entity)params[1], amx_ctof(addr[0]), amx_ctof(addr[1]), amx_ctof(addr[2]), params[3], params[4]);

				return amx_ftoc(height);
			}

			MOD_NATIVE(getEntityHeightAboveGround) {
				if (!arguments(1))
					return 0;

				float height = ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND((::Entity)params[1]);

				return amx_ftoc(height);
			}

			MOD_NATIVE(getEntityQuaternion) {
				if (!arguments(5))
					return 0;

				cell * x = nullptr, *y = nullptr, *z = nullptr, *w = nullptr;
				if ((amx_GetAddr(amx, params[2], &x) != AMX_ERR_NONE || x == nullptr) ||
					(amx_GetAddr(amx, params[3], &y) != AMX_ERR_NONE || y == nullptr) ||
					(amx_GetAddr(amx, params[4], &z) != AMX_ERR_NONE || y == nullptr) ||
					(amx_GetAddr(amx, params[5], &w) != AMX_ERR_NONE || y == nullptr))
					return 0;

				float xx, yy, zz, ww;
				ENTITY::GET_ENTITY_QUATERNION((::Entity)params[1], &xx, &yy, &zz, &ww);

				*x = amx_ftoc(xx);
				*y = amx_ftoc(yy);
				*z = amx_ftoc(zz);
				*w = amx_ftoc(ww);
				
				return 1;
			}

			MOD_NATIVE(getEntityPos) {
				if (!arguments(3))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[2], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;
				
				Vector3 coords = ENTITY::GET_ENTITY_COORDS((::Entity)params[1], params[3]);
				Funcs::vector3ToCellArray(addr, &coords);

				return 1;
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
		};
	};
};