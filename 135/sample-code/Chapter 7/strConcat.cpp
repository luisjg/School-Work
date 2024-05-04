/*string concatenation program*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
   string greeting1 = "Hello ";
   string greeting2;
   string name1 = "World";
   string name2 = "People";

   //the following demonstrate how string concatenation works
   greeting2 = greeting1 + name1;  //now holds "Hello World"
   greeting1 += name2; //now holds "Hello People"

   cout << greeting2 << endl;
   cout << greeting1 << endl;

   system("PAUSE");
   return 0;
}
