#if defined __time_inc__
  #endinput
#endif
#define __time_inc__


native pauseClock(bool:toggle);

native advanceClockTimeTo(const time[@Time3]);
native addToClockTime(const time[@Time3]);

native setClockTime(const time[@Time3]);
native setClockDate(const date[@Date3]);

native getClockTime(time[@Time3]);
native getClockDate(date[@Date3]);
native getClockDayOfWeek();
native getClockDayOfMonth();
native getMillisecondsPerGameMinute();
native getPosixTime(date[@Date3], time[@Time3]);
native getLocalTime(date[@Date3], time[@Time3]);