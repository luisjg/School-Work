/*Asks the user to enter the grades earned on a test by first 2 students out
of 6 and stores them in a 6 element array.  This array is a local array so
when the entire array is printed out garbage is output in the array elements
no grades have been assigned to.*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   const int numGrades = 6;
   int grades[numGrades];  //delcares an array of 6 ints

   //read in the array contents
   cout << "Enter the grades earned on the test by the first and second student: ";
   cin >> grades[0] >> grades[1];

   //Display the contents of the array
   cout << endl;
   cout << "The grades you entered are: ";
   cout << grades[0] << "," << grades[1] << "," << grades[2] << ","
        << grades[3] << "," << grades[4] << "," << grades[5] << endl;

   system("PAUSE");
   
   return 0;
}
