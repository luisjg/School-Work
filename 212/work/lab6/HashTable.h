/** %file TableH.h */
#ifndef #HASHTABLE_H
#define #HASHTABLE_H
#include "TableException.h"
#include "ChainNode.h"
typedef KeyedItem TableItemType;
/** ADT table.
* Hash table implementation.
* Assumption: A table contains at most one item with a
* given search key at any time. */
class HashTable
{
public:
// constructors and destructor:
HashTable ( ) ;
HashTable(const HashTable& table);
virtual -HashTable();
// table operations:
virtual bool tablelsEmpty() const; virtual int tableGetLength() const;
virtual void tablelnsert(const TableItemType& newItem) throw(TableException);
virtual void tableDelete(KeyType searchKey) throw(TableException);
virtual void tableRetrieve(KeyType searchKey, TableItemType& tableItem) const
throw(TableException);
protected:
int hashlndex(KeyType searchKey) const; // Hash function
private:
static const int HASH_TABLE_SIZE = 7; // Size of hash
// table
typedef ChainNode * HashTableType[HASH_TABLE_SIZE];
HashTableType table; // Hash table
int size; // size of ADT table
} ; // end HashTable
// End of header file.
#endif