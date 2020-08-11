#pragma once
/** @file TreeException.h */

#include <stdexcept>
#include <string>

using namespace std;

/** Exception class for the ADT binary tree */
class TreeException : public logic_error
{
public:
  TreeException(const string& message = " ") : logic_error(message.c_str())
  { } // end constructor
}; // end TreeException

