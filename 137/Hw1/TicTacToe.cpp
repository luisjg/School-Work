//L G
//CSIS 137

#include <iostream>
#include "TicTacToe.h"
using namespace std;

//declare constant global variables...
const int ROW = 3;
const int COLUMN = 3;
const int p1 = 1;
const int p2 = 2;

/*
*******************TicTacToe************************
* default constructor, initializes the table to 0s *
****************************************************
*/
TicTacToe::TicTacToe(){
	for(int r = 0; r < ROW; r++){
		for(int c = 0; c < COLUMN; c++){
		gameTable[r][c] = 0;
		}
	}
}

/*
**********printTable****************
* a function that prints the table *
************************************
*/
void TicTacToe::printTable(){
	for(int r = 0; r < ROW; r++){
		for(int c = 0; c < COLUMN; c++){
		cout << gameTable[r][c];
		}
	//make it look pretty
	cout << endl;
	}
}
/*
**********startGame***************
* the entry point of the program *
* calls other methods to print   *
* calls on input validation      *
**********************************
*/

void TicTacToe::startGame(){
bool gameStatus = false;
int player = p1;
int turns = 1;

cout << endl;
		while(gameStatus == false){

		printTable();

			if(player == p1){
			cout << endl;
			printPrompt(player);
				while(isGoodInput() == false || isFree() == false){
				errorMessage();
				}
			assignMoves(player);
			player = p2;
			}

			else{
			cout << endl;
			printPrompt(player);
				while(isGoodInput() == false || isFree() == false){
				errorMessage();
				}
			assignMoves(player);
			player = p1;
			}

			cout << endl;
			turns++;
			if(isWinner(player) == true){
			cout << "Game Over.\nPlayer " << player << " wins!" << endl;
			gameStatus = true;
			}
			if(turns == 9){
			printTie();
			gameStatus = true;
			}
		}
}

/*
*******printPrompt****************************
* prints the prompt and asks for users input *
**********************************************
*/

void TicTacToe::printPrompt(const int& i){

	cout << "Player " << i << " please select a valid value for " << endl
                << "ROW" << endl;
                cin >> pRow;
                cout << "COLUMN" << endl;
                cin >> pColumn;

}

/*
**************errorMessage*****************
* function that performs input validation *
*******************************************
*/
void TicTacToe::errorMessage(){
	cout << "That move is invalid." << endl
		<< "Please try again by selecting a row and column between 1 and 3" << endl
		<< "ROW" << endl;
	cin >> pRow;
	cout << "COLUMN" << endl;
	cin >> pColumn;
}

/*
**********assignMoves**********
* assings the player's move   *
*******************************
*/
void TicTacToe::assignMoves(const int& player){
	if(player == p1){
	gameTable[pRow-1][pColumn-1] = p1;
	}
	else if(player == p2){
	gameTable[pRow-1][pColumn-1] = p2;
	}
}

/*
***************isGoodInput***************
* function that checks the user's input *
*****************************************
*/
bool TicTacToe::isGoodInput(){
	if(pRow >= 1 && pRow <= 3 || pColumn >= 1 && pColumn <= 3){
		return true;
	}

	else {
		return false;
	}
}

/*
*********isWInner**********
*   checks for who won    *
***************************
*/
bool TicTacToe::isWinner(const int& player){

	/*

	  0 1 2
	0 * * *
	1 * * *
	2 * * *

	*/
	//check first row which is 0
			if(gameTable[ROW-ROW][COLUMN-COLUMN] == player && gameTable[ROW-ROW][COLUMN-2] == player && gameTable[ROW-ROW][COLUMN-1] == player){
				return true;
			}
	//check second row which is 1
			else if(gameTable[ROW-2][COLUMN-COLUMN] == player && gameTable[ROW-2][COLUMN-2] == player && gameTable[ROW-2][COLUMN-1] == player){
				return true;
			}
	//check the third row which is 2
			else if(gameTable[ROW-1][COLUMN-COLUMN] == player && gameTable[ROW-1][COLUMN-2] == player && gameTable[ROW-1][COLUMN-1] == player){
				return true;
			}
	//left diagonal
			else if(gameTable[ROW-ROW][COLUMN-COLUMN] == player && gameTable[ROW-2][COLUMN-2] == player && gameTable[ROW-1][COLUMN-1] == player){
				return true;
			}
	//right diagonal
			else if(gameTable[ROW-1][COLUMN-COLUMN] == player && gameTable[ROW-2][COLUMN-2] == player && gameTable[ROW-2][COLUMN-1] == player){
				return true;
			}
	//check the first column 0
			else if(gameTable[ROW-ROW][COLUMN-COLUMN] == player && gameTable[ROW-2][COLUMN-COLUMN] == player && gameTable[ROW-1][COLUMN-COLUMN] == player){
				return true;
			}
	//check the second column 2
			else if(gameTable[ROW-ROW][COLUMN-2] == player && gameTable[ROW-2][COLUMN-2] == player && gameTable[ROW-1][COLUMN-2] == player){
				return true;
			}
	//check the third column 3
			else if(gameTable[ROW-ROW][COLUMN-1] == player && gameTable[ROW-2][COLUMN-1] == player && gameTable[ROW-1][COLUMN-1] == player){
				return true;
			}
	//otherwise it's false
			else
				return false;
}

/*
***********printTie***********
* prints that there is a tie *
******************************
*/

void TicTacToe::printTie(){
	cout << "The game is a tie!" << endl;
}

/*
*****************isFree*********************
* determines whether there is a valid move *
********************************************
*/

bool TicTacToe::isFree(){
		if(gameTable[pRow-1][pColumn-1] == p1 || gameTable[pRow-1][pColumn-1] == p2){
			return false;
			}

		else{
			return true;
			}

}
