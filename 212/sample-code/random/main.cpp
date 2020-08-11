#include <iostream>
#include "random.h"

int main()
{
	srand(seed);

	for (int x = 0; x < 10; x ++)
		cout << initialsRandom() << endl;
	for (int x = 0; x < 10; x++)
		cout << "random numbers " << rand() * rand() << endl;
	system("pause");
	return 0;
}