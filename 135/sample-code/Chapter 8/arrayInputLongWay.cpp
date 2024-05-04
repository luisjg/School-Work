/*Asks the user to enter the grades earned on a test by 6 students
and stores them in an array.  It then outputs the grades entered*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   const int numGrades = 6;
   int grades[numGrades];  //delcares an array of 6 ints

   //read in the array contents
   cout << "Enter the grades earned on the test by six students: ";
   cin >> grades[0] >> grades[1] >> grades[2] >> grades[3]
       >> grades[4] >> grades[5];

   //Display the contents of the array
   cout << "The grades you entered are: ";
   cout << grades[0] << "," << grades[1] << "," << grades[2] << ","
        << grades[3] << "," << grades[4] << "," << grades[5] << endl;

   system("PAUSE");
   return 0;
}
