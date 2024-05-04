/*Asks the user to enter the grades earned on a test by the first 2
students out of 6 students and stores them in an array of 6 elements.  The 
array elements have been initialized to -1 so that if the array is printed later
its easy to see the last 4 elements do not yet contain grades.  
It then outputs the grades entered.*/

#include <iostream>
using namespace std;

int main()
{
   const int NUM_GRADES = 6;
   int grades[NUM_GRADES];  //declares an array of 6 ints
   int count;              	//loop counter

   //initialize all of the array elements to -1
   for(count = 0; count < NUM_GRADES; count++)
   {
      grades[count] = -1;
   }
//read in the array contents for only two grade values
   
   cout << "Enter the grades earned on the test by the first two students\n";
   for(count = 0; count < 2; count++)
   {
      //I added a do-while loop here to not allow entry of a grade less than 0
      //or greater than 100
      //Notice since an array element is just a value of the array's data type
      //I can use it like a regular integer (or whatever data type the array is
      do
      {
        cout << "Please enter a grade: ";
        cin >> grades[count];
        
        if(grades[count] < 0 || grades[count] > 100)
        {
          cout << "Please enter a grade greater than 0 and less than 100\n";
        }
        
      }while(grades[count] < 0 || grades[count] > 100);
   }

   //Display the contents of the array
   cout << "The grades you entered are: ";
   for(count = 0; count < NUM_GRADES; count++)
   {
       //only prints array elements with a valid value in them
      if(grades[count] != -1)
      {
         cout << grades[count] << "   ";
      }
   }

   cout << '\n';
   system("PAUSE");
   return 0;
}
