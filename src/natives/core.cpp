#include "core.hpp"

namespace AmxVHook {

	extern std::shared_ptr<Log> gLog;
	extern std::shared_ptr<Pool> gPool;
	extern std::shared_ptr<Timer::Pool> gTimer;

	namespace Natives {
		namespace Core {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(log)
				MOD_DEFINE_NATIVE(logf)
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
				checkargs(1);

				gLog->log((char *)String::get(amx, params[1]).data());

				return 1;
			}
			
			MOD_NATIVE(logf) {
				cell *fstr;
				if (amx_GetAddr(amx, params[1], &fstr) != AMX_ERR_NONE)
					return 0;

				std::string out;
				String::format(amx, &params[2], fstr, out);

				gLog->log((char *)out.data());

				return 1;
			}

			MOD_NATIVE(format) {
				cell *fstr;
				if (amx_GetAddr(amx, params[3], &fstr) != AMX_ERR_NONE)
					return 0;

				std::string out;
				out.reserve(params[2]);

				String::format(amx, &params[4], fstr, out);
				String::set(amx, params[1], out, params[2]);

				return 1;
			}

			MOD_NATIVE(isModLoaded) {
				checkargs(1);

				return gPool->contains(String::get(amx, params[1]));
			}

			MOD_NATIVE(getFps) {
				return AmxVHook::Core::getFps();
			}
			
			MOD_NATIVE(getVersion) {
				return AMXVHOOK_VER_INT;
			}

			MOD_NATIVE(getPoolSize) {
				return static_cast<cell>(gPool->size());
			}

			MOD_NATIVE(getTickCount) {
				return GetTickCount();
			}

			MOD_NATIVE(getAllPeds) {
				checkargs(2);

	/*			cell * amxDest;
				if (amx_GetAddr(amx, params[1], &amxDest) != AMX_ERR_NONE)
					return 0;

				int * dest = (int *)alloca(params[2] * sizeof(int));
				int ret = worldGetAllPeds(dest, params[2]);
				Funcs::cpy(amxDest, dest, params[2]);

				return ret;*/

				cell * dest;
				if (amx_GetAddr(amx, params[1], &dest) != AMX_ERR_NONE)
					return 0;

				return worldGetAllPeds(dest, params[2]);
			}

			MOD_NATIVE(getAllObjects) {
				checkargs(2);

				cell * dest;
				if (amx_GetAddr(amx, params[1], &dest) != AMX_ERR_NONE)
					return 0;

				return worldGetAllObjects(dest, params[2]);
			}

			MOD_NATIVE(getAllPickups) {
				checkargs(2);

				cell * dest;
				if (amx_GetAddr(amx, params[1], &dest) != AMX_ERR_NONE)
					return 0;

				return worldGetAllPickups(dest, params[2]);
			}

			MOD_NATIVE(getAllVehicles) {
				checkargs(2);

				cell * dest;
				if (amx_GetAddr(amx, params[1], &dest) != AMX_ERR_NONE)
					return 0;

				return worldGetAllVehicles(dest, params[2]);
			}

			MOD_NATIVE(setVersionVisible) {
				checkargs(1);

				AmxVHook::Core::versionVisible = params[1];

				return 1;
			}
			
			MOD_NATIVE(callFunc) {
				if ((params[0] / sizeof(cell)) < 3)
					return 0;

				AmxArgs stk;
				Aux::toStack(amx, params, String::get(amx, params[2]), stk, 4);

				std::string modname = String::get(amx, params[3]);

				if (!modname.compare("self")) {
					return gPool->exec(amx, String::get(amx, params[1]).c_str(), &stk);
				}
				else if (!modname.compare("all")) {
					gPool->execAll(String::get(amx, params[1]).c_str(), &stk);
				}
				else {
					if (gPool->contains(modname))
						return gPool->exec(gPool->find(modname)->second.amx, String::get(amx, params[1]).c_str(), &stk);
				}

				return 1;
			}

			MOD_NATIVE(addTimer) {
				if ((params[0] / sizeof(cell)) < 3)
					return 0;

				std::shared_ptr<Timer::Timer> timer = std::make_shared<Timer::Timer>();

				timer->amx = amx;
				timer->interval = params[2];
				timer->funcname = String::get(amx, params[1]);

				int index;
				if (amx_FindPublic(amx, (char *)timer->funcname.c_str(), &index) != AMX_ERR_NONE)
					return 0;

				Aux::toStack(amx, params, String::get(amx, params[3]), timer->params, 4);

				timer->lastTime = GAMEPLAY::GET_GAME_TIMER();

				return gTimer->add(timer);
			}

			MOD_NATIVE(dropTimer) {
				checkargs(1);

				return gTimer->drop(params[1]);
			}
			
			MOD_NATIVE(stopTimer) {
				checkargs(2);

				return gTimer->stop(params[1], params[2]);
			}

			MOD_NATIVE(isTimerExist) {
				checkargs(1);

				return gTimer->contains(params[1]);
			}
			
			MOD_NATIVE(isTimerStopped) {
				checkargs(1);

				return gTimer->stopped(params[1]);
			}
			
			MOD_NATIVE(setTimerData) {
				if ((params[0] / sizeof(cell)) < 2)
					return 0;

				AmxArgs stk;
				Aux::toStack(amx, params, String::get(amx, params[2]), stk, 3);
				
				return gTimer->setData(params[1], stk);
			}

			MOD_NATIVE(setTimerInterval) {
				checkargs(2);

				return gTimer->setInterval(params[1], params[2]);
			}
		};
	};
};