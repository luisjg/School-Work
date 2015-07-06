//Luis Guzman
//CSIS 137
//Homework #4

#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(const string& sName, const string& sAddress, const string& sCity, const string& sState, int sZip, 
		const string& rName, const string& rAddress, const string& rCity, const string& rState, int rZip , double weight,
		double cost, double aFee)
		: Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, weight, cost)
{
	setFlatFee(aFee);
}

void TwoDayPackage::setFlatFee(double fee){
flatFee = fee;
}

double TwoDayPackage::getFlatFee()const{
return flatFee;
}

double TwoDayPackage::calculateCost()const{
return (getFlatFee() + Package::calculateCost());
}