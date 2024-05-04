/*This program uses two functions that accept pointers as arguments*/
#include <iostream>
#include <stdlib.h>
using namespace std;

void getNumber(int*);  //The functions now take pointer parameters
void doubleValue(int*);

int main()
{
   int number;
   
   getNumber(&number);  //the address of the variable is passed to the function
   cout << "\nThe number input was " << number << endl;
   doubleValue(&number); //the address of the variable is passed to the function
   cout << "The value of number doubled is " << number << endl;

   system("PAUSE");
   return 0;
}

//since the parameter is a pointer so an address should be passed to it
void getNumber(int* input)
{
   cout << "Please enter a number: ";
   cin >> *input;  //The * is necessary to store the value entered by the user 
}

//since the parameter is a pointer so an address should be passed to it
void doubleValue(int* value)
{
   *value = (*value) *2;  //The parenthesis ensure the order of operations
}
