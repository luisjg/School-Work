/*Asks the user to enter the grades earned on a test by 6 students and stores them in an array.  It then outputs the grades entered.  This program uses the named constant inside the for loop*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   const int numGrades = 6;
   int grades[numGrades];  //delcares an array of 6 ints
	
   //read in the array contents
   cout << "Enter the grades earned on the test by six students\n";
   for(int count = 0; count < numGrades; count++)
   {
      cout << "Please enter a grade: ";
      cin >> grades[count];
    }

   //Display the contents of the array
   cout << "The grades you entered are: ";
   for(int count = 0; count < numGrades; count++)
   {
      cout << grades[count];
      if(count < 5)
         cout << ",";
   }

   cout << '\n';
   
   system("PAUSE");
   return 0;
}
