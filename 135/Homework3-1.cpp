//Luis Guzman
//CSIS 135
//Homeowk #3-1
/*pseudocode: print title of the program and ask for user input. save user input, validate
user input. generate random numbers. keep track of how many times the dice has landed on
each number and add it's unique counter. Print the formatted output to the screen.*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	//declare variables
	int numRolls;
	//initialize counters
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	int counter5 = 0;
	int counter6 = 0;
	srand ((unsigned int)time(NULL));
	//print the prompt to the screen
	cout << "DICE ROLL SIMULATOR" << endl
		<< "-------------------------\n" << endl
		<< "Welcome to DICE ROLL SIMULATOR!\n" << endl
		//ask user for input
		<< "Please enter the number of rolls that you'd like." << endl;
	//save input
	cin >> numRolls;
	//input validation
	while(numRolls < 1){
			cout << "You have entered an invalid number.\nPlease try again.\n" << endl
				<< "Please enter the number of rolls that you'd like." << endl;
			cin >> numRolls;
			}
		//simulate dice roll
		for(int i = 1; i <= numRolls; i++){
		//generate random numbers 1-6
		int randNumber = rand() % 6 + 1;
			//analyze each number and keep track of each number
			switch(randNumber){
			//keep track of times landed on 1
			case 1:
			counter1++;
			break;
			//keep track of times landed on 2
			case 2:
			counter2++;
			break;
			//keep track of times landed on 3
			case 3:
			counter3++;
			break;
			//keep track of times landed on 4
			case 4:
			counter4++;
			break;
			//keep track of times landed on 5
			case 5:
			counter5++;
			break;
			//keep track of times landed on 6
			case 6:
			counter6++;
			break;
			}//switch
		}//for
			//print the formatted dice roll statistics to the screen.
			//cast numRolls for it to calculate and display the % correctly
			cout << "\nDICE ROLL STATISTICS\n" << endl
				<< "# Rolled\t# Times\t\t% Times" << endl
				<< "---------\t--------\t--------" << endl;
		cout << setw(5) << "1" << setw(16) << counter1 << setw(18) << fixed << setprecision(2) << ((counter1 / (double)numRolls) * 100.00) << "%" << endl
			<< setw(5) << "2" << setw(16) << counter2 << setw(18) << fixed << setprecision(2) << ((counter2 / (double)numRolls) * 100.00) << "%" << endl
			<< setw(5) << "3" << setw(16) << counter3 << setw(18) << fixed << setprecision(2) << ((counter3 / (double)numRolls) * 100.00) << "%" << endl
			<< setw(5) << "4" << setw(16) << counter4 << setw(18) << fixed << setprecision(2) << ((counter4 / (double)numRolls) * 100.00) << "%" << endl
			<< setw(5) << "5" << setw(16) << counter5 << setw(18) << fixed << setprecision(2) << ((counter5 / (double)numRolls) * 100.00) << "%" << endl
			<< setw(5) << "6" << setw(16) << counter6 << setw(18) << fixed << setprecision(2) << ((counter6 / (double)numRolls) * 100.00) << "%" << endl;
		cout << endl;

	system("PAUSE");
	return 0;
}//main
