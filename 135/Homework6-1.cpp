#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//constant array size
const int DRAWING = 7;

//declare function protoypes
void getLottoPicks(int[DRAWING]);
void GenWinNums(int[DRAWING]);
bool NoDuplicates(int[DRAWING], int);
string numberMatcher(int);

int main(){
//declare variables
srand ((unsigned int)time (NULL));
char selection;
string userName;
int matchingNums = 0;

//declare arrays of 7 elements
int UserTicket[DRAWING];
int WinningNums[DRAWING];

do{
cout << "LITTLETON CITY LOTTO MODEL:" << endl
	<< "--------------------------------" << endl
	<< "1) Play Lotto" << endl
	<< "q) Quit" << endl
	<< "Please make a selection:" << endl;
	cin >> selection;
	cin.ignore();

		while(selection != '1' && selection != 'q'){
		cout << "You have entered the wrong selection." << endl
		<< "Please try again." << endl;
		cin >> selection;
		cin.ignore();
		}

	switch(selection){
	case '1':
	cout << "Please enter your name." << endl;
	getline(cin, userName);
	//convert user's name to upper case
	for(int i = 0; i < userName.length(); i++){
	userName[i] = toupper(userName[i]);
	}
	//pass arrays to functions to generate numbers
	getLottoPicks(UserTicket);
	GenWinNums(WinningNums);
	for(int l = 0; l < DRAWING; l++){
	if(UserTicket[l] == WinningNums[l])
	matchingNums++;
	}
	//print the the lotto results and user's choice
	cout << "\n" << endl
		<< userName << "'S LOUTO RESULTS" << endl
		<< "-------------------------------" << endl
		<< "WINNING TICKET NUMBERS:";
		for(int j = 0; j < DRAWING; j++){
		cout << setw(4) << WinningNums[j];
	}

	cout << "\n" << userName <<"'S TICKET\t      :";
		for(int k = 0; k < DRAWING; k++){
		cout << setw(4) << UserTicket[k];
		}

	//print the results to the screen
	cout << "\n" << endl
		<< "RESULTS:" << endl
		<< "--------" << endl
		<< "Number Matches: " << matchingNums << endl
		<< "Winnings      : "
		<< numberMatcher(matchingNums) << endl
		<< "\n" << endl;
	break;

	case 'q':
	cout << "The program will now quit." << endl;
	break;
	}
}while(selection != 'q');
	system("PAUSE");
	return 0;
}
//##############################################################################
void getLottoPicks(int userPicks[DRAWING]){
cout << "\nPlease choose a number between 1 and 40." << endl;
	for(int i = 0; i < DRAWING; i++){
	int numsSelect = 0;
	userPicks[i] = 0;
	cout << "Choice for " << i+1 << endl;
	cin >> numsSelect;
	cin.ignore();
		while(numsSelect < 1 || numsSelect > 40){
		cout << "\nYou have entered an invalid number, please try again for choice " << i+1 << "." << endl;
		cin >> numsSelect;
		cin.ignore();
		}
	//save random number
	if(NoDuplicates(userPicks, numsSelect)){
	i--;
	}
	else
	userPicks[i] = numsSelect;
	}
}
//##############################################################################
void GenWinNums(int genNums[DRAWING]){
	for(int i = 0; i < DRAWING; i++){
	int winNums = 0;
	genNums[i] = 0;
	//generate random number
	winNums = rand() % 40 + 1;
	//save random number
	if(NoDuplicates(genNums, winNums)){
	i--;
	}
	else
	genNums[i] = winNums;
	}
}
//##############################################################################
bool NoDuplicates(int nums[DRAWING], int choice){
	for(int i = 0; i < DRAWING; i++){
		if(nums[i] == choice){
		return true;
		}
	}
return false;
}
//##############################################################################
string numberMatcher(int matchingNums){
		string result;
		switch(matchingNums){
		case 3:
		result = "FREE TICKET";
		break;

		case 4:
		result = "NOT BAD - $100";
		break;

		case 5:
		result = "LUCKY YOU! - $5,000";
		break;

		case 6:
		result = "GREAT! - $100,000";
		break;

		case 7:
		result = "JACKPOT - 1 MILLION";
		break;

		default:
		result = "SORRY NOTHING";
		break;
		}
		return result;
}
