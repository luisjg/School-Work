#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string str1; // an empty string
   string str2("Good Morning");
   string str3 = "Hot Dog";
   string str4(str3);
   string str5(str4, 4);
   string str6 = "linear";
   string str7(str6, 3, 3);
   cout << "str1 is: " << str1 << endl;
   cout << "str2 is: " << str2 << endl;
   cout << "str3 is: " << str3 << endl;
   cout << "str4 is: " << str4 << endl;
   cout << "str5 is: " << str5 << endl;
   cout << "str6 is: " << str6 << endl;
   cout << "str7 is: " << str7 << endl;

   system("PAUSE");
   return 0;
}
