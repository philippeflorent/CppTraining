#include "SalesData.h"
#include "SalesItem.h"

#include <iostream>
#include <iostream>
#include <string>
using std::string;
// needs c++ command line/additional options -> /std:c++latest 
using std::cout, std::cin, std::endl, std::cerr, std::clog;
#include <vector>
using std::vector;
#include <iterator> // for begin/end on arrays
using std::begin, std::end;

int ex1()
{
	cout << "Enter two numbers:" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << endl;
	return 0;
}

int ex2()
{
	int sum = 0, val = 1;
	// keep executing the while as long as val is less than or equal to 10
	while (val <= 10) {
		sum += val;// assigns sum + val to sum
		++val;// add 1 to val
	}
	cout << "Sum of 1 to 10 inclusive is "
		<< sum << endl;
	return 0;
}

int ex3()
{
	int sum = 0;
	// sum values from 1 through 10 inclusive
	for (int val = 1; val <= 10; ++val)
	{
		sum += val;  // equivalent to sum = sum + val
	}
	cout << "Sum of 1 to 10 inclusive is "
		<< sum << endl;
	return 0;
}

int ex4()
{
	cout << "Ender numbers separated by spaces and non numerical or CTRL+Z to end list, then ENTER" << endl;
	int sum = 0, value = 0;
	// read until end-of-file, calculating a running total of all values read
	while (cin >> value)
	{
		sum += value; // equivalent to sum = sum + value
	}
	cout << "Sum is: " << sum << endl;
	return 0;
}

int ex5()
{
	cout << "Ender numbers separated by spaces and non numerical or CTRL+Z to end list, then ENTER" << endl;
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (cin >> currVal) {
		int cnt = 1;  // store the count for the current value we're processing
		while (cin >> val) { // read the remaining numbers
			if (val == currVal)   // if the values are the same
				++cnt;            // add 1 to cnt
			else { // otherwise, print the count for the previous value
				cout << currVal << " occurs "
					<< cnt << " times" << endl;
				currVal = val;    // remember the new value
				cnt = 1;          // reset the counter
			}
		}  // while loop ends here
		// remember to print the count for the last value in the file
		cout << currVal << " occurs "
			<< cnt << " times" << endl;
	} // outermost if statement ends here
	return 0;
}

int ex6()
{
	cout << "example: 0-201-70353-X 4 24.99" << endl;

	SalesItem book;
	// read ISBN, number of copies sold, and sales price
	cin >> book;
	// write ISBN, number of copies sold, total revenue, and average price
	cout << book << endl;
	return 0;
}

int ex7()
{
	cout << "example: 0-201-78345-X 3 20.00" << endl;
	cout << "example: 0-201-78345-X 2 25.00" << endl;
	
	SalesItem item1, item2;
	cin >> item1 >> item2;   // read a pair of transactions
	cout << item1 + item2 << endl; // print their sum
	return 0;
}

int ex8()
{
	cout << "example: 0-201-78345-X 3 20.00" << endl;
	cout << "example: 0-201-78345-X 2 25.00" << endl;

	SalesItem item1, item2;
	cin >> item1 >> item2;
	// first check that item1 and item2 represent the same book
	if (item1.isbn() == item2.isbn()) {
		cout << item1 + item2 << endl;
		return 0;   // indicate success
	}
	else {
		cerr << "Data must refer to same ISBN"
			<< endl;
		return -1;  // indicate failure
	}
}

int ex9()
{
	SalesItem total; // variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	if (cin >> total) {
		SalesItem trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (cin >> trans) {
			// if we're still processing the same book
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			else {
				// print results for the previous book
				cout << total << endl;
				total = trans;// total now refers to the next book
			}
		}
		cout << total << endl; // print the last transaction
	}
	else {
		// no input! warn the user
		cerr << "No data?!" << endl;
		return -1;// indicate failure
	}
	return 0;
}

int ex10()
{
	cout << "cout test" << endl;
	clog << "clog test" << endl;
	cerr << "cerr test" << endl;
	return 0;
}

int ex11()
{
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;
	cout << u - u2 << endl;

	int i = 10, i2 = 42;
	cout << i2 - i << endl;
	cout << i - i2 << endl;

	cout << i - u << endl;
	cout << u - i << endl;
	return 0;
}

int ex12()
{
	SalesData data1, data2;
	// code to read into data1 and data2
	cout << "example: 0-201-78345-X 3 20.00" << endl;
	cout << "example: 0-201-78345-X 2 25.00" << endl;

	double price1 = 0, price2 = 0;
	cin >> data1.bookNo >> data1.units_sold >> price1;
	cin >> data2.bookNo >> data2.units_sold >> price2;

	data1.revenue = price1 * data1.units_sold;
	data2.revenue = price2 * data2.units_sold;

	// code to check whether data1 and data2 have the same ISBN
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		// print: ISBN, total sold, total revenue, average price per book
		cout << data1.bookNo << " " << totalCnt
			<< " " << totalRevenue << " ";
		if (totalCnt != 0)
			cout << "avg price per book " << (totalRevenue / totalCnt) << endl;
		else
			cout << "(no sales)" << endl;
		return 0; // indicate success
	}
	else {// transactions weren't for the same ISBN
		cerr << "Data must refer to the same ISBN"
			<< endl;
		return -1; // indicate failure
	}

	return 0;
}

int ex13()
{
	//----------------------------------------------------------
	string s("Hello World!!!");
	// punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
	decltype(s.size()) punct_cnt = 0;
	// count the number of punctuation characters in s
	for (auto c : s) // for every char in s
		if (ispunct(c)) // if the character is punctuation
			++punct_cnt; // increment the punctuation counter
	cout << punct_cnt << " punctuation characters in " << s << endl;

	//----------------------------------------------------------
	// convert s to uppercase
	for (auto& c : s) // for every char in s (note: c is a reference)
		c = toupper(c); // c is a reference, so the assignment changes the char	in s
	cout << s << endl;
	if (!s.empty()) // make sure there's a character to print
		cout << s[0] << endl; // print the first character in s

	//----------------------------------------------------------
	s = "some string";
	if (!s.empty()) // make sure there's a character in s[0]
		s[0] = toupper(s[0]); // assign a new value to the first character in s
	cout << s << endl;

	//----------------------------------------------------------
	// process characters in s until we run out of characters or we hit a whitespace
	s = "Another String";
	for (decltype(s.size()) index = 0;
		index != s.size() && !isspace(s[index]);
		++index)
		s[index] = toupper(s[index]); // capitalize the current character
	cout << s << endl;

	//----------------------------------------------------------
	const string s2 = "Keep out!";
	for (auto& c : s2) 
	{
		cout << c << " ";
	}
	cout << endl;
	return 0;
}

int ex14()
{
	//----------------------------------------------------------
	const string hexdigits = "0123456789ABCDEF"; // possible hex digits
	cout << "Enter a series of numbers between 0 and 15"
		<< " separated by spaces. Hit ENTER when finished: "
		<< endl;
	string result; // will hold the resulting hexify'd string
	string::size_type n; // hold numbers from the input

	while (cin >> n)
		if (n < hexdigits.size()) // ignore invalid input
			result += hexdigits[n]; // fetch the indicated hex digit
	cout << "Your hex number is: " << result << endl;

	return 0;
}

int ex15()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	for (auto& i : v) // for each element in v (note: i is a reference)
		i *= i; // square the element value
	
	for (auto i : v) // for each element in v
		cout << i << " "; // print the element
	cout << endl;

	for (decltype(v.size()) index = 0;index != v.size(); ++index)
		cout << v[index] << " is " << ( (v[index] % 2 == 0) ? "even" :"odd") << endl; // print the element

	cout << endl;
	return 0;
}

int ex16()
{
	vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
	unsigned grade;
	while (cin >> grade)  // read the grades
	{
		if (grade <= 100) // handle only valid grades
			++scores[grade / 10]; // increment the counter for the current cluster
	}
	for (auto i : scores) // for each element in v
		cout << i << " "; // print the element
	return 0;
}

int ex17()
{
	//----------------------------------------------------------
	string s("some string");
	if (s.begin() != s.end())  // make sure s is not empty
	{
		auto it = s.begin(); // it denotes the first character in s
		*it = toupper(*it); // make that character uppercase
	}
	cout << s << endl;

	//----------------------------------------------------------
	// process characters in s until we run out of characters or we hit a whitespace
	s = "another string";
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it); // capitalize the current character
	}
	cout << s << endl;
	//----------------------------------------------------------
	// binary search using iterator operator <
	// beg and end will denote the range we're searching
	string text = "some text string";
	char sought = 'r';
	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg) / 2; // original midpoint
	// while there are still elements to look at and we haven't yet found sought
	while (mid != end && *mid != sought) 
	{
		if (sought < *mid) // is the element we want in the first half?
		{
			end = mid; // if so, adjust the range to ignore the second half
		}
		else // the element we want is in the second half
		{
			beg = mid + 1; // start looking with the element just after mid
		}
		mid = beg + (end - beg) / 2; // new midpoint
		cout << "mid point " << *mid << endl;
	}

	return 0;
}

int ex18()
{
	// count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
	unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100)
			++scores[grade / 10]; // increment the counter for the current cluster
	}

	for (auto i : scores) // for each counter in scores
		cout << i << " "; // print the value of that counter
	cout << endl;

	// unsafe to use [10] "past the end of"
	//unsigned* b = &scores[0]; // pointer to beginning
	//unsigned* e = &scores[10]; // pointer just past the last element 
	unsigned* b = begin(scores); // pointer to the first element in ia
	unsigned* e = end(scores); // pointer one past the last element in ia

	for (unsigned* i = b; i != e; ++i)
		cout << *i << " "; // print the value of that counter
	cout << endl;

	return 0;
}

int ex19()
{
	//----------------------------------------------------------------------- multi arrays
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt]; // 12 uninitialized elements
	// for each row
	for (size_t i = 0; i != rowCnt; ++i) {
		// for each column within the row
		for (size_t j = 0; j != colCnt; ++j) {
			// assign the element's positional index as its value
			ia[i][j] = i * colCnt + j;
		}
	}

	//----------------------------------------------------------------------- multi arrays
	// wee HAVE to use references otherwise the inner loop wont be compiled as loc would iterate to a int*, not an array
	size_t cnt = 0;
	for (auto& row : ia) // for every element in the outer array
		for (auto& col : row) { // for every element in the inner array
			col = cnt; // give this element the next value
			++cnt; // increment cnt
		}
	return 0;
}

int ex20()
{
	return 0;
}

int main()
{
	return ex15();
	//return ex20();
}

// p233