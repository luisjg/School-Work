/*example of phantom newline problem with cin.get()*/
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
   char letter;
   char letter2;
   cout << "Enter a letter: ";
   cin.get(letter);

   cout << "The ASCII code for the letter is " << (int)letter << endl;

   cout << "Enter a second letter: ";
   cin.get(letter2);
   cout << "The ASCII code for the letter is " << (int)letter2 << endl;

   system("PAUSE");
   return 0;
}
