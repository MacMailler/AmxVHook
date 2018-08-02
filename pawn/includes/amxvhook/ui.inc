#if defined __ui_inc__
  #endinput
#endif
#define __ui_inc__


enum eHudComps {
	HUD = 0,
	HUD_WANTED_STARS = 1,
	HUD_WEAPON_ICON = 2,
	HUD_CASH = 3,
	HUD_MP_CASH = 4,
	HUD_MP_MESSAGE = 5,
	HUD_VEHICLE_NAME = 6,
	HUD_AREA_NAME = 7,
	HUD_VEHICLE_CLASS = 8,
	HUD_STREET_NAME = 9,
	HUD_HELP_TEXT = 10,
	HUD_FLOATING_HELP_TEXT_1 = 11,
	HUD_FLOATING_HELP_TEXT_2 = 12,
	HUD_CASH_CHANGE = 13,
	HUD_RETICLE = 14,
	HUD_SUBTITLE_TEXT = 15,
	HUD_RADIO_STATIONS = 16,
	HUD_SAVING_GAME = 17,
	HUD_GAME_STREAM = 18,
	HUD_WEAPON_WHEEL = 19,
	HUD_WEAPON_WHEEL_STATS = 20,
	MAX_HUD_COMPONENTS = 21,
	MAX_HUD_WEAPONS = 22,
	MAX_SCRIPTED_HUD_COMPONENTS = 141
};


native isHudHidden();
native isRadarHidden();
native isRadarEnabled();
native isWidescreen();
native isHudComponentActive(id);

native setHudVisible(bool:visible);
native setRadarVisible(bool:visible);
native setRadarZoom(zoom);

native getScreenSize(&width, &height);
native Float:getSafeZoneSize();
native Float:getScreenAspectRatio(bool:b);
native getLabelText(const lable[], dest[], len = sizeof dest);

native showNotify(const text[], bool:blink = false, bool:in_breif = false);
native showSubtitle(const text[], duration = 2000, bool:immediately = true);
native showHelpMessage(const text[], bool:beep = true, duration = -1);
native showLoadingSpinner(const text[], type);
native showHudComponentThisFrame(id);
native showHud(bool:toggle);
native showRadar(bool:toggle);
native showCash(bool:toggle);
native showAreaName(bool:toggle);

native hideLoadingSpinner();
native hideHudAndRadarThisFrame();
native hideHudComponentThisFrame(id);

native removeNotify(notifyid);

native activateFrontendMenu(menuhash, bool:pause, component);
native restartFrontendMenu(menuhash);
native getCurrentFrontendMenu();
