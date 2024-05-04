#include <iostream>
using namespace std;

int main()
{
 //declare and initialize variables
 int a = 12; 
 int b = 2; 
 int i = 15; 
 int j = 30; 
 int complete = 0;
 
 cout << "(i == j) || (a < b) || complete is " 
      << ((i == j) || (a < b) || complete) << endl;
      
  cout << "\ni == j || a < b || complete is " 
      << (i == j || a < b || complete) << endl;
 
 system("PAUSE");
 return 0;
}
