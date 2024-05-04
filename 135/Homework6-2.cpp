//Luis Guzman
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//constant array size
const int ROWS = 15;
const int COLUMNS = 20;
//function prototypes
void ticketPrice(double[ROWS]);
void seatingChart(char[ROWS][COLUMNS]);
void sellSeats(char[ROWS][COLUMNS]);

int main(){
//variables
double priceRows[ROWS];
char seatChart[ROWS][COLUMNS];
char openSeat = '*';
char userInput;
cout << "Movie Theater Tickets" << endl
	<< "-----------------------" << endl
	<< "Welcome to Movie Theater Ticket program" << endl;
ticketPrice(priceRows);
//initialize default to available seats
for(int rows = 0; rows < ROWS; rows++){
	for(int columns = 0; columns < COLUMNS; columns++){
	seatChart[ROWS][COLUMNS] = openSeat;
	}
}
//display the menu once
do{
cout << "Movie Theater Tickets Menu" << endl
	<< "---------------------------" << endl
	<< "1) Sell Tickets" << endl
	<< "2) Display the Seating Chart -- Like a Boss" << endl
	<< "q) Quit" << endl
	<< "\nPlease make a selection" << endl;
cin >> userInput;
	if(userInput < 'q' && userInput > 'q'){
	cout << "You have entered an invalid value\n" << endl;
}
else if(userInput == 'q'){
	cout << "The program will now quit\n" << endl;
}
else{
	if(userInput == '1'){
	sellSeats(seatChart);
	}
		if(userInput == '2'){
		seatingChart(seatChart);
		}
	/*
	switch(userInput){
	case '1':
	seatsTaken(seatChart);
	break;
	case '2':
	seatingChart(seatChart);
	break;
	}*/
//keep displaying manu as long as uerInput is not 'q'
}
}while(userInput != 'q');

//system("PAUSE");
return 0;
}
//#######################################################################
void ticketPrice(double price[ROWS]){
	cout << "Please enter the ammounts for each row" << endl;
	for(int i = 0; i < ROWS; i++){
	double prices = 0;
	cout << "Row " << i << endl;
	cin >> prices;
		if(prices < 0){
		i--;
		}
		else
		price[i] = prices;
}
cout << endl;
}
//######################################################################
void seatingChart(char chart[ROWS][COLUMNS]){
int ticketsSold = 0;
int ticketsAvail = 0;
cout << "\nSeats ";
	for(int columns = 0; columns < COLUMNS; columns++){
	cout << setw(3) << columns;
	}
cout << endl;
		for(int rows = 0; rows < ROWS; rows++){
		cout << "Row " << setw(2) << rows;
			for(int columns = 0; columns < COLUMNS; columns++){
			cout << setw(3) << chart[ROWS][COLUMNS];
				if(chart[ROWS][COLUMNS] == '#'){
				ticketsSold++;
				}
				else if(chart[ROWS][COLUMNS] == '*'){
				ticketsAvail++;
				}
			}
		cout << endl;
		}
cout << endl;
cout << "TICKETS SOLD: " << ticketsSold << endl;
cout << "AVAILABLE TICKETS: " << ticketsAvail << "\n" << endl;
}
//######################################################################
void sellSeats(char taken[ROWS][COLUMNS]){
int row;
int column;
char takenSeat = '#';
cout << "Please enter the Row of the Ticket" << endl;
cin >> row;
while(row > ROWS){
cout << "You have entered an invalid Row.\nPlease try again." << endl;
cin >> row;
}
cout << "Please enter the Column of the Ticket" << endl;
cin >> column;
while(column > COLUMNS){
cout << "You have entered an invalid Column.\nPlease try again." << endl;
cin >> column;
}
cout << endl;
//taken[row][column] = takenSeat;
if(taken[row][column] == '#'){
cout << "Sorry that seat is taken." << endl;
}
else
taken[row][column] = takenSeat;
//cout << taken[row][column] << endl;
}
