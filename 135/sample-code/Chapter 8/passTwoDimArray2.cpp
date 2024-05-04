#include <iostream>
#include <cstdlib>
using namespace std;

//make these global to pass 2dim array to function
const int maxRows = 3;
const int maxCol = 4;

void displayArray(int [maxRows][maxCol]); //function prototype
void doubleEvenElements(int [maxRows][maxCol]); //function prototype

int main()
{
   int inputNum = 0;

   int twoDim[maxRows][maxCol]; //declare array

   //input the array
   for(int row = 0; row < maxRows; row++)
   {
      for(int col = 0; col < maxCol; col++)
      {
         twoDim[row][col] = inputNum += 1;  //changed to add one rather than 2
      }
   }
    cout << "ORIGINAL ARRAY" << endl;
    displayArray(twoDim);  //function call
    cout << endl;
    
    doubleEvenElements(twoDim);
    
    cout << "ARRAY WITH EVEN ELEMENTS DOUBLED" << endl;
    displayArray(twoDim);

    system("PAUSE");
    return 0;
}

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

//if an array element is even, this doubles it
void doubleEvenElements(int arr[maxRows][maxCol])
{
   for(int row = 0; row < maxRows; row++)
   {
      for(int col = 0; col < maxCol; col++)
      {
         if(arr[row][col] %2 == 0)
         {
            arr[row][col] *= 2; 
         }
      }
   }
}
