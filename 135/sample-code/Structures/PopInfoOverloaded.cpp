#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/*The struct - Defines the PopInfo data type*/
struct PopInfo  //declare struct to hold city name and population info
{
  string cityName;
  long population;

  //constructor with 2 parameters and one default value
  PopInfo(string n, long p = 0)  
  {
     cityName = n;
     population = p;
  }
  
  PopInfo(long p)  //c
  {
    cityName = "Unnamed";
    population = p;
  }
  
  PopInfo()
  {
    cityName = "Unnamed";
    population = 0;
  }
};

int main()
{
   //creates three variables of the PopInfo Data Type
   PopInfo city1("Fremont", 50000);
   PopInfo city2("Lancaster", 30302);
   PopInfo city3;     //the default constructor values are used

   //display the data
   cout << city1.cityName << " has a population of " << city1.population << endl;
   cout << city2.cityName << " has a population of " << city2.population << endl;
   cout << city3.cityName << " has a population of " << city3.population << endl;

   system("PAUSE");
   return 0;
}
