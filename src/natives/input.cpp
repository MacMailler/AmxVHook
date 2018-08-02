#include "input.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Input {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isLookInverted)
				MOD_DEFINE_NATIVE(isLookInverted)
				MOD_DEFINE_NATIVE(isControlEnabled)
				MOD_DEFINE_NATIVE(isControlPressed)
				MOD_DEFINE_NATIVE(isControlReleased)
				MOD_DEFINE_NATIVE(isControlJustPressed)
				MOD_DEFINE_NATIVE(isControlJustReleased)
				MOD_DEFINE_NATIVE(isDisabledControlPressed)
				MOD_DEFINE_NATIVE(isDisabledControlJustPressed)
				MOD_DEFINE_NATIVE(isDisabledControlJustReleased)
				MOD_DEFINE_NATIVE(isKeyboardDisplayed)
				MOD_DEFINE_NATIVE(isKeyDown)
				MOD_DEFINE_NATIVE(isKeyJustUp)
				MOD_DEFINE_NATIVE(resetKeyState)
				MOD_DEFINE_NATIVE(getCommandParams)
				MOD_DEFINE_NATIVE(getCommandParamsInt)
				MOD_DEFINE_NATIVE(getCommandParamsHash)
				MOD_DEFINE_NATIVE(getCommandParamsFloat)
				MOD_DEFINE_NATIVE(displayOnScreeKeyboard)
				MOD_DEFINE_NATIVE(disableControlAction)
				MOD_DEFINE_NATIVE(enableControlAction)
				MOD_DEFINE_NATIVE(disableAllControlActions)
				MOD_DEFINE_NATIVE(enableAllControlActions)
				MOD_DEFINE_NATIVE(setPadShake)
				MOD_DEFINE_NATIVE(setInputExclusive)
				MOD_DEFINE_NATIVE(setControlNormal)
				MOD_DEFINE_NATIVE(getControlValue)
				MOD_DEFINE_NATIVE(getControlNormal)
				MOD_DEFINE_NATIVE(getDisabledControlNormal)
				MOD_DEFINE_NATIVE(stopPadShake)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(isLookInverted) {
				return CONTROLS::IS_LOOK_INVERTED();

			}
			
			MOD_NATIVE(isControlEnabled) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_CONTROL_ENABLED(params[1], params[2]);
			}

			MOD_NATIVE(isControlPressed) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_CONTROL_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isControlReleased) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_CONTROL_RELEASED(params[1], params[2]);
			}

			MOD_NATIVE(isControlJustPressed) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_CONTROL_JUST_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isControlJustReleased) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_CONTROL_JUST_RELEASED(params[1], params[2]);
			}

			MOD_NATIVE(isDisabledControlPressed) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_DISABLED_CONTROL_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isDisabledControlJustPressed) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isDisabledControlJustReleased) {
				if (!arguments(2))
					return 0;

				return CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(params[1], params[2]);
			}
			
			MOD_NATIVE(isKeyboardDisplayed) {
				return Keyboard::isDisplayed();
			}

			MOD_NATIVE(isKeyDown) {
				if (!arguments(1))
					return 0;

				return Keyboard::isKeyDown((DWORD)params[1]);
			}

			MOD_NATIVE(isKeyJustUp) {
				if (!arguments(2))
					return 0;

				return Keyboard::isKeyJustUp((DWORD)params[1], params[2]);

			}

			MOD_NATIVE(resetKeyState) {
				if (!arguments(1))
					return 0;

				Keyboard::resetKeyState((DWORD)params[1]);

				return 1;
			}
			
			MOD_NATIVE(getCommandParams) {
				if (!arguments(3))
					return 0;

				String::set(amx, params[2], Keyboard::getCommandParamS(params[1]), (std::size_t)params[3]);

				return 1;
			}

			MOD_NATIVE(getCommandParamsInt) {
				if (!arguments(1))
					return 0;

				return Keyboard::getCommandParam(params[1]);
			}
			
			MOD_NATIVE(getCommandParamsHash) {
				if (!arguments(1))
					return 0;

				return GAMEPLAY::GET_HASH_KEY((char *)Keyboard::getCommandParamS(params[1]).c_str());
			}

			MOD_NATIVE(getCommandParamsFloat) {
				if (!arguments(1))
					return 0;

				float ret = Keyboard::getCommandParamF(params[1]);

				return amx_ftoc(ret);
			}

			MOD_NATIVE(displayOnScreeKeyboard) {
				if (!arguments(2))
					return 0;

				Keyboard::displayOnScreeKeyboard((char *)String::get(amx, params[1]).c_str(), (char *)String::get(amx, params[2]).c_str());

				return 1;
			}

			MOD_NATIVE(disableControlAction) {
				if (!arguments(3))
					return 0;

				CONTROLS::DISABLE_CONTROL_ACTION(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(enableControlAction) {
				if (!arguments(3))
					return 0;

				CONTROLS::ENABLE_CONTROL_ACTION(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(disableAllControlActions) {
				if (!arguments(1))
					return 0;

				CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(params[1]);

				return 1;
			}

			MOD_NATIVE(enableAllControlActions) {
				if (!arguments(1))
					return 0;

				CONTROLS::ENABLE_ALL_CONTROL_ACTIONS(params[1]);

				return 1;
			}

			MOD_NATIVE(setPadShake) {
				if (!arguments(2))
					return 0;

				CONTROLS::SET_PAD_SHAKE(NULL, params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setInputExclusive) {
				if (!arguments(2))
					return 0;

				CONTROLS::SET_INPUT_EXCLUSIVE(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setControlNormal) {
				if (!arguments(3))
					return 0;

				CONTROLS::_SET_CONTROL_NORMAL(params[1], params[2], amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(getControlValue) {
				if (!arguments(2))
					return 0;

				return CONTROLS::GET_CONTROL_VALUE(params[1], params[2]);
			}

			MOD_NATIVE(getControlNormal) {
				if (!arguments(2))
					return 0;

				float normal = CONTROLS::GET_CONTROL_NORMAL(params[1], params[2]);

				return amx_ftoc(normal);
			}

			MOD_NATIVE(getDisabledControlNormal) {
				if (!arguments(2))
					return 0;

				float normal = CONTROLS::GET_DISABLED_CONTROL_NORMAL(params[1], params[2]);

				return amx_ftoc(normal);
			}

			MOD_NATIVE(stopPadShake) {
				CONTROLS::STOP_PAD_SHAKE(NULL);

				return 1;
			}
		};
	};
};