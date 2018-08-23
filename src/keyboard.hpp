#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace Keyboard {
		const int KEYS_SIZE = 255;
		const int NOW_PERIOD = 100;
		const int MAX_DOWN = 5000;

		void handler(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);

		bool isKeyDown(DWORD key);
		bool isKeyJustUp(DWORD key, bool exclusive = true);
		bool getKeyInfo(DWORD key, DWORD &time, BOOL &isWithAlt, BOOL &wasDownBefore, BOOL &isUpNow);
		void resetKeyState(DWORD key);

		bool isDisplayed();
		void displayOnScreeKeyboard(char * windowTitle, char * defaultText);
		void displayOnScreenKeyboardProcess();

		std::string getCmdParam(int index);
		int getCmdParamInt(int index);
		int64_t getCmdParamHex(int index);
		float getCmdParamFloat(int index);
	};
};