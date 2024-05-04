/*This program demonstrates when a constructor executes*/
#include <iostream>
#include <cstdlib>
using namespace std;

/*CLASS DECLARATION - Normally would be in a .h file*/
//Since the class has no private members the private access specifier can be left out
class Demo
{
   public:
      Demo();
};

/*IMPLEMENTATION SECTION - Normallly would be in a .cpp implementation file*/
//The Demo Constructor prints a message to show us when the constructor function is executued
Demo::Demo()  //NOTICE NO RETURN TYPE IS SPECIFIED - because constructors never have a return type
{
   cout << "Now the Demo Constructor is running\n";              
}

/*Client File - The file containing the program that uses the class, normally a separate
.cpp file*/
int main()
{
   cout << "This message is displayed before the Demo object is created.\n";
   Demo demoObj;  //This defines the demo object and calls the constructor
   cout << "This message is displayed after the Demo object is created.\n";
   system("PAUSE");
   return 0;
}
