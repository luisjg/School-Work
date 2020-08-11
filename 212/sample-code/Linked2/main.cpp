#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
  LinkedList list;
  string file = "list.txt";
  list.readFile(file);
  int val;
  cout << "Enter number or press 0 to quit: ";
  cin >> val;

  while (val != 0)
  {
    list.insert(val);
    cout << "Enter number or press 0 to quit: ";
    cin >> val;
  }

  list.print();
  cout << "\nNumber to remove: ";
  cin >> val;
  list.remove(val);
  list.print();
  list.retrieve(2, val);
  cout << "Index 2 is: " << val << endl;
  list.writeFile(file);
  system("pause");
  return 0;
}
