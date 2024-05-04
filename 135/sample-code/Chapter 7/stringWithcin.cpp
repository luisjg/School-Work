#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string name1;
   cout << "Enter a first and last name.\n";
   cin >> name1;  //enter a first and last name to see the problem
                  //with cin and strings
   cout << "name1 is only read up to the whitespace.  name1 is: " << name1 << endl;

   system("PAUSE");
   return 0;
}
