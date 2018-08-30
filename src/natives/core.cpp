#include "core.hpp"

namespace AmxVHook {

	extern std::shared_ptr<Log> gLog;
	extern std::shared_ptr<Pool> gPool;
	extern std::shared_ptr<Timer::Pool> gTimer;

	namespace Natives {
		namespace Core {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(log)
				MOD_DEFINE_NATIVE(format)
				MOD_DEFINE_NATIVE(invoke)
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
				MOD_DEFINE_NATIVE(getTimerId)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(log) {
				cell *fstr;
				if (amx_GetAddr(amx, params[1], &fstr) != AMX_ERR_NONE)
					return 0;

				std::string out;
				out.reserve(255);
				String::format(amx, &params[2], fstr, out);

				gLog->log(out.data());

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

			MOD_NATIVE(invoke) {
				if (argscount() < 3)
					return 0;

				cell *fstr;
				if (amx_GetAddr(amx, params[3], &fstr) != AMX_ERR_NONE)
					return 0;

				switch (params[2]) {
				case 1: return Funcs::invoke<Void>(params[1], amx, &params[4], fstr);
				case 2: return Funcs::invoke<int>(params[1], amx, &params[4], fstr);
				case 3:
					double val = Funcs::invoke<float>(params[1], amx, &params[4], fstr);
					return amx_ftoc(val);
				}

				return 0;
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
				#if PAWN_CELL_SIZE == 64
					return GetTickCount64();
				#else
					return GetTickCount();
				#endif
			}

			MOD_NATIVE(getAllPeds) {
				checkargs(2);

				cell * amxDest;
				if (amx_GetAddr(amx, params[1], &amxDest) != AMX_ERR_NONE)
					return 0;

				int * dest = (int *)alloca(params[2]);
				int ret = worldGetAllPeds(dest, params[2]);

				Funcs::cpy(amxDest, dest, params[2]);

				return ret;
			}

			MOD_NATIVE(getAllObjects) {
				checkargs(2);

				cell * amxDest;
				if (amx_GetAddr(amx, params[1], &amxDest) != AMX_ERR_NONE)
					return 0;

				int * dest = (int *)alloca(params[2]);
				int ret = worldGetAllObjects(dest, params[2]);

				Funcs::cpy(amxDest, dest, params[2]);

				return ret;
			}

			MOD_NATIVE(getAllPickups) {
				checkargs(2);

				cell * amxDest;
				if (amx_GetAddr(amx, params[1], &amxDest) != AMX_ERR_NONE)
					return 0;

				int * dest = (int *)alloca(params[2]);
				int ret = worldGetAllPickups(dest, params[2]);

				Funcs::cpy(amxDest, dest, params[2]);

				return ret;
			}

			MOD_NATIVE(getAllVehicles) {
				checkargs(2);

				cell * amxDest;
				if (amx_GetAddr(amx, params[1], &amxDest) != AMX_ERR_NONE)
					return 0;

				int * dest = (int *)alloca(params[2]);
				int ret = worldGetAllVehicles(dest, params[2]);

				Funcs::cpy(amxDest, dest, params[2]);

				return ret;
			}

			MOD_NATIVE(setVersionVisible) {
				checkargs(1);

				AmxVHook::Core::versionVisible = params[1];

				return 1;
			}
			
			MOD_NATIVE(callFunc) {
				if (argscount() < 3)
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
						return gPool->exec(gPool->find(modname)->second.amx, String::get(amx, params[1]), &stk);
				}

				return 1;
			}

			MOD_NATIVE(addTimer) {
				if (argscount() < 3)
					return 0;

				if (!(params[2] > 0))
					return 0;

				std::shared_ptr<Timer::Timer> timer = std::make_shared<Timer::Timer>();

				timer->amx = amx;
				timer->interval = params[2];
				timer->funcindex = Aux::getPublicIndex(amx, String::get(amx, params[1]));

				if (timer->funcindex == -1)
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
				if (argscount() < 2)
					return 0;

				AmxArgs stk;
				Aux::toStack(amx, params, String::get(amx, params[2]), stk, 3);
				
				return gTimer->setData(params[1], stk);
			}

			MOD_NATIVE(setTimerInterval) {
				checkargs(2);

				return gTimer->setInterval(params[1], params[2]);
			}

			MOD_NATIVE(getTimerId) {
				return gTimer->getCurrId();
			}
		};
	};
};