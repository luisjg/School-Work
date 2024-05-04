#include "StatsArray.h"

StatsArray::StatsArray(int size)
{
	list = new double[size];
	listSize = size;

	for(int i = 0; i < size; i++) {       //initializes all array values to 5.1
		list[i] = 5.1;
	}
}

StatsArray::~StatsArray()
{
	delete [] list;
}

void StatsArray::displayArray()
{
   for(int i = 0; i < listSize; i++) {
        cout << list[i] << endl;
   }
}
