#include "amxvhook.hpp"


BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved) {
	switch (reason) {
		case DLL_PROCESS_ATTACH :
			scriptRegister(hInstance, AmxVHook::Core::init);
			keyboardHandlerRegister(AmxVHook::Keyboard::handler);
		break;
		
		case DLL_PROCESS_DETACH :
			AmxVHook::Core::cleanup();
			scriptUnregister(hInstance);
			keyboardHandlerUnregister(AmxVHook::Keyboard::handler);
		break;
	}
	return TRUE;
}