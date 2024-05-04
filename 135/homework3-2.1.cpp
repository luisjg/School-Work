 //Luis Guzman
//Homework #3
//CSIS 135
//pseudocode:
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	char selection;
	int tableInput;
	do{
	cout << "MENU" << endl
		<< "a) Generate Multiplication Table" << endl
		<< "q) Quit" << endl
		<< "Please make a selection." << endl;
	cin >> selection;
		if (selection != 'a' && selection != 'q'){
		cout << "You have chosen an invalid value." << endl;
		}//if
	if(selection == 'q'){
	cout << "The program will now quit." << endl;
	}//if
	if(selection == 'a'){
	cout << "Please enter a number for the multiplication table." << endl;
	cin >> tableInput;
		while(tableInput < 1 || tableInput > 10){
		cout << "You have entered an invalid value.\nPlease try again" << endl;
		cin >> tableInput;
		}//while

		//fix me loops

	cout << "\nMultiplication Tables\n" << endl << "  ";
	//print first column
	for(int firstColumn = 1; firstColumn <= tableInput; firstColumn++){
	cout << setw(5) << firstColumn;
	}//for
	//print first divider.
	cout << endl << "--|";
	//print dividers
	for(int i = 1; i <= tableInput; i++){
	cout << setw(5) << "----|";
	}//for
	cout << "\n";
			//print first row
			for(int row = 1; row <= tableInput; row++){
			cout << setw(2) << row << "|";
			//calculate and print columns and rows numbers
				for (int column = 1; column <= tableInput; column++){
				cout << setw(4) << row * column << "|";
				}//for
			cout << endl;
			//print first divider
			cout << "--|";
					//print dividers
					for(int i = 1; i <= tableInput; i++){
					cout << setw(5) << "----|";
					}//for
			cout << endl;
			}//for
	}//if
	}//do
	while (selection != 'q');
	system("PAUSE");
	return 0;
}//main
