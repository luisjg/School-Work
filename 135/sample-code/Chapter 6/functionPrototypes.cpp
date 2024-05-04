#include <iostream>
using namespace std;

void A();
void B();
void C();
	
int main()
{
      A();
      cout << "Now we are in main.\n";
	  system("PAUSE");
      return 0;
}

void A()
{
   B();
   cout << "Now we are in A.\n";
}

void B()
{
   C();
   cout << "Now we are in B.\n";
}

void C()
{
    cout << "Now we are in C.\n";
}
