#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Camera {
			MOD_NATIVE(createCam);
			MOD_NATIVE(createCamEx);
			MOD_NATIVE(destroyCam);
			MOD_NATIVE(destroyAllCams);
			MOD_NATIVE(isCamExist);
			MOD_NATIVE(isCamActive);
			MOD_NATIVE(isCamShaking);
			MOD_NATIVE(isCamInterpolating);
			MOD_NATIVE(isCamPlayingAnim);
			MOD_NATIVE(isCamRendering);
			MOD_NATIVE(isGameplayCamRendering);
			MOD_NATIVE(isGameplayCamShaking);
			MOD_NATIVE(isGameplayCamLookingBehind);
			MOD_NATIVE(isCinematicCamRendering);
			MOD_NATIVE(getCamPos);
			MOD_NATIVE(getCamRot);
			MOD_NATIVE(getCamFov);
			MOD_NATIVE(getCamNearClip);
			MOD_NATIVE(getCamFarClip);
			MOD_NATIVE(getCamFarDof);
			MOD_NATIVE(setCamActive);
			MOD_NATIVE(getRenderingCam);
			MOD_NATIVE(getGameplayCamPos);
			MOD_NATIVE(getGameplayCamRot);
			MOD_NATIVE(getGameplayCamFov);
			MOD_NATIVE(getGameplayCamZoom);
			MOD_NATIVE(setCamFov);
			MOD_NATIVE(setCamPos);
			MOD_NATIVE(setCamRot);
			MOD_NATIVE(setCamNearClip);
			MOD_NATIVE(setCamFarClip);
			MOD_NATIVE(setCamMotionBlurStrength);
			MOD_NATIVE(setCamNearDof);
			MOD_NATIVE(setCamFarDof);
			MOD_NATIVE(setCamDofStrength);
			MOD_NATIVE(setCamUseShallowDofMode);
			MOD_NATIVE(setCamParams);
			MOD_NATIVE(setCamShakeAmplitude);
			MOD_NATIVE(setGameplayCamShakeAmplitude);
			MOD_NATIVE(setCinematicCamShakeAmplitude);
			MOD_NATIVE(setScreenFadeIn);
			MOD_NATIVE(setScreenFadeOut);
			MOD_NATIVE(setCinematicButtonActive);
			MOD_NATIVE(setCamPoint);
			MOD_NATIVE(setCamPointAtEntity);
			MOD_NATIVE(setCamPointAtPedBone);
			MOD_NATIVE(shakeCam);
			MOD_NATIVE(shakeGameplayCam);
			MOD_NATIVE(shakeCinematicCam);
			MOD_NATIVE(stopCamShaking);
			MOD_NATIVE(stopGameplayCamShaking);
			MOD_NATIVE(stopCinematicCamShaking);
			MOD_NATIVE(stopCamPointing);
			MOD_NATIVE(showCrosshairThisFrame);
			MOD_NATIVE(attachCamToEntity);
			MOD_NATIVE(attachCamToPedBone);
			MOD_NATIVE(detachCam);

			AMX_NATIVE_INFO list[];
		};
	};
};