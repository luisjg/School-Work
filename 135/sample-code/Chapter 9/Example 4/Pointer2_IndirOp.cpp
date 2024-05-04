/*This program demonstrates the use of the indirection operator on a pointer
(dereferencing a pointer)*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int x = 25;
   int *ptr;   //ptr is a pointer to an int
   
   ptr = &x;  //store the address of x in ptr
   
   cout << "Here is the value of x printed twice: " 
        << "x = " << x << " *ptr = " << *ptr << endl;
   
   *ptr = 100;  //we have actually changed the value pointed to by ptr
   cout << "Here is the new value of x printed twice: " 
        << "x = " << x << " *ptr = " << *ptr << endl;

   system("PAUSE");
   return 0;
}
