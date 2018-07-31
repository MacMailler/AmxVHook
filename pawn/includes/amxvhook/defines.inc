#if defined __defines_inc__
  #endinput
#endif
#define __defines_inc__


enum @Vector3 {
	Float:@X,
	Float:@Y,
	Float:@Z
}

enum @Vector2 {
	Float:@X,
	Float:@Y
}

#define fpublic%0(%1) forward%0(%1); public%0(%1)