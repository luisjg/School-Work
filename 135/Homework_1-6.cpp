//Luis Guzman
//CSIS 135
//Homework #1
//Pseudocode: Prompt user for imput, save input in variable and print
//the answer
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	char input;
	//print title
	cout << "ASCII Code Single Character Converter\n"
		<< "---------------------------------------\n\n"
		//prompt user for input
		<< "Please enter a character to convert into ASCII code:\n";
	//save input
	cin >> input;
	//print the input and the cast input.
	cout << "\nThe ASCII code for the character " << input << " is " << (int)input << ".\n";
	system("PAUSE");
	return 0;
}