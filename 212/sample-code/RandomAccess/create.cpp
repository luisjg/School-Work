#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ofstream file("people.txt");

    const int NAME = 20;
	const int CITY = 16;
	const int AGE = 3;
	file << setiosflags(ios::left)
	     << setw(NAME) << "Mustang Sally" << setw(CITY) << "Houston"
		 << setw(AGE) << 22 << endl;
	file << setw(NAME) << "George Symthe" << setw(CITY) << "Westchester"
		 << setw(AGE) << 52 << endl;
	file << setw(NAME) << "Harry Harrison" << setw(CITY) << "New York"
		 << setw(AGE) << 37 << endl;
    file << setw(NAME) << "Cherise Eddington" << setw(CITY) << "London"
		 << setw(AGE) << 45 << endl;
	file << setw(NAME) << "Antonio Valdez" << setw(CITY) << "San Francisco"
		 << setw(AGE) << 61 << endl;
	file << setw(NAME) << "Mary Gomez" << setw(CITY) << "Phoenix"
		 << setw(AGE) << 19 << endl;
	file << setw(NAME) << "Jon-luc Doe" << setw(CITY) << "Los Angeles"
		 << setw(AGE) << 61 << endl;
	file << setw(NAME) << "Bruce Bacon" << setw(CITY) << "Paris"
		 << setw(AGE) << 28 << endl;
	cout << "File people.txt has been created\n";
	system("pause");
	return 0;

}

