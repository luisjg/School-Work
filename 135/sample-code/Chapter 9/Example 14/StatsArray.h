#include <iostream>
#include <stdlib.h>
using namespace std;

class StatsArray
{
	private:
	   double *list;
	   int listSize;
	public:
	     StatsArray(int);
	      void displayArray();
	    ~StatsArray();
};
