#include <iostream>
using namespace std;

/*Definition of displayMessge:  This function displays a greeting*/
void displayMessage()  //the function header
{
   cout << "Hello from the function displayMessage.\n";
}

int main()
{
   cout << "Hello from main.\n";
   displayMessage();  //the function call to the displayMessage function
   cout << "We are back in the function main again.\n";

   system("PAUSE");
   return 0;
}
