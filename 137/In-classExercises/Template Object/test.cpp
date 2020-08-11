//David Ortiz
//Luis Guzman

#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
	Rectangle<double> r1(5.1,4.2);
	Rectangle<int> r2(2,3);

	cout << "\nR1 Rectangle Data" << endl;
	cout << r1 << endl;
	
	cout << "\nR2 Rectangle Data" << endl;
	cout << r2 << endl;
	
	system("PAUSE");
	return 0;
}
