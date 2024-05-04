#include <iostream>
using namespace std;

int main()
{
   int points;
   int total = 0;

   cout << "Enter points earned "
        << "(or -1 to quit): ";
   cin >> points;

   while (points != -1) // -1 is the sentinel
   {
      total += points;
      cout << "Enter points earned: ";
      cin >> points;
   }

   cout << "The total points earned are " << total << endl;
   system("PAUSE");
   return 0;
}
