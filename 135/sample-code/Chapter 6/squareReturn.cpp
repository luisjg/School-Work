#include <iostream>
using namespace std;

//function prototype
int square(int);

int main()
{
   int number, result;

   cout << "Enter a number to be squared: ";
   cin >> number;
   result = square(number);  //notice the function call
   cout << number << " squared is " << result << endl;
   system("PAUSE");
   return 0;
}

/*This function accepts an int argument and returns the square of the argument as an int*/
int square(int num)
{
 return num * num;
}
