/** @file TableException.h */
#ifndef TABLEEXCEPTION_H
#define TABLEEXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

/** Exception class for the ADT Table */
class TableException : public logic_error{
	public:
		TableException(const string& message="")
		: logic_error(message.c_str()){
		}// end constructor
}; // end TableException
#endif