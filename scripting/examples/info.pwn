#include <amxvhook\amxvhook>
#include <string>

new colorInfo = 0xFFFFFF44;
new temp[255];


public onModUpdate() {
	new pc[@Vector3];
	getPlayerPos(pc);
	
	format(temp, _, "FPS: %d | %.3f, %.3f, %.3f", getFps(), pc[@X], pc[@Y], pc[@Z]);
	drawString(temp, 0.010, 0.010, 0.26, 0, colorInfo);
}