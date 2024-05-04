#include <iostream>
using namespace std;

int main()
{
      void findMax(int, int);

      int firstnum, secnum;

      cout << "Please enter the first number: ";
      cin >> firstnum;
      cout << "\nPlease enter the second number: ";
      cin >>secnum;

      findMax(firstnum, secnum); // variable declaration
      system("PAUSE");
      return 0;
}

/*This function finds the maximum of two numbers and
prints the result to the screen*/
void findMax (int x, int y)
{ 	// start of function body
      int maxnum; 	// variable declaration
      if (x >= y) 	// find the maximum number
        maxnum = x;
      else
        maxnum = y;
      cout << "\nThe maximum of the two numbers " << x << "," << y 
           << " is "<< maxnum << endl;
} 