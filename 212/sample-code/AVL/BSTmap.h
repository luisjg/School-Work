#pragma once

#include "TreeNode.h"

const int ITEM_WIDTH = 2;

class Map
{
public :
	Map():map(NULL)
	{
	}
	void setMap(TreeNode* tree);
	void printMap();
	int getHeight(TreeNode* tree, int h);

private:
	KeyType **map;
	int level, items;
	void setLevel(int level, int items, TreeNode* tree, int max);
};
