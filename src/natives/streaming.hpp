#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Streaming {
			MOD_NATIVE(isModelValid);
			MOD_NATIVE(isModelLoaded);
			MOD_NATIVE(isModelAVehicle);
			MOD_NATIVE(isModelInRpf);
			MOD_NATIVE(isEntityFocus);
			MOD_NATIVE(setFocusEntity);
			MOD_NATIVE(setVehiclePopulationBudget);
			MOD_NATIVE(setPedPopulationBudget);
			MOD_NATIVE(setInteriorActive);
			MOD_NATIVE(loadModel);
			MOD_NATIVE(unloadModel);

			AMX_NATIVE_INFO list[];
		};
	};
};
