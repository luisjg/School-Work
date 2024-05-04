#include <iostream>
using namespace std;

//function prototype
bool isEven(int);

int main()
{
   int value;
   
   cout << "Please enter an integer number: ";
   cin >> value;

   if(isEven(value))  //function call is used as a boolean expr
   {
     cout << value << " is an even number." << endl;
   }
   
   else
   {
     cout << value << " is an odd number." << endl;
   }
   system("PAUSE");
   return 0;
}

/*The isEven function returns true if the paramter is even and false otherwise*/
bool isEven(int number)
{
   if(number % 2)
	 return false; //the number is odd if there’s a remainder
   else
	 return true;  //otherwise its even
}