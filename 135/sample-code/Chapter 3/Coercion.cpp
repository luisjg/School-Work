#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    double y;
    
    x = 25.75;
    y = 5;
    
    cout << "The value 25.75 was coerced to the integer value " << x << endl;
    cout << fixed << setprecision(2) 
         << "The value 5 was coerced to the double value " << y << endl;

    
    system("PAUSE");
    return 0;
}
