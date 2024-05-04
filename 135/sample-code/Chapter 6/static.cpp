#include <iostream>
using namespace std;

int alienCounter(int);

int main()
{
    int aliensMet;
	int totalAliens;

	cout << "During each level of a five level game you encounter aliens " 
		 << endl  << " enter the aliens you encounter at each level and "
		 << endl << "this program will keep track of the total aliens in "
           << "the game " << endl << endl;

	for(int level = 1; level <= 5; level++)
	{
		cout << "Enter the aliens encountered in Level # " << level << ": ";
		cin >> aliensMet;

		totalAliens = alienCounter(aliensMet);
	}

	cout << "\n\nYou encountered a total of : " << totalAliens << " aliens." << endl;
    system("PAUSE");
    return 0;
}


int alienCounter(int additionalAliens)
{
	static int alienCount = 0;
	alienCount = alienCount + additionalAliens;
	return alienCount;
}
