/*File rectangle.cpp -- Function Implementation File*/
//Contains function definitions for Rectangle class functions

#include "rectangle2.h"
#include <iostream>
using namespace std;


/*RECTANGLE MEMBER FUNCTION DEFINITONS*/
/*******************************************************************************
                        Rectangle::Rectangle()
This constructor takes zero arguments.  It sets length and width to 1.0
*******************************************************************************/
Rectangle::Rectangle()
{
  length = 1.0;
  width = 1.0;
}

/*******************************************************************************
                        Rectangle::Rectangle(double, double)
This constructor takes the two arguments passed to it when an object is instantiated
and assigns those values to the length and width members.  If the arguments passed
in are negative, the constructor sets them to zero
*******************************************************************************/
Rectangle::Rectangle(double len, double w)
{
  if(len >= 0)
    length = len;
  else
    length = 0;
    
  if(w >=0)
    width = w;
  else
    width = 0;
}
/*******************************************************************************
                        Rectangle::setLength
If the argument passed to the setLength function is zero or greater it is copied
into the member variable length and true is returned.  If the argument is negative,
the value of length remains unchanged and false is returned
*******************************************************************************/
bool Rectangle::setLength(double len)
{
   bool validData;  //local variable
   
   if(len >=0)  //if length is positive data is valid
   {
      length = len;  //set the member variable
      validData = true;
   }
   else  //else data is invalid
      validData = false;
      
   return validData;  //return to calling program whether or not data is valid
}

/*******************************************************************************
                        Rectangle::setWidth
If the argument passed to the setWidth function is zero or greater it is copied
into the member variable length and true is returned.  If the argument is negative,
the value of width remains unchanged and false is returned
*******************************************************************************/
bool Rectangle::setWidth(double w)
{
   bool validData;  //local variable
   
   if(w >=0)  //if length is positive data is valid
   {
      width = w;  //set the member variable
      validData = true;
   }
   else  //else data is invalid
      validData = false;
      
   return validData;  //return to calling program whether or not data is valid
}

/*******************************************************************************
                        Rectangle::getLength
This function returns the value that is in the private member length
*******************************************************************************/
double Rectangle::getLength()
{
  return length;
}

/*******************************************************************************
                        Rectangle::getWidth
This function returns the value that is in the private member width
*******************************************************************************/
double Rectangle::getWidth()
{
  return width;
}

/*******************************************************************************
                        Rectangle::getArea
This function calculates and returns the area of the rectangle
*******************************************************************************/
double Rectangle::getArea()
{
  return length * width;
}
