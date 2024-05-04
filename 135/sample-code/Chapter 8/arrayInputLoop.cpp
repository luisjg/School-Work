/*Asks the user to enter the grades earned on a test by 6 students
and stores them in an array.  It then outputs the grades entered*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   const int numGrades = 6;
   int grades[numGrades];  //delcares an array of 6 ints
   int count;              	   //loop counter

   //read in the array contents
   cout << "Enter the grades earned on the test by six students\n";
   for(count = 0; count < 6; count++)
   {
      cout << "Please enter a grade: ";
      cin >> grades[count];
    }

   //Display the contents of the array
   cout << "The grades you entered are: ";
   for(count = 0; count < 6; count++)
   {
      cout << grades[count];
      if(count < 5)
         cout << ",";
   }

   cout << '\n';
   system("PAUSE");
   return 0;
}

