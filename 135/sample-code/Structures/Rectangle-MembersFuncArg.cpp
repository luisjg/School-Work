#include <iostream>
#include <stdlib.h>
using namespace std;

//funciton prototype
double multiply(double, double);

//creates the struct data type rectangle
struct Rectangle
{
  double length;
  double width;
  double area;
};

int main()
{
   //define a variable of type Rectangle
   Rectangle box;
   box.length = 4.3;
   box.width = 5.4;
   
   //this function call passes the length and width members of box to the multiply
   //function and stores the return value from the function into the area member of box
   box.area = multiply(box.length, box.width);
   
   cout << "The area of the box is " << box.area << endl;
   
   system("PAUSE");
   return 0;
   
}

//Define a function that has two double parameters 
double multiply(double x, double y)
{
   return x * y;
}
