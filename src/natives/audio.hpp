#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Audio {
			MOD_NATIVE(isSoundFinished);
			MOD_NATIVE(isRadioRetuning);

			MOD_NATIVE(getSoundId);
			MOD_NATIVE(getRadioStationIndex);
			MOD_NATIVE(getRadioStationName);
			MOD_NATIVE(releaseSoundId);

			MOD_NATIVE(playSound);
			MOD_NATIVE(playSoundFrontend);
			MOD_NATIVE(playSoundFromEntity);
			MOD_NATIVE(playSoundFromPos);
			MOD_NATIVE(stopSound);

			MOD_NATIVE(skipRadioForward);
			MOD_NATIVE(freezeRadioStation);
			MOD_NATIVE(unfreezeRadioStation);

			MOD_NATIVE(loadStream);
			MOD_NATIVE(loadStreamWithOffset);
			MOD_NATIVE(playStreamFromPed);
			MOD_NATIVE(playStreamFromVehicle);
			MOD_NATIVE(playStreamFromObject);
			MOD_NATIVE(playStreamFrontend);
			MOD_NATIVE(stopStream);

			MOD_NATIVE(isAlarmPlaying);
			MOD_NATIVE(prepareAlarm);
			MOD_NATIVE(startAlarm);
			MOD_NATIVE(stopAlarm);
			MOD_NATIVE(stopAllAlarms);

			AMX_NATIVE_INFO list[];
		};
	};
};