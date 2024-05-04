#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string name1;
   cout << "Enter a first and last name.\n";
   getline(cin, name1);  //using getline to read in a string
   cout << "name1 contains the first and last name.  \nname1 is: " << name1 << endl;

   system("PAUSE");
   return 0;
}
