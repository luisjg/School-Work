#include <iostream>
using namespace std;

/*This program tests whether a car is over the mileage limit to be covered
by a warranty*/
int main()
{
   const double LIMIT = 3000.0;
   
   int idNum;
   double miles;
   
   cout << "Please type in the car number followed by the mileage:";
   cin >> idNum >> miles;
   
   //one way if
   if(miles > LIMIT)
   {
      cout << "Car Number " << idNum << " is over the mileage limit." << endl;
   }       
   
   cout << "End of program output." << endl;

   system("PAUSE");
   return 0;
}
