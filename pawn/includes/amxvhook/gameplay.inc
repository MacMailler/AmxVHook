#if defined __gameplay_inc__
  #endinput
#endif
#define __gameplay_inc__

enum eWeathers {
	WEATHER_CLEAR,
	WEATHER_EXTRASUNNY,
	WEATHER_CLOUDS,
	WEATHER_OVERCAST,
	WEATHER_RAIN,
	WEATHER_CLEARING,
	WEATHER_THUNDER,
	WEATHER_SMOG,
	WEATHER_FOGGY,
	WEATHER_XMAS,
	WEATHER_SNOWLIGHT,
	WEATHER_BLIZZARD
};

native isMissionFlag();

native getGameTimer();
native getFrameCount();
native getHashKey(const string[]);
native Float:getFrameTime();
native Float:getDistanceBetweenPos(Float:vec1[@Vector3], Float:vec2[@Vector3], bool:useZ=true);

native setWind(Float:wind);
native setWindSpeed(Float:speed);
native setWindDirection(Float:speed);
native setRainIntensity(Float:intensity);
native Float:getWindSpeed();
native Float:getWindDirection();
native createLightningThunder();

native setPoliceRadarBlips(bool:toggle);
native setPoliceIgnorePlayer(bool:toggle);
native setEveryoneIgnorePlayer(bool:toggle);
native setExplosiveAmmoThisFrame();
native setFireAmmoThisFrame();
native setExplosiveMeleeThisFrame();