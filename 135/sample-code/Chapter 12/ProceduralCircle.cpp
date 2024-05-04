/*PROCEDURAL Circle Program*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

//function prototypes
double setRadius();
double getArea(double);

int main()
{
   double radius;
   double area;

   //function calls to calculate info for function
   radius = setRadius();
   area = getArea(radius);

   cout << "The area of a circle with radius = " << radius << " is "
        << area << endl;

   system("PAUSE");
   return 0;
}


double setRadius()
{
   double rad;  //local variable
   cout << "Please enter the radius of the circle:";
   cin >> rad;
   return rad;
}

double getArea(double radius)
{
   return 3.141592 * pow(radius,2);

}
