//L G
//CSIS 137

#include<iostream>
#include "TicTacToe.h"
using namespace std;

//declare function prototypes
void printMenu();
void inputValidation(int&);

int main(){

//declare variables
TicTacToe game;
int input;

//print the menu
printMenu();

//save the users input
cin >> input;

//check the input
inputValidation(input);

// check users decision
switch(input){
case 1:
	//start the game
	game.startGame();
break;
case 2:
	//quit the programS
	cout << "\nYou chose 2.\nThe program will now quit." << endl;
break;
}

system("PAUSE");
return 0;
}

//function that print the menu
void printMenu(){
cout << "Welcome to the best Tic Tac Toe game!" << endl
	<< "---------------------------------------" << endl
	<< "1) Play" << endl
	<< "2) Quit" << endl
	<< "Please enter 1 to play or 2 to quit." << endl;
}

/*function that accepts a reference and checks to see if the value
* is valid
*/

void inputValidation(int& selection){
	while (selection !=1 && selection != 2){
		cout << "You have entered an invalid value.\n"
		<< "Please try again." << endl
		<< "Please enter 1 to play or 2 to quit" << endl;
		cin >> selection;
		cout << "\n" << endl;
	}
}
