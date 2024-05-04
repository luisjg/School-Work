/*this program uses cin.get and cout.put*/
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
   char ch1;
   char ch2 = 'B';
   char ch3 = '!';
   cout << "Enter a character: ";
   cin.get(ch1);
   
   cout.put(ch1);
   cout.put(ch2);
   cout.put(ch3);
   cout.put('\n');

   system("PAUSE");
   return 0;
}
