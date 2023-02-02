#include "WindowMgr.h"

#include "Screen.h"

void WindowMgr::clear(ScreenIndex i)
{
	// s is a reference to the Screen we want to clear
	Screen& s = screens[i];
	// reset the contents of that Screen to all blanks
	s.contents = string(s.height * s.width, ' ');
}

WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}