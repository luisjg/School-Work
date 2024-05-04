#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
  const int numEmps = 3;
  int index;
  int hours[numEmps];    //parallel arrays to hold each employee's hours and rate
  float payRate[numEmps];

  //get employee work data
  for(index = 0; index < numEmps; index++)
  {
     cout << "Enter Hours worked by Employee #" << index << ": ";
     cin >> hours[index];
     cout << "Enter Pay rate for Employee #" << index << ": ";
     cin >> payRate[index];
  }

  cout << '\n';

  //display employee gross pay
  for(index = 0; index < numEmps; index++)
  {
     cout << "The pay for Employee # " << index << " is: "
          << setiosflags(ios::fixed) << setprecision(2)
          << hours[index] * payRate[index] << endl;
  }

  system("PAUSE");
  return 0;
}
