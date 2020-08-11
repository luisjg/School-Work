#include <iostream>
#include "LinkedList.h"

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
  Node *cur = head;
  Node *prev = NULL;
  Node *newNode = new Node;
  newNode->item = val;
  newNode->next = NULL;
  bool noInsert = true;

  while (cur != NULL && noInsert)
  {
    if (cur->item > val)
    {
       noInsert = false;
      if (prev == NULL)
      {
        newNode->next = head;
        head = newNode;
      }
      else
      {
        newNode->next = cur;
        prev->next = newNode;
      }
    }
    prev = cur;
    cur = cur->next;
  }
  if (noInsert)
  {
    if (head == NULL)
      head = newNode;
    else
      prev->next = newNode;
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

