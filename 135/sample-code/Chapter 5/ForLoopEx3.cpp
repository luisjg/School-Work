#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int MAXNUMS = 10;
    
    //print the number, it's square and its cube, 1 up thru MAXNUMS
    cout << endl;
    cout << "NUMBER   SQUARE   CUBE" << endl;
    cout << "------   ------   ----" << endl;
    
    for(int num = 1; num <= MAXNUMS; num++)
    {
       cout << setw(3) << num << "     " 
            << setw(4) << num * num << "     "
            << setw(4) << num * num * num << endl;
    }
    
    system("PAUSE");        
    return 0;
}
