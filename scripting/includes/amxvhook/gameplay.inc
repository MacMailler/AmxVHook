#if defined __gameplay_inc__
  #endinput
#endif
#define __gameplay_inc__


native isMissionFlag();

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

native isPrevWeather(const weather[]);
native isNextWeather(const weather[]);
native setWeatherPersist(const weather[]);
native setWeatherNowPersist(const weather[]);
native setWeatherNow(const weather[]);
native setWeatherOverTime(const weather[], Float:time);
native setWeatherTransition(sourceWeather, targetWeather, Float:transitionTime);
native setOverrideWeather(const weather[]);
native setRandomWeather();
native getCurrWeather();
native getNextWeather();
native getWeatherTransition(&sourceWeather, &targetWeather, &Float:transitionTime);
native clearWeatherPersist();
native clearOverrideWeather();