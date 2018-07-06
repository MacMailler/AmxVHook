#if defined __weapon_inc__
  #endinput
#endif
#define __weapon_inc__


native isWeaponValid(weaponHash);

native getWeaponComponentTypeModel(componentHash);
native getWeaponTypeModel(weaponHash);
native getWeaponTypeSlot(weaponHash);
native getWeaponTypeGroup(weaponHash);
native getWeaponClipSize(weaponHash);
native getWeaponDamageType(weaponHash);

native enableLaserSightRendering(bool:toggle);
