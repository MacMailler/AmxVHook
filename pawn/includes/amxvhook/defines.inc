#if defined __defines_inc__
  #endinput
#endif
#define __defines_inc__


enum @Vector3 {
	@X = 0,
	@Y = 1,
	@Z = 2
};

enum @Time3 {
	@H = 0,
	@M = 1,
	@S = 2
};

enum @Date3 {
	@YY = 0,
	@MM = 1,
	@DD = 2
};


#define toRGBA(%0,%1,%2,%3) ((%0 << 24) | (%1 << 16) | (%2 << 8) | %3)