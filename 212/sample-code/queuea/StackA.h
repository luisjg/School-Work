#pragma once
/** @file StackA.h */

#include "StackException.h"
const int MAX_STACK = 50 /* <- maximum-size-of-stack */;
typedef char /* <- desired-type-of-stack-item */ StackItemType;

/** ADT stack -- Array-based implementation */
class Stack
{
public:
// constructors and destructors:
	/** Default constructor */
	Stack();
	// copy constructor and destructor are supplied by the compiler

// stack operations:
	/** Determines whether this stack is empty
	 *  @pre None
	 *  @post None
	 *  @return  True if this stack is empty, otherwise returns false */
	bool isEmpty() const;

	/** Adds an item to the top of this stack
	 *  @pre  newItem is the item to be added
	 *  @post  If the insertion is successful, newItem is on the top of this stack
	 *  @parm newItem   The given StackItemType
	 *  @throw StackException   If the item cannot be placed on this stack */
	void push(const StackItemType& newItem) throw(StackException);

	/** Removes the top of this stack
	 *  @pre None
	 *  @post If this stack is not empty, the item that was added most recently
	 *              is removed. However, if this stack is empty, deletion is impossible
	 *  @throw  StackException  If this stack is empty */
	void pop() throw(StackException);

	/** Retrieves and removes the top of this stack
	 *  @pre  None
	 *  @post  If this stack is not empty, stackTop contains the item that was added
	 *             most recently and the item is remove. However, if this stack is empty,
	 *             deletion is impossible and stackTop is unchanged
	 *  @throw  StackException   If this stack is empty */
	void pop(StackItemType& stackTop) throw(StackException);

	/** Retrieves the top of this stack
	 *  @pre  None
	 *  @post  If this stack is not empty, stackTop contains the item that was added
	 *            most recently. However, if this stack is empty, the operation fails and
	 *            stackTop is unchanged. This stack is unchanged
	 *  @throw  StackException    If this stack is empty */
	void getTop(StackItemType& stackTop) const throw(StackException);

private:
	StackItemType items[MAX_STACK];  // Array of stack items
	int	top;	// Index to top of stack
}; // end Stack
// End header file

