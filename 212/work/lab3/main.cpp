#include <iostream>
#include <fstream>
#include <string>
#include "people.h"
using namespace std;

void openFile(int, string&);
//void sortmethodnamehere();

int main()
{
	string fileName;
	cout << "Reading Age\n" << endl;
	openFile(0,fileName);
	cout << "Reading Money\n" << endl;
	openFile(1,fileName);
	cout << "Sorting the arrays\n" << endl;
	system("PAUSE");
	return 0;	
}

void openFile(int file, string& fileName)
{

	switch(file)
	{
	case 0:
		fileName="age.txt";
	break;
	case 1:
		fileName="money.txt";
	break;
	default:
		fileName="";
	break;
	}

	string names="";
	ifstream inFile;
	inFile.open(fileName);
	if(inFile.fail())
	{
		cout << "The file could not be opened." << endl
			<< "The program will now quit." << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		int i=0;
		if(file == 0)
		{
			int inAge;
			people<int> age[5];
			while(!inFile.eof())
			{
				getline(inFile, names);
				inFile >> inAge;
				age[i].setName(names);
				age[i].setValue(inAge);
				inFile.ignore();
				i++;
			}
		}
		else
		{
			double inMoney;
			people<double> money[5];
			while(!inFile.eof())
			{
				getline(inFile, names);
				inFile >> inMoney;
				money[i].setName(names);
				money[i].setValue(inMoney);
				inFile.ignore();
				i++
			}
		}
	}
	cout << endl;
	inFile.close();
}
//sorting algorithm here:
//void sortmethodnamehere(){}