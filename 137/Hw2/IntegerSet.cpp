#include <iostream>
#include "IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet(int iSize){
	 set = new int[iSize];
	 size = iSize;
		for(int i = 0; i < size; i++){
			set[i] = 0;
		}
}

IntegerSet::~IntegerSet(){
delete [] set;
set = 0;
}

IntegerSet::IntegerSet(int aSize, int something[]){
	set = new int[aSize];
	size = aSize;
	for(int i = 0; i < size; i++){
	set[i] = something[i];
	}
}

IntegerSet* IntegerSet::unionOfSets(const IntegerSet& one){
	IntegerSet* test = new IntegerSet(one.getSize());
	for(int i = 0; i < size; i++){
		if(set[i] == 1 || one.set[i] == 1){
			test->insertElement(i);
		}
	}
	return test;
}

IntegerSet* IntegerSet::intersectionOfSets(const IntegerSet& iSet2){
	IntegerSet* test = new IntegerSet(iSet2.getSize());
	for(int i = 0; i < size; i++){
		if(set[i] == 1 && iSet2.set[i] == 1){
			test->insertElement(i);
		}
	}
	return test;
}

void IntegerSet::insertElement(int k){
set[k] = 1;

}

void IntegerSet::deleteElement(int m){
set[m] = 0;

}

void IntegerSet::printSet()const {
	for(int i = 0; i < size; i++){
		cout << set[i] << " ";
	}
}

bool IntegerSet::isEqual(const IntegerSet& iSet2){
	for(int i = 0; i < size; i++){
		if(set[i] == iSet2.set[i])
			return true;
		else
			return false;
	}
}

int IntegerSet::getSize() const{
return size;
}
