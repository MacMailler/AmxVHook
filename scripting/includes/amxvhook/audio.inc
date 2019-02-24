#if defined __audio_inc__
  #endinput
#endif
#define __audio_inc__


native isSoundFinished(soundId);
native isRadioRetuning(soundId);

native getSoundId();
native releaseSoundId(soundId);

native getRadioStationIndex();
native getRadioStationName(stationIndex, dest[], len = sizeof dest);

native playSound(soundId, const audioName[], const audioRef[], bool:p3, bool:p4, bool:p5);
native playSoundFrontend(soundId, const audioName[], const audioRef[]);
native playSoundFromEntity(soundId, const audioName[], const audioRef[], entity);
native playSoundFromPos(soundId, const audioName[], const audioRef[], coords[@Vector3], range);

native stopSound(soundId);

native skipRadioForward();
native freezeRadioStation(const radioStation[]);
native unfreezeRadioStation(const radioStation[]);

native loadStream(const streamName[], const soundSet[]);
native loadStreamWithOffset(const streamName[], const soundSet[], offset);
native playStreamFromPed(ped);
native playStreamFromVehicle(vehicle);
native playStreamFromObject(object);
native playStreamFrontend();
native stopStream();

native isAlarmPlaying(const alarmName[]);
native prepareAlarm(const alarmName[]);
native startAlarm(const alarmName[]);
native stopAlarm(const alarmName[], bool:toggle);
native stopAllAlarms();