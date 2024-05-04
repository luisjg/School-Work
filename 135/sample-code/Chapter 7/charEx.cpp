#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
   //you can't do this....
   //string str = 'a';
   
   //but you can do this
   string str;
   char ch = 'a'; 
   str = ch;
   
   cout << "str contains " << str << endl;
   
   system("PAUSE");  
   return 0;
}
