#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Time {
			MOD_NATIVE(pauseClock);
			MOD_NATIVE(advanceClockTimeTo);
			MOD_NATIVE(addToClockTime);
			MOD_NATIVE(setClockTime);
			MOD_NATIVE(setClockDate);
			MOD_NATIVE(getClockTime);
			MOD_NATIVE(getClockDate);
			MOD_NATIVE(getClockDayOfWeek);
			MOD_NATIVE(getClockDayOfMonth);
			MOD_NATIVE(getMillisecondsPerGameMinute);
			MOD_NATIVE(getPosixTime);
			MOD_NATIVE(getLocalTime);

			AMX_NATIVE_INFO list[];
		};
	};
};