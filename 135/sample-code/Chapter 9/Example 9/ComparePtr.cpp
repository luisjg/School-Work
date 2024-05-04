/*This program uses a pointer to display the contents of an integer array.  It illustrates
the comparison of pointers*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   const int SIZE = 8;  //to use as the array size
   int set[] = {5,10,15,20,25,30,35,40};  //declare and initialize an array of 8 ints
   
   int *nums = set;  //nums is pointing to set (the first element in teh array
   
   //use the pointer to print out the set
   while(nums <= &set[SIZE-1])  //while the address of nums is less than the address of set[7]
   {
     cout << *nums << " " << endl;
     nums++;
   } 

   system("PAUSE");
   return 0;
}
