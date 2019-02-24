/***
*	 AmxVHook Trainer
*
*	(C) MacMailler, 2018
**/
#include <amxvhook\amxvhook>
#include <amxvhook\hash>
#include <amxvhook\useful>

#define MAX_MENUS (1)
#define MAX_PAGES (64)
#define MAX_ELEMS (48)
#define __menu_limits__
#include "menu\menu"

#define FCOLOR_TO_COLOR(%0) floatround(%0 / 0.003921)
#define COLOR_TO_FCOLOR(%0) (%0 * 0.003921)

//#define clampValue(%0,%1,%2,%3) do{switch(%1){case ElemTapNavRight:if(++%0>%3)%0=%2;case ElemTapNavLeft:if(--%0<%2)%0=%3;}}while(0)

static temp[255];

new bool:keyboardDisplayed = false;

new Float:menuPosX = 0.800;
new Float:menuPosY = 0.090;

new menuColorR = 174;
new menuColorG = 17;
new menuColorB = 64;

new trainerMenu;
new mainPage;
new aboutPage;
new colorOptions;
new playerOptions;
new vehicleOptions;
new weaponOptions;
new weatherOptions;
new timeOptions;
new miscOptions;
new trackerOptions;
new posOptions;
new speedoOptions;
new vehicleSpawner;
new vehicleSpawnerList[sizeof vehiclesInfo];

new playerPed;
new updateFeaturesTimer;


enum eFeatures {
	bool:playerInvincible,
	bool:playerNeverWanted,
	
	bool:vehicleInvincible,
	bool:vehicleWrapInSpawn,
	bool:vehicleDeleteLast,
	bool:vehicleSpeedo,
	vehicleLastSpawned,
	
	bool:weaponNoReload,
	bool:weaponFireAmmo,
	bool:weaponExplosiveAmmo,
	bool:weaponExplosiveMelee,
	
	bool:timePause,
	bool:timeSyncWithSystem,
	
	bool:weatherWind,
	bool:weatherPersist
}
new features[eFeatures] = {
	false, false,
	
	false, false, false, false, -1,
	
	false, false, false, false,
	
	false, false,
	
	false, false
};


static const weatherData[][] = {
	"CLEAR",
	"EXTRASUNNY",
	"CLOUDS",
	"SMOG",
	"FOGGY",
	"OVERCAST",
	"RAIN",
	"THUNDER",
	"CLEARING",
	"NEUTRAL",
	"SNOW",
	"BLIZZARD",
	"SNOWLIGHT",
	"XMAS",
	"HALLOWEEN"
};


new texSpeedoBack, texSpeedoArrow;
new speedoSize[@Vector2] = {0.15, 0.15};
new speedoCenter[@Vector2] = {0.5, 0.5};
new speedoPos[@Vector2] = {0.9, 0.9};
new Float:speedoColor[4] = {1.0, 1.0, 1.0, 1.0};


public onModLoad() {
	trainerMenu = addMenu(menuPosX, menuPosY, 0.180);

	mainPage = addPage(trainerMenu, "Main Menu");
	addElem(trainerMenu, mainPage, "Player", ElemTypePage);
	addElem(trainerMenu, mainPage, "Vehicle", ElemTypePage);
	addElem(trainerMenu, mainPage, "Weapon", ElemTypePage);
	addElem(trainerMenu, mainPage, "Time", ElemTypePage);
	addElem(trainerMenu, mainPage, "Weather", ElemTypePage);
	addElem(trainerMenu, mainPage, "Misc", ElemTypePage);
	setElemValueFont(trainerMenu, mainPage, addElem(trainerMenu, mainPage, " ", ElemTypeValue, .value = "AmxVHook Trainer"), FONT_ITALIC);
	
	aboutPage = addPage(trainerMenu, "About", mainPage);
	addElem(trainerMenu, aboutPage, "Project: https://github.com/MacMailler/AmxVHook", .font = FONT_IMPACT);
	addElem(trainerMenu, aboutPage, "Author: MacMailler", .font = FONT_IMPACT);
	
	playerOptions = addPage(trainerMenu, "Player Options", mainPage);
	addElem(trainerMenu, playerOptions, "Fix Player");
	addElem(trainerMenu, playerOptions, "Invincible", ElemTypeToggle);
	addElem(trainerMenu, playerOptions, "Never Wanted", ElemTypeToggle);
	addElem(trainerMenu, playerOptions, "Wanted Level", ElemTypeValue, .value = "<0>");
	
	vehicleOptions = addPage(trainerMenu, "Vehicle Options", mainPage);
	addElem(trainerMenu, vehicleOptions, "Spawner", ElemTypePage);
	addElem(trainerMenu, vehicleOptions, "Speedo", ElemTypePage);
	addElem(trainerMenu, vehicleOptions, "Invincible", ElemTypeToggle);
	addElem(trainerMenu, vehicleOptions, "Wrap In Spawn", ElemTypeToggle);
	addElem(trainerMenu, vehicleOptions, "Delete Last Spawned Vehicle", ElemTypeToggle);
	addElem(trainerMenu, vehicleOptions, "Delete Vehicle");
	
	weaponOptions = addPage(trainerMenu, "Weapon Options", mainPage);
	addElem(trainerMenu, weaponOptions, "Give All Weapons");
	addElem(trainerMenu, weaponOptions, "Remove All Weapons");
	addElem(trainerMenu, weaponOptions, "No Reload", ElemTypeToggle);
	addElem(trainerMenu, weaponOptions, "Fire Ammo", ElemTypeToggle);
	addElem(trainerMenu, weaponOptions, "Explosive Ammo", ElemTypeToggle);
	addElem(trainerMenu, weaponOptions, "Explosive Melee", ElemTypeToggle);
	
	timeOptions = addPage(trainerMenu, "Time Options", mainPage);
	format(temp, _, "<%i>", 0);
	addElem(trainerMenu, timeOptions, "Hour", ElemTypeValue, .value = temp);
	addElem(trainerMenu, timeOptions, "Pause Clock", ElemTypeToggle);
	addElem(trainerMenu, timeOptions, "Sync With System", ElemTypeToggle);
	
	weatherOptions = addPage(trainerMenu, "Weather Options", mainPage);
	addElem(trainerMenu, weatherOptions, "Wind", ElemTypeToggle);
	addElem(trainerMenu, weatherOptions, "Set Persist", ElemTypeToggle);
	format(temp, _, "<%s>", weatherData[0]);
	addElem(trainerMenu, weatherOptions, "Weather", ElemTypeValue, .value = temp);

	miscOptions = addPage(trainerMenu, "Misc Options", mainPage);
	addElem(trainerMenu, miscOptions, "Menu Position", ElemTypePage);
	addElem(trainerMenu, miscOptions, "Menu Color", ElemTypePage);
	addElem(trainerMenu, miscOptions, "Tracker", ElemTypePage);
	
	posOptions = addPage(trainerMenu, "Menu Position", miscOptions);
	addElem(trainerMenu, posOptions, "Menu X", ElemTypeValue, .value = "<0.800>");
	addElem(trainerMenu, posOptions, "Menu Y", ElemTypeValue, .value = "<0.090>");
	
	colorOptions = addPage(trainerMenu, "Menu Color", miscOptions);
	addElem(trainerMenu, colorOptions, "Red", ElemTypeValue, .value = "<174>");
	addElem(trainerMenu, colorOptions, "Green", ElemTypeValue, .value = "<17>");
	addElem(trainerMenu, colorOptions, "Blue", ElemTypeValue, .value = "<64>");
	addElem(trainerMenu, colorOptions, "Random");
	
	speedoOptions = addPage(trainerMenu, "Speedo Options", vehicleOptions);
	addElem(trainerMenu, speedoOptions, "Speedo", ElemTypeToggle);
	addElem(trainerMenu, speedoOptions, "Red", ElemTypeValue, .value = "<255>");
	addElem(trainerMenu, speedoOptions, "Green", ElemTypeValue, .value = "<255>");
	addElem(trainerMenu, speedoOptions, "Blue", ElemTypeValue, .value = "<255>");
	addElem(trainerMenu, speedoOptions, "Random");
	
	trackerOptions = addPage(trainerMenu, "Tracker Options", miscOptions);
	addElem(trainerMenu, trackerOptions, "Vehicle", ElemTypeToggle);
	addElem(trainerMenu, trackerOptions, "Ped", ElemTypeToggle);
	
	genVehicleSpawner();
	
	texSpeedoBack = createTexture("SpeedoBack.png");
	texSpeedoArrow = createTexture("SpeedoArrow.png");
	
	updateFeaturesTimer = addTimer("updateFeatures", 500);
}

stock genVehicleSpawner() {
	vehicleSpawner = addPage(trainerMenu, "Vehicle Spawner", vehicleOptions, true);
	addElem(trainerMenu, vehicleSpawner, "Input Model", ElemTypeInput);
	addElem(trainerMenu, vehicleSpawner, "Random Vehicle");
	
	for (new i; i < sizeof vehiclesInfo; i++) {
		addElem(trainerMenu, vehicleSpawner, vehiclesInfo[i][vehicleClass], ElemTypePage);
		vehicleSpawnerList[i] = addPage(trainerMenu, vehiclesInfo[i][vehicleClass], vehicleSpawner, true);
		
		for (new j; j < MAX_VEH_HASHES_PER_CLASS; j++) {
			if (vehiclesInfo[i][vehicleHashes][j] != 0) {
				getDisplayNameFromVehicleModel(vehiclesInfo[i][vehicleHashes][j], temp);
				getLabelText(temp, temp);
				addElem(trainerMenu, vehicleSpawnerList[i], temp);
			}
			else break;
		}
	}
}

public onModUnload() {
	if (features[vehicleLastSpawned] != -1)
		deleteVehicle(features[vehicleLastSpawned]);
	
	dropTimer(updateFeaturesTimer);
}

public onModUpdate() {
	if (!isPlayerPlaying())
		return 1;
		
	playerPed = getPlayerPed();
	
	menuDrawProcess();
	if (!keyboardDisplayed)
		menuInputProcess();
		
	if (features[vehicleSpeedo])
		updateSpeedo();
		
	updateOnFrameFeatures();

	return 1;
}

public onModInputCanceled()
	keyboardDisplayed = false;

public onModInputText(text[]) {
	if (keyboardDisplayed) {
		keyboardDisplayed = false;
		if (!spawnVehicle(getHashKey(text)))
			showNotify("Invalid model");
	}
	return 1;
}

forward onMenuElemTap(menuid, pageid, elemid, eElemTapTypes:tapType);
public onMenuElemTap(menuid, pageid, elemid, eElemTapTypes:tapType) {
	if (menuid != trainerMenu)
		return 0;
	
	switch (tapType) {
		case ElemTapSelect : {
			if (pageid == mainPage)
				switch (elemid) {
					case 0 : setActivePage(trainerMenu, playerOptions);
					case 1 : setActivePage(trainerMenu, vehicleOptions);
					case 2 : setActivePage(trainerMenu, weaponOptions);
					case 3 : setActivePage(trainerMenu, timeOptions);
					case 4 : setActivePage(trainerMenu, weatherOptions);
					case 5 : setActivePage(trainerMenu, miscOptions);
					case 6 : setActivePage(trainerMenu, aboutPage);
				}
			
			else if (pageid == playerOptions)
				switch (elemid) {
					case 0 : {
						setEntityHealth(playerPed, getEntityMaxHealth(playerPed));
						addPedArmor(playerPed, getPlayerMaxArmor() - getPedArmor(playerPed));
						new vehicle = getPedVehicle(playerPed);
						if (isEntityExist(vehicle) && !isEntityDead(vehicle))
							setVehicleFixed(vehicle);
					}
					case 1 : {
						features[playerInvincible] = !features[playerInvincible];
						setPlayerInvincible(features[playerInvincible]);
					}
					case 2 : {
						features[playerNeverWanted] = !features[playerNeverWanted];
					}
					case 3 : setPlayerWantedLevel(0);
				}
				
			else if (pageid == vehicleOptions)
				switch (elemid) {
					case 0 : setActivePage(trainerMenu, vehicleSpawner);
					case 1 : setActivePage(trainerMenu, speedoOptions);
					case 2 : features[vehicleInvincible] = !features[vehicleInvincible];
					case 3 : features[vehicleWrapInSpawn] = !features[vehicleWrapInSpawn];
					case 4 : features[vehicleDeleteLast] = !features[vehicleDeleteLast];
					case 5 : {
						new vehicle = getPedVehicle(playerPed);
						if (isEntityExist(vehicle)) {
							if (features[vehicleLastSpawned] == vehicle)
								features[vehicleLastSpawned] = -1;
								
							deleteVehicle(vehicle);
						}
					}
				}
				
				
			else if (pageid == vehicleSpawner)
				switch (elemid) {
					case 0 : {
						keyboardDisplayed = true;
						displayOnScreeKeyboard("FMMC_KEY_TIP8", "");
					}
					
					case 1 : spawnVehicle(vehiclesInfo[getRandomInt(0, sizeof vehiclesInfo)][vehicleHashes][getRandomInt(0, 37)]);
					
					default : setActivePage(trainerMenu, vehicleSpawnerList[elemid - 2]);
				}
			
			else if (pageid == weaponOptions)
				switch (elemid) {
					case 0 : {
						for (new i ; i < sizeof(weaponHashes); i++)
							givePedDelayedWeapon(playerPed, weaponHashes[eWeaponHashes:i], 1000, false);
							
						showNotify("All weapon added");
					}
					case 1 : removePedWeapons(playerPed);
					case 2 : features[weaponNoReload] = !features[weaponNoReload];
					case 3 : features[weaponFireAmmo] = !features[weaponFireAmmo];
					case 4 : features[weaponExplosiveAmmo] = !features[weaponExplosiveAmmo];
					case 5 : features[weaponExplosiveMelee] = !features[weaponExplosiveMelee];
				}
				
			else if (pageid == timeOptions)
				switch (elemid) {
					case 1 : {
						features[timePause] = !features[timePause];
						pauseClock(features[timePause]);
					}
					
					case 2 : features[timeSyncWithSystem] = !features[timeSyncWithSystem];
				}
			
			else if (pageid == weatherOptions)
				switch (elemid) {
					case 0 : {
						if ((features[weatherWind] = !features[weatherWind])) {
							setWind(1.0);
							setWindSpeed(11.99);
							setWindDirection(getEntityHeading(playerPed));
						}
						else {
							setWind(0.0);
							setWindSpeed(0.0);
						}
					}
					
					case 1 : features[weatherPersist] = !features[weatherPersist];
					
					case 2 : {
						
					}
				}
			
			else if (pageid == miscOptions)
				switch (elemid) {
					case 0 : setActivePage(trainerMenu, posOptions);
					case 1 : setActivePage(trainerMenu, colorOptions);
					case 2 : setActivePage(trainerMenu, trackerOptions);
				}
			
			else if (pageid == trackerOptions)
				switch (elemid) {
					case 0, 1 : {
						callFunc(
							"toggleTracker", "ii", "tracker", elemid,
							!callFunc("isTrackerActive", "i", "tracker", elemid)
						);
					}
				}
			
			else if (pageid == speedoOptions)
				switch (elemid) {
					case 0 : features[vehicleSpeedo] = !features[vehicleSpeedo];
				}
			
			else
				for (new i; i < sizeof vehiclesInfo; i++) {
					if (vehicleSpawnerList[i] == pageid)
						spawnVehicle(vehiclesInfo[i][vehicleHashes][elemid]);
				}
		}
	}
	
	if (pageid == posOptions) {
		switch (elemid) {
			case 0 : {
				switch (tapType) {
					case ElemTapNavRight :
						if (menuPosX < 0.820)
							menuPosX += 0.010;
					
					case ElemTapNavLeft :
						if (menuPosX > 0.010)
							menuPosX -= 0.010;
				}
					
				setMenuPos(menuid, menuPosX, menuPosY);
				format(temp, _, "<%.3f>", menuPosX);
				setElemValue(menuid, posOptions, elemid, temp);
			}
		
			case 1 : {
				switch (tapType) {
					case ElemTapNavRight :
						if (menuPosY < 0.879)
							menuPosY += 0.010;
					
					case ElemTapNavLeft :
						if (menuPosY > 0.010)
							menuPosY -= 0.010;
				}
					
				setMenuPos(menuid, menuPosX, menuPosY);
				format(temp, _, "<%.3f>", menuPosY);
				setElemValue(menuid, posOptions, elemid, temp);
			}
		}	
	}
	
	if (pageid == speedoOptions) {
		new r = FCOLOR_TO_COLOR(speedoColor[0]),
			g = FCOLOR_TO_COLOR(speedoColor[1]),
			b = FCOLOR_TO_COLOR(speedoColor[2]);
			
		switch (elemid) {
			case 1 : clampValue(r, tapType, 0, 255);
			case 2 : clampValue(g, tapType, 0, 255);
			case 3 : clampValue(b, tapType, 0, 255);
			
			case 4 : {
				r = getRandomInt(0, 255);
				g = getRandomInt(0, 255);
				b = getRandomInt(0, 255);
			}
		}
		
		speedoColor[0] = COLOR_TO_FCOLOR(r);
		speedoColor[1] = COLOR_TO_FCOLOR(g);
		speedoColor[2] = COLOR_TO_FCOLOR(b);
		
		format(temp, _, "<%i>", r), setElemValue(menuid, speedoOptions, 1, temp);
		format(temp, _, "<%i>", g), setElemValue(menuid, speedoOptions, 2, temp);
		format(temp, _, "<%i>", b), setElemValue(menuid, speedoOptions, 3, temp);
	}
	
	if (pageid == colorOptions) {
		switch (elemid) {
			case 0 : clampValue(menuColorR, tapType, 0, 255);
			case 1 : clampValue(menuColorG, tapType, 0, 255);
			case 2 : clampValue(menuColorB, tapType, 0, 255);
			case 3 : {
				menuColorR = getRandomInt(0, 255);
				menuColorG = getRandomInt(0, 255);
				menuColorB = getRandomInt(0, 255);
			}
		}
		
		format(temp, _, "<%i>", menuColorR), setElemValue(menuid, colorOptions, 0, temp);
		format(temp, _, "<%i>", menuColorG), setElemValue(menuid, colorOptions, 1, temp);
		format(temp, _, "<%i>", menuColorB), setElemValue(menuid, colorOptions, 2, temp);
		setMenuColor(menuid, rgbaToInt(menuColorR, menuColorG, menuColorB, 0xDE));
	}
	else if (pageid == timeOptions) {
		if (elemid == 0) {
			new time[@Time3];
			getClockTime(time);
			clampValue(time[@H], tapType, 0, 23);
			format(temp, _, "<%02i>", time[@H]), setElemValue(menuid, timeOptions, 0, temp);
			setClockTime(time);
		}
	}
	else if (pageid == weatherOptions) {
		if (elemid == 2) {
			static index = 0;
			clampValue(index, tapType, 0, sizeof weatherData - 1);
			format(temp, _, "<%s>", weatherData[index]), setElemValue(menuid, weatherOptions, 2, temp);
			
			clearOverrideWeather();
			if (features[weatherPersist]) {
				setOverrideWeather(weatherData[index]);
			}
			else {
				setWeatherNowPersist(weatherData[index]);
				clearWeatherPersist();
			}
		} 
	}
	else if (pageid == playerOptions) {
		if (elemid == 3) {
			new wantedLavel = getPlayerWantedLevel();
			clampValue(wantedLavel, tapType, 0, 5);
			format(temp, _, "<%i>", wantedLavel), setElemValue(menuid, playerOptions, 3, temp);
			setPlayerWantedLevel(wantedLavel);
		}
	}
	return 1;
}

timer updateFeatures() {
	if (features[playerNeverWanted])
		clearPlayerWantedLevel();
		
	if (features[weaponNoReload]) {
		new weapon, maxAmmo;
		getPedCurrentWeapon(playerPed, weapon);
		maxAmmo = getPedMaxAmmoInClip(playerPed, weapon);
		if (maxAmmo > 0)
			setPedAmmoInClip(playerPed, weapon, maxAmmo);
	}
	
	if (features[timeSyncWithSystem]) {
		new time[@Time3];
		getLocalTime({0, 0, 0}, time);
		setClockTime(time);
	}
	
	setEntityInvincible(getPedVehicle(playerPed), features[vehicleInvincible]);
	
	return TIMER_CODE_CONT;
}

stock updateOnFrameFeatures() {
	if (features[weaponFireAmmo])
		setFireAmmoThisFrame();
		
	if (features[weaponExplosiveAmmo])
		setExplosiveAmmoThisFrame();
		
	if (features[weaponExplosiveMelee])
		setExplosiveMeleeThisFrame();
}

stock updateSpeedo() {
	static Float:arrowColor[4] = {1.0, 1.0, 1.0, 0.0};
	static const Float:speedoAlphaMax = 0.8;
	
	if (isPedInAnyVehicle(playerPed, true)) {
		if (isHudComponentActive(HUD_VEHICLE_NAME) || isPedRunningMobilePhoneTask(playerPed)) {
			speedoColor[3] = 0;
			return;
		}
		new Float:rot = getEntitySpeed(getPedVehicle(playerPed)) * 2.51 /*as miles*/ * 1.6 /*as kilometers*/ / 320.0 /*circle max*/ + 0.655 /*arrow initial rotation*/;
		new Float:aspectRatio = getScreenAspectRatio(false);
		
		if (speedoColor[3] < 0.0) speedoColor[3] = 0.0;
		if (speedoColor[3] < speedoAlphaMax) speedoColor[3] += 0.01;
		if (speedoColor[3] > speedoAlphaMax) speedoColor[3] = speedoAlphaMax;
		
		drawTexture(
			texSpeedoBack,
			0, -9999, 100,
			speedoSize,
			speedoCenter,
			speedoPos,
			0.0,
			aspectRatio,
			speedoColor
		);
		
		arrowColor[3] = speedoColor[3];
		drawTexture(
			texSpeedoArrow,
			0, -9998, 100,
			speedoSize,
			speedoCenter,
			speedoPos,
			rot,
			aspectRatio,
			arrowColor
		);
	}
	else {
		speedoColor[3] = 0.0;
	}
}

stock spawnVehicle(hash) {
	if (isModelAVehicle(hash)) {
		if (features[vehicleDeleteLast])
			if (features[vehicleLastSpawned] != -1)
				deleteVehicle(features[vehicleLastSpawned]);
			
		new coords[@Vector3];
		getOffsetFromEntityInWorldPos(playerPed, { 0.0, 5.0, 0.0 }, coords);
		features[vehicleLastSpawned] = createVehicle(hash, coords, getEntityHeading(playerPed));
		setVehicleNumberPlateText(features[vehicleLastSpawned], "NENADO");
		setVehicleNumberPlateTextIndex(features[vehicleLastSpawned], 5);
		
		if (features[vehicleWrapInSpawn])
			setPedIntoVehicle(playerPed, features[vehicleLastSpawned], -1);
			
		return true;
	}
	return false;
}

stock clampValue(&val, type, a=0, b=255) {
	switch (type) {
		case ElemTapNavRight : if (++val > b) val = b;
		case ElemTapNavLeft : if (--val < a) val = a;
	}
}