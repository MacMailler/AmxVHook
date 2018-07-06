#include "keyboard.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Pool> gPool;

	namespace Keyboard {
		struct keyS {
			DWORD time;
			BOOL isWithAlt;
			BOOL wasDownBefore;
			BOOL isUpNow;
		} keyStates[KEYS_SIZE];
		
		std::vector<std::string> params;
		bool inputStarted = false;

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

		void displayOnScreeKeyboard(char * windowTitle, char * defaultText) {
			if (!inputStarted) {
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(UNK::_GET_UI_LANGUAGE_ID(), windowTitle, "", defaultText, "", "", "", 256);
				inputStarted = true;
			}
		}

		void displayOnScreeKeyboardProcess() {
			if (isKeyJustUp(VK_ADD)) {
				displayOnScreeKeyboard("FMMC_KEY_TIP8", "!");
			}

			if (inputStarted) {
				int status = GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD();
				if (status == 0) {

				}
				else if (status == 1) {
					char *buf = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();

					params.clear();
					boost::split(params, buf, boost::is_any_of(" "));

					if (params[0].front() == '!') {
						if (!params[0].compare("!r") && params.size() > 1) {
							if (!params[1].compare("all")) {
								gPool->remake();
								Funcs::showSubtitle("~g~AmxVHook:~w~ all mods reloaded!", 4000, TRUE);
							}
							else {
								char temp[64];
								for (int i = 1; i < params.size(); i++)
									if (!params[i].empty()) {
										if (gPool->reloadMod(params[i])) {
											sprintf_s(temp, "~g~AmxVHook: ~w~`~b~%s~w~` reloaded!", params[i].c_str());
											Funcs::showSubtitle(std::string(temp), 4000, TRUE);
										}
										else {
											sprintf_s(temp, "~g~AmxVHook:~w~`~b~%s~w~` ~r~NOT ~w~found!", params[i].c_str());
											Funcs::showSubtitle(std::string(temp), 4000, TRUE);
										}
									}
							}
						}
						else if (!params[0].compare("!l") && params.size() > 1) {
							for (int i = 1; i < params.size(); i++)
								if (!params[i].empty())
									gPool->loadMod(boost::filesystem::path(gPool->getLocation().string() + params[i] + ".amx"));
						}
						else {
							gPool->onModInputCommand((char *)params[0].c_str(), static_cast<cell>(params.size()) - 1);
						}
					}
					else {
						gPool->onModInputText(buf);
					}

					inputStarted = false;
				}
				else if (status == 2) {
					inputStarted = false;
					gPool->execAll("onModInputCanceled");
				}
				else {
					inputStarted = false;
				}
			}
		}

		int getCommandParam(int id) {
			if (0 > id || id > params.size() - 1)
				return NULL;
			
			return std::stoi(params[id]);
		}

		float getCommandParamF(int id) {
			if (0 > id || id > params.size() - 1)
				return NULL;

			return std::stof(params[id]);
		}

		std::string getCommandParamS(int id) {
			if (0 > id || id > params.size() - 1)
				return NULL;

			return params[id];
		}
	};
};