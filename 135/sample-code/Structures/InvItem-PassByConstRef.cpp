#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//creates the struct data type Inv Item
struct InvItem
{
   int partNum;
   string description;
   int onHand;  //number of units on hand
   double price;
};
   
//function prototype, passes InvItem by ref to populate struct with data
void getItem(InvItem&);

//function prototype, passes InvItem by constant reference to print out its data
void showItem(const InvItem&);

int main()
{

  InvItem firstPart;
  getItem(firstPart);//function call to pass by reference function
  
  showItem(firstPart);//function call to pass by value function
  
  system("PAUSE");
  return 0; 
}

void getItem(InvItem& piece)  
{
   cout << "Enter the Part Number: ";
   cin >> piece.partNum;   
   cout << "Enter the Part Description: ";
   cin >> piece.description;
   cout << "Enter the quantity on hand: ";
   cin >> piece.onHand;
   cout << "Enter price per part: ";
   cin >> piece.price;      
}

void showItem(const InvItem& piece)//pass arg to parameter by const reference
{
   cout << setiosflags(ios::fixed) << setprecision(2) << endl;
   cout << "Part Number:          " << piece.partNum << endl;
   cout << "Part Description:     " << piece.description << endl;
   cout << "Quantity on Hand:     " << piece.onHand << endl;
   cout << "Price Per Part:       " << piece.price << endl;
}
