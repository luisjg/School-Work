//Luis Guzman
//CSIS 137
//Homework 3

/*
************************FeetInches*******************************
*****************************************************************
*	operator << (:ostream&, :FeetInches& const):ostream& friend *
*	operator >> (:istream&, :FeetInches&):istream& friend		*
*****************************************************************
*	-feet:int													*
*	-inches:int													*
*	-checker():void												*
*****************************************************************
*	+FeetInches(:int,:int):FeetInches							*
*	+setInches(:int):void										*
*	+setFeet(:int):void											*
*	+getFeet():int const										*
*	+getInches():int const										*
*	+printDecimal():void const									*
*	+operator + (:FeetInches& const):FeetInches					*
*	+operator - (:FeetInches& const):FeetInches					*
*	+operator == (:FeetInches& const):bool						*
*	+operator != (:FeetInches& const):bool						*
*	+operator < (:FeetInches& const):bool						*
*	+operator > (:FeetInches& const):bool						*
*	+operator <= (:FeetInches& const):bool						*
*	+operator >= (:FeetInches& const):bool						*
*****************************************************************
*****************************************************************
*/


#ifndef FEETINCHES_H
#define FEETINCHES_H
#include<iostream>
using namespace std;
class FeetInches{

      friend ostream& operator<<(ostream&, const FeetInches&);
      friend istream& operator>>(istream&, FeetInches&);

private:
	int feet;
	int inches;
	void checker();
public:
	FeetInches(int = 0, int = 0);
	void setInches(int);
	void setFeet(int);
	int getFeet() const;
	int getInches() const;
	void printDecimal() const;

	FeetInches operator + (const FeetInches&);
	FeetInches operator - (const FeetInches&);
	bool operator == (const FeetInches&);
	bool operator != (const FeetInches&);
	bool operator < (const FeetInches&);
	bool operator > (const FeetInches&);
	bool operator <= (const FeetInches&);
	bool operator >= (const FeetInches&);
};
#endif