//Luis Guzman
//CSIS 137
//Homework #4

/*
**********Package***********
- sendName:string
- sendAddress:string
- sendCity:string
- sendState:string
- sendZipCode:int
- receiveName:string
- receiveAddress:string
- receiveCity:string
- receiveState:string
- receiveZipCode:int
- weight:double
- costPerOunce:double
**********************************
+ Package(:string& const,
  :string& const, :string& const,
  :string& const, :int,
  :string& const, :string& const,
  :string& const, :string& const,
  :double, :double)
+ setAdditionalFee():void
+ getAdditionalFee():void const
+ calculateCost():double const
+ getWeight():double const
+ getCostPerOunce():double const
+ setSenderName(:string&):void
+ setSenderAddress(:string&):void
+ setSenderCity(:string&):void
+ setSenderState(:string&):void
+ setSenderZip(:int&):void
+ getSenderName():string const
+ getSenderAddress():string const
+ getSenderCity():string const
+ getSenderState():string const
+ getSenderZip():int const
+ printSenderInfo():void const
+ setReceiveName(:string&):void
+ setReceiveAddress(:string&):void
+ setReceiveCity(:string&):void
+ setReceiveState(:string&):void
+ setReceiveZip(:int&):void
+ getReceiveName():string const
+ getReceiveAddress()const;
+ getReceiveCity():string const
+ getReceiveState():string const
+ getReceiveZip():int const
+ printReceiveInfo():void const
+ setPackageWeight(:double):void
+ setCostPerOunce("double):void
**********************************
*/

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

class Package{
private:
string sendName;
string sendAddress;
string sendCity;
string sendState;
int sendZipCode;
string receiveName;
string receiveAddress;
string receiveCity;
string receiveState;
int receiveZipCode;
double weight;
double costPerOunce;

public:
Package(const string&, const string&, const string&, const string&, int,
	const string&, const string&, const string&, const string&, int, double = 0.0, double = 0.0);

void setSenderName(string&);
void setSenderAddress(string&);
void setSenderCity(string&);
void setSenderState(string&);
void setSenderZip(int&);
string getSenderName()const;
string getSenderAddress()const;
string getSenderCity()const;
string getSenderState()const;
int getSenderZip()const;
void printSenderInfo()const;


void setReceiveName(string&);
void setReceiveAddress(string&);
void setReceiveCity(string&);
void setReceiveState(string&);
void setReceiveZip(int&);
string getReceiveName()const;
string getReceiveAddress()const;
string getReceiveCity()const;
string getReceiveState()const;
int getReceiveZip()const;
void printReceiveInfo()const;

void setPackageWeight(double);
void setCostPerOunce(double);

double calculateCost()const;
double getWeight()const;
double getCostPerOunce()const;

};
#endif