#include<iostream>
#include "IntegerSet.h"
using namespace std;

const int SIZE = 10;

int main(){

	int sample[SIZE] = {5,10,15,20};

	IntegerSet test1(SIZE);
	IntegerSet test2(SIZE);
	IntegerSet* test3;
	IntegerSet* test4;
	IntegerSet test5(SIZE, sample);

	for(int i = 0; i < SIZE; i++){
		test1.insertElement(i);
		test2.insertElement(i);
	}

	//test2.deleteElement(0);
	test2.deleteElement(3);
	test2.deleteElement(5);
	test2.deleteElement(9);

	test3 = test1.unionOfSets(test2);
	test4 = test1.intersectionOfSets(test2);

	cout << "Set one" << endl;
	test1.printSet();
	cout << "\n" << endl
		<< "Set two" << endl;
	test2.printSet();
	cout << endl;

	if(test1.isEqual(test2) == true){
		cout << "\nSet one and set two are equal sets." << endl;
	}
	else{
		cout << "\nSet one and set two are not equal sets." << endl;
	}

	cout << endl
		<< "Union of sets one and two" << endl;
	test3->printSet();
	cout << "\n" << endl
		<< "Intersection of sets one and two" << endl;
	test4->printSet();
	cout << "\n" << endl
		<< "Sample array" << endl;
	test5.printSet();
	cout << "\n" << endl;

	test3 = 0;
	delete test3;
	test4 = 0;
	delete test4;
system("PAUSE");
return 0;
}
