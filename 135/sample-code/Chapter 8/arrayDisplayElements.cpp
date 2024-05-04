/*This program has the user enter 5 integers and then displays the 
subscript of each array element and the value contained in it*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   const int NUM_INTS = 5;  //usually better to capitalize symbolic constants
   int grades[NUM_INTS];    //declares an array of 5 ints
   
   //read in the array contents
   cout << "Please enter 5 integers\n";
   for(int count = 0; count < NUM_INTS; count++)
   {
      cout << "Please enter integer #" << count + 1 << ": ";
      cin >> grades[count];
    }

   //Display the contents of the array
   cout << endl;
   cout << "The grades you entered are: \n";
   for(int count = 0; count < NUM_INTS; count++)
   {
      cout << "grades[" << count << "] = " <<grades[count] << endl;
   }

   cout << '\n';
   
   system("PAUSE");
   return 0;
}
