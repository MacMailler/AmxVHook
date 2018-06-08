#include <amxvhook\core>
#include <string>


new colorInfo[@RGBA] = {255, 255, 255, 128};
new temp[255];


public onModUpdate() {
	new Float:pc[@Vector3];
	getPlayerPos(pc);
	format(temp, sizeof temp, false, "FPS: %d | %.3f, %.3f, %.3f", getFps(), pc[@X], pc[@Y], pc[@Z]);
	drawText(temp, 0.010, 0.010, 0.26, 0, colorInfo);
}

stock getFps() {
	static timer, frames = 0, last_frames = 0;
	
	if (getGameTimer() - timer < 1000)
		frames ++;
	else
		timer = getGameTimer(), last_frames = frames, frames = 0;
		
	return last_frames;
}