#ifndef _TREE_NODE
#define _TREE_NODE

struct treeNode
{
	treeNode *parent;
	treeNode *leftCh;
	treeNode *rightCh;

	int value;
	short balance;
};
#endif