#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
  LinkedList list;
  int val;
  cout << "Enter number: ";
  cin >> val;

  do
  {
    list.insert(val);
    cout << "Enter number: ";
    cin >> val;
  } while (val != 0);

  list.print();
  cout << "number to remove: ";
  cin >> val;
  list.remove(val);
  list.print();
  list.retrieve(2, val);
  cout << "Index 2 is: " << val << endl;
  return 0;
}
