/*This program passes variables by reference into two functions*/
#include <iostream>
#include <stdlib.h>
using namespace std;

void getNumber(int&);
void doubleValue(int&);

int main()
{
   int number;
   
   getNumber(number);  //the variables are passed by reference to the function
   cout << "\nThe number input was " << number << endl;
   doubleValue(number); //the details of how it works are hidden
   cout << "The value of number doubled is " << number << endl;

   system("PAUSE");
   return 0;
}

//since the parameter is passed by reference the variable passed to this function is
//altered by the function
void getNumber(int& input)
{
   cout << "Please enter a number: ";
   cin >> input;
}

//since the parameter is passed by reference the variable passed to this function is
//altered by the function
void doubleValue(int& value)
{
   value = value *2;
}
