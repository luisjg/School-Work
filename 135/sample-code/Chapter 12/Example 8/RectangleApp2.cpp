#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "rectangle2.h"
using namespace std;

/*******************************************************************************
                              main
*******************************************************************************/
int main()
{
   Rectangle box(4.1,6.0); //declare a rectangle object - call constructor that 
                           //takes two doubles and set length to 4.1 and width to 6.0
   
   Rectangle box2;  //The default Constructor is now called


   //call box's member functions to get the box information to display
   cout <<"\nHere is the Rectangle BOX'S data:\n";
   cout << setiosflags(ios::fixed) << setprecision(2);
   cout <<"Length: " << box.getLength() << endl;
   cout <<"Width:  " << box.getWidth() << endl;
   cout <<"Area:   " << box.getArea() << endl;
   
   //call box2's member functions to get the box2 information to display – What prints?
   cout <<"\nHere is the Rectangle BOX2'S data:\n";
   cout << setiosflags(ios::fixed) << setprecision(2);
   cout <<"Length: " << box2.getLength() << endl;
   cout <<"Width:  " << box2.getWidth() << endl;
   cout <<"Area:   " << box2.getArea() << endl;

   system("PAUSE");
   return 0;
}
