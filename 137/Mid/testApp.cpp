#include <iostream>
#include "Time.h"
#include "Date.h"
using namespace std;

int main(){
Date date;

date.setMonth(11).setDay(1).setYear(2011);

Time t;
Time test(02,56);
Time test1(02,56);



cout << "Please enter the time in this form HH:MM \n"; 
cin >> t;

cout << "\nThe first time is: " << test << endl
	<< "The second test is: " << test << endl;

if(test == test1){

	cout << "\nThey are equal!" << endl;
}


if(test != test1){

	cout << "\nThey are not equal!" << endl;
}


if(test <= test1){

	cout << "\n" << test << " is less than or equal to " << test1 << endl;
}

if(test < test1){

	cout << "\n" << test << " is less than " << test1 << endl;
}

if(test > test1){

	cout << "\n" << test << " is greater than " << test1 << endl;
}


if(test >= test1){

	cout << "\n" << test << " is greater than or equal to " << test1 << endl;
}

cout << "\nToday's date is " << date << endl
	<< "The time you entered was: " << t << endl;

system("PAUSE");
return 0;
}
