#if defined __menu_defines_inc__
  #endinput
#endif
#define __menu_defines_inc__

#if !defined __menu_limits__
	#define __menu_limits__
	
	#define MAX_MENUS (8)
	#define MAX_PAGES (64)
	#define MAX_ELEMS (64)
	
#endif

#define INVALID_MENU_ID (-1)
#define INVALID_PAGE_ID (-1)
#define INVALID_ELEM_ID (-1)

#define isValidMenu(%0) (0 <= %0 < MAX_MENUS)
#define isValidPage(%0) (0 <= %0 < MAX_PAGES)
#define isValidElem(%0) (0 <= %0 < MAX_ELEMS)