#include <iostream>
using namespace std;

//function prototype - the parameter is a reference variable
void doubleNum(int&);

int main()
{
   int value = 4;

   cout << "In main the value is " << value << endl;
   cout << "Now I'm calling the doubleNum function..." << endl;
   doubleNum(value);  //function call, no ampersand
   cout << "Now back in main, value is " << value << endl;
   system("PAUSE");
   return 0;
}

/*Function Definition for doubleNum.  The parameter refVar
is a reference variable.  The value in refVar is doubled.*/
void doubleNum(int &refVar)
{
   refVar *= 2;
}
