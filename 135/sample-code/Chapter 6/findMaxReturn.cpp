/*Notice how the findMax function can be more useful & REUSABLE when it returns a value*/
#include <iostream>
using namespace std;

int findMax(int, int); //function prototype

int main()
{
      int firstnum, secnum;
      int max;
      
      cout << "Please enter the first number: ";
      cin >> firstnum;
      cout << "\nPlease enter the second number: ";
      cin >>secnum;

      max = findMax(firstnum, secnum);
      
      cout << "\nThe maximum number " << max << " doubled is " << (max * 2) << endl;
      
      if(max % 3 == 0)
      {
        cout << "The maximum number " <<  max << " is divisible by 3." << endl;
      }
      system("PAUSE");
      return 0;
}

/*This function finds the maximum of two numbers and returns the maximum number*/
int findMax (int x, int y)
{ // start of function definition
      int maxnum; 	// variable declaration
      if (x >= y) 	// find the maximum number
        maxnum = x;
      else
        maxnum = y;
      
      return maxnum; 
} 	// end of function definition and end of function
