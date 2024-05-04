#include <iostream>

using namespace std;

int main()
	{
	int low = 0;
	int high = 0;
	int rows = 0;
	int columns = 0;
	int sum = 0;

	cout << "Enter first number: ";
	cin >> rows;
	cout << "Enter second numnber: ";
	cin >> columns;
	cout << endl;
	cout << "THE MULTIPLICATION TABLE";
	cout << endl << endl;
	
	// Print out top number row, THESE are NOT calculated values
	for (int i = rows; i <= columns; i++)
	{
		cout << "\t" << i;
	}
	cout << endl;   

	// Print the inner rows, THESE ARE calculated values
	for (int j = rows; j <= columns; j++)
	{
		cout << j; // Print the row #
		
			for (int k = rows; k <= columns; k++)
			{
				cout << "\t" << j * k;
				sum += j * k; // Add the number to the sum
			}

		cout << endl; // Next row
	}

	cout << "\nRows printed: " << columns << endl; // This needs to be columns, because the program prints out the same # of rows
												 // and columns
	cout << "Columns printed: " << columns << endl;
	cout << "Sum of table: " << sum << endl << endl;

	system("PAUSE");
	return 0;
}