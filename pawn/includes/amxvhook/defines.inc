#if defined __defines_inc__
  #endinput
#endif
#define __defines_inc__


enum @Vector3 {
	@X = 0,
	@Y = 1,
	@Z = 2
};


#define toRGBA(%0,%1,%2,%3) ((%0 << 24) | (%1 << 16) | (%2 << 8) | %3)