//L G
//CSIS 137
//Homework #4

#include <iostream>
#include <iomanip>
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
using namespace std;
int main(){
	Package p1("Test Name","123 Fake St.","Tunnel", "Some State", 1000, "Another Name", "Address2", "City 2", "Sate", 1000, 10.0, 5.00 );
	OvernightPackage p2("Name3", "8489 Random St", "Some City", "State", 10000, "Name4","Test St.","Sample City","State", 2000, 0.05, 7.0, 6.0);
	TwoDayPackage p3("Name5", "789 St.", "Another Test City", "Different State", 5, "Name6", "951 St.", "Paradise", "VA", 50000, 4.0, 0.03, 0.2);
	cout << fixed << setprecision(2);
	cout << "This Program only tests Inheritance" << endl
		<< "(Only has sample values)" << endl
		<< "------------------------------------------\n"
		<< "This is the Packge info:\n" << endl;
	p1.printSenderInfo();
	cout << endl;
	p1.printReceiveInfo();
	cout << endl;
	cout << "Total:\t$" << p1.calculateCost() << endl;
	cout << "------------------------------------------\n";
	cout << "This is the OvernightPackge info:\n" << endl;
	p2.printSenderInfo();
	cout << endl;
	p2.printReceiveInfo();
	cout << endl;
	cout << "Total:\t$" << p2.calculateCost() << endl;
	cout << "------------------------------------------\n";
	cout << "This is the TwoDayPackage info:\n" << endl;
	p3.printSenderInfo();
	cout << endl;
	p3.printReceiveInfo();
	cout << endl;
	cout << "Total:\t$" << p3.calculateCost() << endl;
	cout << "------------------------------------------\n";
	/*
	cout << "\nTesting Set/Get functions" << endl
		<< "Set the Weight to 15 ounces" << endl;
	p1.setPackageWeight(15);
	cout << "Test it" << endl;
	cout << p1.getWeight() << endl;*/
system("PAUSE");
return 0;
}
