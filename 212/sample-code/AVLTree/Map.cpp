#include "Map.h"
#include <iostream>
#include <iomanip>

Map::Map(): map(NULL){}

void Map::setMap(treeNode* tree)
{
	if (map != NULL)
	{
		for (int r = 0; r <= level; r++)
		  delete map[r];
		delete map;
		map = NULL;
	}
	level = getHeight(tree, 0);
	items = pow(2.0, level) * 2 - 1;

	map = new int*[level + 1];
	for (int r = 0; r <= level; r++)
	{
		map[r] = new int[items + 1];
		for (int c = 0; c < items+1; c++)
			map[r][c] = BLANK;
	}

	balMap = new short*[level + 1];
	for (int r = 0; r <= level; r++)
	{
		balMap[r] = new short[items + 1];
		for (int c = 0; c < items+1; c++)
			balMap[r][c] = BLANK;
	}

	setLevel(0, (items+1)/2, tree, items + 1);
}

void Map::setLevel(int lvlNum, int itmNum, treeNode* tree, int max)
{
	int offset = (max/pow(2.0, lvlNum+1))/2;
	map[lvlNum][itmNum] = tree->value;
	if (tree->leftCh != NULL)
		setLevel(lvlNum + 1, itmNum - offset, tree->leftCh, max);
	if (tree->rightCh != NULL)
		setLevel(lvlNum + 1, itmNum + offset, tree->rightCh, max);

	balMap[lvlNum][itmNum] = tree->balance;
	if (tree->leftCh != NULL)
		setLevel(lvlNum + 1, itmNum - offset, tree->leftCh, max);
	if (tree->rightCh != NULL)
		setLevel(lvlNum + 1, itmNum + offset, tree->rightCh, max);
}

void Map::printMap()
{
	

	for (int r = 0; r <= level; r++)
	{
		for (int c = 0; c <= items; c++)
			if (map[r][c] == BLANK)
				cout << setw(ITEM_WIDTH) << " ";
			else
			    cout << setw(ITEM_WIDTH) << map[r][c];
		cout << endl;
	}

}

void Map::printBalance()
{
	outFile.open("balance.txt");

	for (int r = 0; r <= level; r++)
	{
		for (int c = 0; c <= items; c++)
			if (balMap[r][c] == BLANK)
				outFile << setw(ITEM_WIDTH) << " ";
			else
			    outFile << setw(ITEM_WIDTH) << balMap[r][c];
		outFile << endl;
	}
	outFile.clear();
	outFile.close();
}

int Map::getHeight(treeNode* tree, int h)
{
	int left = h,
		right = h;
	if (tree->leftCh != NULL)
		left = getHeight(tree->leftCh, h + 1);
	if (tree->rightCh != NULL)
		right = getHeight(tree->rightCh, h + 1);
	if (left > right)
		return left;
	else
	    return right;
}