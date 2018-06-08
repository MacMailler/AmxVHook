#if defined __player_inc__
  #endinput
#endif
#define __player_inc__

native getPlayerPed();
native getPlayerName(dest[], maxlen = sizeof dest);
native getPlayerPos(Float:pos[@Vector3], bool:alive=true);

native isPlayerPlaying();
native isPlayerDead();
native isPlayerClimbing();
native isPlayerRidingTrain();
native isPlayerBusted(bool:atArresting);
native isPlayerTargettingEntity(entity);
native isPlayerTargettingAnything();
native isPlayerControlOn();

native setPlayerSprint(bool:toggle);
native setPlayerLockOn(bool:toggle);
native setPlayerInvincible(player, bool:invincible);
native getPlayerInvincible(player);

native getTimeSincePlayerLastArrest();
native getTimeSincePlayerLastDeath();
native getTimeSincePlayerHitVehicle();
native getTimeSincePlayerHitPed();
native getTSPlayerDroveOnPavement(); // TS - time since
native getTSPlayerDroveAgainstTraffic();

native getPlayerWantedLevel();
native getPlayerWantedLevelThreshold(level);
native setPlayerWantedLevel(level);
native setPlayerWantedLevelNoDrop(level);

native reportPlayerCrime(crimeType, wantedLvlThresh);

native getPlayerMaxArmor();
native setPlayerMaxArmor(armor);

native Float:getPlayerStealthNoise();
native getPlayerTargetEntity(&entity);