/*
*************IntegerSet**************
-set:int*
-size:int
*************************************
+IntegerSet():IntegerSet
+IntegerSet():IntegerSet
+IntegerSet(:int, :int[]):IntegerSet
+~IntegerSet():IntegerSet
+unionOfSets():IntegerSet*
+intersetionOfSets():IntegerSet*
+insertElemen():void
+deleteElement():void
+printSet():void
+isEqual():bool
+getsize():int
*/

#ifndef INTEGERSET_H
#define INTEGERSET_H


class IntegerSet{
	
	private:
	int *set;
	int size;

	public:
	IntegerSet(int);//constructor
	IntegerSet(int, int[]);//constructor that accepts an integer array
	~IntegerSet();//destructor
	
	IntegerSet* unionOfSets(const IntegerSet&);//1 for now...
	IntegerSet* intersectionOfSets(const IntegerSet&);//2 for now...
	void insertElement(int);//3
	void deleteElement(int);//4
	void printSet() const;//5
	bool isEqual(const IntegerSet&);//6
	int getSize() const;

};

#endif
