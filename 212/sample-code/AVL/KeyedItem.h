#pragma once
#include <string>
/** @file KeyedItem.h */

using namespace std;

typedef int /* desired-type-of-search-key */ KeyType;
const KeyType BLANK = 0; // value you wish to treat as "Blank"

/**  KeyedItem class for the ADT binary search tree */
class KeyedItem
{
public:
  KeyedItem() {}
  KeyedItem(const KeyType& keyValue) :
      searchKey(keyValue) {}
  KeyType getKey() const
  {  return searchKey;
  } // end getKey

 
private:
  KeyType searchKey;
}; // end KeyedItem

