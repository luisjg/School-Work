#pragma once

#include "TreeNode.h"

const int itemWidth = 6;

class Map
{
public :
	void setMap(TreeNode* tree);
	void printMap();
	int getHeight(TreeNode* tree, int h);

private:
	KeyType **map;
	int level, items;
	void setLevel(int level, int items, TreeNode* tree, int max);
};
