#if defined __graphics_inc__
  #endinput
#endif
#define __graphics_inc__


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

enum eMarkers {
	MARKER_UPSIDEDOWNCONE = 0,
	MARKER_VERTICALCYLINDER = 1,
	MARKER_THICKCHEVRONUP = 2,
	MARKER_THINCHEVRONUP = 3,
	MARKER_CHECKEREDFLAGRECT = 4,
	MARKER_CHECKEREDFLAGCIRCLE = 5,
	MARKER_VERTICLECIRCLE = 6,
	MARKER_PLANEMODEL = 7,
	MARKER_LOSTMCDARK = 8,
	MARKER_LOSTMCLIGHT = 9,
	MARKER_NUMBER0 = 10,
	MARKER_NUMBER1 = 11,
	MARKER_NUMBER2 = 12,
	MARKER_NUMBER3 = 13,
	MARKER_NUMBER4 = 14,
	MARKER_NUMBER5 = 15,
	MARKER_NUMBER6 = 16,
	MARKER_NUMBER7 = 17,
	MARKER_NUMBER8 = 18,
	MARKER_NUMBER9 = 19,
	MARKER_CHEVRONUPX1 = 20,
	MARKER_CHEVRONUPX2 = 21,
	MARKER_CHEVRONUPX3 = 22,
	MARKER_H_CIRCLEFAT = 23,
	MARKER_REPLAYICON = 24,
	MARKER_H_CIRCLESKINNY = 25,
	MARKER_H_CIRCLESKINNY_ARROW = 26,
	MARKER_H_SPLITARROWCIRCLE = 27,
	MARKER_DEBUGSPHERE = 28,
	MARKER_DALLORSIGN = 29,
	MARKER_HORIZONTALBARS = 30,
	MARKER_WOLFHEAD = 31
};

enum eFonts {
	FONT_NORMAL = 0,
	FONT_IMPACT = 4,
	FONT_ITALIC = 1,
	FONT_PRICEDOWN = 7,
	FONT_CAPS = 2
};

native drawInt(value, Float:x, Float:y);
native drawFloat(Float:value, Float:x, Float:y, decimal_places = 9);
native drawText(Float:x, Float:y);
native drawCounter(value1, value2, Float:x, Float:y);
native drawString(const text[], Float:x, Float:y, Float:scale = 1.0, font = FONT_NORMAL, color = 0xFFFFFFFF, bool:centre = false);
native drawRect(Float:x, Float:y, Float:width, Float:height, color = 0xFFFFFFFF);
native drawBox(point1[@Vector3], point2[@Vector3], color = 0xFFFFFFFF);
native drawLine(point1[@Vector3], point2[@Vector3], color = 0xFFFFFFFF);
native drawPoly(point1[@Vector3], point2[@Vector3], point3[@Vector3], color = 0xFFFFFFFF);
native drawMarker(type, pos[@Vector3], dir[@Vector3]={0.0,...}, rot[@Vector3]={0.0,...}, scale[@Vector3]={1.0,...}, color = 0xFFFFFFFF, bool:bobUpAndDown = false, bool:fadeCamera = false, bool:drawOnEnts = false);
native drawSprite(const textureDict[], const textureName[], Float:x, Float:y, Float:width, Float:height, Float:heading = 0.0, color = 0xFFFFFFFF);
native drawSpotLight(coords[@Vector3], dir[@Vector3], Float:distance, Float:brightness, Float:roundness, Float:radius, Float:fadeout, color = 0xFFFFFFFF);
native drawSpotLightWithShadow(coords[@Vector3], dir[@Vector3], Float:distance, Float:brightness, Float:roundness, Float:radius, Float:fadeout, shadowid, color = 0xFFFFFFFF);
native drawLightWithRange(coords[@Vector3], Float:range, Float:intensity, color = 0xFFFFFFFF);
native drawLightWithRangeAndShadow(coords[@Vector3], Float:range, Float:intensity, Float:shadow, color = 0xFFFFFFFF);

native bool:isWidescreen();
native bool:isHudComponentActive(id);

native setUILayer(layer);
native setDrawPosition(Float:x, Float:y);
native setDrawPositionRatio(Float:x, Float:y, Float:p2, Float:p3);
native setDrawPositionEnd();

native setTextEntry(const text[]);
native setTextFont(font);
native setTextCentre(bool:centre = true);
native setTextScale(Float:scale, Float:size);
native setTextColor(color);
native setTextDropShadow(dist, color = 0x000000FF);
native setTextEdge(dist, color = 0x000000FF);
native setTextWrap(Float:start = 0.0, Float:end = 1.0);
native setTextJustification(justifyType);
native setTextRightJustify(bool:toggle);

native setHudVisible(bool:visible);
native setRadarVisible(bool:visible);
native setRadarZoom(zoom);

native addTextComponentStr(const value[]);
native addTextComponentInt(value);
native addTextComponentFloat(Float:value, decimal_places = 6);

native showNotify(const text[], bool:blink = false, bool:in_breif = false);
native showSubtitle(const text[], duration = 2000, bool:immediately = true);
native showHelpMessage(const text[], bool:beep = true, duration = -1);
native showLoadingSpinner(const text[], type);
native hideLoadingSpinner();

native getScreenSize(&width, &height);
native Float:getSafeZoneSize();

native hideHudAndRadarThisFrame();
native hideHudComponentThisFrame(id);
native showHudComponentThisFrame(id);

native requestStreamedTextureDict(const textureDict[]);
native isStreamedTextureDictLoaded(const textureDict[]);
native setStreamedTextureDictNoNeeded(const textureDict[]);
native getTextureResolution(const textureDict[], const textureName[], resolution[@Vector3]);

native world3DToScreen2D(coords[@Vector3], &Float:sx, &Float:sy);

native activateFrontendMenu(menuhash, bool:pause, component);
native restartFrontendMenu(menuhash);
native getCurrentFrontendMenu();