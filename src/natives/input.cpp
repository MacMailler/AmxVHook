#include "input.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Input {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(isKeyDown)
				MOD_DEFINE_NATIVE(isKeyJustUp)
				MOD_DEFINE_NATIVE(resetKeyState)
				MOD_DEFINE_NATIVE(getCommandParams)
				MOD_DEFINE_NATIVE(getCommandParamsInt)
				MOD_DEFINE_NATIVE(getCommandParamsFloat)
				MOD_DEFINE_NATIVE(displayOnScreeKeyboard)

				{NULL, NULL} // terminator
			};

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
		};
	};
};