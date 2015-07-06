//Luis Guzman
//CSIS 137
//Homework #4

#include "Package.h"
#include <iostream>

Package::Package(const string& sName, const string& sAddress, const string& sCity, 
	const string& sState, int sZip, const string& rName, const string& rAddress, 
	const string& rCity, const string& rState, int rZip, double pWeight, double pCost)
	: sendName(sName), sendAddress(sAddress), sendCity(sCity), sendState(sState), receiveName(rName),
	receiveAddress(rAddress), receiveCity(rCity), receiveState(rState)
{

	setSenderZip(sZip);
	setReceiveZip(rZip);

	setPackageWeight(pWeight);
	setCostPerOunce(pCost);

}

//Sender Info

void Package::setSenderName(string& name){
sendName = name;
}

void Package::setSenderAddress(string& address){
sendAddress = address;
}

void Package::setSenderCity(string& city){
sendCity = city;
}

void Package::setSenderState(string& state){
sendState = state;
}

void Package::setSenderZip(int& zip){
sendZipCode = zip;
}

string Package::getSenderName()const{
return sendName;
}
string Package::getSenderAddress()const{
return sendAddress;
}

string Package::getSenderCity()const{
return sendCity;
}

string Package::getSenderState()const{
return sendState;
}

int Package::getSenderZip()const{
return sendZipCode;
}

void Package::printSenderInfo()const{
cout << getSenderName() << endl
	<< getSenderAddress() << endl
	<< getSenderCity() << ", " << getSenderState() << " " << getSenderZip() << endl;
}


//Receiver Info


void Package::setReceiveName(string& rName){
receiveName = rName;
}

void Package::setReceiveAddress(string& rAddress){
receiveAddress = rAddress;
}

void Package::setReceiveCity(string& rCity){
receiveCity = rCity;
}

void Package::setReceiveState(string& rState){
receiveState = rState;
}

void Package::setReceiveZip(int& rZip){
receiveZipCode = rZip;
}

string Package::getReceiveName()const{
return receiveName;
}
string Package::getReceiveAddress()const{
return receiveAddress;
}

string Package::getReceiveCity()const{
return receiveCity;
}

string Package::getReceiveState()const{
return receiveState;
}

int Package::getReceiveZip()const{
return receiveZipCode;
}

void Package::printReceiveInfo()const{
cout << getReceiveName() << endl
	<< getReceiveAddress() << endl
	<< getReceiveCity() << ", " << getReceiveState() << " "
	<< getReceiveZip() << endl;
}


void Package::setCostPerOunce(double cost){
	if(cost > 0){
	costPerOunce = cost;
	}
	else
		costPerOunce = 0.0;
}
void Package::setPackageWeight(double pWeight){
	if(pWeight > 0){
		weight = pWeight;
	}
	else
		weight = 0.0;
}

double Package::getWeight()const{
return weight;
}
double Package::getCostPerOunce()const{
return costPerOunce;
}

double Package::calculateCost()const{
return (getCostPerOunce() * getWeight());
}