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
				checkargs(1);

				TIME::PAUSE_CLOCK(params[1]);

				return 1;
			}

			MOD_NATIVE(advanceClockTimeTo) {
				checkargs(1);

				cell *time;
				if (amx_GetAddr(amx, params[1], &time) != AMX_ERR_NONE)
					return 0;

				TIME::ADVANCE_CLOCK_TIME_TO(time[0], time[1], time[2]);

				return 1;
			}

			MOD_NATIVE(addToClockTime) {
				checkargs(1);

				cell *time;
				if (amx_GetAddr(amx, params[1], &time) != AMX_ERR_NONE)
					return 0;

				TIME::ADD_TO_CLOCK_TIME(time[0], time[1], time[2]);

				return 1;
			}

			MOD_NATIVE(setClockTime) {
				checkargs(1);

				cell *time;
				if (amx_GetAddr(amx, params[1], &time) != AMX_ERR_NONE)
					return 0;

				TIME::SET_CLOCK_TIME(time[0], time[1], time[2]);

				return 1;
			}

			MOD_NATIVE(setClockDate) {
				checkargs(1);

				cell *time;
				if (amx_GetAddr(amx, params[1], &time) != AMX_ERR_NONE)
					return 0;

				TIME::SET_CLOCK_DATE(time[2], time[1], time[0]);

				return 1;
			}

			MOD_NATIVE(getClockTime) {
				checkargs(1);

				cell time[3];
				time[0] = TIME::GET_CLOCK_HOURS();
				time[1] = TIME::GET_CLOCK_MINUTES();
				time[2] = TIME::GET_CLOCK_SECONDS();

				return Aux::setArray(amx, params[1],  time, 3);
			}

			MOD_NATIVE(getClockDate) {
				checkargs(1);

				cell data[3];
				data[0] = TIME::GET_CLOCK_YEAR();
				data[1] = TIME::GET_CLOCK_MONTH();
				data[2] = 0;

				return Aux::setArray(amx, params[1], data, 3);
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
				checkargs(2);

				cell date[3], time[3];
				TIME::GET_POSIX_TIME(&date[0], &date[1], &date[2], &time[0], &time[1], &time[2]);

				Aux::setArray(amx, params[1], date, 3);
				Aux::setArray(amx, params[2], time, 3);

				return 1;
			}

			MOD_NATIVE(getLocalTime) {
				checkargs(2);

				cell date[3], time[3];
				TIME::GET_LOCAL_TIME(&date[0], &date[1], &date[2], &time[0], &time[1], &time[2]);

				Aux::setArray(amx, params[1], date, 3);
				Aux::setArray(amx, params[2], time, 3);

				return 1;
			}
		};
	};
};