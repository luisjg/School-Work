#include <iostream>
using namespace std;

int main()
{
   const int MAXNUMS = 4;
   int count = 1;
   double num;
   double total = 0;  //initialize the accumulator

   cout << "This program will ask you to enter " << MAXNUMS << " numbers.\n";

   while(count <= MAXNUMS)
   {
      cout << "\n\nEnter a number: ";
      cin >> num;
      total += num;
      cout << "The total is now " << total;
      count++;
   }

   cout << '\n';
   system("PAUSE");
   return 0;
}
