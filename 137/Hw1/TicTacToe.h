//L G
//CSIS 137

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
	private:
	int pRow;
	int pColumn;
	int gameTable[3][3];
	public:

	TicTacToe();
	void printTable();
	void startGame();
	void printPrompt(const int&);
	void errorMessage();
	void assignMoves(const int&);
	bool isGoodInput();
	bool isWinner(const int&);
	bool isTaken();
	void printTie();
	bool isFree();
};

#endif
