#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Course.h"
using namespace std;

ostream& operator<<(ostream& output, const Course& oCourse){
output << "Course Info:\t" << oCourse.getName() << "\n#of Units:\t"
	<< oCourse.getUnits() << "\nCourse Dates:\t" << "stuff - stuff"
	<< "\nMeeting Days:\t" << "stuff"
	<< "\nMeeting Time:\t" << "A time";   
	return output;
}


Course::Course(){
//Course::Course(string number, string name, string days, double units, Date &startD, Date &endD, Time &startT, Time &endT){
	
	/*setNumber(number);
	setName(name);
	setDaysMet(days);
	setUnits(units);
	dStart(startD),
	dEnd(endD),
	startT(tStart),
	endT(tEnd);*/
}

Course::~Course(){
	cout << "A course has been deleted!";
}

Course& Course::setNumber(string num){
cNumber = num;
return *this;
}

Course& Course::setName(string name){
cName = name;
return *this;
}

Course& Course::setDaysMet(string dys){
cDays = dys;
return *this;
}

Course& Course::setUnits(double units){
numUnits = units;
return *this;
}

string Course::getNumber() const{
	return cNumber;
}

string Course::getName() const{
	return cName;
}

string Course::getDaysMet() const{
	return cDays;
}

double Course::getUnits() const{
	return numUnits;
}
