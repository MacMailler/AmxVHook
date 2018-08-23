#include "streaming.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Streaming {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isModelValid)
				MOD_DEFINE_NATIVE(isModelLoaded)
				MOD_DEFINE_NATIVE(isModelAVehicle)
				MOD_DEFINE_NATIVE(isModelInRpf)
				MOD_DEFINE_NATIVE(isEntityFocus)
				MOD_DEFINE_NATIVE(setFocusEntity)
				MOD_DEFINE_NATIVE(setVehiclePopulationBudget)
				MOD_DEFINE_NATIVE(setPedPopulationBudget)
				MOD_DEFINE_NATIVE(setInteriorActive)
				MOD_DEFINE_NATIVE(loadModel)
				MOD_DEFINE_NATIVE(unloadModel)

				{ NULL, NULL } // terminator
			};

			MOD_NATIVE(isModelValid) {
				checkargs(1);

				return STREAMING::IS_MODEL_VALID((Hash)params[1]);
			}

			MOD_NATIVE(isModelLoaded) {
				checkargs(1);

				return STREAMING::HAS_MODEL_LOADED((Hash)params[1]);
			}

			MOD_NATIVE(isModelAVehicle) {
				checkargs(1);

				return STREAMING::IS_MODEL_A_VEHICLE((Hash)params[1]);
			}

			MOD_NATIVE(isModelInRpf) {
				checkargs(1);

				return STREAMING::IS_MODEL_IN_CDIMAGE((Hash)params[1]);
			}
		
			MOD_NATIVE(isEntityFocus) {
				checkargs(1);

				return STREAMING::IS_ENTITY_FOCUS((::Entity)params[1]);
			}

			MOD_NATIVE(setFocusEntity) {
				checkargs(1);

				STREAMING::SET_FOCUS_ENTITY((::Entity)params[1]);

				return 1;
			}

			MOD_NATIVE(setVehiclePopulationBudget) {
				checkargs(1);

				STREAMING::SET_VEHICLE_POPULATION_BUDGET(params[1]);

				return 1;
			}
			MOD_NATIVE(setPedPopulationBudget) {
				checkargs(1);

				STREAMING::SET_PED_POPULATION_BUDGET(params[1]);

				return 1;
			}

			MOD_NATIVE(setInteriorActive) {
				checkargs(2);

				STREAMING::SET_INTERIOR_ACTIVE(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(loadModel) {
				checkargs(1);

				STREAMING::REQUEST_MODEL(params[1]);

				return 1;
			}

			MOD_NATIVE(unloadModel) {
				checkargs(1);

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((Hash)params[1]);

				return 1;
			}
		};
	};
};