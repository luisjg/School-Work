#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string name1 = "Mark Twain";
   string name2 = "Samuel Clemens";
   name2 = name1; //Now name2's value is Mark Twain
   cout << "name1 is " << name1 << "\nname2 is also " << name2 << endl;
   system("PAUSE");
   return 0;
}
