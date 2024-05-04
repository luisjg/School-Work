/*This program uses a structure to hold geometric data about a circle*/
#include <iostream>
#include <iomanip>
#include <cmath>  //needed to use the pow function
#include <stdlib.h>
using namespace std;

 const double PI = 3.14159;
struct Circle  //declares the circle structure
{
  float radius;
  float diameter;
  float area;
};

int main()
{
  

   Circle circ1, circ2;  //define 2 circle structure variables

   //get the Circle diamters
   cout << "Enter the diameter of circle 1: ";
   cin >> circ1.diameter;
   cout << "Enter the diameter of circle 2: ";
   cin >> circ2.diameter;

   //Perform calculations
   circ1.radius = circ1.diameter/2;
   circ1.area = PI * pow(circ1.radius, 2.0);
   circ2.radius = circ2.diameter/2;
   circ2.area = PI * pow(circ2.radius, 2.0);

   //output results
   cout << "\nThe radius and area of the circles are: \n";
   cout << "Circle 1 -- Radius: " << setw(6) << circ1.radius
        << "   Area:  " << setw(6) << circ1.area << endl;
   cout << "Circle 2 -- Radius: " << setw(6) << circ2.radius
        << "   Area:  " << setw(6) << circ2.area << endl;

   system("PAUSE");
   return 0;
}
