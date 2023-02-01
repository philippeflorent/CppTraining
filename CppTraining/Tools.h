#pragma once

#include "common.h"

/*
	presentation
*/
void line(bool empty);
void header();
void footer();

/*
	exercices functions from the book
*/
int factorial(int val);
size_t count_calls();
string::size_type find_char(const string& s, char c, string::size_type& occurs);
bool is_sentence(const string& s);
void printArrayOldStyle(const char* cp);
void printArrayBegEnd(const int* beg, const int* end);
void printArrayWithSize(const int ia[], size_t size);
void printArrayReference(int(&arr)[10]);