#include "Screen.h"

Screen& Screen::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c; // move cursor to the column within that row
	return *this; // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
	pos row = r * width; // compute row location
	return contents[row + c]; // return character at the given column
}

Screen& Screen::set(char c)
{
	while (contents.size() < cursor)
	{
		contents += " ";
	}
	contents[cursor] = c; // set the new value at the current cursor location
	return *this; // return this object as an lvalue
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch; // set specified location to given value
	return *this; // return this object as an lvalue
}