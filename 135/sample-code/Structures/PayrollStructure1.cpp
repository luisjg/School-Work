#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//why is this ok global?
struct Payroll //declaration of the payroll struct
{
  int empNumber;
  string name;
  float hours;
  float payRate;
  float grossPay;
};  //don't forget the semi colon

int main()
{
   
   
   Payroll employee;  //variable of type Payroll

   cout << "Enter the employee's number: ";  //get the employee data
   cin >> employee.empNumber;
   cout << "Enter the employee's name: ";
   cin.ignore();  //to ignore the \n character left in the buffer from cin
   getline(cin, employee.name);  //had to use getline to allow first and last name
   cout << "How many hours did the employee work? ";
   cin >> employee.hours;
   cout << "What was the employee's pay rate? ";
   cin >> employee.payRate;

   employee.grossPay = employee.hours * employee.payRate;  //calc gross  pay
   cout << "The gross pay for employee #" << employee.empNumber << " named "
          << employee.name << " is $" << setiosflags(ios::fixed) << setprecision(2) << employee.grossPay << endl;
   system("PAUSE");
   return 0;
}

