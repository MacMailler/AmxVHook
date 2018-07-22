#include "audio.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Audio {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isSoundFinished)
				MOD_DEFINE_NATIVE(isRadioRetuning)

				MOD_DEFINE_NATIVE(getSoundId)
				MOD_DEFINE_NATIVE(getRadioStationIndex)
				MOD_DEFINE_NATIVE(getRadioStationName)
				MOD_DEFINE_NATIVE(releaseSoundId)

				MOD_DEFINE_NATIVE(playSound)
				MOD_DEFINE_NATIVE(playSoundFrontend)
				MOD_DEFINE_NATIVE(playSoundFromEntity)
				MOD_DEFINE_NATIVE(playSoundFromPos)
				MOD_DEFINE_NATIVE(stopSound)

				MOD_DEFINE_NATIVE(skipRadioForward)
				MOD_DEFINE_NATIVE(freezeRadioStation)
				MOD_DEFINE_NATIVE(unfreezeRadioStation)

				MOD_DEFINE_NATIVE(loadStream)
				MOD_DEFINE_NATIVE(loadStreamWithOffset)
				MOD_DEFINE_NATIVE(playStreamFromPed)
				MOD_DEFINE_NATIVE(playStreamFromVehicle)
				MOD_DEFINE_NATIVE(playStreamFromObject)
				MOD_DEFINE_NATIVE(playStreamFrontend)
				MOD_DEFINE_NATIVE(stopStream)

				MOD_DEFINE_NATIVE(isAlarmPlaying)
				MOD_DEFINE_NATIVE(prepareAlarm)
				MOD_DEFINE_NATIVE(startAlarm)
				MOD_DEFINE_NATIVE(stopAlarm)
				MOD_DEFINE_NATIVE(stopAllAlarms)
				
				{NULL, NULL}
			};

			MOD_NATIVE(isSoundFinished) {
				if (!arguments(1))
					return 0;

				return AUDIO::HAS_SOUND_FINISHED(params[1]);
			}

			MOD_NATIVE(isRadioRetuning) {
				return AUDIO::IS_RADIO_RETUNING();
			}

			MOD_NATIVE(getSoundId) {
				return AUDIO::GET_SOUND_ID();
			}

			MOD_NATIVE(getRadioStationIndex) {
				return AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
			}

			MOD_NATIVE(getRadioStationName) {
				if (!arguments(3))
					return 0;

				char * name = AUDIO::GET_RADIO_STATION_NAME(params[1]);
				String::set(amx, params[2], name, params[3]);

				return 1;
			}

			MOD_NATIVE(releaseSoundId) {
				if (!arguments(1))
					return 0;

				AUDIO::RELEASE_SOUND_ID(params[1]);

				return 1;
			}

			MOD_NATIVE(playSound) {
				if (!arguments(6))
					return 0;

				AUDIO::PLAY_SOUND(params[1], (char *)String::get(amx, params[2]).c_str(), (char *)String::get(amx, params[3]).c_str(), params[4], params[5], params[6]);

				return 1;
			}

			MOD_NATIVE(playSoundFrontend) {
				if (!arguments(3))
					return 0;

				AUDIO::PLAY_SOUND_FRONTEND(params[1], (char *)String::get(amx, params[2]).c_str(), (char *)String::get(amx, params[3]).c_str(), FALSE);

				return 1;
			}

			MOD_NATIVE(playSoundFromEntity) {
				if (!arguments(4))
					return 0;

				AUDIO::PLAY_SOUND_FROM_ENTITY(params[1], (char *)String::get(amx, params[2]).c_str(), params[4], (char *)String::get(amx, params[3]).c_str(), FALSE, FALSE);

				return 1;
			}
			MOD_NATIVE(playSoundFromPos) {
				if (!arguments(5))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[4], coords, 3))
					return 0;

				AUDIO::PLAY_SOUND_FROM_COORD(
					params[1],
					(char *)String::get(amx, params[2]).c_str(),
					coords[0], coords[1], coords[2],
					(char *)String::get(amx, params[3]).c_str(),
					FALSE, params[5], FALSE
				);

				return 1;
			}

			MOD_NATIVE(stopSound) {
				if (!arguments(1))
					return 0;

				AUDIO::STOP_SOUND(params[1]);

				return 1;
			}

			MOD_NATIVE(skipRadioForward) {
				AUDIO::SKIP_RADIO_FORWARD();

				return 1;
			}

			MOD_NATIVE(freezeRadioStation) {
				if (!arguments(1))
					return 0;

				AUDIO::FREEZE_RADIO_STATION((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(unfreezeRadioStation) {
				if (!arguments(1))
					return 0;

				AUDIO::UNFREEZE_RADIO_STATION((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(loadStream) {
				if (!arguments(2))
					return 0;

				return AUDIO::LOAD_STREAM((char *)String::get(amx, params[1]).c_str(), (char *)String::get(amx, params[2]).c_str());
			}

			MOD_NATIVE(loadStreamWithOffset) {
				if (!arguments(3))
					return 0;

				return AUDIO::LOAD_STREAM_WITH_START_OFFSET((char *)String::get(amx, params[1]).c_str(), params[3], (char *)String::get(amx, params[2]).c_str());
			}

			MOD_NATIVE(playStreamFromPed) {
				if (!arguments(1))
					return 0;

				AUDIO::_0x89049DD63C08B5D1(params[1]);

				return 1;
			}

			MOD_NATIVE(playStreamFromVehicle) {
				if (!arguments(1))
					return 0;

				AUDIO::PLAY_STREAM_FROM_VEHICLE(params[1]);

				return 1;
			}

			MOD_NATIVE(playStreamFromObject) {
				if (!arguments(1))
					return 0;

				AUDIO::PLAY_STREAM_FROM_OBJECT(params[1]);

				return 1;
			}

			MOD_NATIVE(playStreamFrontend) {
				if (!arguments(1))
					return 0;

				AUDIO::PLAY_STREAM_FRONTEND();

				return 1;
			}

			MOD_NATIVE(stopStream) {
				AUDIO::STOP_STREAM();

				return 1;
			}

			MOD_NATIVE(isAlarmPlaying) {
				if (!arguments(1))
					return 0;

				return AUDIO::IS_ALARM_PLAYING((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(prepareAlarm) {
				if (!arguments(1))
					return 0;

				return AUDIO::PREPARE_ALARM((char *)String::get(amx, params[1]).c_str());
			}

			MOD_NATIVE(startAlarm) {
				if (!arguments(1))
					return 0;

				AUDIO::START_ALARM((char *)String::get(amx, params[1]).c_str(), FALSE);

				return 1;
			}

			MOD_NATIVE(stopAlarm) {
				if (!arguments(2))
					return 0;

				AUDIO::STOP_ALARM((char *)String::get(amx, params[1]).c_str(), params[2]);

				return 1;
			}

			MOD_NATIVE(stopAllAlarms) {
				if (!arguments(1))
					return 0;

				AUDIO::STOP_ALL_ALARMS(TRUE);

				return 1;
			}
		};
	};
};