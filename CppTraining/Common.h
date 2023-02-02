#pragma once

#include <iostream>
#include <iostream>
#include <iosfwd>
using std::istream, std::ostream;

#include <string>
using std::string;
// needs c++ command line/additional options -> /std:c++latest 
using std::cout, std::cin, std::endl, std::cerr, std::clog;
#include <vector>
using std::vector;
#include <iterator> // for begin/end on arrays
using std::begin, std::end;

#include <stdexcept>
using std::runtime_error, std::exception,std::underflow_error;

#include <initializer_list>
using std::initializer_list;

#include <cassert>
