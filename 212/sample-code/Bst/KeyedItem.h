/** @file KeyedItem.h */

typedef string /* desired-type-of-search-key */ KeyType;

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

