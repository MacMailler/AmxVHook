#include "time.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Time {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(pauseClock)
				MOD_DEFINE_NATIVE(advanceClockTimeTo)
				MOD_DEFINE_NATIVE(addToClockTime)
				MOD_DEFINE_NATIVE(setClockTime)
				MOD_DEFINE_NATIVE(setClockDate)
				MOD_DEFINE_NATIVE(getClockTime)
				MOD_DEFINE_NATIVE(getClockDate)
				MOD_DEFINE_NATIVE(getClockDayOfWeek)
				MOD_DEFINE_NATIVE(getClockDayOfMonth)
				MOD_DEFINE_NATIVE(getMillisecondsPerGameMinute)
				MOD_DEFINE_NATIVE(getPosixTime)
				MOD_DEFINE_NATIVE(getLocalTime)

				{ NULL, NULL } // terminator
			};

			MOD_NATIVE(pauseClock) {
				if (!arguments(1))
					return 0;

				TIME::PAUSE_CLOCK(params[1]);

				return 1;
			}

			MOD_NATIVE(advanceClockTimeTo) {
				if (!arguments(1))
					return 0;

				cell time[3];
				if (!Utility::getArrayFromParam(amx, params[1], time, 3))
					return 0;

				TIME::ADVANCE_CLOCK_TIME_TO(time[0], time[1], time[2]);

				return 1;
			}

			MOD_NATIVE(addToClockTime) {
				if (!arguments(1))
					return 0;

				cell time[3];
				if (!Utility::getArrayFromParam(amx, params[1], time, 3))
					return 0;

				TIME::ADD_TO_CLOCK_TIME(time[0], time[1], time[2]);

				return 1;
			}

			MOD_NATIVE(setClockTime) {
				if (!arguments(1))
					return 0;

				cell time[3];
				if (!Utility::getArrayFromParam(amx, params[1], time, 3))
					return 0;

				TIME::SET_CLOCK_TIME(time[0], time[1], time[2]);

				return 1;
			}

			MOD_NATIVE(setClockDate) {
				if (!arguments(1))
					return 0;

				cell time[3];
				if (!Utility::getArrayFromParam(amx, params[1], time, 3))
					return 0;

				TIME::SET_CLOCK_DATE(time[2], time[1], time[0]);

				return 1;
			}

			MOD_NATIVE(getClockTime) {
				if (!arguments(1))
					return 0;

				cell time[3];
				time[0] = TIME::GET_CLOCK_HOURS();
				time[1] = TIME::GET_CLOCK_MINUTES();
				time[2] = TIME::GET_CLOCK_SECONDS();

				Utility::setArrayToParam(amx, params[1],  time, 3);

				return 1;
			}

			MOD_NATIVE(getClockDate) {
				if (!arguments(1))
					return 0;

				cell time[3];
				time[0] = TIME::GET_CLOCK_YEAR();
				time[1] = TIME::GET_CLOCK_MONTH();
				time[2] = 0;

				Utility::setArrayToParam(amx, params[1], time, 3);

				return 1;
			}

			MOD_NATIVE(getClockDayOfWeek) {
				return TIME::GET_CLOCK_DAY_OF_WEEK();
			}

			MOD_NATIVE(getClockDayOfMonth) {
				return TIME::GET_CLOCK_DAY_OF_MONTH();
			}
			MOD_NATIVE(getMillisecondsPerGameMinute) {
				return TIME::GET_MILLISECONDS_PER_GAME_MINUTE();
			}

			MOD_NATIVE(getPosixTime) {
				if (!arguments(2))
					return 0;

				cell date[3], time[3];
				TIME::GET_POSIX_TIME(&date[0], &date[1], &date[2], &time[0], &time[1], &time[2]);

				Utility::setArrayToParam(amx, params[1], date, 3);
				Utility::setArrayToParam(amx, params[2], time, 3);

				return 1;
			}

			MOD_NATIVE(getLocalTime) {
				if (!arguments(2))
					return 0;

				cell date[3], time[3];
				TIME::GET_LOCAL_TIME(&date[0], &date[1], &date[2], &time[0], &time[1], &time[2]);

				Utility::setArrayToParam(amx, params[1], date, 3);
				Utility::setArrayToParam(amx, params[2], time, 3);

				return 1;
			}
		};
	};
};