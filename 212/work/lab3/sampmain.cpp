#include "people.h"

int main()
{
	people<double> money("Richie Rich", 1234.5);

	cout << money << endl;

	people<double> money2("Freddie Freeloader", 0.02);
	cout << money2 << endl;

	cout << (money > money2) << endl;

	people<int> lots[5];

	for (int i = 0; i < 5; i++)
	{
		string name;
		int val;
		cout << "Enter age\n";
		cin >> val;
		cout << "Enter name\n";
		getline(cin, name);
		getline(cin, name);
		{
			people<int> temp(name, val);
			lots[i] = temp;
		}
	}
	for (int i = 0; i < 5; i++)
	  cout << lots[i] << endl;

	system("pause");
	return 0;
}