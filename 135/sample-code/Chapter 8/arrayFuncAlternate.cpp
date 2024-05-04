#include <iostream>
#include <cstdlib>
using namespace std;

//make array size a constant global variable
const int arraySize = 4;

void showValues(int[arraySize]); //function prototype

int main()
{
   int grades[arraySize] = {91, 87, 73, 99};

   showValues(grades);  //pass entire array to function
   system("PAUSE");
   return 0;
}

void showValues(int nums[arraySize])
{
   for(int index = 0; index < arraySize; index++)
      cout << nums[index] << " ";

    cout << endl;
}
