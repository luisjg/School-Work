/*this is a program for comparing two strings*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string string1;
   string string2;

   cout << "Enter the first string to compare: ";
   getline(cin, string1);
   cout << "Enter the second string to compare: ";
   getline(cin, string2);

   if(string1 > string2)
      cout << string1 << " is greater than " << string2 << endl;

   else if(string2 > string1)
      cout << string2 << " is greater than " << string1 << endl;

   else  //otherwise the strings are equal
      cout << string1 << " and " << string2 << " are equal." << endl;

   system("PAUSE");
   return 0;
}
