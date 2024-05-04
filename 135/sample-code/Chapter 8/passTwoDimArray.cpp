#include <iostream>
#include <stdlib.h>
using namespace std;

//make these global to pass 2dim array to function
const int maxRows = 3;
const int maxCol = 4;

void displayArray(int [maxRows][maxCol]); //function prototype

int main()
{
   int inputNum = 0;

   int twoDim[maxRows][maxCol]; //declare array

   //input the array
   for(int row = 0; row < maxRows; row++)
   {
      for(int col = 0; col < maxCol; col++)
      {
         twoDim[row][col] = inputNum += 2;
      }
   }

    displayArray(twoDim);  //function call

   system("PAUSE");
   return 0;
}

/*this function accepts an entire two dimensional array as an argument
and displays its contents...remember this DOES NOT CREATE A NEW ARRAY or
pass a copy, it provides access to the array passed to the function*/
void displayArray(int theArray[maxRows][maxCol])
{
  //display the array
   for(int row = 0; row < maxRows; row++)
   {
      for(int col = 0; col < maxCol; col++)
      {
         cout << "[" << row << "," << col << "] = "
              << theArray[row][col] << endl;
      }
   }
}
