#pragma once
#include "weapon.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Weapon {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isWeaponValid)
				MOD_DEFINE_NATIVE(getWeaponComponentTypeModel)
				MOD_DEFINE_NATIVE(getWeaponTypeModel)
				MOD_DEFINE_NATIVE(getWeaponTypeSlot)
				MOD_DEFINE_NATIVE(getWeaponTypeGroup)
				MOD_DEFINE_NATIVE(getWeaponClipSize)
				MOD_DEFINE_NATIVE(getWeaponDamageType)
				MOD_DEFINE_NATIVE(enableLaserSightRendering)

				{NULL, NULL}
			};

			MOD_NATIVE(isWeaponValid) {
				if (arguments(1))
					return 0;

				return WEAPON::IS_WEAPON_VALID(params[1]);
			}

			MOD_NATIVE(getWeaponComponentTypeModel) {
				if (arguments(1))
					return 0;

				return WEAPON::GET_WEAPON_COMPONENT_TYPE_MODEL(params[1]);
			}

			MOD_NATIVE(getWeaponTypeModel) {
				if (arguments(1))
					return 0;

				return WEAPON::GET_WEAPONTYPE_MODEL(params[1]);
			}

			MOD_NATIVE(getWeaponTypeSlot) {
				if (arguments(1))
					return 0;

				return WEAPON::GET_WEAPONTYPE_SLOT(params[1]);
			}

			MOD_NATIVE(getWeaponTypeGroup) {
				if (arguments(1))
					return 0;

				return WEAPON::GET_WEAPONTYPE_GROUP(params[1]);
			}

			MOD_NATIVE(getWeaponClipSize) {
				if (arguments(1))
					return 0;

				return WEAPON::GET_WEAPON_CLIP_SIZE(params[1]);
			}

			MOD_NATIVE(getWeaponDamageType) {
				if (arguments(1))
					return 0;

				return WEAPON::GET_WEAPON_DAMAGE_TYPE(params[1]);
			}

			MOD_NATIVE(enableLaserSightRendering) {
				if (arguments(1))
					return 0;

				WEAPON::ENABLE_LASER_SIGHT_RENDERING(params[1]);

				return 1;
			}
		};
	};
};