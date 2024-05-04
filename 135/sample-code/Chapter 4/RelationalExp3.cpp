#include <iostream>
using namespace std;

int main()
{
 //declare and initialize variables
 int x = 10;
 int y = 7;
 bool z;
 
 z = x < y;
 cout << "\nIn (z = x < y;) z is " << z 
      << " because x is NOT less than y" << endl;
 
 //Notice the parenthesis, prints 1 for true
 cout << "\n(x > y) evaluates to " << (x > y) << endl;  
 
 //notice the precedence of the addition operator over the relational op
 cout << "\n( x == y + 3 ) evaluates to " << (x == y + 3) << endl;
 
 //Notice the precedence of the relational op over the assignment op
 cout << "\n(z = y != x) is " << (z = y !=x) << endl;
 
 system("PAUSE");
 return 0;
}
