#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
{
	double len;
	double w;
	double area;
	double perim;

	cout << "Enter the length of the rectangle: ";
	cin >> len;
	cout << "Enter the width of the rectangle: ";
	cin >> w;

	area = calcArea(len, w);
	perim = calcPerimeter(len, w);

	cout << "\n\nRECTANGLE CALCULATIONS" << endl;
	cout << "----------------------" << endl;
	cout << "Area:\t\t" << area << endl;
	cout << "Perimeter\t" << perim << endl << endl;

   system("PAUSE");
   return 0;
}
