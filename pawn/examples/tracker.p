#include <amxvhook\core>
#include <string>


new bool:tracker = false;
new temp[128];

new peds[1024];
new vehicles[1024];

new colorAlive = toRGBA(101, 101, 101, 75);
new colorDead = toRGBA(200, 75, 75, 160);


public onModUpdate() {
	if (isKeyJustUp(VK_NUMPAD0))
		tracker = !tracker;
		
	if (!tracker)
		return 1;
		
	if (isMissionFlag())
		return 1;
		
	new playerPed = getPlayerPed();
	if (!isEntityExist(playerPed) || !isPlayerControlOn() || isPedDead(playerPed))
		return 1;
	
	new	Float:pc[@Vector3];
	getEntityPos(playerPed, pc);
	for (new i = 0, count = getAllVehicles(vehicles); i < count; i++) {	
		new	Float:vc[@Vector3], Float:sx, Float:sy;
		getEntityPos(vehicles[i], vc);
		new model = getEntityModel(vehicles[i]);
		
		if (world3DToScreen2D(vc, sx, sy)) {
			new Float:dist = getDistanceBetweenPos(vc, pc);
			if (dist < 20.0) {
				new name[32];
				getDisplayNameFromVehicleModel(model, name);
				
				format(
					temp, sizeof temp,
					"^\n%s\n| Distance %.2f\n| Health %.2f\n| Speed %.1f km'h\n| %.1f %.1f %.1f",
					name, dist, getEntityHealth(vehicles[i]), getEntitySpeed(vehicles[i]) * 3.6, vc[@X], vc[@Y], vc[@Z]
				);
				drawText(temp, sx, sy, 0.2);
				drawRect(sx, sy, 0.058, 0.086, isEntityDead(vehicles[i]) ? colorDead : colorAlive);
			}
		}
	}
	
	for (new i = 0, count = getAllPeds(peds); i < count; i++) {
		if (peds[i] == playerPed)
			continue;
			
		if (isPedInAnyVehicle(peds[i], true))
			continue;
			
		new	Float:pos[@Vector3], Float:sx, Float:sy;
		getEntityPos(peds[i], pos);
		
		if (world3DToScreen2D(pos, sx, sy)) {
			new Float:dist = getDistanceBetweenPos(pos, pc);
			if (dist < 20.0) {				
				format(
					temp, sizeof temp,
					"^\n%d\n| Distance %.2f\n| %.1f %.1f %.1f",
					peds[i], dist, pos[@X], pos[@Y], pos[@Z]
				);
				drawText(temp, sx, sy, 0.2);
				drawRect(sx, sy, 0.058, 0.056, isEntityDead(peds[i]) ? colorDead : colorAlive);
			}
		}
	}
	
	return 1;
}