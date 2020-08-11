#include "AVLtree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree() 
{root = NULL;}

AVLTree::~AVLTree()
{burnTree(root);}

void AVLTree::burnTree(treeNode *& treePtr)
{
	if(treePtr != NULL)
	{
		burnTree(treePtr->leftCh);
		burnTree(treePtr->rightCh);
		delete treePtr;
		treePtr = NULL;
	}
}

void AVLTree::clientInsert(int val)
{insert(root, root, val);}

void AVLTree::insert(treeNode *& treePtr, treeNode *par, int &val)
{
	if(treePtr == NULL)
	{
		treePtr = new treeNode;
		treePtr->balance = 0;
		if(treePtr == par)
			treePtr->parent = NULL;					//special case, root
		else
			treePtr->parent = par;
		treePtr->leftCh = NULL;
		treePtr->rightCh = NULL;
		treePtr->value = val;

		if(treePtr->parent != NULL)
		{
			if(treePtr == treePtr->parent->leftCh)	//direction is left
				insertBalance(treePtr->parent, 1);
			else									//direction is right
				insertBalance(treePtr->parent, -1);		
		}
	}
	else if(val < treePtr->value)
		insert(treePtr->leftCh, treePtr, val);
	else if(val > treePtr->value)
		insert(treePtr->rightCh, treePtr, val);
	else
		cout << "inserting duplicate values is not supported at this time" << endl;
}

void AVLTree::insertBalance(treeNode *& treePtr, int dir)
{
	if(treePtr != NULL)
	{
		short prevBal = treePtr->balance;
		treePtr->balance += dir;										//adjust balance
		bool keepGoing = true;

		if(treePtr->balance == 2)										//too heavy on left
		{
			//both nodes are heavy on left, technically left child's balance could be 0 and a RR could still be required,
			//however this would only occcur if RL/LR are not implemented, rotate function takes this into account(see super fun balance diagram)
			if(treePtr->leftCh->balance == 1)
			{
				leftRotate(treePtr);
				cout << "Left Rotate!" << endl;
			}
			else//balance of left child here is actually -1
			{
				leftRightRotate(treePtr);
				cout << "Left Right Rotate!" << endl;
			}
			keepGoing = false;											//one rotation is always enough to balance on insertion
		}
		else if(treePtr->balance == -2)
		{
			if(treePtr->rightCh->balance == -1)
			{
				rightRotate(treePtr);
				cout << "Right Rotate!" << endl;
			}
			else//balance of right child is 1
			{
				rightLeftRotate(treePtr);
				cout << "Right Left Rotate!" << endl;
			}
			keepGoing = false;
		}
		
		if(keepGoing == true)
		{
			if(abs(prevBal) > abs(treePtr->balance))						//the weight has become more balanced, stop
				keepGoing = false;											
			else
				keepGoing = true;


			if(treePtr->parent != NULL && treePtr->balance != 0 && keepGoing == true)		//keep travelling up
			{
				if(treePtr == treePtr->parent->leftCh)
					insertBalance(treePtr->parent, 1);
				else
					insertBalance(treePtr->parent, -1);
			}
		}
	}
}

//IMPORTANT INSERT: treePtr goes in pointing at c, it is b->parent in fact
//IMPORTANT INSERT: it returns as the old parent of c, now parent of b, which is one level higher(which could very well be NULL)
//IMPORTANT INSERT: b->parent to old c->parent aka cur b->parent...
void AVLTree::leftRotate(treeNode *& treePtr)
{
	/*          (c)                 (b)
	            /                   / \
			  (b)                (a)  (c)
			  / \                / \   /
			(a) (3)     ->     (1) (2)(3)
			/ \
		  (1) (2) */

	treeNode *c = treePtr;
	treeNode *b = treePtr->leftCh;


	if(c->parent != NULL)						//manage parent pointers
	{
		treeNode *oldParent = c->parent;
		if(oldParent->leftCh == c)				//parent has c on the left
			oldParent->leftCh = b;
		else									//parent has c on the right
			oldParent->rightCh = b;
		b->parent = oldParent;
	}
	else
	{
		root = b;							//find new root if special case
		b->parent = NULL;
	}

	if(b->rightCh != NULL)						//more parent management
		b->rightCh->parent = c;
	c->parent = b;				

	c->leftCh = b->rightCh;						//and finally, the actual rotation
	b->rightCh = c;

	b->balance--;								//rebalance
	c->balance = -b->balance;
}

void AVLTree::rightRotate(treeNode *& treePtr)
{
	/* (a)                    (b)
	     \					  / \
		 (b)       ->      (a)   (c)
		 / \                 \   / \
	  (3)   (c)              (3)(2)(1)
	        / \
		  (2) (1)    */

	treeNode *a = treePtr;
	treeNode *b = treePtr->rightCh;

	if(a->parent != NULL)
	{
		treeNode *oldParent = a->parent;
		if(oldParent->leftCh == a)
			oldParent->leftCh = b;
		else
			oldParent->rightCh = b;
		b->parent = oldParent;
	}
	else
	{
		root = b;
		b->parent = NULL;
	}
	if(b->leftCh != NULL)
		b->leftCh->parent = a;
	a->parent = b;

	a->rightCh = b->leftCh;
	b->leftCh = a;

	/*super special BALANCE formula fun time diagram: Why don't we just rebalance everything to 0?
	-2               1
	  \             / \
	   0     ->   -1   0
	  / \           \
	 0   0          0       */
	b->balance++;
	a->balance = -b->balance;
}

void AVLTree::leftRightRotate(treeNode *& treePtr)
{
	/*        (c)               (c)              (b)
		      / \               / \     LL       / \
			(a) (4)   ->      (b) (4)   ->     (a) (c)
			/ \               / \              / \  /\
		  (3) (b)           (a) (1)         (3) (2)(1)(4)
		      / \           / \
			(2) (1)       (3) (2) */
	/* rebalancing guide:
	    The 3 possible versions of a tree that needs LRR are predicated on the state of b's child pointers(and thus balance)
		1. going in: b->balance = 0, no children  -> going out: b->balance = 0, c->balance = 0, a->balance = 0
		2. going in: b->balance = 1, left child   -> going out: b->balance = 0, c->balance = -1, a->balance = 0
		3. going in: b->balance = -1, right child -> going out: b->balance = 0, c->balance = 0, a->balance = 1 */
	
	treeNode *c = treePtr;
	treeNode *a = c->leftCh;
	treeNode *b = a->rightCh;
	
	c->leftCh = b;
	a->rightCh = b->leftCh;
	b->leftCh = a;

	c->leftCh = b->rightCh;
	b->rightCh = c;

	if(c->parent != NULL)
	{
		treeNode *oldParent = c->parent;
		if(oldParent->leftCh == c)
			oldParent->leftCh = b;
		else
			oldParent->rightCh = b;
		b->parent = oldParent;
	}
	else
	{
		root = b;
		b->parent = NULL;
	}
	a->parent = b;
	c->parent = b;
	if(a->rightCh != NULL)
		a->rightCh->parent = a;
	if(c->leftCh != NULL)
		c->leftCh->parent = c;

	if(b->balance == 0)
	{
		c->balance = 0;
		a->balance = 0;
	}
	else if(b->balance == 1)
	{
		c->balance = -1;
		a->balance = 0;
	}
	else
	{
		c->balance = 0;
		a->balance = 1;
	}
	b->balance = 0;
}

void AVLTree::rightLeftRotate(treeNode *& treePtr)
{
	/*    (a)              (a)                (b)
	      / \              / \                / \
		(1) (c)          (1) (b)            (a) (c)
		    / \              / \    RR      /\   /\
		  (b) (4) ->       (2) (c)  ->    (1)(2)(3)(4)
		  / \                  / \
		(2) (3)              (3) (4)
	*/
	treeNode *a = treePtr;
	treeNode *c = a->rightCh;
	treeNode *b = c->leftCh;

	a->rightCh = b;
	c->leftCh = b->rightCh;
	b->rightCh = c;

	a->rightCh = b->leftCh;
	b->leftCh = a;
	
	if(a->parent != NULL)
	{
		treeNode *oldParent = a->parent;
		if(oldParent->leftCh == a)
			oldParent->leftCh = b;
		else
			oldParent->rightCh = b;
		b->parent = oldParent;
	}
	else
	{
		root = b;
		b->parent = NULL;
	}
	a->parent = b;
	c->parent = b;
	if(a->rightCh != NULL)
		a->rightCh->parent = a;
	if(c->leftCh != NULL)
		c->leftCh->parent = c;

	if(b->balance == 0)
	{
		c->balance = 0;
		a->balance = 0;
	}
	else if(b->balance == 1)
	{
		c->balance = -1;
		a->balance = 0;
	}
	else
	{
		c->balance = 0;
		a->balance = 1;
	}
	b->balance = 0;
}

void AVLTree::clientDelete(int val)
{nodeDelete(root, val);}

void AVLTree::nodeDelete(treeNode *& treePtr, int val)
{
	//case 1: no children
	//case 2: no left child
	//case 3: no right child
	//case 4: 2 children

	if(treePtr == NULL)
		cout << "item requested for deletion is not in tree" << endl;
	else if(val < treePtr->value)
		nodeDelete(treePtr->leftCh, val);
	else if(val > treePtr->value)
		nodeDelete(treePtr->rightCh, val);
	else
	{
		if(treePtr->leftCh == NULL && treePtr->rightCh == NULL)		//case 1
		{
			bool reBalance = false;
			int direction = 0;
			treeNode *balParent = treePtr->parent;
			if(root == treePtr)
				root = NULL;
			else
			{
				if(treePtr->parent->leftCh == treePtr)				//directions switch for delete
					direction = -1;
				else
					direction = 1;
				reBalance = true;
			}
			treePtr->parent = NULL;
			delete treePtr;
			treePtr = NULL;

			if(reBalance == true)
				//deleteBalance(balParent, direction);
				deleteBalance(balParent);
		}
		else if(treePtr->leftCh == NULL)							//case 2
		{
			int direction = 0;
			treeNode *balParent = treePtr->parent;
			if(treePtr->parent->leftCh == treePtr)
				direction = -1;
			else
				direction = 1;

			treeNode *delNode = treePtr;
			treePtr = treePtr->rightCh;
			treePtr->parent = delNode->parent;
			delNode->parent = NULL;
			delNode->rightCh = NULL;
			delete delNode;

			//deleteBalance(balParent, direction);
			deleteBalance(balParent);
		}
		else if(treePtr->rightCh == NULL)							//case 3
		{
			int direction = 0;
			treeNode *balParent = treePtr->parent;
			if(treePtr->parent->leftCh == treePtr)
				direction = -1;
			else
				direction = 1;

			treeNode *delNode = treePtr;
			treePtr = treePtr->leftCh;
			treePtr->parent = delNode->parent;
			delNode->parent = NULL;
			delNode->leftCh = NULL;
			delete delNode;

			//deleteBalance(balParent, direction);
			deleteBalance(balParent);
		}
		else														//case 4
		{
			treeNode *replacement = treePtr->rightCh;
			while(replacement->leftCh != NULL)
				replacement = replacement->leftCh;

			treePtr->value = replacement->value;
			treeNode *delNode = replacement;

			treeNode *balParent = NULL;								//rebalancing variables
			int direction = 0;
			//3 cases for what the node being deleted may be. 
			//Immediately to the right; right and left most(no children); right child of left most 
			if(replacement->parent == treePtr)						//case 1
			{
				balParent = treePtr;
				direction = 1;
			}
			else if(replacement->rightCh == NULL)					//case 2
			{
				balParent = replacement->parent;
				direction = -1;
			}
			else													//case 3, consolidate?
			{
				balParent = replacement->parent;
				direction = -1;
			}

			if(replacement->parent->leftCh == replacement)			//while loop travels by copy, so have to use parent ptr
				replacement->parent->leftCh = replacement->rightCh;
			else
				replacement->parent->rightCh = replacement->rightCh;
			
			if(replacement->rightCh != NULL)
				replacement->rightCh->parent = treePtr;
			replacement->parent = delNode->parent;

			delNode->parent = NULL;
			delNode->rightCh = NULL;
			delete delNode;

			//deleteBalance(balParent, direction);
			deleteBalance(balParent);
		}
	}
}

void AVLTree::deleteBalance(treeNode *& treePtr, int dir) //:(((((((((((((((((((((((((((((((((
{
	if(treePtr != NULL)
	{
		//After delete, treePtr has a correct new balance, whatever is below is also correct because
		//we are always deleting a leaf or level directly above a leaf with 1 child(which will still be 0)
		//the problem is there's no easy way to rebalance as we traverse up without a brute force getHeight.
		//Insert has some bullet proof conditions(the tree is becoming more balanced or a rotation has happened)
		//that not only make insert more efficient, but dictate when a tree needs to be rebalanced. 
		//I have not been able to come up with the equivelant of that after a deletion. More than 1 rotation may
		//be required, current node may indeed be more balanced but some other node may need to be rebalanced above.
		short prevBal = treePtr->balance;
		treePtr->balance += dir;
		bool keepGoing = true;

		if(treePtr->parent != NULL && keepGoing == true)
		{
			if(treePtr == treePtr->parent->leftCh)
				deleteBalance(treePtr->parent, -1);
			else
				deleteBalance(treePtr->parent, 1);
		}
	}
}

void AVLTree::deleteBalance(treeNode *& treePtr)
{
	short newBal = calcBalance(treePtr);
	treePtr->balance = newBal;

	if(treePtr->balance == 2)							
	{
		if(treePtr->leftCh->balance >= 0)						//note rebalncing condition is more precise
		{
			leftRotate(treePtr);
			cout << "DELETE: Left Rotate!" << endl;
		}
		else
		{
			leftRightRotate(treePtr);
			cout << "DELETE: Left Right Rotate!" << endl;
		}
	}
	else if(treePtr->balance == -2)
	{
		if(treePtr->rightCh->balance <= 0)
		{
			rightRotate(treePtr);
			cout << "DELETE: Right Rotate!" << endl;
		}
		else
		{
			rightLeftRotate(treePtr);
			cout << "DELETE: Right Left Rotate!" << endl;
		}
	}

	if(treePtr->parent != NULL)
		deleteBalance(treePtr->parent);
}

void AVLTree::tester()
{
	cout << root->leftCh->leftCh->leftCh->value << endl;
	short balance = calcBalance(root->leftCh->leftCh->leftCh);

	cout << balance << endl;
}

short AVLTree::calcBalance(treeNode *treePtr)
{
	short leftHeight = 0;
	short rightHeight = 0;

	if(treePtr->leftCh != NULL)
		leftHeight = calcHeight(treePtr->leftCh, 1);
	if(treePtr->rightCh != NULL)
		rightHeight = calcHeight(treePtr->rightCh, 1);

	return leftHeight - rightHeight;
}

short AVLTree::calcHeight(treeNode *treePtr, short h)
{
	short left = h;
	short right = h;
	if(treePtr->leftCh != NULL)
		left = calcHeight(treePtr->leftCh, h + 1);
	if(treePtr->rightCh != NULL)
		right = calcHeight(treePtr->rightCh, h + 1);
	if (left > right)
		return left;
	else
	    return right;
}

void AVLTree::printTree()
{
	m1.setMap(root);
	m1.printMap();
}

void AVLTree::printBalance()
{
	m1.printBalance();
}

void AVLTree::printParent()
{
	tempPrint(root);
}

void AVLTree::tempPrint(treeNode *& treePtr)
{
	if(treePtr->leftCh != NULL)
		tempPrint(treePtr->leftCh);
	if(treePtr->parent != NULL)
		cout << "The parent of node: " << treePtr->value << " is: " << treePtr->parent->value << endl;
	else
		cout << "The node: " << treePtr->value << " is the root node" << endl;
	if(treePtr->rightCh != NULL)
		tempPrint(treePtr->rightCh);
}
