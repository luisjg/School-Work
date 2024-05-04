// This program displays the numbers 1 through 10 and their squares.
#include <iostream>
using namespace std;

int main()
{
   int num = 1; // Initialize counter
   int numSquares;
   
   cout << "How many squares would you like to print?";
   cin >> numSquares;
      
   while (num <= numSquares)
   {
      cout << num << " " << (num * num) << endl;
      num++; // Increment counter
   }
   
   system("PAUSE");
   return 0;
}
