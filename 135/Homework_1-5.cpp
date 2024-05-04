//Luis GUzman
//CSIS 135
//Homework #1
//Psuedocode:print menu. prompt user for number of apples. save input
//prompt user for number of bananas. save input. prompt user for number
//of oranges. save input. calculate the totals. print invoice with totals.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables
	int numApples;
	int numBananas;
	int numOranges;
	double priceApples;
	double priceBananas;
	double priceOranges;
	double total;
	//print the title
	cout << "Welcome to Bob's Fruits Grocery!\n"
		<< "==================================\n\n"
		//pront user for number of apples
		<< "Please enter the number of Apples you would like to purchase:\n";
	//save input
	cin >> numApples;
	//prompt user for number of bananas
	cout << "Please enter the number of Bananas you would like to purchase:\n";
	//save input
	cin >> numBananas;
	//prompt user for number of oranges
	cout << "Please enter the number of Oranges you would like to purchase:\n";
	//save input
	cin >> numOranges;
	//calculate price of each item and its total
	priceApples = numApples * 0.65;
	priceBananas = numBananas * 0.70;
	priceOranges = numOranges * 0.90;
	total = priceApples + priceBananas + priceOranges;
	//print the formatted invoice which shows number, price of each item, total of each item
	//and the total purchase
	cout << "\n\nBOB'S FRUITS GROCERY INVOICE\n"
		<< "------------------------------\n\n"
		<< numApples << " Apples  @ 0.65 each \t = $" << fixed << setprecision(2) << priceApples << endl
		<< numBananas << " Bananas @ 0.70 each \t = $" << fixed << setprecision(2) << priceBananas << endl
		<< numOranges << " Oranges @ 0.90 each \t = $" << fixed << setprecision(2) << priceOranges << endl
		<< "\t\t\t=========\n"
		<< "\t\tTOTAL \t = $" << fixed << setprecision(2) << total << endl;
	system("PAUSE");
	return 0;
}