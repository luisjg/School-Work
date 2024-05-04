//Luis Guzman
//CSIS 135
//Homework #1
//Pseudocode: print title. ask user for input. save the input
//ask user for input. save input. calculate the survivors.
//calculate the gold division. print the message with
//number of explorers, explorers who died, survivied and the gold.
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	int numExplorers;
	int explorersLost;
	int explorersSurvived;
	int gold;
	//print title
	cout << "Welcome to Lost Fortune!\n\n"
		<< "Please answer the following questions for your personalized aventure:\n\n"
	//prompt user for number of explorers	
		<< "Enter the number of Explorers:\n";
	//save input
	cin >> numExplorers;
	//prompt user for number of explorers lost
	cout << "Enter the number of Explorers Lost in Battle:\n";
	//save input
	cin >> explorersLost;
	//calculate survivors
	explorersSurvived = numExplorers - explorersLost;
	//calculate number of gold
	gold = 750 / explorersSurvived;
	//print the number of explorers, number of explorers lost, number of explorers survived
	//and the gold
	cout << "\n\nYou bravely led " << numExplorers << " adventurers on a quest for gold.\n"
		"The group fought a band of ogres and lost " << explorersLost << " members.\n"
		"Only "<< explorersSurvived << " survived.\n\n";
	cout << "The party was about to give up when they stumbled upon\n"
		"the buried fortune of 750 gold pieces.  The group split the\n"
		"loot evenly with each getting " << gold <<" and as the quest\n"
		"leader you kept the extra 2 gold pieces.\n";
	system("PAUSE");
	return 0;
}