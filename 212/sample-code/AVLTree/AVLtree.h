#ifndef _AVL_TREE
#define _AVL_TREE

#include "treeNode.h"
#include "Map.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void clientInsert(int val);
	void clientDelete(int val);
	void printTree();
	void printBalance();
	void printParent();

	void tester();
private:
	void insert(treeNode *& treePtr, treeNode *par, int &val);
	void insertBalance(treeNode *& treePtr, int dir);

	void nodeDelete(treeNode *& treePtr, int val);
	void deleteBalance(treeNode *& treePtr, int dir);				//can't get by without a getHeight at the moment :(

	void deleteBalance(treeNode *& treePtr);
	short calcBalance(treeNode *treePtr);
	short calcHeight(treeNode *treePtr, short h);

	void rightRotate(treeNode *& treePtr);
	void leftRightRotate(treeNode *& treePtr);

	void leftRotate(treeNode *& treePtr);
	void rightLeftRotate(treeNode *& treePtr);

	void tempPrint(treeNode *& treePtr);
	void burnTree(treeNode *& treePtr);

	treeNode *root;
	Map m1;
};
#endif