#include <iostream>
using namespace std;

int main()
{
      int opselect;
      double fnum, snum;

      cout << "Please type in two numbers: ";
      cin >> fnum >> snum;

      cout << "\n1)Addition";
      cout << "\n2)Multiplication";
      cout << "\n3)Division";
      cout << "\nPlease make a selection:  ";
      cin >> opselect;

      switch(opselect)
      {
         case 1:
              cout << "The sum of the numbers is " << fnum + snum << endl;
              break;

         case 2:
              cout << "The multiplication of the numbers is " << fnum * snum << endl;
              break;

         case 3:
              if(snum != 0)
                 cout << "The division of the numbers is " << fnum/snum << endl;
              
              else
                 cout << "Division by zero is not allowed." << endl;
              
              break;
      }
      system("PAUSE");
      return 0;
}
