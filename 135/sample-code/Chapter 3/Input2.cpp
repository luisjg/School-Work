#include <iostream>
using namespace std;

int main()
{
    int num1;
    double num2;
    double sum;

    //prompt the user for information
    cout << "Please input two numbers: ";
    cin >> num1 >> num2;

    //use input received from the user for the computation of the product
    sum = num1 + num2;

    //output results
    cout << num1 << " plus " << num2 << " is " << sum << endl;

    system("PAUSE");
    return 0;
}
