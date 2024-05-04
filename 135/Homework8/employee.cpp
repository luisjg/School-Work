/*File employee.cpp -- Function Implementation File*/
//Contains function definitions for employee class functions

#include "employee.h"
using namespace std;

employee::employee()
{
	name = "";
	idNumber = "";
	department = "";
	position = "";
	yearsWorked = 0;
}

employee::employee(string empName, string id, string dept, string pos, int yearsWrkd)
{
	name = empName;
	idNumber = id;
	department = dept;
	position = pos;
	yearsWorked = yearsWrkd;
}

employee::employee(string empName, string id)
{
	name = empName;
	idNumber = id;
	department = "";
	position = "";
	yearsWorked = 0;
}
void employee::setName(string empName)
{
	name = empName;
}
void employee::setIdNumber(string id)
{
	idNumber = id;
}
void employee::setPosition(string pos)
{
	position = pos;
}
bool employee::setYearsWorked(int years)
{
bool condition;
	if(years >= 0){
	yearsWorked = years;
	condition = true;
	}
	else{
	condition = false;
	}
	return condition;
}
string employee::getName()const
{
	return name;
}
string employee::getIdNumber() const
{
	return idNumber;
}
string employee::getDepartment() const
{
	return department;
}
string employee::getPosition() const
{
	return position;
}
int employee::getYearsWorked() const
{
	return yearsWorked;
}