#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   cout << fixed << setprecision(2)
        << setw(6) << 6.1 << endl
        << setw(6) << 18.2 << endl
        << setw(6) << 124.0 << endl
        << "------\n"
        << 6.1+18.2+124<< endl;

   system("PAUSE");
   return 0;
}
