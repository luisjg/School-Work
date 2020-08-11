#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void readIt(ifstream& infile, char temp[], int length)
{
	bool space = false;

	for (int i = 0; i < length; i++)
		infile.get(temp[i]);
}

int main()
{
	ifstream file("people.txt", ios::in);

    const int NAME = 20;
	const int CITY = 16;
	const int AGE = 3;
	int length = NAME + CITY + AGE + 2;
	int index;
    char name[NAME+1];
    char city[CITY+1];

	int age;

	do
	{
		cout << "Which person do you want to see (-1 to quit)? ";
		cin >> index;
		if (index == -1)
			break;
		file.clear();
	    file.seekg(length * index, ios::beg);

        readIt(file, name, NAME);
		name[NAME] = '\0';
		readIt(file, city, CITY);
		city[CITY] = '\0';
		file >> age;
		cout << name << " " << city << " " << age << endl;
	} while (index != -1);

	system("pause");
	return 0;

}

