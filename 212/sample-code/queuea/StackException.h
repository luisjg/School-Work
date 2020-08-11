#ifndef STACKEXCEP
#define STACKEXP

#include <stdexcept>
#include <string>
using namespace std;

class StackException : public logic_error
{
public:
	StackException(const string & message = "") : logic_error(message.c_str())
	{} // end constructor
};	// end StackException
#endif
