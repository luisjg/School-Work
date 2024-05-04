//Luis Guzman
//CSIS 135
//Homework #1
//Pseudocode:print the expression 3.0*5.0 and the solution right aligned screen
//print the expression 7.1*8.3-2.2 and the solution right aligned on screen
//print the expression 3.2/(6.1*5) and the solution right aligned on screen
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//print the expression 3.0*5.0 and the solution screen
	cout << fixed << setprecision(1) << setw(5) << 3.0 << endl
		<< "*" << fixed << setprecision(1) << setw(4) << 5.0 << endl
		<< "-------\n"
		<< fixed << setprecision(2) << 3.0*5.0 << endl;

	//print the expression 7.1*8.3-2.2 and the solution on screen
	cout << "\n\n"
		<< fixed << setprecision(1) << setw(5) << 7.1 << endl
		<< "*" << fixed << setprecision(1) << setw(4) << 8.3 << endl
		<< "-" << fixed << setprecision(1) << setw(4) << 2.2 << endl
		<< "-------\n"
		<< fixed << setprecision(2) << (7.1*8.3)-2.2 << endl;
	//print the expression 3.2/(6.1*5) and the solution on screen
	cout << "\n\n"
		<< fixed << setprecision(1) << setw(5) << 3.2 << endl
		<< "/" << fixed << setprecision(1) << setw(4) << 6.1 << endl
		<< "*" << fixed << setprecision(1) << setw(4) << 5 << endl
		<< "------\n"
		<< fixed << setprecision(2) << 3.2/(6/1*5) << endl
		<< endl;
	system("PAUSE");
	return 0;

}