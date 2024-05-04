#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double SALES_TAX = .05;
    
    double amount;
    double taxes;
    double total;

    //prompt the user for information
    cout << "Enter the amount of yoru purchase before sales tax $:";
    cin >> amount;

    //use input received from the user for the computation of the total price
    taxes = amount * SALES_TAX;
    total = amount + taxes;

    //output results
    cout << fixed << setprecision(2);
    
    cout <<"\nThe taxes at a sales tax rate of " << SALES_TAX << " is " << taxes; 
    
    cout <<"\nThe total price including taxes is $" << total << endl;

    system("PAUSE");
    return 0;
}
