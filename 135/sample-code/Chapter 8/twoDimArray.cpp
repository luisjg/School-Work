#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   const int maxRows = 3;
   const int maxCol = 4;
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

   //display the array
   for(int row = 0; row < maxRows; row++)
   {
      for(int col = 0; col < maxCol; col++)
      {
         cout << "[" << row << "," << col << "] = "
              << twoDim[row][col] << endl;
      }
   }

   system("PAUSE");
   return 0;
}
