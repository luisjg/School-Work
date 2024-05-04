/*This program demonstrates the ability of a poiter to point to different
variables*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int x = 2, y = 2, z = 2;
   int *ptr;   //ptr is a pointer to an int
   
   cout << "Original Values: x = " << x << " y = " << y << " z = " << z << endl; 
   
   ptr = &x;  //store the address of x in ptr
   *ptr = *ptr * 2;  //we are indirectly changing the value in x 
   ptr = &y;  //store the address of y in ptr
   *ptr = *ptr * 3;  //we are indirectly changing the value in y
   ptr = &z;   //store the address of z in ptr
   *ptr = *ptr * 4;  //we are indirectly changing the value in z
   
   cout << "Modified Values: x = " << x << " y = " << y << " z = " << z << endl; 

   system("PAUSE");
   return 0;
}
