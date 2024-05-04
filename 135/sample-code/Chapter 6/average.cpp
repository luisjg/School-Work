#include <iostream>
using namespace std;

//function prototype
int sum3(int, int, int);

int main()
{
    int sum;
    double average;
    int num1, num2, num3;
    
    cout << "Please enter the three numbers:";
    cin >> num1 >> num2 >> num3;
    
    sum = sum3(num1, num2, num3);  //function call
    
    average = (double)sum/3; //what would happen without the cast?

    cout << "The average of the numbers is " << average << endl;
    system("PAUSE");
    return 0;
}

/*This function calculates the sum of the 3 numbers passed to it as
parameters and returns the sum to the calling function*/
int sum3(int a, int b, int c)
{
    int sum;
    sum =  a + b + c;
	return sum;
}