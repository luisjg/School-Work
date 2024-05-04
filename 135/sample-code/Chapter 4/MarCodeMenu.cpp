#include <iostream>
using namespace std;

int main()
{
  char selection;
  
  cout << "Marital Code Menu" << endl;
  cout << "m) Married" << endl;
  cout << "s) Single" << endl;
  cout << "w) Widowed" << endl;
  cout << "d) Divorced" << endl;
  cout << "Please make a selection: ";
  
  cin >> selection;
  
  if(selection == 'm')
     cout << "You selected Married." << endl;
  
  else if(selection == 's')
     cout << "You selected Single." << endl;
  
  else if(selection == 'w')
     cout << "You selected Widowed." << endl;
  
  else if(selection == 'd')
     cout << "You selected Divorced." << endl;
  
  else
     cout << "You made an Invalid Choice." << endl;
  
  system("PAUSE");
  return 0;
}
