#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

   struct Payroll //declaration of the payroll struct
   {
   int empNumber;
   string name;
   float hours;
   float payRate;
   float grossPay;
   };  //don't forget the semi colon

   Payroll employee = {0, "", 5.0, 15.50};  //variable of type Payroll - ADD PARITIAL INIT LIST

   employee.grossPay = employee.hours * employee.payRate;  //calc gross  pay
   cout << "The gross pay for employee #" << employee.empNumber << " named "
        << employee.name << " is $" << setiosflags(ios::fixed)
        << setprecision(2) << employee.grossPay << endl;

   system("PAUSE");
   return 0;
}
