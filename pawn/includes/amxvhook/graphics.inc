#if defined __graphics_inc__
  #endinput
#endif
#define __graphics_inc__


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

native world3DToScreen2D(Float:coords[@Vector3], &Float:sx, &Float:sy);

native getScreenSize(&width, &height);
native Float:getSafeZoneSize();
native bool:isWidescreen();

native drawText(const text[], Float:x, Float:y, Float:scale = 1.0, font = FONT_NORMAL, color[@RGBA] = {255,255,255,255});
native drawRect(Float:x, Float:y, Float:width, Float:height, color[@RGBA] = {255,255,255,255});
native drawMarker(type, Float:pos[@Vector3], Float:dir[@Vector3]={0,...}, Float:rot[@Vector3]={0,...}, Float:scale[@Vector3]={1,...}, color[@RGBA]={255,255,255,255}, bool:bobUpAndDown = false, bool:fadeCamera = false, bool:drawOnEnts = false);
native drawSprite(const textureDict[], const textureName[], Float:x, Float:y, Float:width, Float:height, Float:heading = 0.0, color[@RGBA]={255,255,255,255});

native setUILayer(layer);
native setDrawPosition(Float:x, Float:y);
native setDrawPositionRatio(Float:x, Float:y, Float:p2, Float:p3);
native setDrawPositionEnd();

/*
enum eDrawCommands {
	SET_TEXT_FONT,
	SET_TEXT_SCALE,
	SET_TEXT_COLOR,
	SET_TEXT_WRAP,
	SET_TEXT_CENTRE,
	SET_TEXT_DROPSHADOW,
	SET_TEXT_EDGE,
	SET_TEXT_RIGHT_JUSTIFY,
	SET_TEXT_JUSTIFICATION,
	SET_TEXT_LEADING,
	SET_TEXT_PROPORTIONAL,
	SET_TEXT_OUTLINE,
	SET_TEXT_ENTRY,
	SET_TEXT_ENTRY_2,
	SET_TEXT_RENDER_ID,
	ADD_TEXT_STRING,
	ADD_TEXT_INTEGER,
	ADD_TEXT_FLOAT,
	SET_NOTIFY_TEXT_ENTRY,
	DRAW_SUBTITLE_TIMED,
	DRAW_NOTIFY,
	DRAW_TEXT,
	DRAW_RECT,
	DRAW_LINE,
	DRAW_POLY,
	DRAW_BOX
};*/