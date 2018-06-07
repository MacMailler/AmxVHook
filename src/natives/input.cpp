#include "input.hpp"

namespace AmxVHook {
	namespace Natives {
		namespace Input {
			AMX_NATIVE_INFO list[] = {
				AMX_DEFINE_NATIVE(isKeyDown)
				AMX_DEFINE_NATIVE(isKeyJustUp)
				AMX_DEFINE_NATIVE(resetKeyState)
				AMX_DEFINE_NATIVE(getCommandParams)
				AMX_DEFINE_NATIVE(getCommandParamsInt)
				AMX_DEFINE_NATIVE(getCommandParamsFloat)
				AMX_DEFINE_NATIVE(displayOnScreeKeyboard)

				{NULL, NULL} // terminator
			};

			AMX_NATIVE(isKeyDown) {
				if (!arguments(1))
					return 0;

				return Keyboard::isKeyDown((DWORD)params[1]);
			}

			AMX_NATIVE(isKeyJustUp) {
				if (!arguments(2))
					return 0;

				return Keyboard::isKeyJustUp((DWORD)params[1], params[2]);

			}

			AMX_NATIVE(resetKeyState) {
				if (!arguments(1))
					return 0;

				Keyboard::resetKeyState((DWORD)params[1]);

				return 1;
			}
			
			AMX_NATIVE(getCommandParams) {
				if (!arguments(3))
					return 0;

				String::set(amx, params[2], Keyboard::getCommandParamS(params[1]), (std::size_t)params[3]);

				return 1;
			}

			AMX_NATIVE(getCommandParamsInt) {
				if (!arguments(1))
					return 0;

				return Keyboard::getCommandParam(params[1]);
			}

			AMX_NATIVE(getCommandParamsFloat) {
				if (!arguments(1))
					return 0;

				float ret = Keyboard::getCommandParamF(params[1]);

				return amx_ftoc(ret);
			}

			AMX_NATIVE(displayOnScreeKeyboard) {
				if (!arguments(2))
					return 0;

				Keyboard::displayOnScreeKeyboard((char *)String::get(amx, params[1]).c_str(), (char *)String::get(amx, params[2]).c_str());

				return 1;
			}
		};
	};
};