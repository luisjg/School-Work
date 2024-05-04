#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;

   if(isupper(letter))
      cout << "The letter " << letter << " is uppercase." << endl;

   else
      cout <<"The letter " << letter << " is NOT uppercase." << endl;

   system("PAUSE");
   return 0;
}
