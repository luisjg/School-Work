#include <iostream>
using namespace std;

void C()
{
    cout << "Now we are in C.\n";
}

void B()
{
   C();
   cout << "Now we are in B.\n";
}
	
void A()
{
   B();
   cout << "Now we are in A.\n";
}
	
int main()
{
      A();
      cout << "Now we are in main.\n";
      system("PAUSE");      
      return 0;
}
