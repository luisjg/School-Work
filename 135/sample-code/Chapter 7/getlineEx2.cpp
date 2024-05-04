#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string message;
   cout << "Enter a message. Enter ! to signify the end of the message.\n";
   getline(cin, message, '!');  //using getline to read in a string and terminate
                            //with something other than newline
   cout << "The message is: \n" << message << endl;

   system("PAUSE");
   return 0;
}
