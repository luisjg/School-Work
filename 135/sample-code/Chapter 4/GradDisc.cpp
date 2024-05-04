#include <iostream>
using namespace std;

int main()
{
  char employed, recentGrad;

  cout << "Answer the following questions\n";
  cout << "with either Y for yes or N for no.\n\n";
  cout << "Are you employed? ";
  cin >> employed;
  

  if(employed == 'Y')
  {
     cout << "Have you graduated from college in the past 2 years? ";
     cin >> recentGrad;
     
     if(recentGrad == 'Y')
     {
        cout << "You qualify for the special interest rate. \n";
     }
     else
     {
		cout << "You must have graduated in the last two years to qualify.\n";
     }	
  }

  else
  {
      cout << "You must be employed to qualify\n";
  }
  system("PAUSE");
  return 0;
}

