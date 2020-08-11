#include "AVLtree.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	AVLTree tree;

	ifstream inFile("list.txt");

	int item;

	while (inFile >> item)
	{
		int key(item);
		tree.clientInsert(key);
	}

	cout << "AVL tree" << endl;
	tree.printTree();
	tree.clientDelete(9);
	cout << "\nAVL tree after delete 9" << endl;
	tree.printTree();
	tree.clientDelete(4);
	cout << "\nAVL tree after delete 4" << endl;
	tree.printTree();
	tree.clientDelete(8);
	cout << "\nAVL tree after delete 8" << endl;
	tree.printTree();
	tree.clientInsert(15);
	cout << "\nAVL tree after insert 15" << endl;
	tree.printTree();
	tree.clientDelete(10);
	cout << "\nAVL tree after delete 10" << endl;
	tree.printTree();
	system("pause");
    return 0;
}