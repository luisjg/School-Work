#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   const int NUM_TEMPS = 7;
   double temps[NUM_TEMPS] = {90.5, 80.7, 79.9, 75.2, 100};

   double ave;  //to store the value of an average temperature
   int numAboveAve = 0;  ///to store how many temps are above average
   
   do
   {
     cout << "What is the average temperature?";
     cin >> ave;
     
     if(ave <= 0)
       cout << "Please enter a temperature > 0";
   }while(ave <= 0);

    cout << "\nABOVE AVERAGE TEMPS: ";
   //loop print temperatures that are above average
   for(int count = 0; count < NUM_TEMPS; count++)
   {
       if(temps[count] > ave)
       {
           cout <<  temps[count] << " ";
           numAboveAve++;  //counting number of temps that were above average
       }
   }
   cout << "\nNUMBER OF TEMPS ABOVE AVERAGE: " << numAboveAve << endl << endl;

   system("PAUSE");
   return 0;
}
