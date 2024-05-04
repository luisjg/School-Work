#include <iostream>
using namespace std;

//function prototype
void sum3(int, int, int);

int main()
{
    int total;
    int num1, num2, num3;
    
    cout << "Please enter the three numbers:";
    cin >> num1 >> num2 >> num3;
    
    sum3(num1, num2, num3);  //function call
    
    //NOW let's say we want to average the three numbers
    //The main function can't access the sum calculated with our function due to the function's scope.  
    //We need the sum3 function to return the calculated sum to main so main
    //can use that calculated sum to then calculate the average
    system("PAUSE");
    return 0;
}

/*This void function calculates the sum of the 3 numbers passed to it as parameters. When the function ends so
does the scope of the parameter variables a,b,c and the local variable sum.  The main function can't see these
variables.  The solution is to return, or pass data back to the function. RIGHT NOW NOTHING'S HAPPENING…main can't see the sum variable.  We need some way to get sum back to main*/
void sum3(int a, int b, int c)
{
    int sum;
    sum =  a + b + c;
}
