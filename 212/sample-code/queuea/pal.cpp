#include <iostream>
#include "QueueA.h"
#include "StackA.h"
using namespace std;

int main()
{
  Stack aStack;
  Queue aQueue;

  string str;

  cout << "Please enter a sentence to see if it is a palindrome (will remove blanks)\n";
  getline(cin, str);

  char nextChar;
  char *cstr = new char[str.length()+1];
  strcpy(cstr, str.c_str());
  for (int i=0; i < str.length(); i++)
  {
    nextChar = cstr[i]; // get the ith character of str
    if (nextChar == ' ')
      continue; // skip it if it is a blank
    aQueue.enqueue(nextChar);
    aStack.push(nextChar);
  } // end for

  // compare the queue characters with the stack characters
  bool charactersAreEqual = true;
  char queueFront, stackTop;
  while (!aQueue.isEmpty() && charactersAreEqual)
  {  aQueue.getFront(queueFront);
     aStack.getTop(stackTop);

     if(queueFront == stackTop)
     {  aQueue.dequeue();
        aStack.pop();
     }
     else
       charactersAreEqual = false;
  } // end while

  if (charactersAreEqual)
    cout << str << " is a palindrome\n";
  else
    cout << str << " is not a palindrome\n";

  return 0;
}

