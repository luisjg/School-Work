#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char selection = 0;
	int userNumber = 0;

	do
	{
		do
		{
			cout << "MENU" << endl;
			cout << "a) Generate Multiplication Table" << endl;
			cout << "q) Quit Program" << endl;
			cout << "Please make a selection:" << endl;
			cin >> selection;

			if(selection != 'a' && selection != 'q')
				cout << "Invalid Selection" << endl;

		}while(selection != 'a' && selection != 'q');

		if(selection == 'a')
		{
			do
			{
				cout << "Please enter a number:" << endl;
				cin >> userNumber;

			}while(userNumber > 10 || userNumber < 1);

			cout << endl << "MULTIPICATION TABLE: " << userNumber << "'s" << endl << endl << "  ";
			//to print the line of horizontal numbers
			for(int n = 1; userNumber >= n; n++)
				cout << setw (5) << n;

			for(int n = 1; userNumber >= n; n++)
			{
				//to format the cells
				cout << endl << "--|";
				//to format the cells
				for(int n = 1; userNumber >= n; n++)
					cout << setw(5) << "----|";
				//to print the line of vertical numbers
				cout << endl << setw(2) << n << "|";
				//to print the inner body of the table
				for(int n2 = 1; userNumber >= n2; n2++)
				{
					cout << setw(4) << n * n2 << "|";
				}
			}

			cout << endl << "--|";
			
			for(int n = 1; userNumber >= n; n++)
				cout << setw(5) << "----|";

			cout << endl << endl;

		}
		else
			;

	}while(selection != 'q');

	system("PAUSE");
	return 0;
}