#if defined __input_inc__
  #endinput
#endif
#define __input_inc__

enum eKeys {
	VK_LBUTTON= 0x01,
	VK_RBUTTON= 0x02,
	VK_CANCEL = 0x03,
	VK_MBUTTON= 0x04,
	VK_XBUTTON1=0x05,
	VK_XBUTTON2=0x06,
	VK_BACK   = 0x08,
	VK_TAB    = 0x09,
	VK_CLEAR  = 0x0C,
	VK_RETURN = 0x0D,
	VK_SHIFT  = 0x10,
	VK_CONTROL= 0x11,
	VK_MENU   = 0x12,
	VK_PAUSE  = 0x13,
	VK_CAPITAL= 0x14,
	VK_ESCAPE = 0x1B,
	VK_SPACE  = 0x20,
	VK_PRIOR  = 0x21,
	VK_NEXT   = 0x22,
	VK_END    = 0x23,
	VK_HOME   = 0x24,
	VK_LEFT   = 0x25,
	VK_UP     = 0x26,
	VK_RIGHT  = 0x27,
	VK_DOWN   = 0x28,
	VK_SELECT = 0x29,
	VK_PRINT  = 0x2A,
	VK_EXECUTE= 0x2B,
	VK_SNAPSHOT=0x2C,
	VK_INSERT = 0x2D,
	VK_DELETE = 0x2E,
	VK_HELP   = 0x2F,
	VK_LWIN   = 0x5B,
	VK_RWIN   = 0x5C,
	VK_APPS   = 0x5D,
	VK_SLEEP  = 0x5F,
	VK_NUMPAD0= 0x60,
	VK_NUMPAD1= 0x61,
	VK_NUMPAD2= 0x62,
	VK_NUMPAD3= 0x63,
	VK_NUMPAD4= 0x64,
	VK_NUMPAD5= 0x65,
	VK_NUMPAD6= 0x66,
	VK_NUMPAD7= 0x67,
	VK_NUMPAD8= 0x68,
	VK_NUMPAD9= 0x69,
	VK_MULTIPLY=0x6A,
	VK_ADD    = 0x6B,
	VK_SEPARATOR=0x6C,
	VK_SUBTRACT=0x6D,
	VK_DECIMAL= 0x6E,
	VK_DIVIDE = 0x6F,
	VK_F1     = 0x70,
	VK_F2     = 0x71,
	VK_F3     = 0x72,
	VK_F4     = 0x73,
	VK_F5     = 0x74,
	VK_F6     = 0x75,
	VK_F7     = 0x76,
	VK_F8     = 0x77,
	VK_F9     = 0x78,
	VK_F10    = 0x79,
	VK_F11    = 0x7A,
	VK_F12    = 0x7B,
	VK_F13    = 0x7C,
	VK_F14    = 0x7D,
	VK_F15    = 0x7E,
	VK_F16    = 0x7F,
	VK_F17    = 0x80,
	VK_F18    = 0x81,
	VK_F19    = 0x82,
	VK_F20    = 0x83,
	VK_F21    = 0x84,
	VK_F22    = 0x85,
	VK_F23    = 0x86,
	VK_F24    = 0x87,
	VK_NUMLOCK= 0x90,
	VK_SCROLL = 0x91,
	VK_LSHIFT = 0xA0,
	VK_RSHIFT = 0xA1,
	VK_LCONTROL=0xA2,
	VK_RCONTROL=0xA3,
	VK_LMENU  = 0xA4,
	VK_RMENU  = 0xA5
};

enum eInputGroups {
	IG_MOVE = 0,
	IG_LOOK = 1,
	IG_WHEEL = 2,
	IG_CELLPHONE_NAVIGATE = 3,
	IG_CELLPHONE_NAVIGATE_UD = 4,
	IG_CELLPHONE_NAVIGATE_LR = 5,
	IG_FRONTEND_DPAD_ALL = 6,
	IG_FRONTEND_DPAD_UD = 7,
	IG_FRONTEND_DPAD_LR = 8,
	IG_FRONTEND_LSTICK_ALL = 9,
	IG_FRONTEND_RSTICK_ALL = 10,
	IG_FRONTEND_GENERIC_UD = 11,
	IG_FRONTEND_GENERIC_LR = 12,
	IG_FRONTEND_GENERIC_ALL = 13,
	IG_FRONTEND_BUMPERS = 14,
	IG_FRONTEND_TRIGGERS = 15,
	IG_FRONTEND_STICKS = 16,
	IG_SCRIPT_DPAD_ALL = 17,
	IG_SCRIPT_DPAD_UD = 18,
	IG_SCRIPT_DPAD_LR = 19,
	IG_SCRIPT_LSTICK_ALL = 20,
	IG_SCRIPT_RSTICK_ALL = 21,
	IG_SCRIPT_BUMPERS = 22,
	IG_SCRIPT_TRIGGERS = 23,
	IG_WEAPON_WHEEL_CYCLE = 24,
	IG_FLY = 25,
	IG_SUB = 26,
	IG_VEH_MOVE_ALL = 27,
	IG_CURSOR = 28,
	IG_CURSOR_SCROLL = 29,
	IG_SNIPER_ZOOM_SECONDARY = 30,
	IG_VEH_HYDRAULICS_CONTROL = 31,
	IG_MAX_INPUTGROUPS = 32,
	IG_INVALID = 33
};

forward onModInputText(text[]);
forward onModInputCommand(cmd[], params);
forward onModInputCanceled();

native isLookInverted();
native isControlEnabled(group, control);
native isControlPressed(group, control);
native isControlReleased(group, control);
native isControlJustPressed(group, control);
native isControlJustReleased(group, control);
native isDisabledControlPressed(group, control);
native isDisabledControlJustPressed(group, control);
native isDisabledControlJustReleased(group, control);

native isKeyDown(key);
native isKeyJustUp(key, bool:exclusive = false);
native resetKeyState(key);

native disableControlAction(group, control, bool:disable);
native enableControlAction(group, control, bool:enable);
native disableAllControlActions(group);
native enableAllControlActions(group);

native setPadShake(duration, frequency);
native setInputExclusive(group, control); 
native setControlNormal(group, control, Float:normal); 

native getControlValue(group, control); 
native Float:getControlNormal(group, control); 
native Float:getDisabledControlNormal(group, control); 

native getCommandParams(id, dest[], len = sizeof dest);
native getCommandParamsInt(id);
native getCommandParamsHash(id);
native Float:getCommandParamsFloat(id);

native stopPadShake();

native displayOnScreeKeyboard(const title[], const defaultText[]);