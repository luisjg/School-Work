//Luis Guzman
//CSIS 137
//Homework #4

#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(const string& seName, const string& seAddress, const string& seCity,
	const string& seState, int seZip, const string& reName, const string& reAddress, const string& reCity,
	const string& reState, int reZip, double weight, double cost, double fee)
	: Package(seName, seAddress, seCity, seState, seZip, reName, reAddress, reCity, reState,
	reZip, weight, cost)
{
	setAdditionalFee(fee);
}

void OvernightPackage::setAdditionalFee(double fFee){
addtlFeePerOunce = fFee;
}

double OvernightPackage::getAdditionalFee()const{
return addtlFeePerOunce;
}

double OvernightPackage::calculateCost()const{
return (getAdditionalFee() + Package::getCostPerOunce() * Package::getWeight());
}