#include "tools.h"

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

void header()
{
	line(false);
	cout << " Exercices from the book C++ Primer 5th edition" << endl << endl;
	cout << " Philippe Florent 2023" << endl << endl;
	cout << " a simple repo to help me strenghten my C++/GIT knowledge" << endl;
	line(false);
	line(true);
}

void footer()
{
	line(true);
	line(false);
}

// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int factorial(int val)
{
	int ret = 1; // local variable to hold the result as we calculate it
	while (val > 1)
		ret *= val--; // assign ret * val to ret and decrement val
	return ret; // return the result
}

/*
 static local variables in function keep their values
*/
size_t count_calls()
{
	static size_t ctr = 0; // value will persist across calls
	return ++ctr;
}

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
// use const when parameter is read only!!
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

bool is_sentence(const string& s)
{
	// if there's a single period at the end of s, then s is a sentence
	string::size_type ctr = 0;
	// gives its const s string as parameter
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

