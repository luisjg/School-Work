#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
    Circle circ1;  //instantiate a variable of type Circle
    double area;  //to hold the area of the circle after its calculated

    Circle *circPtr; //define a pointer to a circle called circPtr

    circPtr = &circ1; //circPtr points to the circ1 object (contains circ1’s address)

    //the cirPtr can then be used to call circ1’s member 
    //functions using the -> operator
    circPtr->setRadius(10);  //sets circ1’s radius to 10


   area = circPtr->getArea();  //calls circ1’s getArea member function and stores
     		                //the result in the area variable
   
   cout << "circ1's radius is " << circ1.getRadius() << " and the area is " << area << endl;

   system("PAUSE");
   return 0;
} 
