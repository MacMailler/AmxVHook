#pragma once
#include "..\amxvhook.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Input {
			MOD_NATIVE(isLookInverted);
			MOD_NATIVE(isControlEnabled);
			MOD_NATIVE(isControlPressed);
			MOD_NATIVE(isControlReleased);
			MOD_NATIVE(isControlJustPressed);
			MOD_NATIVE(isControlJustReleased);
			MOD_NATIVE(isDisabledControlPressed);
			MOD_NATIVE(isDisabledControlJustPressed);
			MOD_NATIVE(isDisabledControlJustReleased);
			MOD_NATIVE(isKeyboardDisplayed);
			MOD_NATIVE(isKeyDown);
			MOD_NATIVE(isKeyJustUp);
			MOD_NATIVE(resetKeyState);
			MOD_NATIVE(getCommandParams);
			MOD_NATIVE(getCommandParamsInt);
			MOD_NATIVE(getCommandParamsHash);
			MOD_NATIVE(getCommandParamsFloat);
			MOD_NATIVE(displayOnScreeKeyboard);
			MOD_NATIVE(disableControlAction);
			MOD_NATIVE(enableControlAction);
			MOD_NATIVE(disableAllControlActions);
			MOD_NATIVE(enableAllControlActions);
			MOD_NATIVE(setPadShake);
			MOD_NATIVE(setInputExclusive);
			MOD_NATIVE(setControlNormal);
			MOD_NATIVE(getControlValue);
			MOD_NATIVE(getControlNormal);
			MOD_NATIVE(getDisabledControlNormal);
			MOD_NATIVE(stopPadShake);
		
			AMX_NATIVE_INFO list[];
		};
	};
};
