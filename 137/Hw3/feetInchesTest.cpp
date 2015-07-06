//L G
//CSIS 137
//Homework 3

/*
* FeetInches Client that tests the
* overloaded operators
*/

#include<iostream>
#include"FeetInches.h"
using namespace std;

int main(){

//declare various FeetInches objects
FeetInches empty;
FeetInches test1;
FeetInches test2;
//declare and initialize various FeetInches objects
FeetInches test3(6,17);
FeetInches test4(6,17);
FeetInches add(6,5);
FeetInches subtract(2,3);

//call the overloaded >> operator
cin >> test1;
//print the results with the overloaded << operator
cout << "\nYou entered\n" << test1 << "\n" << endl;
//call the overloaded >> operator
cin >> test2;
//print the results with the overloaded << operator
cout << "\nYou entered" << endl;
test2.printDecimal();
cout << "\n" << endl;

//print the results with the overloaded << operator
cout << "test3 is\n" << test3 << "\n" << endl;
cout << "test4 is\n" << test4 << "\n" << endl;

//evalute the object with the overloaded == operator
if(test3 == test4){
	cout << "test3 and test4 are equal.\n" << endl;
}
//evalute the objects with the overloaded != operator
if(test3 != test4){
	cout << "test3 and test4 are not equal.\n" << endl;
}
//evaluate the objects with the overloaded > operator
if(test3 > test4){
	cout << "test3 is greater than test4.\n" << endl;
}
//evaluate the objects with the overloaded < operator
if(test3 < test4){
	cout << "test3 is less than test4.\n" << endl;
}
//evalute the objects with the overloaded >= operator
if(test3 >= test4){
	cout << "test3 is greater than or equal to test4.\n" << endl;
}
//evaluate the objects with the overloaded <= operator
if(test3 <= test4){
	cout << "test3 is less than or equal to test4.\n" << endl;
}
//print the default constructor with the overloaded << operator
cout << "The default constructor is\n\n" << empty << "\n" << endl;

//test the overloaded - operator and overloaded + operator
cout << "Before subtracting we have\n" << endl
	<< add << endl
	<< "and" << endl
	<< subtract << endl
	<< "\nNow we subtract" << endl
	<< (add-subtract) << endl
	<< "\nNow we add" << endl
	<< (add+subtract) << endl;

system("PAUSE");
return 0;
}
