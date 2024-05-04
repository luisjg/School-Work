// This program displays the numbers 1 through 10 and their squares.
#include <iostream>
using namespace std;

int main()
{
    int age = 0;
    
    //prompt the user for an age and only accept ages > 0
    while(age <= 0)
    {
      cout << "Please enter your age: ";
      cin >> age;
      
      if(age <= 0)
      {
        cout << "The age you entered is INVALID. Try again." << endl;
      }
    }
    
    cout << "Your age is " << age << endl;
    
    system("PAUSE");
    return 0;
}
