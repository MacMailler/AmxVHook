#if defined __menu_data_inc__
  #endinput
#endif
#define __menu_data_inc__


enum eMenuData {
	bool:menuHide,
	bool:menuActive,
	bool:menuFirstStart,
	
	Float:menuX,
	Float:menuY,
	Float:menuW,
	
	menuCurrPage,
	menuLastPage,
	
	menuOffset,
	menuSelector,
	menuSelectorPos,
	
	menuMaxDrawElems,
	
	menuPageCounter
};
new Menus[MAX_MENUS][eMenuData];
new MenuCounter = 0;
new CurrActiveMenu = 0;


enum ePageData {
	pageParent,
	
	pageTitle[32],
	
	pageTitleFont,
	pageTitleColor,
	pageTitleTextColor,
	pageSelectorColor,
	pageBackgroundColor,
	
	Float:pageY,
	Float:pageH,
	
	Float:pageElemSize,
	Float:pageTitleSize,
	Float:pageTitleFontSize,
	
	bool:pageDrawCounter,
	
	pageElemCounter
};
new Pages[MAX_MENUS][MAX_PAGES][ePageData];


enum eElemData {
	eElemTypes:elemType,
	
	elemFont[2],
	elemText[64],
	elemValue[64],
	
	elemTextColor,
	elemValueColor,
	
	bool:elemCentre,
	bool:elemToggle,
	
	Float:elemTextSize,
	Float:elemValueSize,
	
	Float:elemX0,
	Float:elemY0,
	Float:elemX1,
	Float:elemY1
};
new Elems[MAX_MENUS][MAX_PAGES][MAX_ELEMS][eElemData];
