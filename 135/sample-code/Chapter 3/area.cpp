#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double length;
    double width;
    double area;
    
    length = 27.2;
    width = 13.6;
    area = length * width;
    
    cout << fixed << setprecision(2);
    cout << "The length of the rectangle is " << setw(6) << length << endl;
    cout << "The width of the rectangle is  " << setw(6) << width << endl;
    cout << "The area of the rectangle is   " << setw(6) << area << endl;
    
    system("PAUSE");
    return 0;
}
