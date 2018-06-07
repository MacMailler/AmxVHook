#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Input {
			AMX_NATIVE(isKeyDown);
			AMX_NATIVE(isKeyJustUp);
			AMX_NATIVE(resetKeyState);
			AMX_NATIVE(getCommandParams);
			AMX_NATIVE(getCommandParamsInt);
			AMX_NATIVE(getCommandParamsFloat);
			AMX_NATIVE(displayOnScreeKeyboard);
		
			AMX_NATIVE_INFO list[];
		};
	};
};
