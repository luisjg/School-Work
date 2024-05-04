#include <iostream>
using namespace std;

int main()
{
 //declare and initialize variables
 bool trueValue;
 bool falseValue;
 int x = 5;
 int y = 10;

 trueValue  = x < y;
 falseValue = y == x;
 
 cout << "True is " << trueValue << endl;
 cout << "False is " << falseValue << endl;

 system("PAUSE");
 return 0;
}
