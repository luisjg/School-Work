#include <iostream>
using namespace std;

int main()
{
    double num1;
    double num2;
    double product;

    //prompt the user for information
    cout << "Please input a number: ";
    cin >> num1;
    cout << "Please input another number: ";
    cin >> num2;

    //use input received from the user for the computation of the product
    product = num1 * num2;

    //output results
    cout << num1 << " times " << num2 << " is " << product << endl;

    system("PAUSE");
    return 0;
}
