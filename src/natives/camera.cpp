#include "camera.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Camera {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createCam)
				MOD_DEFINE_NATIVE(createCamEx)
				MOD_DEFINE_NATIVE(destroyCam)
				MOD_DEFINE_NATIVE(destroyAllCams)
				MOD_DEFINE_NATIVE(isCamExist)
				MOD_DEFINE_NATIVE(isCamActive)
				MOD_DEFINE_NATIVE(isCamShaking)
				MOD_DEFINE_NATIVE(isCamInterpolating)
				MOD_DEFINE_NATIVE(isCamPlayingAnim)
				MOD_DEFINE_NATIVE(isCamRendering)
				MOD_DEFINE_NATIVE(isGameplayCamRendering)
				MOD_DEFINE_NATIVE(isGameplayCamShaking)
				MOD_DEFINE_NATIVE(isGameplayCamLookingBehind)
				MOD_DEFINE_NATIVE(isCinematicCamRendering)
				MOD_DEFINE_NATIVE(getCamPos)
				MOD_DEFINE_NATIVE(getCamRot)
				MOD_DEFINE_NATIVE(getCamFov)
				MOD_DEFINE_NATIVE(getCamNearClip)
				MOD_DEFINE_NATIVE(getCamFarClip)
				MOD_DEFINE_NATIVE(getCamFarDof)
				MOD_DEFINE_NATIVE(getRenderingCam)
				MOD_DEFINE_NATIVE(getGameplayCamPos)
				MOD_DEFINE_NATIVE(getGameplayCamRot)
				MOD_DEFINE_NATIVE(getGameplayCamFov)
				MOD_DEFINE_NATIVE(getGameplayCamZoom)
				MOD_DEFINE_NATIVE(setCamActive)
				MOD_DEFINE_NATIVE(setCamFov)
				MOD_DEFINE_NATIVE(setCamPos)
				MOD_DEFINE_NATIVE(setCamRot)
				MOD_DEFINE_NATIVE(setCamNearClip)
				MOD_DEFINE_NATIVE(setCamFarClip)
				MOD_DEFINE_NATIVE(setCamMotionBlurStrength)
				MOD_DEFINE_NATIVE(setCamNearDof)
				MOD_DEFINE_NATIVE(setCamFarDof)
				MOD_DEFINE_NATIVE(setCamDofStrength)
				MOD_DEFINE_NATIVE(setCamUseShallowDofMode)
				MOD_DEFINE_NATIVE(setCamParams)
				MOD_DEFINE_NATIVE(setCamShakeAmplitude)
				MOD_DEFINE_NATIVE(setGameplayCamShakeAmplitude)
				MOD_DEFINE_NATIVE(setCinematicCamShakeAmplitude)
				MOD_DEFINE_NATIVE(setScreenFadeIn)
				MOD_DEFINE_NATIVE(setScreenFadeOut)
				MOD_DEFINE_NATIVE(setCinematicButtonActive)
				MOD_DEFINE_NATIVE(setCamPoint)
				MOD_DEFINE_NATIVE(setCamPointAtEntity)
				MOD_DEFINE_NATIVE(setCamPointAtPedBone)
				MOD_DEFINE_NATIVE(shakeCam)
				MOD_DEFINE_NATIVE(shakeGameplayCam)
				MOD_DEFINE_NATIVE(shakeCinematicCam)
				MOD_DEFINE_NATIVE(stopCamShaking)
				MOD_DEFINE_NATIVE(stopGameplayCamShaking)
				MOD_DEFINE_NATIVE(stopCinematicCamShaking)
				MOD_DEFINE_NATIVE(stopCamPointing)
				MOD_DEFINE_NATIVE(showCrosshairThisFrame)
				MOD_DEFINE_NATIVE(attachCamToEntity)
				MOD_DEFINE_NATIVE(attachCamToPedBone)
				MOD_DEFINE_NATIVE(detachCam)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createCam) {
				checkargs(1);

				return CAM::CREATE_CAMERA(params[1], FALSE);
			}

			MOD_NATIVE(createCamEx) {
				checkargs(4);

				cell *coords, *rot;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &rot) != AMX_ERR_NONE)
					return 0;

				return CAM::CREATE_CAMERA_WITH_PARAMS(
					params[1], 
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					amx_ctof(rot[0]), amx_ctof(rot[1]), amx_ctof(rot[2]),
					params[4], FALSE, 2
				);
			}

			MOD_NATIVE(destroyCam) {
				checkargs(1);

				CAM::DESTROY_CAM((::Cam)params[1], TRUE);

				return 1;
			}

			MOD_NATIVE(destroyAllCams) {
				CAM::DESTROY_ALL_CAMS(TRUE);

				return 1;
			}

			MOD_NATIVE(isCamExist) {
				checkargs(1);

				return CAM::DOES_CAM_EXIST((::Cam)params[1]);
			}

			MOD_NATIVE(isCamActive) {
				checkargs(1);

				return CAM::IS_CAM_ACTIVE((::Cam)params[1]);
			}

			MOD_NATIVE(isCamInterpolating) {
				checkargs(1);

				return CAM::IS_CAM_INTERPOLATING((::Cam)params[1]);
			}

			MOD_NATIVE(isCamShaking) {
				checkargs(1);

				return CAM::IS_CAM_SHAKING((::Cam)params[1]);
			}

			MOD_NATIVE(isCamPlayingAnim) {
				checkargs(3);

				return CAM::IS_CAM_PLAYING_ANIM((::Cam)params[1], (Any *)String::get(amx, params[2]).c_str(), (Any *)String::get(amx, params[3]).c_str());
			}
			MOD_NATIVE(isCamRendering) {
				checkargs(1);

				return CAM::IS_CAM_RENDERING((::Cam)params[1]);
			}

			MOD_NATIVE(isGameplayCamRendering) {
				return CAM::IS_GAMEPLAY_CAM_RENDERING();
			}

			MOD_NATIVE(isGameplayCamShaking) {
				return CAM::IS_GAMEPLAY_CAM_SHAKING();
			}

			MOD_NATIVE(isGameplayCamLookingBehind) {
				return CAM::IS_GAMEPLAY_CAM_LOOKING_BEHIND();
			}

			MOD_NATIVE(isCinematicCamRendering) {
				return CAM::IS_CINEMATIC_CAM_RENDERING();
			}

			MOD_NATIVE(getCamPos) {
				checkargs(2);

				Vector3 coords = CAM::GET_CAM_COORD((::Cam)params[1]);
				return Aux::setVector3(amx, params[2], coords);
			}
			MOD_NATIVE(getCamRot) {
				checkargs(2);

				Vector3 coords = CAM::GET_CAM_ROT((::Cam)params[1], 2);
				return Aux::setVector3(amx, params[2], coords);
			}

			MOD_NATIVE(getCamFov) {
				checkargs(1);

				float fov = CAM::GET_CAM_FOV((::Cam)params[1]);

				return amx_ftoc(fov);
			}

			MOD_NATIVE(getCamNearClip) {
				checkargs(1);

				float clip = CAM::GET_CAM_NEAR_CLIP((::Cam)params[1]);

				return amx_ftoc(clip);
			}

			MOD_NATIVE(getCamFarClip) {
				checkargs(1);

				float clip = CAM::GET_CAM_FAR_CLIP((::Cam)params[1]);

				return amx_ftoc(clip);
			}

			MOD_NATIVE(getCamFarDof) {
				checkargs(1);

				float dof = CAM::GET_CAM_FAR_DOF((::Cam)params[1]);

				return amx_ftoc(dof);
			}

			MOD_NATIVE(getRenderingCam) {
				return CAM::GET_RENDERING_CAM();
			}

			MOD_NATIVE(getGameplayCamPos) {
				checkargs(1);

				Vector3 coords = CAM::GET_GAMEPLAY_CAM_COORD();

				return Aux::setVector3(amx, params[1], coords);
			}

			MOD_NATIVE(getGameplayCamRot) {
				checkargs(1);

				Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(params[2]);

				return Aux::setVector3(amx, params[1], rot);
			}

			MOD_NATIVE(getGameplayCamFov) {
				float fov = CAM::GET_GAMEPLAY_CAM_FOV();
				return amx_ftoc(fov);
			}

			MOD_NATIVE(getGameplayCamZoom) {
				float fov = CAM::_GET_GAMEPLAY_CAM_ZOOM();
				return amx_ftoc(fov);
			}

			MOD_NATIVE(setCamActive) {
				checkargs(2);

				CAM::SET_CAM_ACTIVE((::Cam)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setCamFov) {
				checkargs(2);

				CAM::SET_CAM_FOV((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamPos) {
				checkargs(2);

				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				CAM::SET_CAM_COORD((::Cam)params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]));

				return 1;
			}

			MOD_NATIVE(setCamRot) {
				checkargs(2);

				cell *rot;
				if (amx_GetAddr(amx, params[2], &rot) != AMX_ERR_NONE)
					return 0;

				CAM::SET_CAM_ROT((::Cam)params[1], amx_ctof(rot[0]), amx_ctof(rot[1]), amx_ctof(rot[2]), 2);

				return 1;
			}

			MOD_NATIVE(setCamNearClip) {
				checkargs(2);

				CAM::SET_CAM_NEAR_CLIP((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamFarClip) {
				checkargs(2);

				CAM::SET_CAM_FAR_CLIP((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamMotionBlurStrength) {
				checkargs(2);

				CAM::SET_CAM_MOTION_BLUR_STRENGTH((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamNearDof) {
				checkargs(2);

				CAM::SET_CAM_NEAR_DOF((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamFarDof) {
				checkargs(2);

				CAM::SET_CAM_FAR_DOF((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamDofStrength) {
				checkargs(2);

				CAM::SET_CAM_DOF_STRENGTH((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamUseShallowDofMode) {
				checkargs(2);

				CAM::SET_CAM_USE_SHALLOW_DOF_MODE((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setCamParams) {
				checkargs(4);

				cell *coords, *rot;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &rot) != AMX_ERR_NONE)
					return 0;

				CAM::SET_CAM_PARAMS(
					(::Cam)params[1],
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					amx_ctof(rot[0]), amx_ctof(rot[1]), amx_ctof(rot[2]),
					amx_ctof(params[4]),
					NULL, NULL, NULL, NULL
				);

				return 1;
			}

			MOD_NATIVE(setCamShakeAmplitude) {
				checkargs(2);

				CAM::SET_CAM_SHAKE_AMPLITUDE((::Cam)params[1], amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setGameplayCamShakeAmplitude) {
				checkargs(1);

				CAM::SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(setCinematicCamShakeAmplitude) {
				checkargs(1);

				CAM::SET_CINEMATIC_CAM_SHAKE_AMPLITUDE(amx_ctof(params[1]));

				return 1;
			}

			MOD_NATIVE(setScreenFadeIn) {
				checkargs(1);

				CAM::DO_SCREEN_FADE_IN(params[1]);

				return 1;
			}

			MOD_NATIVE(setScreenFadeOut) {
				checkargs(1);

				CAM::DO_SCREEN_FADE_OUT(params[1]);

				return 1;
			}

			MOD_NATIVE(setCinematicButtonActive) {
				checkargs(1);

				CAM::SET_CINEMATIC_BUTTON_ACTIVE(params[1]);

				return 1;
			}

			MOD_NATIVE(setCamPoint) {
				checkargs(2);

				cell *coords;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE)
					return 0;

				CAM::POINT_CAM_AT_COORD((::Cam)params[1], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]));

				return 1;
			}

			MOD_NATIVE(setCamPointAtEntity) {
				checkargs(3);

				cell *coords;
				if (amx_GetAddr(amx, params[3], &coords) != AMX_ERR_NONE)
					return 0;

				CAM::POINT_CAM_AT_ENTITY((::Cam)params[1], (::Entity)params[2], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), TRUE);

				return 1;
			}

			MOD_NATIVE(setCamPointAtPedBone) {
				checkargs(4);

				cell *coords;
				if (amx_GetAddr(amx, params[4], &coords) != AMX_ERR_NONE)
					return 0;

				CAM::POINT_CAM_AT_PED_BONE((::Cam)params[1], (::Entity)params[2], params[3], amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), TRUE);

				return 1;
			}

			MOD_NATIVE(shakeCam) {
				checkargs(3);

				CAM::SHAKE_CAM((::Cam)params[1], (char *)String::get(amx, params[2]).c_str(), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(shakeGameplayCam) {
				checkargs(2);

				CAM::SHAKE_GAMEPLAY_CAM((char *)String::get(amx, params[1]).c_str(), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(shakeCinematicCam) {
				checkargs(2);

				CAM::SHAKE_CINEMATIC_CAM((char *)String::get(amx, params[1]).c_str(), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(stopCamShaking) {
				checkargs(2);

				CAM::STOP_CAM_SHAKING((::Cam)params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(stopGameplayCamShaking) {
				checkargs(1);

				CAM::STOP_GAMEPLAY_CAM_SHAKING(params[1]);

				return 1;
			}

			MOD_NATIVE(stopCinematicCamShaking) {
				checkargs(1);

				CAM::STOP_CINEMATIC_CAM_SHAKING(params[1]);

				return 1;
			}

			MOD_NATIVE(stopCamPointing) {
				checkargs(1);

				CAM::STOP_CAM_POINTING((::Cam)params[1]);

				return 1;
			}

			MOD_NATIVE(showCrosshairThisFrame) {
				CAM::_ENABLE_CROSSHAIR_THIS_FRAME();

				return 1;
			}

			MOD_NATIVE(attachCamToEntity) {
				checkargs(4);

				cell *offset;
				if (amx_GetAddr(amx, params[3], &offset) != AMX_ERR_NONE)
					return 0;

				CAM::ATTACH_CAM_TO_ENTITY((::Cam)params[1], (::Entity)params[2], amx_ctof(offset[0]), amx_ctof(offset[1]), amx_ctof(offset[2]), params[4]);

				return 1;
			}

			MOD_NATIVE(attachCamToPedBone) {
				checkargs(5);

				cell *offset;
				if (amx_GetAddr(amx, params[4], &offset) != AMX_ERR_NONE)
					return 0;

				CAM::ATTACH_CAM_TO_PED_BONE((::Cam)params[1], (::Ped)params[2], params[3], amx_ctof(offset[0]), amx_ctof(offset[1]), amx_ctof(offset[2]), params[5]);

				return 1;
			}

			MOD_NATIVE(detachCam) {
				checkargs(1);

				CAM::DETACH_CAM((::Cam)params[1]);

				return 1;
			}
		};
	};
};