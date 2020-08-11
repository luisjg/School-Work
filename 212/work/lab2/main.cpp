#include <iostream>
#include <fstream>
#include <string>
//#include "Qeueu.h"
//#include "LinkedList.h"
using namespace std;
void printMenu();
void readFile();
void writeFile();

int main(){
	char choice;

	cout << "Welcome to " << /*name of tour here << */ endl;
	cin >> choice;
	switch(choice){
    	case 'A':
    	//add customer
    	break;
    	case 'D':
    	//Delete tour
    	break;
    	case 'H':
    	//diplsay help menu
    	break;
    	case 'L':
    	//list the tours
    	break;
    	case 'N':
    	//Make a new tour
    	break;
    	case 'T':
    	//Do the tour
    	break;
    	case 'Q':
    	cout << "The program will now quit." << endl;
        writeFile();
    	break;
	}0
	system("PAUSE");
	return 0;
}

/*this only readts the first tour. Unless we're
supposed to input the other tour.*/

void readFile(){
    string tour, name;
    int time1, time2;
    ifstream inFile;
    inFile.open("GreatBigRock.txt"); // or whatever I call it.
    if(inFile.fail()){
        cout << "Failed to open file" << endl;
    }
    else{
        getline(inFile,tour);
        inFile >> time1;
        inFile >> time2;
        cout << tour << endl
            << time1 << time2;
        while(!inFile.eof()){
            getLine(inFile,name);
            cout << name << endl;
        }
    }
    inFile.close();
}

void writeFile(){
    ofstream outputFile;
    outputFile.open("output.txt");
    outputFile.close();
}

void printMenu(){
cout << "A) Add customer to tour" << endl
		 << "D) Delete tour" << endl
         << "H) Help" << endl
         << "L) List of tours" << endl
         << "N) New tour" << endl
         << "T) Do tour" << endl
         << "Q) Quit" << endl;
}