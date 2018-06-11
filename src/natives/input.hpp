#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Input {
			MOD_NATIVE(isKeyDown);
			MOD_NATIVE(isKeyJustUp);
			MOD_NATIVE(resetKeyState);
			MOD_NATIVE(getCommandParams);
			MOD_NATIVE(getCommandParamsInt);
			MOD_NATIVE(getCommandParamsFloat);
			MOD_NATIVE(displayOnScreeKeyboard);
		
			AMX_NATIVE_INFO list[];
		};
	};
};
