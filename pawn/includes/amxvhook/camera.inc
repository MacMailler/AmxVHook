#if defined __camera_inc__
  #endinput
#endif
#define __camera_inc__

enum eCamHash {
	DEFAULT_SCRIPTED_CAMERA = 0x19286A9,
	DEFAULT_ANIMATED_CAMERA = 0x397ED48C,
	DEFAULT_SPLINE_CAMERA = 0xAC2E098,
	DEFAULT_SCRIPTED_FLY_CAMERA = 0xFFE1773D,
	TIMED_SPLINE_CAMERA = 0x69D5F9D0,
};

//native createCam(camHash);
native getRenderingCam();

native setCamFov(cam, Float:fov);