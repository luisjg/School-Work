#include <iostream>
using namespace std;

int main()
{
  int total = 0;
  int tempNum;      //to hold each individual number
                     //before it gets added to total
  int numberToAdd;  //the number of ints the user will enter that the  
                    //program will add

  cout << "How many numbers would you like to add together?";
  cin  >> numberToAdd;

  for(int i = 0; i < numberToAdd; i++)
  {
     cout << "enter a number:";
     cin >> tempNum;

     total = total + tempNum;  //so you are keeping a running  
                                           //total.  this is what you want  
                                           //to do for the number of rooms  
                                           //and number of occupied rooms
  }
  cout << "The sum of the numbers is \n" << total << endl;
  //in your program you should do your division only once right here

  system("PAUSE");
  return 0;
}
