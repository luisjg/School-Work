#include <iostream>
using namespace std;

//function prototype – the prototype is global – ok to have global prototypes
void anotherFunction();

int main()
{
   int num = 1;  //local variable to main
   cout << "In main, num is " << num << endl;
   anotherFunction();
   cout << "Back in main, num is still " << num << endl;
   system("PAUSE");
   return 0;
}

/*Definition of anotherFunction.  This function has a local variable num whose value is
displayed*/
void anotherFunction()
{
 int num = 20;  //local variable
 cout << "In anotherFunction num is " << num << endl;
}
