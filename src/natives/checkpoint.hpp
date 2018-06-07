#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Checkpoint {
			AMX_NATIVE(createCP);
			AMX_NATIVE(setCPScale);
			AMX_NATIVE(setCPCylinderHeight);
			AMX_NATIVE(setCPColor);
			AMX_NATIVE(deleteCP);
		
			AMX_NATIVE_INFO list[];
		};
	};
};
