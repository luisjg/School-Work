#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
  //head = NULL;
  dummyHead = NULL;
  head->next = dummyHead;
}

LinkedList::~LinkedList()
{
  Node *cur;
  while (head != NULL)
  {
    cur = head->next;
    delete head;
    head = cur;
  }
}

bool LinkedList::isEmpty() const
{
  return (head == NULL);
}

int LinkedList::getLength() const
{
  Node *cur = head;
  int count = 0;
  while (cur != NULL)
  {
    count++;
    cur=cur->next;
  }
  return count;
}

void LinkedList::insert(ItemType newValue)
{
  Node *cur = head;
  Node *prev = NULL;
  Node *newPtr = new Node;
  newPtr->item = newValue;
  newPtr->next = NULL;

  for (prev = NULL, cur = head;
       (cur != NULL) && (newValue > cur->item);
       prev = cur, cur = cur->next);

  if (prev == NULL)
  { newPtr -> next = cur;
    head = newPtr;
  }
  else
  { newPtr->next = cur;
    prev->next = newPtr;
  }  
    
}

void LinkedList::remove(ItemType val)
{
  Node *cur = head;
  Node *prev = NULL;
  bool noRemove = true;

  while (cur != NULL && noRemove)
  {
    if (cur->item == val)
    {
      if (prev == NULL)
        head = cur->next;
      else
        prev->next = cur->next;
      cur->next = NULL;
      delete cur;
      noRemove = false;
    }
    else
    {
      prev = cur;
      cur = cur->next;
    }
  }
}

void LinkedList::retrieve(int index, ItemType& dataItem) const
{
  Node *cur = head;
  int count = 0;
  dataItem = 0;
  while (cur != NULL && count < index)
  {
    count++;
    cur = cur->next;
  }
  if (cur != NULL)
    dataItem = cur->item;
}

void LinkedList::print()
{
  for (Node *cur = head; cur != NULL; cur = cur->next)
    cout << cur->item << endl;
}

void LinkedList::writeFile(string fileName)
{
	ofstream outFile(fileName.c_str());

    for (Node *cur = head; cur != NULL; cur = cur->next)
       outFile << cur->item << endl;
	outFile.close();
}

void LinkedList::readFile(string fileName)
{
	ifstream inFile(fileName.c_str());

	ItemType val;
	if (!inFile.is_open())
	{
		cout << "File " << fileName << " not open\n";
		return;
	}
	while (inFile>>val)
	{
		insert(val);
	}
}