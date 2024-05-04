#include <iostream>
using namespace std;

int main()
{
 float num1, num2, quotient;
 cout << "Enter a number: ";
 cin >> num1;
 cout << "Enter a second number: ";
 cin >> num2;

 if(num2 == 0)
 {
  cout << "Division by zero is not possible. \n";
  cout << "Please run the program again and enter ";
  cout << "\na number other than zero for the second number\n";
 }

 else
 {
  quotient = num1/num2;
  cout << "The quotient of  " << num1 << " divided by "
       << num2 << " is " << quotient << "." << endl;
 }

 system("PAUSE");
 return 0;
}
