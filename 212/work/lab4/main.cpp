#include "BST.h"
#include <iostream>
#include <fstream>
using namespace std;

void insert(BinarySearchTree& b, string name)
{
  KeyedItem node(name);
  b.searchTreeInsert(node);
}

int main()
{
  BinarySearchTree tree;
  ifstream file("list.txt");
  cout << "Reading list.txt...\n" << endl;
  string name;
  if(file.fail())
  {
	file.close();
    cout << "The file could not be opened\nThe program will now quit." << endl;
    system("PAUSE");
    exit(0);
  }
  else
  {
    while (!file.eof())
    { 
	  getline(file,name);
	  cout << "Inserting \"" << name << "\"." << endl;
      insert(tree, name);
    }
	cout << "\nReading complete." << endl;
	file.close();
  }
  tree.setMapParms();
  tree.print();
  system("PAUSE");
  return 0;
}