#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/*CLASS DECLARATION - Attributes and Function prototypes*/
class Rectangle
{
   private:                 //make the attributes private
     double length;
     double width;

   public:                 //function prototypes
     void setLength(double);
     void setWidth(double);
     double getLength()const;
     double getWidth()const;
     double getArea()const;
};

/*IMPLEMENTATION SECTION - MEMBER FUNCTION DEFINITONS*/
/*******************************************************************************
                        Rectangle::setLength
This function sets the value of the member variable length.  If
the argument passed to the funcion is greater than zero it is copied into length.
If the argument passed to the function is negative, 1.0 is assigned to length
*******************************************************************************/
void Rectangle::setLength(double len)
{
   //do not allow for a negative length
   if(len >=0)
      length = len;
   else
   {
      length = 1.0;
      cout << "Invalid length.  Using a default value of 1.0.\n";
   }
}

/*******************************************************************************
                        Rectangle::setWidth
This function sets the value of the member variable width.  If
the argument passed to the funcion is greater than zero it is copied into width.
If the argument passed to the function is negative, 1.0 is assigned to width
*******************************************************************************/
void Rectangle::setWidth(double w)
{
   //do not allow for a negative width
   if(w >=0)
      width = w;
   else
   {
      width = 1.0;
      cout << "Invalid width.  Using a default value of 1.0.\n";
   }
}

/*******************************************************************************
                        Rectangle::getLength
This function returns the value that is in the private member length
*******************************************************************************/
double Rectangle::getLength() const
{
  return length;
}

/*******************************************************************************
                        Rectangle::getWidth
This function returns the value that is in the private member width
*******************************************************************************/
double Rectangle::getWidth()const
{
  return width;
}

/*******************************************************************************
                        Rectangle::getArea
This function calculates and returns the area of the rectangle
*******************************************************************************/
double Rectangle::getArea()const
{
  return length * width;
}


/*******************************************************************************
                              main - Client
*******************************************************************************/
int main()
{
   Rectangle box; //declare a rectangle object
   double boxLength, boxWidth;

   //get box length and width from the user using prompts
   cout << "This program will calculate the area of a rectangle." << endl;
   cout << "What is the length of the rectangle?";
   cin  >> boxLength;
   cout << "What is the width of the rectangle?";
   cin  >> boxWidth;

   //call the member functions to set the box dimensions
   box.setLength(boxLength);
   box.setWidth(boxWidth);

   //call box's member functions to get the box information to display
   cout <<"\nHere is the Rectangle's data:\n";
   cout << setiosflags(ios::fixed) << setprecision(2);
   cout <<"Length: " << box.getLength() << endl;
   cout <<"Width: " << box.getWidth() << endl;
   cout <<"Area: " << box.getArea() << endl;

   system("PAUSE");
   return 0;
}
