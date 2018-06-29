#include <amxvhook\core>
#include <string>


new colorInfo = toRGBA(255, 255, 255, 128);
new temp[255];


public onModUpdate() {
	new Float:pc[@Vector3];
	getPlayerPos(pc);
	format(temp, sizeof temp, false, "FPS: %d | %.3f, %.3f, %.3f", getFps(), pc[@X], pc[@Y], pc[@Z]);
	drawText(temp, 0.010, 0.010, 0.26, 0, colorInfo);
}