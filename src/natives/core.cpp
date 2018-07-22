#include "core.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;
	extern boost::shared_ptr<Pool> gPool;
	extern boost::shared_ptr<Timer::Pool> gTimer;

	namespace Natives {
		namespace Core {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(log)
				MOD_DEFINE_NATIVE(logf)
				MOD_DEFINE_NATIVE(wait)
				MOD_DEFINE_NATIVE(format)
				MOD_DEFINE_NATIVE(isModLoaded)
				MOD_DEFINE_NATIVE(getFps)
				MOD_DEFINE_NATIVE(getVersion)
				MOD_DEFINE_NATIVE(getPoolSize)
				MOD_DEFINE_NATIVE(getTickCount)
				MOD_DEFINE_NATIVE(getAllPeds)
				MOD_DEFINE_NATIVE(getAllObjects)
				MOD_DEFINE_NATIVE(getAllPickups)
				MOD_DEFINE_NATIVE(getAllVehicles)
				MOD_DEFINE_NATIVE(setVersionVisible)
				MOD_DEFINE_NATIVE(callFunc)
				MOD_DEFINE_NATIVE(addTimer)
				MOD_DEFINE_NATIVE(dropTimer)
				MOD_DEFINE_NATIVE(stopTimer)
				MOD_DEFINE_NATIVE(isTimerExist)
				MOD_DEFINE_NATIVE(isTimerStopped)
				MOD_DEFINE_NATIVE(setTimerData)
				MOD_DEFINE_NATIVE(setTimerInterval)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(log) {
				if (!arguments(1))
					return 0;

				gDebug->log((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
			
			MOD_NATIVE(logf) {
				if ((params[0] / sizeof(cell)) == 1)
					gDebug->log((char *)String::get(amx, params[1]).c_str());
				else {
					cell * f;
					if (amx_GetAddr(amx, params[1], &f) != AMX_ERR_NONE)
						return 0;

					std::string out;
					String::format(amx, (params + 2), f, out);

					gDebug->log((char *)out.c_str());
				}
				return 1;
			}
			
			MOD_NATIVE(wait) {
				if (!arguments(1))
					return 0;

				scriptWait(params[1]);

				return 1;
			}

			MOD_NATIVE(format) {
				cell paramsCount = (params[0] / sizeof(cell));

				if (paramsCount < 3)
					return 0;

				else if (paramsCount == 3)
					String::set(amx, params[1], String::get(amx, params[3]), params[2]);

				else {
					cell * f;
					if (amx_GetAddr(amx, params[3], &f) != AMX_ERR_NONE)
						return 0;

					std::string out;
					String::format(amx, (params + 4), f, out);
					String::set(amx, params[1], out, params[2]);
				}
				return 1;
			}

			MOD_NATIVE(isModLoaded) {
				if (!arguments(1))
					return 0;

				return gPool->contains(String::get(amx, params[1]));
			}

			MOD_NATIVE(getFps) {
				return AmxVHook::Core::getFps();
			}
			
			MOD_NATIVE(getVersion) {
				return AmxVHook::Core::AMXVHOOK_VERSION;
			}

			MOD_NATIVE(getPoolSize) {
				return static_cast<cell>(gPool->size());
			}

			MOD_NATIVE(getTickCount) {
				return GetTickCount();
			}

			MOD_NATIVE(getAllPeds) {
				if (!arguments(2))
					return 0;

				cell * dest = Utility::getAddrFromParam(amx, params[1]);
				if (dest == nullptr)
					return 0;

				return worldGetAllPeds(dest, params[2]);
			}

			MOD_NATIVE(getAllObjects) {
				if (!arguments(2))
					return 0;

				cell * dest = Utility::getAddrFromParam(amx, params[1]);
				if (dest == nullptr)
					return 0;

				return worldGetAllObjects(dest, params[2]);
			}

			MOD_NATIVE(getAllPickups) {
				if (!arguments(2))
					return 0;

				cell * dest = Utility::getAddrFromParam(amx, params[1]);
				if (dest == nullptr)
					return 0;

				return worldGetAllPickups(dest, params[2]);
			}

			MOD_NATIVE(getAllVehicles) {
				if (!arguments(2))
					return 0;

				cell * dest = Utility::getAddrFromParam(amx, params[1]);
				if (dest == nullptr)
					return 0;

				return worldGetAllVehicles(dest, params[2]);
			}

			MOD_NATIVE(setVersionVisible) {
				if (!arguments(1))
					return 0;

				AmxVHook::Core::versionVisible = params[1];

				return 1;
			}
			
			MOD_NATIVE(callFunc) {
				if ((params[0] / sizeof(cell)) < 3)
					return 0;

				std::stack<boost::variant<cell, std::string>> stk;
				Utility::convertParamsToStack(amx, params, String::get(amx, params[2]), stk, 4);

				if (params[3] == 1)
					gPool->execAll(String::get(amx, params[1]).c_str(), &stk);
				else
					return gPool->exec(amx, String::get(amx, params[1]).c_str(), &stk);

				return 1;
			}

			MOD_NATIVE(addTimer) {
				if ((params[0] / sizeof(cell)) < 3)
					return Timer::Pool::invalidTimerId;

				boost::shared_ptr<Timer::Timer> timer = boost::make_shared<Timer::Timer>();

				timer->amx = amx;
				timer->interval = params[2];
				timer->funcname = String::get(amx, params[1]);

				int index;
				if (amx_FindPublic(amx, (char *)timer->funcname.c_str(), &index) != AMX_ERR_NONE)
					return Timer::Pool::invalidTimerId;

				Utility::convertParamsToStack(amx, params, String::get(amx, params[3]), timer->params, 4);

				timer->lastTime = GAMEPLAY::GET_GAME_TIMER();

				return gTimer->add(timer);
			}

			MOD_NATIVE(dropTimer) {
				if (!arguments(1))
					return 0;

				return gTimer->drop(params[1]);
			}
			
			MOD_NATIVE(stopTimer) {
				if (!arguments(2))
					return 0;

				return gTimer->stop(params[1], params[2]);
			}

			MOD_NATIVE(isTimerExist) {
				if (!arguments(1))
					return 0;

				return gTimer->contains(params[1]);
			}
			
			MOD_NATIVE(isTimerStopped) {
				if (!arguments(1))
					return 0;

				return gTimer->stopped(params[1]);
			}
			
			MOD_NATIVE(setTimerData) {
				if ((params[0] / sizeof(cell)) < 2)
					return 0;

				std::stack<boost::variant<cell, std::string>> stk;
				Utility::convertParamsToStack(amx, params, String::get(amx, params[2]), stk, 3);
				
				return gTimer->setData(params[1], stk);
			}

			MOD_NATIVE(setTimerInterval) {
				if (!arguments(2))
					return 0;

				return gTimer->setInterval(params[1], params[2]);
			}
		};
	};
};