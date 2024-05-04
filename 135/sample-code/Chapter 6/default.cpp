#include <iostream>
#include <stdlib.h>

using namespace std;

double calcArea(double = 20.0, double = 10.0);

int main()
{
	double area;

	//call the function and pass no arguments, default arguments are used
	area = calcArea();
	cout << "When no arguments are passed to the function area  = " << area << endl;

	//call the function and pass one argument
	area = calcArea(5.0);
	cout << "When one argument is passed to the function area  = " << area << endl;

	//call the function and pass two arguments
	area = calcArea(5.0, 1.0);
	cout << "When two arguments are passed to the function area  = " << area << endl;

    system("PAUSE");
	return 0;
}

double calcArea(double length, double width)
{
	return length * width;
}
