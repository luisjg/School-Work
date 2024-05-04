/*This program uses an array of structures to hold the employee id #,hours
worked, and hourly pay rates for 3 employees*/
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct PayInfo
{
  string empID;
  int hours;
  float payRate;
  float grossPay;
};

int main()
{
   const int numWorkers = 3;

   int index;  //loop counter
   PayInfo workers[numWorkers];  //array of 3 PayInfo structures

   //get Payroll Data
   for(index = 0; index < numWorkers; index++)
   {
      cout << "Enter the employee ID number: ";
      cin >> workers[index].empID;
      cout << "Enter the employee hours: ";
      cin >> workers[index].hours;
      cout << "Enter the employee pay rate ";
      cin >> workers[index].payRate;

      //calculate and input gross pay
      workers[index].grossPay = workers[index].payRate * workers[index].hours;
   }
    cout << '\n';
   
   for(index = 0; index < numWorkers; index++) //display each employee's gross pay
   {
      cout << "Employee #" << workers[index].empID
           << " has gross pay of $" << setiosflags(ios::fixed)
           << setprecision(2) << workers[index].grossPay << endl;
   }

   system("PAUSE");
   return 0;
}
