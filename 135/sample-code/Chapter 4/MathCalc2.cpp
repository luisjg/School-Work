#include <iostream>
using namespace std;

int main()
{
      char opselect;
      double fnum, snum;

      cout << "Please type in two numbers: ";
      cin >> fnum >> snum;

      cout << "\na)Addition";
      cout << "\nb)Multiplication";
      cout << "\nc)Division";
      cout << "\nPlease make a selection:  ";
      cin >> opselect;

      switch(opselect)
      {
         case 'a':
              cout << "The sum of the numbers is " << fnum + snum << endl;
              break;

         case 'b':
              cout << "The multiplication of the numbers is " << fnum * snum << endl;
              break;

         case 'c':
              if(snum != 0)
                 cout << "The division of the numbers is " << fnum/snum << endl;
              
              else
                 cout << "Division by zero is not allowed." << endl;              
              break;
      }
      system("PAUSE");
      return 0;
}

