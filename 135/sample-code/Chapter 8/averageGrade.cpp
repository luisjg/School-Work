/*Example program to calculate the average of
some grade scores using an array*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   const int numScores = 5;
   double scores[numScores] = {90, 88, 91, 82, 95};

   double total = 0; //initialize the accumulator
   double average;   //to hold the average

   //loop to calculate(sum) the total of the grades
   for(int count = 0; count < numScores; count++)
           total += scores[count];

   average = total/numScores;

   cout << "The average of the scores is " << average << endl;

   system("PAUSE");
   return 0;
}
