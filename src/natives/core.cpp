#include "core.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;
	extern boost::shared_ptr<Pool> gPool;

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

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(log) {
				if (!arguments(1))
					return 0;

				gDebug->log((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
			
			MOD_NATIVE(logf) {
				cell paramsCount = (params[0] / sizeof(cell));
				if (paramsCount == 1)
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

				if (!gPool->find(String::get(amx, params[1]))->first.empty())
					return 1;

				return 0;
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
		};
	};
};