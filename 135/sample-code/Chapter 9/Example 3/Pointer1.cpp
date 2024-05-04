/*This program stores the address of a variable in a pointer and prints the address*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int x = 25;
   int *ptr;   //ptr is a pointer to an int
   
   ptr = &x;  //store the address of x in ptr
   
   cout << "The value in x is " << x << endl;
   cout << "The value in ptr is " << ptr << endl;

   system("PAUSE");
   return 0;
}
