#include <iostream>
#include <string>
#include "employee.h"
using namespace std;
int main(){
employee emp1, emp2, emp3;
string empName;
string idNum;
string dept;
string pos;
int years;
cout << "Welcome to Employee Test" << endl
	<< "-----------------------------" << endl
	<< "Please enter the following" << endl
	<< "Employee One" << endl
	<< "Employee Name";
getline(cin, empName);
emp1.setName(empName);
cout << "\nID Number";
cin >> idNum;
emp1.setIdNumber(idNum);
cout << "\nDepartment";
cin >> dept;
emp1.setDepartment(dept);
cout <<"\nPosition";
cin >> pos;
emp1.setPosition(pos);
cout << "\nyears"
cin >> years;
emp1.setYearsWorked(years);

cout << "Employee Two" << endl
	<< "Employee Name";
getline(cin, empName);
emp2.setName(empName);
cout << "\nID Number";
cin >> idNum;
emp2.setIdNumber(idNum);
cout << "\nDepartment";
cin >> dept;
emp2.setDepartment(dept);
cout <<"\nPosition";
cin >> pos;
emp2.setPosition(pos);
cout << "\nyears"
cin >> years;
emp2.setYearsWorked(years);

cout << "Employee Three" << endl
	<< "Employee Name";
getline(cin, empName);
emp3.setName(empName);
cout << "\nID Number";
cin >> idNum;
emp3.setIdNumber(idNum);
cout << "\nDepartment";
cin >> dept;
emp3.setDepartment(dept);
cout <<"\nPosition";
cin >> pos;
emp3.setPosition(pos);
cout << "\nyears"
cin >> years;
emp3.setYearsWorked(years);
cout << endl;
system("PAUSE");
return 0;
}