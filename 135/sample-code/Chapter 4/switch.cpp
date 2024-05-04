#include <iostream>
using namespace std;

int main()
{
      int opselect;
      double fnum, snum;

      cout << "Please type in two numbers: ";
      cin >> fnum >> snum;

      cout << "Enter a select code:  ";
      cout << "\n    1 for addition:       ";
      cout << "\n    2 for multiplication: ";
      cout << "\n    3 for division:       ";
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
              cout << "The division of the numbers is " << fnum/snum << endl;
              break;
      }

      system("PAUSE");
      return 0;
}
