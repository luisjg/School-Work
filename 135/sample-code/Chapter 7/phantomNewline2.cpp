#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   int value;
   string message;
   cout << "Enter a number:\n";
   cin >> value;
   cin.ignore();
   cout << "The number entered is " << value << endl;

   cout << "Enter a message:\n";
   getline(cin, message);
   cout << "The message is: \n" << message << endl;

   system("PAUSE");
   return 0;
}
