/*This program illustrates the use of pointers to structs*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   struct Circle  //declare the type Circle
   {
     double radius;
   };
   
   Circle piePlate;  //declare a variable of type Circle
   
   Circle *circPtr; //declare a pointer to a Circle Structure

   circPtr = &piePlate; //store the address of piePlate in the circPointer variable
   
   //set piePlate's member radius to 10 using the circPointer
   circPtr->radius = 10;
   
   cout << "piePlate's radius is " << circPtr->radius << endl;

   system("PAUSE");
   return 0;
}


