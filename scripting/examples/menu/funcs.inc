#if defined __menu_funcs_inc__
  #endinput
#endif
#define __menu_funcs_inc__


stock addMenu(Float:x, Float:y, Float:w) {
	if (!isValidMenu(MenuCounter))
		return INVALID_MENU_ID;
		
	new id = MenuCounter++;
	
	Menus[id][menuHide] = true;
	Menus[id][menuActive] = false;
	Menus[id][menuFirstStart] = true;
	
	Menus[id][menuX] = x;
	Menus[id][menuY] = y;
	Menus[id][menuW] = w;
	
	Menus[id][menuCurrPage] = 0;
	Menus[id][menuLastPage] = 0;
	
	Menus[id][menuOffset] = 0;
	Menus[id][menuSelector] = 0;
	Menus[id][menuSelectorPos] = 0;
	
	Menus[id][menuMaxDrawElems] = 12;
	
	Menus[id][menuPageCounter] = 0;
	
	return id;
}

stock addPage(menu, const title[], parent = INVALID_PAGE_ID, bool:counter = false) {
	if (!isValidMenu(menu))
		return INVALID_PAGE_ID;
		
	if (!isValidPage(Menus[menu][menuPageCounter]))
		return INVALID_PAGE_ID;
		
	new id = Menus[menu][menuPageCounter];
	Menus[menu][menuPageCounter] = Menus[menu][menuPageCounter] + 1;
	
	Pages[menu][id][pageParent] = parent;
	
	strmid(Pages[menu][id][pageTitle], title, 0, strlen(title), 32);
	
	Pages[menu][id][pageTitleFont] = FONT_ITALIC;
	
	Pages[menu][id][pageTitleColor] = 0xAE1140DE;
	Pages[menu][id][pageTitleTextColor] = 0xDEDEDEFF;
	Pages[menu][id][pageSelectorColor] = 0xAE114033;
	Pages[menu][id][pageBackgroundColor] = 0x88;
	
	Pages[menu][id][pageElemSize] = 0.0390;
	Pages[menu][id][pageTitleSize] = 0.0390;
	Pages[menu][id][pageTitleFontSize] = 0.6;
	
	Pages[menu][id][pageY] = Menus[menu][menuY] + Pages[menu][id][pageElemSize];
		
	Pages[menu][id][pageH] = 0.0;
	
	Pages[menu][id][pageDrawCounter] = counter;
	
	Pages[menu][id][pageElemCounter] = 0;
	
	return id;
}

stock addElem(menu, page, const text[], eElemTypes:type = ElemTypeNone, font = FONT_NORMAL, bool:toggle = false, bool:centre = false, const value[] = "??") {
	if (!isValidMenu(menu))
		return INVALID_ELEM_ID;
		
	if (!isValidPage(page))
		return INVALID_ELEM_ID;
		
	new id = Pages[menu][page][pageElemCounter];
	Pages[menu][page][pageElemCounter] = Pages[menu][page][pageElemCounter] + 1;
	
	Elems[menu][page][id][elemType] = type;
	Elems[menu][page][id][elemFont][0] = font;
	Elems[menu][page][id][elemFont][1] = FONT_IMPACT;
	
	strmid(Elems[menu][page][id][elemText], text, 0, strlen(text), 64);
	switch (type) {
		case ElemTypePage : strmid(Elems[menu][page][id][elemValue], ">>", 0, 2, 64);
		case ElemTypeInput : strmid(Elems[menu][page][id][elemValue], "...", 0, 5, 64);
		default : strmid(Elems[menu][page][id][elemValue], value, 0, strlen(value), 64);
	}
	
	Elems[menu][page][id][elemCentre] = centre;
	Elems[menu][page][id][elemToggle] = toggle;
	
	Elems[menu][page][id][elemTextColor] = 0xDEDEDEFF;
	Elems[menu][page][id][elemValueColor] = 0xDEDEDEFF;
	
	Elems[menu][page][id][elemTextSize] = 0.3;
	Elems[menu][page][id][elemValueSize] = 0.35;
	
	if (id < Menus[menu][menuMaxDrawElems])
		Pages[menu][page][pageH] += Pages[menu][page][pageElemSize];
	
	calc(menu, page, id);
	
	return id;
}

stock setActiveMenu(menu) {
	if (!isValidMenu(menu))
		return 0;
		
	CurrActiveMenu = menu;
	
	return 1;
}

stock setActivePage(menu, page) {
	if (!isValidMenu(menu))
		return 0;
		
	if (!isValidPage(page))
		return 0;
		
	if (Menus[menu][menuOffset] != 0)
		for (new i; i < Pages[menu][Menus[menu][menuCurrPage]][pageElemCounter]; i++)
			calc(menu, Menus[menu][menuCurrPage], i);
				
	swap(Menus[menu][menuCurrPage], Menus[menu][menuLastPage]);
	
	Menus[menu][menuCurrPage] = page;
	Menus[menu][menuOffset] = 0;
	Menus[menu][menuSelector] = 0;
	Menus[menu][menuSelectorPos] = 0;
	
	return 1;
}

stock setMenuColor(menu, color) {
	if (!isValidMenu(menu))
		return 0;
		
	for (new i; i < Menus[menu][menuPageCounter]; i++) {
		Pages[menu][i][pageTitleColor] = color;
		Pages[menu][i][pageSelectorColor] = rgbaSetAlpha(color, 0x33);
	}
	
	return 1;
}

stock setPageColor(menu, page, color) {
	if (!isValidMenu(menu))
		return 0;
		
	if (!isValidPage(page))
		return 0;
		
	Pages[menu][page][pageTitleColor] = color;
	Pages[menu][page][pageSelectorColor] = rgbaSetAlpha(color, 0x33);
	
	return 1;
}

stock setElemValue(menu, page, elem, const value[]) {
	if (!isValidMenu(menu))
		return 0;
		
	if (!isValidPage(page))
		return 0;
		
	if (!isValidElem(elem))
		return 0;
		
	strmid(Elems[menu][page][elem][elemValue], value, 0, strlen(value), 64);
	
	return 1;
}

stock setElemValueFont(menu, page, elem, font) {
	if (!isValidMenu(menu))
		return 0;
		
	if (!isValidPage(page))
		return 0;
		
	if (!isValidElem(elem))
		return 0;
		
	Elems[menu][page][elem][elemFont][1] = font;
	
	return 1;
}

stock getMenuCount() {
	return MenuCounter;
}

stock getPageCount(menu) {
	if (!isValidMenu(menu))
		return 0;

	return Menus[menu][menuPageCounter];
}

stock getElemHash(menu, page, elem) {
	if (!isValidMenu(menu))
		return 0;
		
	if (!isValidPage(page))
		return 0;
		
	return getHashKey(Elems[menu][page][elem][elemText]);
}

stock moveMenu(menu, Float:x, Float:y) {
	if (!isValidMenu(menu))
		return 0;
		
	Menus[menu][menuX] += x;
	Menus[menu][menuY] += y;
	
	for(new i; i < Menus[menu][menuPageCounter]; i++) {
		Pages[menu][i][pageY] += y;
		for (new j; j < Pages[menu][i][pageElemCounter]; j++)
			calc(menu, i, j);
	}
	
	return 1;
}

stock setMenuPos(menu, Float:x, Float:y) {
	if (!isValidMenu(menu))
		return 0;
		
	Menus[menu][menuX] = x;
	Menus[menu][menuY] = y;
	
	for(new i; i < Menus[menu][menuPageCounter]; i++) {
		Pages[menu][i][pageY] = y + Pages[menu][i][pageTitleSize];
		for (new j; j < Pages[menu][i][pageElemCounter]; j++)
			calc(menu, i, j);
	}
	
	return 1;
}

stock menuDrawProcess() {
	for (new menu; menu < MenuCounter; menu++) {
		if (Menus[menu][menuHide])
			continue;
		
		new page = Menus[menu][menuCurrPage];
	
		// draw title
		drawRect(
			Menus[menu][menuX],
			Menus[menu][menuY],
			Menus[menu][menuW],
			Pages[menu][page][pageTitleSize],
			Pages[menu][page][pageTitleColor]
		);
	
		setTextDropShadow(2);
		drawString(
			Pages[menu][page][pageTitle],
			Menus[menu][menuX] + (Menus[menu][menuW] / 2),
			Menus[menu][menuY],
			Pages[menu][page][pageTitleFontSize],
			Pages[menu][page][pageTitleFont],
			Pages[menu][page][pageTitleTextColor],
			.centre = true
		);
		
	
		// draw background
		drawRect(
			Menus[menu][menuX],
			Pages[menu][page][pageY],
			Menus[menu][menuW],
			Pages[menu][page][pageH],
			Pages[menu][page][pageBackgroundColor]
		);
	
	
		// draw selector
		drawRect(
			Menus[menu][menuX],
			Pages[menu][page][pageY] + (Pages[menu][page][pageElemSize] * Menus[menu][menuSelectorPos]),
			Menus[menu][menuW],
			Pages[menu][page][pageElemSize],
			Pages[menu][page][pageSelectorColor]
		);
	
	
		// draw elems
		for (new i = Menus[menu][menuOffset], totalDrawElems = Menus[menu][menuMaxDrawElems] + Menus[menu][menuOffset]; i < totalDrawElems; i++) {
		
			switch (Elems[menu][page][i][elemType]) {
				case ElemTypeToggle : {
					static const color[] = { 0xAE1140DE, 0x11AE40DE };
					static const text[][] = { "(D)", "(E)" };

					drawString(
						Elems[menu][page][i][elemText],
						Elems[menu][page][i][elemX0],
						Elems[menu][page][i][elemY0],
						Elems[menu][page][i][elemTextSize],
						Elems[menu][page][i][elemFont][0],
						Elems[menu][page][i][elemTextColor],
						Elems[menu][page][i][elemCentre]
					);
					
					setTextWrap(.end = Elems[menu][page][i][elemX1]);
					setTextJustification(2);
					drawString(
						text[Elems[menu][page][i][elemToggle]],
						Elems[menu][page][i][elemX1],
						Elems[menu][page][i][elemY1],
						Elems[menu][page][i][elemValueSize],
						Elems[menu][page][i][elemFont][1],
						color[Elems[menu][page][i][elemToggle]]
					);
				}
				
				case ElemTypeInput, ElemTypePage,  ElemTypeValue : {
					drawString(
						Elems[menu][page][i][elemText],
						Elems[menu][page][i][elemX0],
						Elems[menu][page][i][elemY0],
						Elems[menu][page][i][elemTextSize],
						Elems[menu][page][i][elemFont][0],
						Elems[menu][page][i][elemTextColor],
						Elems[menu][page][i][elemCentre]
					);
					
					setTextWrap(.end = Elems[menu][page][i][elemX1]);
					setTextJustification(2);
					setTextDropShadow(2);
					drawString(
						Elems[menu][page][i][elemValue],
						Elems[menu][page][i][elemX1],
						Elems[menu][page][i][elemY1],
						Elems[menu][page][i][elemValueSize],
						Elems[menu][page][i][elemFont][1],
						Elems[menu][page][i][elemValueColor]
					);
				}
				
				default : {
					drawString(
						Elems[menu][page][i][elemText],
						Elems[menu][page][i][elemX0],
						Elems[menu][page][i][elemY0],
						Elems[menu][page][i][elemTextSize],
						Elems[menu][page][i][elemFont][0],
						Elems[menu][page][i][elemTextColor],
						Elems[menu][page][i][elemCentre]
					);
				}
			}
		}
	
	
		// draw elem counter
		if (Pages[menu][page][pageDrawCounter]) {
			drawRect(
				Menus[menu][menuX],
				Pages[menu][page][pageY] + Pages[menu][page][pageH],
				Menus[menu][menuW],
				Pages[menu][page][pageElemSize] / 2.0,
				Pages[menu][page][pageTitleColor]
			);
			
			setTextFont(FONT_IMPACT);
			setTextScale(0.3, 0.3);
			setTextColor(0xDEDEDEFF);
			setTextDropShadow(2, 0x000000FF);
			setTextJustification(2);
			setTextWrap(.end = (Menus[menu][menuX] + Menus[menu][menuW]) - 0.008);
			drawCounter(
				Menus[menu][menuSelector] + 1, Pages[menu][page][pageElemCounter],
				(Menus[menu][menuX] + Menus[menu][menuW]) - 0.008,
				(Pages[menu][page][pageY] + Pages[menu][page][pageH]) - 0.002
			);
		}
	}
	return 1;
}

stock menuInputProcess() {
	static wait, waitTime = 8;
	if (wait > 0) {
		wait--;
		return 0;
	}
	
	if (CurrActiveMenu == INVALID_MENU_ID)
		return 0;
		
	if (isKeyboardDisplayed())
		return 0;
		
	new menu = CurrActiveMenu;
	new page = Menus[menu][menuCurrPage];
	new selector = Menus[menu][menuSelector];
	
	if (isKeyJustUp(VK_NUMPAD9)) {
		if (Menus[menu][menuHide]) {
			if (Menus[menu][menuFirstStart]) {
				Menus[menu][menuFirstStart] = false;
				playSoundFrontend(-1, "FocusIn", "HintCamSounds");
			}
			playSoundDefault("SELECT");
		}
		else
			playSoundDefault("QUIT");
			
		Menus[menu][menuHide] = !Menus[menu][menuHide];

		wait = waitTime;
	}
	
	if (Menus[menu][menuHide])
		return 0;
		
	if (isKeyDown(VK_NUMPAD8)) {
		if (selectorUp(menu))
			playSoundDefault("NAV_UP_DOWN");
			
		wait = waitTime;
	}
	
	if (isKeyDown(VK_NUMPAD2)) {
		if (selectorDown(menu))
			playSoundDefault("NAV_UP_DOWN");
		
		wait = waitTime;
	}
	
	if (isKeyJustUp(VK_NUMPAD5)) {
		switch (Elems[menu][page][selector][elemType]) {
			case ElemTypeToggle : Elems[menu][page][selector][elemToggle] = !Elems[menu][page][selector][elemToggle];
		}

		//callFunc("onMenuElemTap", "iiii", _, menu, page, selector, ElemTapSelect);
		onMenuElemTap(menu, page, selector, ElemTapSelect);
		playSoundDefault("SELECT");
		
		wait = waitTime;
	}
	
	if (isKeyDown(VK_NUMPAD4)) {
		if (Elems[menu][page][selector][elemType] == ElemTypeValue) {
			playSoundDefault("NAV_LEFT_RIGHT");
			//callFunc("onMenuElemTap", "iiii", _, menu, page, selector, ElemTapNavLeft);
			onMenuElemTap(menu, page, selector, ElemTapNavLeft);
		}
		wait = waitTime;
	}
	
	if (isKeyDown(VK_NUMPAD6)) {
		if (Elems[menu][page][selector][elemType] == ElemTypeValue) {
			playSoundDefault("NAV_LEFT_RIGHT");
			//callFunc("onMenuElemTap", "iiii", _, menu, page, selector, ElemTapNavRight);
			onMenuElemTap(menu, page, selector, ElemTapNavRight);
		}
		wait = waitTime;
	}
	
	if (isKeyJustUp(VK_NUMPAD7) && page > 0) {
		if (Pages[menu][page][pageParent] != -1)
			setActivePage(menu, Pages[menu][page][pageParent]);
		else
			swap(Menus[menu][menuCurrPage], Menus[menu][menuLastPage]);
		
		if (Menus[menu][menuOffset] != 0)
			for (new i; i < Pages[menu][Menus[menu][menuCurrPage]][pageElemCounter]; i++)
				calc(menu, Menus[menu][menuCurrPage], i);
				
		Menus[menu][menuSelector] = 0;
		Menus[menu][menuSelectorPos] = 0;
		Menus[menu][menuOffset] = 0;
		
		playSoundDefault("BACK");
		
		wait = waitTime;
	}
	
	return 1;
}

static selectorUp(menu) {
	new i = Menus[menu][menuSelector];
	new page = Menus[menu][menuCurrPage];
	while (--i >= 0) {
		if (Elems[menu][page][i][elemType] != ElemTypeBreak) {
			Menus[menu][menuSelector] = i;
			break;
		}
	}
	
	if (i != Menus[menu][menuSelector])
		return false;
		
	Menus[menu][menuSelectorPos]--;
	if (Menus[menu][menuSelectorPos] < 0)
		Menus[menu][menuSelectorPos] = 0;
		
	if ((Menus[menu][menuSelector] - Menus[menu][menuOffset]) == -1) {
		Menus[menu][menuOffset]--;
		for (new j; j < Pages[menu][page][pageElemCounter]; j++) {
			Elems[menu][page][j][elemY0] += Pages[menu][page][pageElemSize];
			Elems[menu][page][j][elemY1] += Pages[menu][page][pageElemSize];
		}
	}
	return true;
}
	
static selectorDown(menu) {	
	new i = Menus[menu][menuSelector];
	new page = Menus[menu][menuCurrPage];
	while (++i < Pages[menu][page][pageElemCounter]) {
		if (Elems[menu][page][i][elemType] != ElemTypeBreak) {
			Menus[menu][menuSelector] = i;
			break;
		}
	}
	
	if (i != Menus[menu][menuSelector])
		return false;
	
	Menus[menu][menuSelectorPos]++;
	if (Menus[menu][menuSelectorPos] > Menus[menu][menuMaxDrawElems] - 1) {
		if (Menus[menu][menuSelector] > Menus[menu][menuMaxDrawElems] - 1) {
			Menus[menu][menuOffset]++;
			Menus[menu][menuSelectorPos]--;
			for (new j; j < Pages[menu][page][pageElemCounter]; j++) {
				Elems[menu][page][j][elemY0] -= Pages[menu][page][pageElemSize];
				Elems[menu][page][j][elemY1] -= Pages[menu][page][pageElemSize];
			}
		}	
	}
	return true;
}

static calc(menu, page, elem) {
	if (Elems[menu][page][elem][elemCentre])
		Elems[menu][page][elem][elemX0] = Menus[menu][menuX] + (Menus[menu][menuW] / 2);
	else
		Elems[menu][page][elem][elemX0] = Menus[menu][menuX] + 0.008;
		
	Elems[menu][page][elem][elemY0] = (Pages[menu][page][pageY] + (Pages[menu][page][pageElemSize] * elem)) + 0.008;

	Elems[menu][page][elem][elemX1] = (Menus[menu][menuX] + Menus[menu][menuW]) - 0.008;
	Elems[menu][page][elem][elemY1] = (Pages[menu][page][pageY] + (Pages[menu][page][pageElemSize] * elem)) + 0.008;
}

static playSoundDefault(const soundName[]) {
	playSoundFrontend(-1, soundName, "HUD_FRONTEND_DEFAULT_SOUNDSET");
}