#include <iostream>
using namespace std;

//function prototype
void changeThem(int, float);

int main()
{
   int whole = 12;
   float real = 3.5;

   cout << "In main the value of whole is: " << whole << endl;
   cout << "In main the value of real is: " << real << endl;

   changeThem(whole, real);  //function call to the changeThem function
   
   cout << "Now back in main the value of whole is " << whole << endl;
   cout << "Now back in main the value of real is " << real << endl;
   
   system("PAUSE");
   return 0;
}

/*Definition of function changeThem.  It uses i an int parameter and f a
float parameter.  The values of i and f are changed and then displayed*/
void changeThem(int i, float f)
{
   i = 100;
   f = 27.5;
   cout << "In change them the value of i is changed to " << i  << endl;
   cout << "In change them the value of f is changed to " << f  << endl;
}
