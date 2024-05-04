#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int values[3];   //this is an array with 3 elements not 2
   int count;

   cout << "The counter variable is off by one in the input loop\n"
         << "causing only 2 values to only be input in the 3 element array. \n";

   for(count = 1; count < 3; count++)
     values[count] = 100;

   for(count = 0; count < 3; count++)
     cout << values[count]<< endl;


   system("PAUSE");
   return 0;
}
