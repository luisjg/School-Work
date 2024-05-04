#include <iostream>
#include <cstdlib>
using namespace std;

bool isEven(int); //function prototypes
void showValue(int);

int main()
{
    const int SIZE = 5;
    int numbers[SIZE] = {25,30,16,7,-1};
    
    for(int counter = 0; counter < SIZE; counter++)
    {
       //array elements are passed into the functions
       if(isEven(numbers[counter]))  //same as if(isEven(numbers[counter])) == true)
       {
          showValue(numbers[counter]);
       }
    }
    cout << endl;
    system("PAUSE");
    return 0;   
}

bool isEven(int value)  //function returns true if argument passed to it is even
{
     if(value%2 == 0)
     {
        return true;
     }
     
     return false;
}

void showValue(int value)
{
	 cout << value << " ";
}
