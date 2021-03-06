#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date{
	//overloaded operators
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date);

private:

	int month; //1-12
	int day; //1-31 depending on month
	int year; //any year
                
	//utility function to check if day is proper for month and year
	int checkDay(int) const;      
    
public:
	Date(int = 1, int = 1, int = 1990);
	Date& setMonth(int);
	Date& setDay(int);
	Date& setYear(int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
};
#endif
