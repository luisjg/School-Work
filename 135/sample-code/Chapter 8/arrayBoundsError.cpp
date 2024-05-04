/*This program unsafely accesses an area of memory
by writing values beyond the arrays boundary.  This could cause
your program to crash*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int values[3];   //this is an array with 3 elements not 4
   int count;

   cout << "The array bounds are off by one in the loops\n";

   for(count = 0; count <=3; count++)
     values[count] = 100;

   for(count = 0; count <=3; count++)
     cout << values[count]<< endl;


   system("PAUSE");
   return 0;
}
