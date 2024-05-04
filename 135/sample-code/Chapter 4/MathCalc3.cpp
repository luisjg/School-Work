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

      //ALL OF THE BREAK STATEMENTS ARE GONE SO IT FALLS THROUGH THEM ALL ONCE
      //ONCE CASE MATCH IS FOUND
      switch(opselect)
      {
         case 'a':
              cout << "The sum of the numbers is " << fnum + snum << endl;

         case 'b':
              cout << "The multiplication of the numbers is " << fnum * snum << endl;

         case 'c':
              if(snum != 0)
                 cout << "The division of the numbers is " << fnum/snum << endl;
              
              else
                 cout << "Division by zero is not allowed." << endl;              
      }
      system("PAUSE");
      return 0;
}
