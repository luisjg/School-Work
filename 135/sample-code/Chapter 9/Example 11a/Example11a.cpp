#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
   double *sales;  //a pointer to a double - we'll use it to point to our dynamically allocated memory
   double total = 0;
   double average;
   int numDays, count;

   cout << "How many days to you wish to process sales figures for?" << endl;
   cin >> numDays;  //this is how big we want our array to be – unknown until runtime
   sales = new double[numDays];   //dynamically allocate memory for the array of the user input size

   //now get the sales figures from the user
   cout << "You will enter the sales figures for each day below:" << endl;
   for(int i = 0; i < numDays; i++)
   {
       cout << "Day " << (i + 1) << ": ";
	cin >> sales[i];
   }

   //calculate total sales
   for(int i = 0; i < numDays; i++)
   {
	   total = total + sales[i];
   }

   average = total/numDays;

   cout <<fixed << setprecision(2) << "\nTotal Sales = " << total << "\nAverage Sales =  "<< average << endl;
   delete [] sales;  //don't forget to free the dynamically allocated memory
   
   system("PAUSE");
   return 0;
}
