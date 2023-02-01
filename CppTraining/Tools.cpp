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
