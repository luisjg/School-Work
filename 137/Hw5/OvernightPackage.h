//L G
//CSIS 137
//Homework #5

/*
**********OvernightPackage********
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
+ OverNightPackage(:string& const,
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
+ setCostPerOunce(:double):void
**********************************
			    *
			   ***
			 *******
				*
				*
				*
				*
				*
				*
*********OverNightPackage*********
-addtlFeePerOunce:double
**********************************
+ OverNightPackage(:string& const,
  :string& const, :string& const,
  :string& const, :int,
  :string& const, :string& const,
  :string& const, :string& const,
  :double, :double, :double)
+ setAdditionalFee(:double):void
+ getAdditionalFee():void const
+ calculateCost():double const
**********************************
*/


#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "Package.h"
#include <string>
class OvernightPackage : public Package {
private:
	double addtlFeePerOunce;
public:
	OvernightPackage(const string&, const string&, const string&, const string&, int,
		const string&, const string&, const string&, const string&, int, double = 0.0,
		double = 0.0, double = 0.0);
	void setAdditionalFee(double);
	double getAdditionalFee() const;
	virtual double calculateCost() const;
};
#endif
