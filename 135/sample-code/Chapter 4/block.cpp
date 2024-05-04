#include <iostream>
using namespace std;

int main()
{
    { 	// start of outer block
	   int a = 25;
	   int b = 17;
	   cout << "The value of a is " << a << " and b is " << b << endl;

      {  // start of inner block
		 double a = 46.25;
		 int c = 10;
		 cout << "\na is now " << a
              << " b is now " << b
              << " and c is " << c << endl;
      } // end of inner block

      cout << "\na is now " << a << " and b is " << b << endl << endl;

	}    // end of outer block

      system("PAUSE");
      return 0;
}
