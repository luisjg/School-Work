//Luis Guzman
//CSIS 135
/*pseudocode:*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//construct the Drink structure with its fields
struct Drink{
string drinkName;
double drinkCost;
int numDrinks;
};

//##################################################################
int main(){
//declare variables
char selection;
double change;
double moneyEntered;
double userMoney;
double moneyEarned;
int drinkSelect;
const int DRINKS = 5;
const int NUMDRINKS = 20;
//create an array of Drink structures
Drink drinks[DRINKS];

//initialize the arrays

drinks[0].drinkName = "Cola";
drinks[0].drinkCost = 0.65;
drinks[0].numDrinks = NUMDRINKS;

drinks[1].drinkName = "Root Beer";
drinks[1].drinkCost = 0.70;
drinks[1].numDrinks = NUMDRINKS;

drinks[2].drinkName = "Lemon-Lime";
drinks[2].drinkCost = 0.75;
drinks[2].numDrinks = NUMDRINKS;

drinks[3].drinkName = "Grape Soda";
drinks[3].drinkCost = 0.85;
drinks[3].numDrinks = NUMDRINKS;

drinks[4].drinkName = "Water";
drinks[4].drinkCost = 0.90;
drinks[4].numDrinks = NUMDRINKS;

//display the menu with the choice options
do{
cout << "Vending Machine" << endl
	<< "----------------------" << endl
	<< "1) Cola \t$0.65" << endl
	<< "2) Root Beer \t$0.70" << endl
	<< "3) Lemon-Lime \t$0.75" << endl
	<< "4) Grape Soda \t$0.85" << endl
	<< "5) Water \t$0.90" << endl
	<< "q) Quit" << endl
	<< "Please select an option" << endl;
//save user input
cin >> selection;
//evaluate user input
if(selection > '0' && selection < '6'){
	//switch user input to the equivalent int
	switch(selection){
	case '1':
	drinkSelect = 0;
	break;
	case '2':
	drinkSelect = 1;
	break;
	case '3':
	drinkSelect = 2;
	break;
	case '4':
	drinkSelect = 3;
	break;
	case '5':
	drinkSelect = 4;
	break;
	}
	//loop to evaluate the total ammount user has entered.
	while(userMoney < drinks[drinkSelect].drinkCost){
	//ask for user to input ammount
	cout << "\nPlease enter the amount" << endl;
	//save the input
	cin >> moneyEntered;
		//loop to evaluate the amount entered
		while(moneyEntered <= 0 || moneyEntered > 1){
		//display an invalid amount entered
		cout << "Sorry.\nThe maximun amount of money is only $1.00" << endl
			<< "Please enter the correct amount" << endl;
		//save the input
		cin >> moneyEntered;
		}
	//keep track of the total amount entered
	userMoney += moneyEntered;
	}
		//evaluates if there are any drinks
		if(drinks[drinkSelect].numDrinks == 0){
		//display that there are no drinks
		cout << "Drink is out of stock!\n" << endl;
		}
		//continues if there are
		else{
		//subtracts 1 from the number of drink user selected
		drinks[drinkSelect].numDrinks--;
		//calculates the change that the user will get
		change = userMoney - drinks[drinkSelect].drinkCost;
		//clear any previous value
		userMoney = 0;
		//display the choice
		cout << "\nYou chose " << drinks[drinkSelect].drinkName << "."<< endl;
		//display the number of remaining drinks
		cout << "Remaining "  << drinks[drinkSelect].numDrinks << endl;
		//display the change the user will recieve
		cout << "Change $" << fixed << setprecision(2) << change << "\n" << endl;
		}
//keep track of the money earned.
moneyEarned += drinks[drinkSelect].drinkCost;
}
//input validation
else if(selection < 'q' || selection > 'q'){
//dsplay error message
cout << "\nYou have entered an invalid value.\nPlease try again.\n" << endl;
}
//displays total earnings and quits the program
else{
cout << "\nTotal Earnings $" << fixed << setprecision(2) << moneyEarned << endl
<< "The program will now quit.\n" << endl;
}
}while(selection != 'q');
system("PAUSE");
return 0;
}
