#include <iostream>
using namespace std;

//function prototypes
void getNums(int&, int&);
void swap(int&, int&);

int main()
{
   int firstNum,secNum;

   getNums(firstNum, secNum); //call getNums to get the two numbers
   cout << "\nBEFORE the swap firstNum = " << firstNum << " and secNum = " << secNum;
   
   swap(firstNum, secNum); //call orderNums to put the two numbers in order
   cout << "\n\nAFTER the swap firstNum = " << firstNum << " and secNum = " << secNum << endl;
   
   system("PAUSE");
   return 0;
}

/*getNums Definition.  The arguments passed into input1 and input2 are passed by reference so the values 
entered in thesetwo parameters will be stored in the memory space of main's small and big vairables*/
void getNums(int &input1, int &input2)
{
   cout << "Enter the first integer: ";
   cin >> input1;
   cout << "\nEnter the second integer: ";
   cin >> input2;
}

/*orderNums Definition.  The arguments are passed by reference into num1 and num2 so that if they are out of 
order main's small and big variables are actually swapped. */
void swap(int &num1, int &num2)
{
      int temp;

      temp = num1;
      num1 = num2;
      num2 = temp;
   
}	