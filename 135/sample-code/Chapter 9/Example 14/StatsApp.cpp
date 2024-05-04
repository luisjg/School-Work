#include "StatsArray.h"

int main()
{
	int arrSize;
	cout << "How big would you like the array to be?" << endl;
	cin >> arrSize;
	StatsArray arr(arrSize);
	arr.displayArray();
	
	system("PAUSE");
	return 0;
}
