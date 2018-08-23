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