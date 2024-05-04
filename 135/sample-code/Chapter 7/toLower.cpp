/*this program converts an uppercase letter to lowercase and uses three
 different casts to print the result to the screen three times*/
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
   char letter;
   cout << "Enter an uppercase letter: ";
   cin >> letter;

   //c-style cast
   cout << "The lowercase equivalent using a c-style cast is "
        << (char)(tolower(letter)) << endl;

   //c++-style compile time cast
   cout << "The lowercase equivalent using a c++-style compile time cast is "
        << char(tolower(letter)) << endl;

   //c++-style run time cast
   cout << "The lowercase equivalent using a c++-style run time cast is "
        << static_cast<char>(tolower(letter)) << endl;

   system("PAUSE");
   return 0;
}
