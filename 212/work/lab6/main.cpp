#include <iostream>
#include "random.h"

int main()
{
	srand(seed);
	50 + (rand() % 101);

	for (int x = 0; x < 10; x ++)
		cout << initialsRandom() << endl;
	for (int x = 0; x < 10; x++)
		cout << "random numbers " << rand() * rand() << endl;

cout << "1) Print hash table" << endl
	<< "2) Retrieve hash item (print id and initials)" << endl
	<< "3) Delete item" << endl
	<< "4) Quit" << endl;
	system("PAUSE");
	return 0;
}