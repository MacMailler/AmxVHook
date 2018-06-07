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
								for (int i = 1; i < params.size(); i++)
									if (!params[i].empty()) {
										if (gPool->reloadMod(params[i])) {
											char temp[64];
											sprintf_s(temp, "~g~AmxVHook: ~w~`~b~%s~w~` reloaded!", params[i].c_str());
											Funcs::showSubtitle(std::string(temp), 4000, TRUE);
										}
										else {
											char temp[64];
											sprintf_s(temp, "~g~AmxVHook:~w~`~b~%s~w~` ~r~NOT ~w~found!", params[i].c_str());
											Funcs::showSubtitle(std::string(temp), 4000, TRUE);
										}
									}
							}
						}
						else if (!params[0].compare("!l") && params.size() > 1) {
							for (int i = 1; i < params.size(); i++)
								if (!params[i].empty())
									gPool->loadMod(params[i]);
						}
						else {
							gPool->onModInputCommand(params[0], static_cast<cell>(params.size()) - 1);
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

		/*std::string inputBox() {
			float y = 1.1f;
			while (y > 0.984f) {
				WAIT(10);
				AmxVHook::Funcs::drawRect(0.000f, y, 1.0f, 0.10f, 0, 0, 0, 120);
				y -= 0.0050f;
			}

			static const char chars_upper[] = {
				'0','1','2','3','4','5','6','7','8','9',
				'A','B','C','D','E','F','G','H','I','J',
				'K','L','M','N','O','P','Q','R','S','T',
				'Y','V','W','X','Y','Z'
			};
			static const char chars_lower[] = {
				'!','@','#','$','%','^','&','*','(',')',
				'a','b','c','d','e','f','g','h','i','j',
				'k','l','m','n','o','p','q','r','s','t',
				'y','v','w','x','y','z'
			};

			std::string temp;
			while (!isKeyDown(VK_RETURN)) {
				WAIT(5);
				AmxVHook::Funcs::drawRect(0.000f, y, 1.0f, 0.10f, 0, 0, 0, 120);

				for (int i = 0; i < sizeof chars_upper; i++) {
					if (isKeyJustUp(chars_upper[i]))
						if (isKeyDown(VK_LSHIFT))
							if (i <= 9)
								temp.push_back(chars_lower[i]);
							else
								temp.push_back(chars_upper[i]);
						else
							if (i <= 9)
								temp.push_back(chars_upper[i]);
							else
								temp.push_back(chars_lower[i]);
				}

				if (isKeyJustUp(VK_BACK)) {
					if (temp.length() > 0)
						temp.pop_back();
				} else if (isKeyJustUp(VK_SPACE))
					temp.push_back(' ');
				else if (isKeyJustUp(VK_ESCAPE))
					return "";

				AmxVHook::Funcs::setupDraw(14, 0.2f, 200, 200, 200, 255);
				UI::SET_TEXT_CENTRE(1);
				UI::_SET_TEXT_ENTRY("STRING");
				UI::_ADD_TEXT_COMPONENT_STRING("INPUT:");
				UI::_DRAW_TEXT(0.010f, y);

				AmxVHook::Funcs::setupDraw(0, 0.2f, 200, 200, 200, 255);
				UI::SET_TEXT_CENTRE(0);
				UI::_SET_TEXT_ENTRY("STRING");
				UI::_ADD_TEXT_COMPONENT_STRING((char *)temp.c_str());
				UI::_DRAW_TEXT(0.020f, y);

			}
			return temp;
		}*/
	};
};