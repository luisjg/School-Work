/*Example of two of the three items associated with a variable*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int num;
   num = 22;
   cout << "The value stored in num is " << num << endl;
   cout << "The address of num is " << &num << endl;
   cout << sizeof(num) << " bytes are used to store this variable" << endl; 

   system("PAUSE");
   return 0;
}
