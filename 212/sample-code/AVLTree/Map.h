#ifndef _MAP
#define _MAP

#include "treeNode.h"
#include <fstream>

using namespace std;

const int ITEM_WIDTH = 2;
const int BLANK = 666;

class Map
{
public :
	Map();
	void setMap(treeNode* tree);

	void printMap();
	void printBalance();

	int getHeight(treeNode* tree, int h);

private:
	ofstream outFile;

	int **map;
	short **balMap;
	int level, items;
	void setLevel(int level, int items, treeNode* tree, int max);
};

#endif