#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Checkpoint {
			MOD_NATIVE(createCheckpoint);
			MOD_NATIVE(setCheckpointScale);
			MOD_NATIVE(setCheckpointCylinderHeight);
			MOD_NATIVE(setCheckpointColor);
			MOD_NATIVE(setCheckpointIconColor);
			MOD_NATIVE(deleteCheckpoint);
		
			AMX_NATIVE_INFO list[];
		};
	};
};
