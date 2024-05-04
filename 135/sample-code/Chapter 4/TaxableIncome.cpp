#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 //declare named constants
 const double TAX_RATE_1 = .02;
 const double TAX_RATE_2 = .025;
 const double TAX_BRACKET_1 = 20000;
 
 //declare and initialize variables
 double taxable;
 double taxes;
 
 //prompt for and get user input
 cout << "Please enter your taxable income:";
 cin >> taxable;
 
 //if taxable income is less than or equal to 20,000 the tax rate is .02
 if(taxable <= TAX_BRACKET_1)
 {
   taxes = taxable * TAX_RATE_1;
 }
 
 //otherwise calculate taxes with this formual for income of greater than
 //20,000
 else
 {
     taxes = TAX_RATE_2 * (taxable - TAX_BRACKET_1) + 400.00; 
 }
 
 //display results
 cout << fixed << setprecision(2) << "The taxes on " << taxable 
      << " of taxable income  are $" << taxes << endl; 
 
 system("PAUSE");
 return 0;
}
