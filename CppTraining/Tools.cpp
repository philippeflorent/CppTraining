#include "tools.h"

/*!
Function that outputs a line of '=' on the console and an end of line character

\param[in] empty           if true, only the new line is output
*/
void line(bool empty)
{
	if (!empty)
	{
		for (int i = 0; i < 80; i++)
		{
			cout << "=";
		}
	}
	cout << endl;
}

/*!
Function that outputs my header
*/
void header()
{
	line(false);
	cout << " Exercices from the book C++ Primer 5th edition" << endl << endl;
	cout << " Philippe Florent 2023" << endl << endl;
	cout << " a simple repo to help me strenghten my C++/GIT knowledge" << endl;
	line(false);
	line(true);
}

/*!
Function that outputs my footer
*/
void footer()
{
	line(true);
	line(true);
	line(false);
}

/*!
Function that outputs the factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)

\param[in] val		the value to factorize
\retval ret"		the factorial value
*/
int factorial(int val)
{
	int ret = 1; // local variable to hold the result as we calculate it
	while (val > 1)
		ret *= val--; // assign ret * val to ret and decrement val
	return ret; // return the result
}

/*!
Function that counts calls with a static local variable that keep its value
*/
size_t count_calls()
{
	static size_t ctr = 0; // value will persist across calls
	return ++ctr;
}

/*!
Function that returns the index of the first occurrence of c in s
- the reference parameter occurs counts how often c occurs
- use const when parameter is read only!!

\param[in] s			string to parse
\param[in] c			character to search for
\param[in] occurs		occurences counter
\retval ret				first occurence
*/
string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
	auto ret = s.size(); // position of the first occurrence, if any
	occurs = 0; // set the occurrence count parameter
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i; // remember the first occurrence of c
			++occurs; // increment the occurrence count
		}
	}
	return ret; // count is returned implicitly in occurs
}

/*!
Function that check if phrase as an ending '.' character

\param[in] s			string to parse
\retval bool			is sentence
*/
bool is_sentence(const string& s)
{
	// if there's a single period at the end of s, then s is a sentence
	string::size_type ctr = 0;
	// gives its const s string as parameter
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

/*!
Function that parse an array - old style array passing needs a NULL terminator

\param[in] cp	array pointer (must terminate with NULL element !!)
*/
void printArrayOldStyle(const char* cp)
{
	if (cp) // if cp is not a null pointer
		while (*cp) // so long as the character it points to is not a null character
			cout << *cp++; // print the character and advance the pointer
}


/*!
Function that parse an array - better array passing

\param[in] beg			start of array
\param[in] end			end of array
*/
void printArrayBegEnd(const int* beg, const int* end)
{
	// print every element starting at beg up to but not including end
	while (beg != end)
		cout << *beg++ << " "; // print the current element
	// and advance the pointer
}

/*!
Function that parse an array - better array passing with size parameter

\param[in] ia			array to parse
\param[in] size			size of array
*/
void printArrayWithSize(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << " ";
	}
}

/*!
Function that parse an array - parameter is a reference to an array; the dimension is part of the type

\param[in] arr			array to parse, size is fixed
*/
void printArrayReference(int(&arr)[10])
{
	for (auto elem : arr)
		cout << elem << " ";
}