#include "_core.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;
	extern boost::shared_ptr<Pool> gPool;

	namespace Natives {
		namespace Core {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(log)
				AMX_DEFINE_NATIVE(getVersion)
				AMX_DEFINE_NATIVE(getPoolSize)
				AMX_DEFINE_NATIVE(getTickCount)
				AMX_DEFINE_NATIVE(getAllPeds)
				AMX_DEFINE_NATIVE(getAllObjects)
				AMX_DEFINE_NATIVE(getAllPickups)
				AMX_DEFINE_NATIVE(getAllVehicles)
				AMX_DEFINE_NATIVE(setVersionVisible)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(log) {
				if (!arguments(1))
					return 0;

				gDebug->log((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			AMX_NATIVE(getVersion) {
				return AmxVHook::Core::AMXVHOOK_VERSION;
			}

			AMX_NATIVE(getPoolSize) {
				return static_cast<cell>(gPool->size());
			}

			AMX_NATIVE(getTickCount) {
				return GetTickCount();
			}

			AMX_NATIVE(getAllPeds) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllPeds(addr, params[2]);
			}

			AMX_NATIVE(getAllObjects) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllObjects(addr, params[2]);
			}

			AMX_NATIVE(getAllPickups) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllPickups(addr, params[2]);
			}

			AMX_NATIVE(getAllVehicles) {
				if (!arguments(2))
					return 0;

				cell * addr = nullptr;
				if (amx_GetAddr(amx, params[1], &addr) != AMX_ERR_NONE || addr == nullptr)
					return 0;

				return worldGetAllVehicles(addr, params[2]);
			}

			AMX_NATIVE(setVersionVisible) {
				if (!arguments(1))
					return 0;

				AmxVHook::Core::versionVisible = params[1];

				return 1;
			}
		};
	};
};