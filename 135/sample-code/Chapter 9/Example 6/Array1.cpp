/*This program shows an array name being dereferenced with the * operator*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   short numbers [] = {10,20,30,40,50}; //declares and initializes an array of 5 ints
   
   //the array name numbers is a pointer to the beginning of the array, the first element
   //is stored in the first memory location the array name is pointing to
   
   //Notice that numbers is dereferenced so we print the value in the first element of
   //the array rather than the address of the first element in the array
   cout << "The first element of the array is " << *numbers << endl;
   
   //cout << (int)numbers << endl;  //WHAT DOES THIS PRINT??
   
   system("PAUSE");
   return 0;
}
