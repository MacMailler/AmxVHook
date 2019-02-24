#include <amxvhook\amxvhook>

forward bool:isTrackerActive(id);
forward toggleTracker(id, bool:toggle);

new bool:tracker[1 char] = false;
new temp[128];

new colorAlive = 0xDEDEDE22;
new colorDead = 0xAE114033;


public onModUpdate() {
	if (isMissionFlag())
		return 1;
		
	new playerPed = getPlayerPed();
	if (!isEntityExist(playerPed) || !isPlayerControlOn() || isPedDead(playerPed))
		return 1;
			
	if (tracker{0}) {
		new	pc[@Vector3];
		getEntityPos(playerPed, pc);
		
		new vehicles[1024];
		for (new i = 0, count = getAllVehicles(vehicles); i < count; i++) {	
			new	vc[@Vector3], Float:sx, Float:sy;
			getEntityPos(vehicles[i], vc);
			new model = getEntityModel(vehicles[i]);
			
			if (world3DToScreen2D(vc, sx, sy)) {
				new Float:dist = getDistanceBetweenPos(vc, pc);
				if (dist < 20.0) {
					new name[32];
					getDisplayNameFromVehicleModel(model, name);
					getLabelText(name, name);
					
					format(
						temp, _,
						"^\n%s\n| Distance %.2f\n| Health %.2f\n| Speed %.1f km'h\n| %.1f %.1f %.1f",
						name, dist, getEntityHealth(vehicles[i]), getEntitySpeed(vehicles[i]) * 3.6, vc[@X], vc[@Y], vc[@Z]
					);

					drawString(temp, sx, sy, 0.2);
					drawRect(sx, sy, 0.058, 0.086, isEntityDead(vehicles[i]) ? colorDead : colorAlive);
				}
			}
		}
	}
	
	if (tracker{1}) {
		new	pc[@Vector3];
		getEntityPos(playerPed, pc);
		
		new peds[1024];
		for (new i = 0, count = getAllPeds(peds); i < count; i++) {
			if (peds[i] == playerPed)
				continue;
				
			if (isPedInAnyVehicle(peds[i], true))
				continue;
				
			new pos[@Vector3], Float:sx, Float:sy;
			getEntityPos(peds[i], pos);
			
			if (world3DToScreen2D(pos, sx, sy)) {
				new Float:dist = getDistanceBetweenPos(pos, pc);
				if (dist < 20.0) {				
					format(
						temp, sizeof temp,
						"^\n%d\n| Distance %.2f\n| %.1f %.1f %.1f",
						peds[i], dist, pos[@X], pos[@Y], pos[@Z]
					);
					drawString(temp, sx, sy, 0.2);
					drawRect(sx, sy, 0.058, 0.056, isEntityDead(peds[i]) ? colorDead : colorAlive);
				}
			}
		}
	}
	
	return 1;
}

public bool:isTrackerActive(id) {
	if (0 <= id <= 1)
		return tracker{id};

	return false;
}

public toggleTracker(id, bool:toggle) {
	if (0 <= id <= 1)
		tracker{id} = toggle;
}