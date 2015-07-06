//Luis Guzman
//CSIS 137
//Homework 3

#include<iostream>
#include"FeetInches.h"
using namespace std;

//global overloaded << operator friend function that prints the
//feet and inches
ostream& operator<<(ostream& output, const FeetInches& temp1){
	output << temp1.getFeet() << " feet " << temp1.getInches() << " inches.";
	return output;
}

//global overloaded >> operator friend function that asks the
//user for input, saves the input and chacks it
istream& operator>>(istream& input, FeetInches& temp2){
	cout << "Please enter" << endl
		<< "Feet: ";
	input >> temp2.feet;
	cout << "Inches: "; 
	input >> temp2.inches;
	temp2.checker();

	return input;
}

//Constructor that assigns feet and inches
//default f and i are 0
FeetInches::FeetInches(int f, int i){
	//call the set functions
	setFeet(f);
	setInches(i);
}

//overloaded + operator that takes one constant reference
//FeetInches object and adds their values
FeetInches FeetInches::operator+(const FeetInches &temp3){
	FeetInches aCopy;
	aCopy.feet = feet + (temp3.feet);
	aCopy.inches = inches + (temp3.inches);
	aCopy.checker();
	return aCopy;
}

//overloaded - operator that takes one constant reference
//FeetInches object and subtracts their values
FeetInches FeetInches::operator-(const FeetInches &temp4){
	FeetInches sCopy;
	sCopy.feet = feet - (temp4.feet);
	sCopy.inches = inches - (temp4.inches);
	sCopy.checker();
	return sCopy;
}
//overloaded == operator that takes one constant reference
//FeetInches object and checks to see if they're equal
bool FeetInches::operator==(const FeetInches &temp5){
	if(feet == temp5.feet && inches == temp5.inches){
	return true;
	}
	else{
	return false;
	}
}

//overloaded != operator that takes one constant reference
//FeetInches object and checks if they're not equal
bool FeetInches::operator!=(const FeetInches &temp6){
	if(feet == temp6.feet && inches == temp6.inches){
	return false;
	}
	else{
	return true;
	}
}


//overloaded > operator that takes one constant reference
//FeetInches object and checks to see if the conditions are true
bool FeetInches::operator>(const FeetInches &temp7){
	if(feet > temp7.feet){
	return true;
	}
	else if(feet == temp7.feet && inches > temp7.inches){
	return true;
	}
	else{
	return false;
	}
}

//overloaded < operator that takes one constant reference
//FeetInches object and checks to see if the conditions are true
bool FeetInches::operator<(const FeetInches &temp8){
	if(feet < temp8.feet){
	return true;
	}
	else if(feet == temp8.feet && inches < temp8.inches){
	return true;
	}
	else{
	return false;
	}
}

//overloaded <= operator that takes one constant reference
//FeetInches object and checks to see if the conditions are true
bool FeetInches::operator<=(const FeetInches &temp9){
	if(feet <= temp9.feet){
	return true;
	}
	else if(feet == temp9.feet && inches <= temp9.inches){
	return true;
	}
	else{
	return false;
	}
}


//overloaded >= operator that takes one constant reference
//FeetInches object and checks to see if the conditions are true
bool FeetInches::operator>=(const FeetInches &temp10){
	if(feet >= temp10.feet){
	return true;
	}
	else if(feet == temp10.feet && inches >= temp10.inches){
	return true;
	}
	else{
	return false;
	}
}

//function that accepts one int argument and assigns
//it to inches
void FeetInches::setInches(int i){
	inches = i;
	checker();
}

//function that accepts one int argument and assigns
//it to feet
void FeetInches::setFeet(int f){
	feet = f;
}

//function that returns feet
int FeetInches::getFeet() const{
	return feet;
}

//function that returns inches
int FeetInches::getInches() const{
	return inches;
}

//utility function that checks for inches
//that are greater or equal to 12 and
//adjusts the feet and inches accordingly
void FeetInches::checker(){
	if(inches >= 12){
	feet += (inches / 12);
	inches = (inches % 12);
	}
}

//function that prints in the following manner
// x.x feet
void FeetInches::printDecimal() const {
 cout << getFeet() << "." << getInches() << " feet";

}