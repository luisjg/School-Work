/*This program shows an array being processed with pointers*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   short numbers [] = {10,20,30,40,50}; //declares and initializes an array of 5 ints
   
   //adds 1 * sizeof(short) to the pointer numbers to access the second element of
   //the array an so on through all of the array elements
   for(int index = 0; index < 5; index++)
   {
      cout << "numbers[" << index << "] = "<< *(numbers + index) << endl;
   }
   
   system("PAUSE");
   return 0;
}
