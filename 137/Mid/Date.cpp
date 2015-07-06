#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

ostream& operator<<(ostream& output, const Date& oDate){
output << oDate.getMonth() << "/" << oDate.getDay() << "/" << oDate.getYear();
return output;
}
istream& operator>>(istream& input, Date iDate){
input >> setw(2) >> iDate.getMonth();
input.ignore(1);
input >> setw(2) >> iDate.getDay();
input.ignore(1);
input >> setw(4) >> iDate.getYear();
return input;
}

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
setMonth(mn);
setDay(dy);
setYear(yr);
}

Date& Date::setMonth(int mn){
if(mn > 0 && mn <= 12){
	month = mn;
}

else{
	month;
}
return *this;
}

Date& Date::setDay(int dy){
day = checkDay(dy);
return *this;
}

Date& Date::setYear(int yr){
if(yr > 0){
	year = yr;
}
else{
	year;
}
return *this;
}

int Date::getMonth()const{
return month;
}

int Date::getDay()const{
return day;
}

int Date::getYear()const{
return year;
}
//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(testDay > 0 && testDay <= daysPerMonth[month])
    {
     return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if(month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
      return testDay;
    }
    
    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}
