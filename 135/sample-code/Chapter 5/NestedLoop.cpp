#include <iostream>
using namespace std;

int main()
{
   for (int i = 0; i < 4; i++)                // outer loop
   {
      for (int j = 0; j < 2; j++)            // inner loop
      {
         cout << "i is " << i << " j is " << j << "\n";
      }
   }
   
   system("PAUSE");
   return 0;
}
