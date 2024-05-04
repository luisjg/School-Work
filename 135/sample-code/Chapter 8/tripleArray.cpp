#include <iostream>
#include <cstdlib>
using namespace std;

void tripleArray(int[], int); //function prototype

int main()
{
   const int arraySize = 4;
   int grades[arraySize] = {91, 87, 73, 99};

   tripleArray(grades, arraySize);  //pass entire array to function
   
   //display the array
   for(int index = 0; index < arraySize; index++)
   {
      cout << grades[index] << " ";
   }
   cout << endl;

   system("PAUSE");
   return 0;
}

void tripleArray(int arr[], int size)
{
   for(int index = 0; index < size; index++)
   {
      arr[index]  = arr[index] *3;
   }
}
