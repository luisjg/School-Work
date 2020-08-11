#pragma once

/** @file QueueA.h */

#include "QueueException.h"
const int MAX_QUEUE = 50 /* <- maximum-sie-of-queue */;
typedef char /* <- desired-type-of-queue-item */ QueueItemType;

/** ADT queue - Array-based implementation */
class Queue
{
public:
// constructors and destructor:
   Queue();  // default constructor
   // copy constructor and destructor are supplied by the compiler
   // note: if you dynamically allocate the array, then supply a destructor

// Queue operations:
   bool isEmpty() const;
   void enqueue(const QueueItemType& newItem) throw(QueueException);
   void dequeue() throw(QueueException);
   void dequeue(QueueItemType& queueFront) throw(QueueException);
   void getFront(QueueItemType& queueFront) const throw(QueueException);

private:
   QueueItemType items[MAX_QUEUE];
   int           front;
   int           back;
   int           count;
}; // end Queue
// end of header file

