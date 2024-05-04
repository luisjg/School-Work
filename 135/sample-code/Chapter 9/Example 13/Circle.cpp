/*File Circle.cpp -- Function Implementation File*/
//Contains function definitions for Circle class functions

#include "Circle.h"
#include <math.h>
//using namespace std;


/*CIRCLE MEMBER FUNCTION DEFINITONS*/
 void Circle::setRadius(double r) 
 {
    if(r > 0)
       radius = r;
    else
       radius = 0;
 }

double Circle::getRadius()
{
   return radius;
}

double Circle::getArea()
{
   return 3.141592 * pow(radius,2);
}
