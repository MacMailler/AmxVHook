#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Checkpoint {
			MOD_NATIVE(createCP);
			MOD_NATIVE(setCPScale);
			MOD_NATIVE(setCPCylinderHeight);
			MOD_NATIVE(setCPColor);
			MOD_NATIVE(setCPIconColor);
			MOD_NATIVE(deleteCP);
		
			AMX_NATIVE_INFO list[];
		};
	};
};
