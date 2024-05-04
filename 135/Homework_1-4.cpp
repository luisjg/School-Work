//Luis
//CSIS 135
//Homework #1
//Pseudocod: ask user for length of one side of pyramid. save input.
//calculate the area. ask user for height of pyramid. save input.
//calculate the volume save result. print the length, height, area and volume
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables
	double length;
	double height;
	double area;
	double volume;
	//print menu
	cout << "\tPyramid Calculator\n"
		<< "----------------------------------\n\n"
	//prompt user for length of one side of the pyramid
		<< "Please enter the length of one of the sides of the square base:\n";
	//save input
	cin >> length;
	//calculate area
		area = length * length;
	//pront user for height
	cout << "Please enter the height of the pyramid:\n";
	//save input
	cin >> height;
		//calculate volume
		volume = (area*height)/3;
	//print height, length, area and volume
	cout << "\n\nPyramid Statistics\n"
		<< "--------------------\n\n"
		<< "Length: \t" << length << endl
		<< "Height: \t" << height << endl
		<< "Area: \t\t" << area << endl
		<< "Volume: \t" << fixed << setprecision(2) << volume << endl
		<< endl;
	system("PAUSE");
	return 0;
}