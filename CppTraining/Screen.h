#pragma once

#include "Common.h"

class Screen {
public:
	friend class WindowMgr;
	// following does not work --- WindowMgr::clear must have been declared before class Screen
	// friend void WindowMgr::clear(ScreenIndex);

	typedef string::size_type pos;
	// alternative way to declare a type member using a type alias
	// using pos = std::string::size_type;
	Screen() = default; // needed because Screen has another constructor
	// cursor initialized to 0 by its in-class initializer
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) { access_ctr = 0;  }
	char get() const // get the character at the cursor
	{
		return contents[cursor];
	}
	// implicitly inline
	char get(pos ht, pos wd) const; // explicitly inline
	Screen& move(pos r, pos c); // can be made inline later
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(std::ostream& os)
	{
		do_display(os); return *this;
	}
	const Screen& display(std::ostream& os) const
	{
		do_display(os); return *this;
	}
private:
	pos cursor = 0;
	pos height = 25, width = 80;
	string contents;
	mutable size_t access_ctr=0; // may change even in a const object
	void do_display(std::ostream& os) const { os << contents; }
};
