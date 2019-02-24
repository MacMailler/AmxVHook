#if defined __useful_inc__
  #endinput
#endif
#define __useful_inc__


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
			case 'a'..'f', 'A'..'F' : ret = (ret * 16) + ((hex[i] - 32) - 'A') + 10);
		}
	}
	while (++i < len);
	
	return ret;
}

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