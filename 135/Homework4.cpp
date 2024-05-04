//Luis Guzman
//CSIS 135
//Homework #4
/*pseudocode: Display prompt and ask user for input, keep displaying as long as
input is not q. Validate the input and print an error if bad input. Analyze
user input and branch out from there. if q quit the program if p play*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//declare functions
int getComputerChoice();
int getPlayerChoice();
string getString(int);
bool isTie(int, int);
bool isPlayerWinner(int, int);

////////////////////////////////////////////////////////////
int main(){
	//declare variables
	char selection;
	srand((unsigned int)time(NULL));
	int computerChoice;
	int userChoice;
	int win;
	int tie;
	string computerString;
	string userString;
	//display prompt while input is not q
	do{
	cout << "ROCK PAPER SCISSORS MENU" << endl
		<< "--------------------------" << endl
		<< "p) Play Game" << endl
		<< "q) Quit" << endl;
	//save input
	cin >> selection;
	//input validation
	while(selection != 'p' && selection != 'q'){
		//display invalid entry prompt
		cout << "You have entered an invalid value"<< endl
			<< "Please try again\n" << endl;
		//re-print menu
		cout << "ROCK PAPER SCISSORS MENU" << endl
		<< "--------------------------" << endl
		<< "p) Play Game" << endl
		<< "q) Quit" << endl;
		//save input
		cin >> selection;
		cout << endl;
	}//while
	/////////////////////////////////////
	//analyze user's input
	switch (selection){
	case 'p':
	//get computer's choice and save to variable
	computerChoice = getComputerChoice();
	//get user's choice and save to variable
	userChoice = getPlayerChoice();
	cout << endl;
		//send two int arguments to isTie and save result to tie
		tie = isTie(userChoice, computerChoice);
		//send two int arguments to isPlayerWinner and save result to win
		win = isPlayerWinner(userChoice, computerChoice);
		//send one argument int to getString and save to computerString
		computerString = getString(computerChoice);
		//send one argument int to getString and save to userString
		userString = getString(userChoice);
	//print user and computer's choice to the screen
	cout << "You chose: " << userString << endl
		<< "The Computer chose: " << computerString << endl;
	//////////////////////////////////////
		//evaluate if user wins, ties, or looses
		if(tie == 1){
		cout << "It's a TIE!" << endl;
		}//if
		else if(win == 1){
		cout << "You WIN!" << endl;
		}//else if
		else{
		cout << "Sorry you LOOSE!" << endl;
		}//else
	//////////////////////////////////////
		cout << endl;
		break;
	//quit program
	case 'q':
	cout << "The program will now quit." << endl;
		break;
	}//switch
	/////////////////////////////////////
	}//do
	while(selection != 'q');
	/////////////////////////////////////
	/*Professor said it was fine to comment this out
	//system("PAUSE");
	*/
	return 0;
}//main
////////////////////////////////////////////////////////////////
	//function that generates computer choice
	int getComputerChoice(){
	//generate 3 random numbers save to randNum
	int randNum = rand () % 3 + 1;
	//return randNum
	return randNum;
}//getComputerChoice
///////////////////////////////////////////////////////////////
	//function that gets user's choice
	int getPlayerChoice(){
	//declare variable
	int playerChoice;
	//print prompt to the screen
		cout << "\nRock, Paper or Scissors?" << endl
		<< "--------------------------" << endl
		<< "1) Rock" << endl
		<< "2) Paper" << endl
		<< "3) Scissors" << endl
		<< "Please enter your choice:" << endl;
	//save user's choice
	cin >> playerChoice;
	while (playerChoice > 3 || playerChoice < 1){
	cout << "You have entered am invalid value.\nPlease try again" << endl;
	cin >> playerChoice;
	}//getPlayerChoice
	return playerChoice;
}//getPlayerChoice
///////////////////////////////////////////////////////////////
	//function that converts an int to a string
	string getString(int choice){
	//declare variables
	string playerPlayed;
	//analyze each case
	switch(choice){
	case 1:
	playerPlayed = "Rock";
	break;
	case 2:
	playerPlayed = "Paper";
	break;
	case 3:
	playerPlayed = "Scissors";
	break;
	}//switch
	//return playerPlayed string
	return playerPlayed;
}//getString
/////////////////////////////////////////////////////////////
	//function that determines a tie
	bool isTie(int user, int computer){
	//declare variable
	bool tie = false;
	//determine if it's a tie
	if(user == computer){
	return tie = true;
	}//if
	else{
	return tie;
	}//else
}//isTie
////////////////////////////////////////////////////////////
	//function that determines if player is winner
	bool isPlayerWinner(int user, int computer){
	//declare variable
	bool winner = false;
	//determine if player won
	if(user == 2 && computer == 1){
	return winner = true;
	}//if
	else if(user == 3 && computer == 2){
	return winner = true;
	}//else if
	else if(user == 1 && computer == 3){
	return winner = true;
	}//else if
	else{
	return winner;
	}//else
}//isPlayerWinner
/////////////////////////////////////////////////////////////
