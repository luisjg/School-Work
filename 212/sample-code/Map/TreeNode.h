#pragma once
/** @file TreeNode.h */

#include "KeyedItem.h"

typedef KeyedItem TreeItemType;

/** TreeNode class for the ADT binary search tree */
class TreeNode   // a node in the tree
{
private:
  TreeNode() {}
  TreeNode(const TreeItemType& nodeItem,
           TreeNode *left = NULL, TreeNode *right = NULL)
    : item(nodeItem), leftChildPtr(left), rightChildPtr(right) {}

  TreeItemType item;
  TreeNode *leftChildPtr, *rightChildPtr; // pointers to children

  // friend class - can access private parts
  friend class BinarySearchTree;
  friend class Map;
}; // end TreeNode

