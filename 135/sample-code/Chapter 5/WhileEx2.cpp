// This program displays the numbers 1 through 10 and their squares.
#include <iostream>
using namespace std;

int main()
{
   int num = 1; // Initialize counter
   while (num <= 10)
{
   cout << num << " " << (num * num) << endl;
   num++; // Increment counter
}
   system("PAUSE");
   return 0;
}
