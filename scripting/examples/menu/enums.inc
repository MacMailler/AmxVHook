#if defined __menu_enums_inc__
  #endinput
#endif
#define __menu_enums_inc__


enum eElemTypes {
	ElemTypeNone,
	ElemTypeToggle,
	ElemTypeInput,
	ElemTypePage,
	ElemTypeValue,
	ElemTypeBreak
};

enum eElemTapTypes {
	ElemTapSelect,
	ElemTapNavRight,
	ElemTapNavLeft
};
