#include "BSTmap.h"
#include "KeyedItem.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void Map::setMap(TreeNode* tree)
{
	level = getHeight(tree, 0);
	items = pow(2.0, level) * 2 - 1;
	map = new KeyType*[level + 1];
	for (int r = 0; r <= level; r++)
		map[r] = new KeyType[items + 1];
	setLevel(0, (items+1)/2, tree, items + 1);
}

void Map::setLevel(int lvlNum, int itmNum, TreeNode* tree, int max)
{
	int offset = (max/pow(2.0, lvlNum+1))/2;
	map[lvlNum][itmNum] = tree->item.getKey();
	if (tree->leftChildPtr != NULL)
		setLevel(lvlNum + 1, itmNum - offset, tree->leftChildPtr, max);
	if (tree->rightChildPtr != NULL)
		setLevel(lvlNum + 1, itmNum + offset, tree->rightChildPtr, max);
}

void Map::printMap()
{
	ofstream outFile;
	outFile.open("output.txt");
	for (int r = 0; r <= level; r++)
	{
		for (int c = 0; c <= items; c++)
			outFile << setw(itemWidth) << map[r][c];
		outFile << endl;
	}
	outFile.close();
	cout << "Printed to output.txt" << endl;
}

int Map::getHeight(TreeNode* tree, int h)
{
	int left = h,
		right = h;
	if(tree == NULL)
		return 0;
	if (tree->leftChildPtr != NULL)
		left = getHeight(tree->leftChildPtr, h + 1);
	if (tree->rightChildPtr != NULL)
		right = getHeight(tree->rightChildPtr, h + 1);
	if (left > right)
		return left;
	else
	    return right;
}