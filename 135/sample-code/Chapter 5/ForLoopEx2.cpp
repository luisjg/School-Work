/*this for loops sums the numbers from 1 to whatever the user input*/
#include <iostream>
using namespace std;

int main()
{
   int sum = 0; //accumulator
   int maxNum;
   
   cout << "Please enter the maximum number: ";
   cin >> maxNum;

   for (int num = 1; num <= maxNum; num++)
   {
      sum += num;
      cout << "Sum of numbers 1 - " << num << " is "
           << sum << endl;
   }

   system("PAUSE");
   return 0;
}
