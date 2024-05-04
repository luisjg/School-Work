#include <iostream>
#include <cstdlib>
using namespace std;

//function prototype
int sum2Ints(int, int);

int main()
{
    //declare the array
    const int SIZE = 5;
    int numbers[SIZE] = {25,30,16,7,-1};
    
    int sum2;
    
    //the function call - saves the return value from the function into the
    //sum2 variable
    sum2 = sum2Ints(numbers[0], numbers[1]);
    
    cout << "The sum is " << sum2 << endl;
    
    system("PAUSE");
    return 0;
}

//sum2Ints FUNCTION:  Returns the sum of the two integer arguments
int sum2Ints(int value1, int value2)
{
     return value1 +  value2;
}
