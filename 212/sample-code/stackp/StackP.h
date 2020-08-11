#pragma once

/** @file StackP.h */
#include "StackException.h"
typedef char /* <-desired-type-of-stack-item */ StackItemType;

/** ADT stack --  Pointer-based implementation */
class Stack
{
public:
  // Constructors and destructor:
  /** Default constructor
   * @param None */
  Stack();
  /** Copy constructor
   * @param aStack The stack to copy */
  Stack(const Stack& aStack) throw(StackException);

  /** Destructor */
  ~Stack();
  // Stack operations:
  bool isEmpty() const;
  void push(const StackItemType& newItem) throw(StackException);
  void pop() throw(StackException);
  void pop(StackItemType& stackTop) throw(StackException);
  void getTop(StackItemType& stackTop) const throw(StackException);

private:
  struct StackNode // A node on the stack
  {
    StackItemType item; // A data item on the stack
    StackNode *next; // Pointer to next node
  }; // end StackNode
  StackNode *topPtr; // Pointer to first node in the stack
}; // end Stack
 // End of header file

