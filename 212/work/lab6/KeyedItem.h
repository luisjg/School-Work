#ifndef KEYEDITEM_H
#define KEYEDITEM_H
#include <string>
/** @file KeyedItem.h
* Provides basis for classes that need a search key value. */
typedef string KeyType;
class KeyedItem{

public:
	KeyedItem () {}
	KeyedItem(const KeyType& keyValue, string init) : searchKey(keyValue), initials(init) {}
	KeyType getKey() const{// returns search key
	return searchKey;
	}
	void setInitials(string init){
		initials = init;
	}
	string getInitials() const{
		return initials;
	}
private:
	KeyType searchKey;
	string initials;
};
// end KeyedItem
#endif