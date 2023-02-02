#pragma once

#include "Common.h"

/*
	presentation
*/
void line(bool empty);
void header();
void footer();
void exampleBooks();

/*
	exercices functions from the book
*/
int factorial(int val);
int factorialRecursive(int val);
size_t count_calls();
string::size_type find_char(const string& s, char c, string::size_type& occurs);
bool is_sentence(const string& s);
void printArrayOldStyle(const char* cp);
void printArrayBegEnd(const int* beg, const int* end);
void printArrayWithSize(const int ia[], size_t size);
void printArrayReference(int(&arr)[10]);

class ErrCode
{
public:
	ErrCode(int code) {}
	string msg() { return "Some Error Message"; }
};
void error_msg(ErrCode e, initializer_list<string> il);
vector<string> process(string expected, string actual);

char& get_val(string& str, string::size_type ix);