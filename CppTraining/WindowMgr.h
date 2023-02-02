#pragma once

#include "Screen.h"
#include "Common.h"

class WindowMgr {
public:

private:
	using ScreenIndex = std::vector<Screen>::size_type;
	// reset the Screen at the given position to all blanks
	void clear(ScreenIndex);
	// Screens this Window_mgr is tracking
	// by default, a Window_mgr has one standard sized blank Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
public:	
	ScreenIndex addScreen(const Screen&);
};
