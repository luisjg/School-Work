/*this for loops sums the numbers 1-10*/
#include <iostream>
using namespace std;

int main()
{
   int sum = 0; //accumulator

   for (int num = 1; num <= 10; num++)
   {
      sum += num;
      cout << "Sum of numbers 1 - " << num << " is "
           << sum << endl;
   }

   system("PAUSE");
   return 0;
}
