#include <iostream>
#include <stdlib.h>
using namespace std;

void showValues(int[], int); //function prototype

int main()
{
   const int arraySize = 4;
   int grades[arraySize] = {91, 87, 73, 99};

   showValues(grades, arraySize);  //pass entire array to function

   system("PAUSE");
   return 0;
}

void showValues(int nums[], int size)
{
   for(int index = 0; index < size; index++)
      cout << nums[index] << " ";

    cout << endl;
}
