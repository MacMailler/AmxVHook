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
				MOD_DEFINE_NATIVE(getCmdParam)
				MOD_DEFINE_NATIVE(getCmdParamInt)
				MOD_DEFINE_NATIVE(getCmdParamHex)
				MOD_DEFINE_NATIVE(getCmdParamHash)
				MOD_DEFINE_NATIVE(getCmdParamFloat)
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
				checkargs(2);

				return CONTROLS::IS_CONTROL_ENABLED(params[1], params[2]);
			}

			MOD_NATIVE(isControlPressed) {
				checkargs(2);

				return CONTROLS::IS_CONTROL_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isControlReleased) {
				checkargs(2);

				return CONTROLS::IS_CONTROL_RELEASED(params[1], params[2]);
			}

			MOD_NATIVE(isControlJustPressed) {
				checkargs(2);

				return CONTROLS::IS_CONTROL_JUST_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isControlJustReleased) {
				checkargs(2);

				return CONTROLS::IS_CONTROL_JUST_RELEASED(params[1], params[2]);
			}

			MOD_NATIVE(isDisabledControlPressed) {
				checkargs(2);

				return CONTROLS::IS_DISABLED_CONTROL_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isDisabledControlJustPressed) {
				checkargs(2);

				return CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(params[1], params[2]);
			}

			MOD_NATIVE(isDisabledControlJustReleased) {
				checkargs(2);

				return CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(params[1], params[2]);
			}
			
			MOD_NATIVE(isKeyboardDisplayed) {
				return Keyboard::isDisplayed();
			}

			MOD_NATIVE(isKeyDown) {
				checkargs(1);

				return Keyboard::isKeyDown((DWORD)params[1]);
			}

			MOD_NATIVE(isKeyJustUp) {
				checkargs(2);

				return Keyboard::isKeyJustUp((DWORD)params[1], params[2]);

			}

			MOD_NATIVE(resetKeyState) {
				checkargs(1);

				Keyboard::resetKeyState((DWORD)params[1]);

				return 1;
			}

			MOD_NATIVE(getCmdParam) {
				checkargs(3);

				String::set(amx, params[2], Keyboard::getCmdParam(params[1]), (std::size_t)params[3]);

				return 1;
			}

			MOD_NATIVE(getCmdParamInt) {
				checkargs(1);

				return Keyboard::getCmdParamInt(params[1]);
			}
			
			MOD_NATIVE(getCmdParamHex) {
				checkargs(1);

				return static_cast<cell>(Keyboard::getCmdParamHex(params[1]));
			}

			MOD_NATIVE(getCmdParamHash) {
				checkargs(1);

				return GAMEPLAY::GET_HASH_KEY((char *)Keyboard::getCmdParam(params[1]).c_str());
			}

			MOD_NATIVE(getCmdParamFloat) {
				checkargs(1);

				double ret = Keyboard::getCmdParamFloat(params[1]);

				return amx_ftoc(ret);
			}

			MOD_NATIVE(displayOnScreeKeyboard) {
				checkargs(2);

				Keyboard::displayOnScreeKeyboard((char *)String::get(amx, params[1]).c_str(), (char *)String::get(amx, params[2]).c_str());

				return 1;
			}

			MOD_NATIVE(disableControlAction) {
				checkargs(3);

				CONTROLS::DISABLE_CONTROL_ACTION(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(enableControlAction) {
				checkargs(3);

				CONTROLS::ENABLE_CONTROL_ACTION(params[1], params[2], params[3]);

				return 1;
			}

			MOD_NATIVE(disableAllControlActions) {
				checkargs(1);

				CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(params[1]);

				return 1;
			}

			MOD_NATIVE(enableAllControlActions) {
				checkargs(1);

				CONTROLS::ENABLE_ALL_CONTROL_ACTIONS(params[1]);

				return 1;
			}

			MOD_NATIVE(setPadShake) {
				checkargs(2);

				CONTROLS::SET_PAD_SHAKE(NULL, params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setInputExclusive) {
				checkargs(2);

				CONTROLS::SET_INPUT_EXCLUSIVE(params[1], params[2]);

				return 1;
			}

			MOD_NATIVE(setControlNormal) {
				checkargs(3);

				CONTROLS::_SET_CONTROL_NORMAL(params[1], params[2], amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(getControlValue) {
				checkargs(2);

				return CONTROLS::GET_CONTROL_VALUE(params[1], params[2]);
			}

			MOD_NATIVE(getControlNormal) {
				checkargs(2);

				double normal = CONTROLS::GET_CONTROL_NORMAL(params[1], params[2]);

				return amx_ftoc(normal);
			}

			MOD_NATIVE(getDisabledControlNormal) {
				checkargs(2);

				double normal = CONTROLS::GET_DISABLED_CONTROL_NORMAL(params[1], params[2]);

				return amx_ftoc(normal);
			}

			MOD_NATIVE(stopPadShake) {
				CONTROLS::STOP_PAD_SHAKE(NULL);

				return 1;
			}
		};
	};
};