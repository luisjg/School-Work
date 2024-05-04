#include <iostream>
using namespace std;

//function prototypes
//both functions use reference variables as parameters
void doubleNum(int&);
void getNum(int&);

int main()
{
   int value;
   getNum(value);  //function call
   doubleNum(value);  //function call
   cout << "That value doubled is " << value << endl;
   system("PAUSE");
   return 0;
}

/*Function Definition for getNum. The parameter userNum is a reference variable.  The user is asked
to enter a number which is stored in userNum*/
void getNum(int &userNum)
{
 cout << "Enter a number: ";
 cin >> userNum;
}

/*Function Definition for doubleNum.  The parameter refVar
is a reference variable.  The value in refVar is doubled.*/
void doubleNum(int &refVar)
{
   refVar *= 2;
}

