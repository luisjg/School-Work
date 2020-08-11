#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string tour;
	string name;
	int maxPeople;
	int numWaiting;

	ifstream inFile("tours.txt");
	if (!inFile)
	{
		cout << "Could not open file\n";
	    system("pause");
		return 0;
	}
	getline(inFile,tour);
	while (!inFile.eof())
	{
		cout << tour << endl;
		inFile >> maxPeople;
		inFile >> numWaiting;
		getline(inFile,name);
		cout << maxPeople << " " << numWaiting << endl;
		for (int i = 0; i < numWaiting; i++)
		{
			getline(inFile,name);
			cout << name << endl;
		}
		getline(inFile,tour);
	}
	system("pause");
	return 0;
}
