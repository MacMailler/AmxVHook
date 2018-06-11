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

native createCam(camHash);
native createCamEx(camHash, Float:pos[@Vector3], Float:rot[@Vector3], Float:fov);

native destroyCam(cam);
native destroyAllCams();

native isCamExist(cam);
native isCamActive(cam);
native isCamInterpolating(cam);
native isCamShaking(cam);
native isCamPlayingAnim(cam, const animName[], const animDict[]);
native isCamRendering(cam);

native getCamPos(cam, Float:pos[@Vector3]);
native getCamRot(cam, Float:rot[@Vector3]);
native Float:getCamFov(cam);
native Float:getCamNearClip(cam);
native Float:getCamFarClip(cam);
native Float:getCamFarDof(cam);
native getRenderingCam();

native setCamActive(cam);
native setCamFov(cam, Float:fov);
native setCamPos(cam, Float:pos[@Vector3]);
native setCamRot(cam, Float:rot[@Vector3]);
native setCamNearClip(cam, Float:near);
native setCamFarClip(cam, Float:far);
native setCamMotionBlurStrength(cam, Float:strength);
native setCamNearDof(cam, Float:near);
native setCamFarDof(cam, Float:far);
native setCamDofStrength(cam, Float:strength);
native setCamUseShallowDofMode(cam, bool:toggle);
native setCamParams(cam, Float:pos[@Vector3], Float:rot[@Vector3], Float:fov);

native attachCamToEntity(cam, entity, Float:offset[@Vector3], bool:relative);
native attachCamToPedBone(cam, ped, boneIndex, Float:pos[@Vector3], bool:heading);

native detachCam(cam);