#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string str = "Hello";

   //use subscript to change the first letter of the string to J
   str[0] = 'J';
   
   //use the subscript to print the new first letter of the string
   cout << "The first letter is now " << str[0] << endl;

   //use the subscript operator to print the string backwards
   cout << "The string reversed is ";
   for(int i = str.length()-1; i >=0; i--)
   {
      cout << str[i];
   }
   
   cout << endl;
   
   system("PAUSE");
   return 0;
}
