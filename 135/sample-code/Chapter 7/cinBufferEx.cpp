#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string name1;
   string city1;
   cout << "Enter a first and last name:\n";
   cin >> name1;  //enter a first and last name to see the problem
                  //with cin and strings
   cout << "Enter the city you live in:\n";
   cin >> city1;
   cout << "Hello. " << name1 << endl;
   cout << "You live in " << city1 << endl;

   system("PAUSE");
   return 0;
}
