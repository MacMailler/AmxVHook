#if defined __misc_inc__
  #endinput
#endif
#define __misc_inc__


native getGameTimer();
native getFrameCount();
native getHashKey(const string[]);
native Float:getFrameTime();

native getRandomInt(start, end);
native Float:getRandomFloat(Float:start, Float:end);
native Float:getDistanceBetweenPos(vec1[@Vector3], vec2[@Vector3], bool:useZ=true);
native Float:getAngleBetween2dVectors(vec1[@Vector2], vec2[@Vector2]);
native Float:getHeadingFromVector2d(Float:dx, Float:dy);

native world3DToScreen2D(coords[@Vector3], &Float:sx, &Float:sy);


stock rgbaFromInt(color, &r, &g, &b, &a) {
	r = ((color & 0xFF000000) >>> 24);
	g = ((color & 0xFF0000) >>> 16);
	b = ((color & 0xFF00) >>> 8);
	a = (color & 0xFF);
}

stock rgbaToInt(r, g, b, a) {
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

stock rgbaSetAlpha(color, a = 0xFF) {
	return ((color & 0xFFFFFF00) | a);
}

stock swap(&a, &b) {
	new
	c = a;
	a = b;
	b = c;
}
stock swapf(&Float:a, &Float:b) {
	new Float:
	c = a;
	a = b;
	b = c;
}

stock strhex(hex[]) {
	new i, ret, len = strlen(hex);
	
	if (hex[0] == '0' && hex[1] == 'x')
		i += 2;
		
	do {
		switch (hex[i]) {
			case '0'..'9': ret = (ret * 16) + (hex[i] - '0');
			case 'a'..'f', 'A'..'F' : ret = (ret * 16) + ((toupper(hex[i]) - 'A') + 10);
		}
	}
	while (++i < len);
	
	return ret;
}