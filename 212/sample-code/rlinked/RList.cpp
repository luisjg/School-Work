#include <iostream>
#include "RList.h"

using namespace std;

LinkedList::LinkedList()
{
  head = NULL;
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

void LinkedList::insert(ItemType val)
{
  Node *temp = new Node;
  temp->item = val;
  temp->next = NULL;
  insertRecur(head, temp);
}

void LinkedList::insertRecur(Node *& headPtr, Node *newItem)
{
  if (headPtr == NULL)
    headPtr = newItem;
  else if (headPtr->item > newItem->item)
  {
    newItem->next = headPtr;
    headPtr = newItem;
  }
  else
    insertRecur(headPtr->next, newItem);
}

void LinkedList::remove(ItemType val)
{
  if (removeRecur(head, val))
    cout << val << " removed\n";
  else
    cout << val << " not there\n";
}

bool LinkedList::removeRecur(Node *& headPtr, ItemType val)
{
  if (headPtr == NULL)
    return false;
  else if (headPtr->item != val)
    return removeRecur(headPtr->next, val);
  else
  {
    Node *temp = headPtr;
    headPtr = headPtr->next;
    delete temp;
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
  printRecur(head);
}

void LinkedList::printRecur(Node *headPtr)
{
  if (headPtr != NULL)
  {
    cout << headPtr->item << endl;
    printRecur(headPtr->next);
  }
}

