#include <iostream>
using namespace std;

//function prototype
void divide(float, float);

int main()
{
   float num1, num2;

   cout << "Enter two numbers and I will divide the 1st by the 2nd:";
   cin >> num1 >> num2;
   divide(num1, num2); //function call
   
   system("PAUSE");
   return 0;
}

void divide(float x, float y)
{
   //since division is not allowed by zero immediately terminate
   if(y == 0)
   {
      cout << "Sorry division by zero is not allowed.\n";
      return;  //In general a BAD DESIGN unless you have a UNUSUAL SITUATION, very unusual and uncommon
			  //you should always use logic to "end" or "exit" code blocks whenever you can
   }
   cout << "The quotient is " << x/y << endl;
}
