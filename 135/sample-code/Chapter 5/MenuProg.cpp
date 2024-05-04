#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char selection;
    int numMilky = 0;
    int numSnick = 0;
    int numSkit = 0;
    int numStar = 0;
    
    do
    {
          cout << endl;
          cout<< "CANDY MACHINE MENU" << endl;
          cout << "a) Milky Way" << endl;
          cout << "b) Snickers" << endl;
          cout << "c) Skittles"  << endl;
          cout << "d) Starburst" << endl;
          cout << "p) Print Daily Report" << endl;
          cout << "q) Quit Program" << endl;
          cout << "Please enter your selection: ";
          cin >> selection;
          
          //you could also use a switch statement here
          if(selection == 'a')
          {
             numMilky++;
             cout << "A Milky Way was purchased" << endl;          
          }
          
          else if(selection == 'b')
          {
             numSnick++;
             cout << "A Snickers was purchased" << endl;     
          }
          
          else if(selection == 'c')
          {
             numSkit++;
             cout << "A bag of Skittles was purchased" << endl;     
          }
          
          else if(selection == 'd')
          {
             numStar++;
             cout << "A package of Starburst was purchased" << endl;     
          }
          
          else if(selection == 'p')
          {
             cout << endl;
             cout << "STATISTICS REPORT" << endl << endl;
             cout <<"CANDY          \t" << setw(15) << "Number Sold" << endl;
             cout <<"---------------\t" << setw(15) << "-----------" << endl;
             cout << "Milky Way\t" << setw(15) << numMilky << endl;
             cout << "Snickers\t" << setw(15) << numSnick << endl;
             cout << "Skittles\t" << setw(15) << numSkit << endl;
             cout << "Starburst\t" << setw(15) << numStar << endl;
          }
          
          else if(selection != 'q')
          {
             cout << "INVALID SELECTION" << endl;
          }
          
    }while(selection != 'q');
    
    
    system("PAUSE");
    return 0;
}
