#include "keyboard.hpp"

namespace AmxVHook {

	extern std::shared_ptr<Pool> gPool;

	namespace Keyboard {
		struct keyS {
			DWORD time;
			BOOL isWithAlt;
			BOOL wasDownBefore;
			BOOL isUpNow;
		} keyStates[KEYS_SIZE];
		
		std::vector<std::string> tokens;
		bool keyboardDisplayed = false;

		void handler(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow) {
			if (key < KEYS_SIZE) {
				keyStates[key].time = GetTickCount();
				keyStates[key].isWithAlt = isWithAlt;
				keyStates[key].wasDownBefore = wasDownBefore;
				keyStates[key].isUpNow = isUpNow;
			}
		}

		bool isKeyDown(DWORD key) {
			return (KEYS_SIZE > key) ? ((GetTickCount() < keyStates[key].time + MAX_DOWN) && !keyStates[key].isUpNow) : false;
		}

		bool isKeyJustUp(DWORD key, bool exclusive) {
			bool b = (KEYS_SIZE > key) ? (GetTickCount() < keyStates[key].time + NOW_PERIOD && keyStates[key].isUpNow) : false;
			if (b && exclusive)
				resetKeyState(key);

			return b;
		}

		void resetKeyState(DWORD key) {
			if (KEYS_SIZE > key)
				memset(&keyStates[key], 0, sizeof(keyStates[0]));
		}

		bool getKeyInfo(DWORD key, DWORD &time, BOOL &isWithAlt, BOOL &wasDownBefore, BOOL &isUpNow) {
			if (key > 0 || key > KEYS_SIZE)
				return false;

			time = keyStates[key].time;
			isWithAlt = keyStates[key].isWithAlt;
			wasDownBefore = keyStates[key].wasDownBefore;
			isUpNow = keyStates[key].isUpNow;

			return true;
		}

		bool isDisplayed() {
			return keyboardDisplayed;
		}

		void displayOnScreeKeyboard(char * windowTitle, char * defaultText) {
			if (!keyboardDisplayed) {
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(UNK::_GET_UI_LANGUAGE_ID(), windowTitle, "", defaultText, "", "", "", 256);
				keyboardDisplayed = true;
			}
		}

		void displayOnScreenKeyboardProcess() {
			if (isKeyJustUp(VK_ADD)) {
				displayOnScreeKeyboard("FMMC_KEY_TIP8", "!");
			}

			if (keyboardDisplayed) {
				int status = GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD();
				if (status == 0) {

				}
				else if (status == 1) {
					char *buf = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();

					tokens.clear();
					String::tokenize(buf, tokens);

					if (tokens[0].front() == '!') {
						if (!tokens[0].compare("!r") && tokens.size() > 1) {
							if (!tokens[1].compare("all")) {
								gPool->remake();
								Funcs::showSubtitle("~g~AmxVHook:~w~ all mods reloaded!", 4000, TRUE);
							}
							else {
								char temp[64];
								for (int i = 1; i < tokens.size(); i++)
									if (!tokens[i].empty()) {
										if (gPool->reloadMod(tokens[i])) {
											sprintf_s(temp, "~g~AmxVHook: ~w~`~b~%s~w~` reloaded!", tokens[i].c_str());
											Funcs::showSubtitle(std::string(temp), 4000, TRUE);
										}
										else {
											sprintf_s(temp, "~g~AmxVHook:~w~`~b~%s~w~` ~r~NOT ~w~found!", tokens[i].c_str());
											Funcs::showSubtitle(std::string(temp), 4000, TRUE);
										}
									}
							}
						}
						else if (!tokens[0].compare("!l") && tokens.size() > 1) {
							for (int i = 1; i < tokens.size(); i++)
								if (!tokens[i].empty())
									gPool->loadMod(Fs::path(gPool->getLocation().string()+ "\\" + tokens[i] + ".amx"));
						}
						else {
							gPool->onModInputCommand(tokens[0], static_cast<cell>(tokens.size()) - 1);
						}
					}
					else {
						gPool->onModInputText(buf);
					}
					keyboardDisplayed = false;
				}
				else if (status == 2) {
					keyboardDisplayed = false;
					gPool->execAll("onModInputCanceled");
				}
				else {
					keyboardDisplayed = false;
				}
			}
		}

		int getCmdParamInt(int index) {
			if (0 > index || index > tokens.size() - 1)
				return NULL;

			return std::stoi(tokens[index]);
		}

		int64_t getCmdParamHex(int index) {
			if (0 > index || index > tokens.size() - 1)
				return NULL;

			return std::strtoll(tokens[index].data(), NULL, 16);
		}

		float getCmdParamFloat(int index) {
			if (0 > index || index > tokens.size() - 1)
				return NULL;

			return std::stof(tokens[index]);
		}

		std::string getCmdParam(int index) {
			if (0 > index || index > tokens.size() - 1)
				return std::string("");

			return tokens[index];
		}
	};
};