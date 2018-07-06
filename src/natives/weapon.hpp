#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Weapon {
			MOD_NATIVE(isWeaponValid);
			MOD_NATIVE(getWeaponComponentTypeModel);
			MOD_NATIVE(getWeaponTypeModel);
			MOD_NATIVE(getWeaponTypeSlot);
			MOD_NATIVE(getWeaponTypeGroup);
			MOD_NATIVE(getWeaponClipSize);
			MOD_NATIVE(getWeaponDamageType);
			MOD_NATIVE(enableLaserSightRendering);

			AMX_NATIVE_INFO list[];
		};
	};
};