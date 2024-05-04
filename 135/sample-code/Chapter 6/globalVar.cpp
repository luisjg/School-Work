#include <iostream>
using namespace std;

void anotherFunction(); //function prototype
int num = 2;            //global variable – BAD DESIGN FOR THIS PROGRAM

int main()
{
   cout << "In main num is " << num << endl;
   anotherFunction();
   cout << "In main num is now changed to " << num << endl;
   system("PAUSE");
   return 0;
}

/*Definition of another function.  This function changes the value
of the global variable num*/
void anotherFunction()
{
   cout << "In anotherFunction num is first " << num << endl;
   num = 50;
   cout << "Now num in anotherFunction is changed to " << num << endl;
}
