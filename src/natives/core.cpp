#include "core.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;
	extern boost::shared_ptr<Pool> gPool;

	namespace Natives {
		namespace Core {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(log)
				MOD_DEFINE_NATIVE(isModLoaded)
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
			
			MOD_NATIVE(isModLoaded) {
				if (!arguments(1))
					return 0;

				if (!gPool->find(String::get(amx, params[1]))->first.empty())
					return 1;

				return 0;
			}

			MOD_NATIVE(getVersion) {
				return AmxVHook::Core::AMXVHOOK_VERSION;
			}

			MOD_NATIVE(getModPoolSize) {
				return static_cast<cell>(gPool->size());
			}

			MOD_NATIVE(getTickCount) {
				return GetTickCount();
			}

			MOD_NATIVE(getAllPeds) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllPeds(addr, params[2]);
			}

			MOD_NATIVE(getAllObjects) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllObjects(addr, params[2]);
			}

			MOD_NATIVE(getAllPickups) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllPickups(addr, params[2]);
			}

			MOD_NATIVE(getAllVehicles) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllVehicles(addr, params[2]);
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