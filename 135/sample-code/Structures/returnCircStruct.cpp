#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Circle
{
   double radius;
   double diameter;
   double area;
};
   
Circle getData(); //function prototype, returns a circle struct

int main()
{
  Circle piePlate;
  piePlate = getData();

  cout << "PIE PLATE MEMBERS" << endl;
  cout << "Radius: " << piePlate.radius << endl;
  cout << "Diamember: " << piePlate.diameter << endl;
  cout << "Area:  " << piePlate.area << endl;
  
  system("PAUSE");
  return 0; 
}

//returns a variable of the circle data type with information in the members
Circle getData()
{
   Circle temp;
   temp.radius = 10.0;
   temp.diameter = 20.0;
   temp.area = 314.159;
   return temp;
}

