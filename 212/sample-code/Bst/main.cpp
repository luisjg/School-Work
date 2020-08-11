#include "BST.h"
#include <iostream>
#include <fstream>

void insert(BinarySearchTree& b, string name)
{
  KeyedItem node(name);
  b.searchTreeInsert(node);
}

void print(TreeItemType& n)
{
  cout << n.getKey() << endl;
}

int main()
{
  BinarySearchTree tree;

  ifstream file("list.txt");

  string name;

  while (file >> name)
  { 
    insert(tree, name);
  }

  tree.inorderTraverse(print);

  return 0;
}
