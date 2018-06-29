#include <amxvhook\core>
#include <string>


new temp[255];
new vehicle = -1;
new checkpoint = -1;


public onModInputCommand(cmd[], params) {
	if (strcmp(cmd, "!test") == 0) {
		if (params != 3) return 1;
		
		new p3[32];
		getCommandParams(3, p3);
		
		format(temp, sizeof temp, false, "%d, %d, %f, %s, %H", params, getCommandParamsInt(1), getCommandParamsFloat(2), p3, getCommandParamsHash(4));
		showSubtitle(temp);
	}
	else if (strcmp(cmd, "!cp") == 0) {
		if (params != 1) return 1;
		if (checkpoint != -1) deleteCP(checkpoint);
		
		new Float:pc[@Vector3];
		getPlayerPos(pc);
		pc[@Z] -= 0.9;

		checkpoint = createCP(getCommandParamsInt(1), pc);
		setCPColor(checkpoint, random(255), random(255), random(255), 128);
		setCPCylinderHeight(checkpoint, 0.2, 0.8, 0.2);
		setCPScale(checkpoint, 0.2);
		
		format(temp, sizeof temp, false, "cpid:%d", checkpoint);
		showSubtitle(temp, 4000);
	}
	else if (strcmp(cmd, "!dcheck") == 0) {
		if (checkpoint != -1)
			deleteCP(checkpoint);
	}
	else if (strcmp(cmd, "!veh") == 0) {
		if (params != 1) return 1;
		if (vehicle != -1) deleteVehicle(vehicle);
	
		new Float:pc[@Vector3];
		getPlayerPos(pc);
		
		vehicle = createVehicle(getCommandParamsHash(1), pc, 0);
		
		format(temp, sizeof temp, false, "vehicle: %d", vehicle);
		showSubtitle(temp, 4000);
	}
	else if (strcmp(cmd, "!dveh") == 0) {
		deleteVehicle(vehicle);
		vehicle = -1;
	}
	else if (strcmp(cmd, "!gw") == 0) {
		if (params != 2) return 1;
		givePedWeapon(getPlayerPed(), getCommandParamsHash(1), getCommandParamsInt(2), true);
	}
	else if (strcmp(cmd, "!rw") == 0) {
		if (params != 1) return 1;
		removePedWeapon(getPlayerPed(), getCommandParamsHash(1));
	}
	else if (strcmp(cmd, "!wl") == 0) {
		if (params != 1) return 1;
		setPlayerWantedLevel(getCommandParamsInt(1));
	}
	else if (strcmp(cmd, "!rped") == 0) {
		new Float:pc[@Vector3];
		getPlayerPos(pc);
		createRandomPed(pc);
	}
	return 0;
}