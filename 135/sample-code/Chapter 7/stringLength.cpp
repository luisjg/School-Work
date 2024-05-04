#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
   string town;

   cout << "Where do you live? ";
   getline(cin, town);
   cout << "Your town has " << town.length() << " characters." << endl;
   
   system("PAUSE");
   return 0;
}
