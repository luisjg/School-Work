#include <iostream>
#include <stdlib.h>
using namespace std;

//creates the struct data type rectangle
struct Rectangle
{
   double length;
   double width;
   double area;
};
   
//function prototype
//double multiply(double, double);
void showRect(Rectangle);

int main()
{ 
   //define a variable of type Rectangle
   Rectangle box;
   box.length = 4.3;
   box.width = 5.4;
   
   box.area = box.length * box.width;
   
   showRect(box);
   
   system("PAUSE");
   return 0;  
}

//Define a function that uses an entire Rectangle structure variable as its parameter
void showRect(Rectangle r)
{
   cout << "The length of box is " << r.length << endl;
   cout << "The width of box is  " << r.width << endl;
   cout << "The area of box is   " << r.area << endl;
}
