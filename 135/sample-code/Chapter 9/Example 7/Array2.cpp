/*This program shows an array being processed with pointers*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   short numbers [] = {10,20,30,40,50}; //declares and initializes an array 				      //of 5 ints
   
   //adds 1 * sizeof(short) to the pointer numbers to access the second 
   //element of the array an so on through all of the array elements
   cout << "The first element of the array is " << *numbers << endl;
   cout << "The second element of the array is " << *(numbers + 1) << endl;
   cout << "The third element of the array is " << *(numbers + 2) << endl;
   cout << "The fourth element of the array is " << *(numbers + 3) << endl;
   cout << "The fifth (last) element of the array is " << *(numbers + 4) << endl;
   
   system("PAUSE");
   return 0;
}

