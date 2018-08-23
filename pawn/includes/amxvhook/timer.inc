#if defined __timer_inc__
  #endinput
#endif
#define __timer_inc__

#define timer%0(%1) forward%0(%1); public%0(%1)

#define TIMER_CODE_DROP (0)
#define TIMER_CODE_CONT (1)
#define TIMER_CODE_PAUSE (2)

native addTimer(const funcname[], interval, const f[]="", {Float, _}:...);
native dropTimer(timerid);
native stopTimer(timerid, bool:stop);

native isTimerExist(timerid);
native isTimerStopped(timerid);

native setTimerInterval(timerid, interval);
native setTimerData(timerid, const f[]="", {Float, _}:...);