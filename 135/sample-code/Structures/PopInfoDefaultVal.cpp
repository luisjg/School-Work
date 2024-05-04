#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct PopInfo  //declare struct to hold city name and population info
{
  string cityName;
  long population;

  PopInfo(string n = "Unnamed", long p = 0)  //constructor with 2 parameters & DEFAULT VALUES
  {
     cityName = n;
     population = p;
  }
  
};


int main()
{
   PopInfo city1("Fremont", 50000);
   PopInfo city2("Lancaster", 30302);
   PopInfo city3;     //the default constructor values are used

   //print data
   cout << city1.cityName << " has a population of " << city1.population << endl;
   cout << city2.cityName << " has a population of " << city2.population << endl;
   cout << city3.cityName << " has a population of " << city3.population << endl;

   system("PAUSE");
   return 0;
}
