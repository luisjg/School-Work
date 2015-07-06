#ifndef COURSE_H
#define COURSE_H
//#include "Time.h"
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

class Course{
	//overloaded operators
	friend ostream& operator<<(ostream&, const Course&);

	private:
		string cNumber;
		string cName;
		string cDays;
		double numUnits;
		/*Date dStart;
		Date dEnd;
		Time tStart;
		Time tEnd;*/

public:
		//constructor that accepts 8 arguments
		//Course(string, string, string, double, Date&, Date&, Time&, Time&);
		//destructor
		Course();
		~Course();
		
		
		Course& setNumber(string);
		Course& setName(string);
		Course& setDaysMet(string);
		Course& setUnits(double);

		string getNumber() const;
		string getName() const;
		string getDaysMet() const;
		double getUnits() const;
};
#endif
