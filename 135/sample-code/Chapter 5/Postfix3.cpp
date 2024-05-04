#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    int number;
    number = 6 * x++;
    
    cout << "Postfix Assignment and Mult Example" << endl;   
    cout << "number = " << number << endl;
      
    system("PAUSE");
    return 0;
}
