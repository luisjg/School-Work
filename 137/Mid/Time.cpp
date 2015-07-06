#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.h"

ostream& operator<<(ostream& output, const Time& oTime){
output << ((oTime.getHour() == 0 || oTime.getHour() == 12) ? 12 : oTime.getHour() % 12) << ":" 
          << setfill ('0') << setw(2) << oTime.getMinute() << (oTime.getHour() < 12 ? "AM" : "PM" );
return output;
}

istream& operator>>(istream& input, Time& iTime){
input >> setw(2) >> iTime.hour;
input.ignore(1);
input >> setw(2) >> iTime.minute;
return input;
}

//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute)
{
 setTime(hour, minute);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
 setHour(hour);
 setMinute(minute);
 return *this; 
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
  return *this;
}  

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
  minute = (m >= 0 && m < 24) ? m : 0;  //validates minute, if valid set to m, else set to 0
  return *this;
} 

/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

bool Time::operator==(const Time& eTime){
if(minute == eTime.minute && hour == eTime.hour){
	return true;
}
else{
	return false;
}
}

bool Time::operator!=(const Time& nTime){
if(minute == nTime.minute && hour == nTime.hour){
	return false;
}
else{
	return true;
}
}

bool Time::operator<(const Time& lTime){
if(hour < lTime.hour){
	return true;
}
else if(hour == lTime.hour && minute < lTime.minute){
	return true;
}
else{
	return false;
}
}

bool Time::operator>(const Time& gTime){
if(hour > gTime.hour){
	return true;
}
else if(hour == gTime.hour && minute > gTime.minute){
	return true;
}
else{
	return false;
}
}

bool Time::operator>=(const Time& geTime){
if(hour >= geTime.hour){
	return true;
}
else if(hour == geTime.hour && minute >= geTime.minute){
	return true;
}
else{
	return false;
}
}

bool Time::operator<=(const Time& leTime){
if(hour <= leTime.hour){
	return true;
}
else if(hour == leTime.hour && minute <= leTime.minute){
	return true;
}
else{
	return false;
}
}
