#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

struct AnnualCostInfo
{
  float food;
  float medical;
  float license;
  float misc;
};

struct PetInfo
{
  string name;
  string type;
  int age;
  AnnualCostInfo cost;
};

int main()
{
   PetInfo pet;   //define a structure variable
   pet.name = "Sassy";
   pet.type = "cat";
   pet.age = 5;
   pet.cost.food = 250.00;
   pet.cost.medical = 150.00;
   pet.cost.license = 7.00;
   pet.cost.misc = 50.00;

   cout << setiosflags(ios::fixed) << setprecision(2)
        << "Annual costs for my " << pet.age << " year old "
        << pet.type << " " << pet.name << " are $"
        << (pet.cost.food + pet.cost.medical + pet.cost. license +
            pet.cost.misc) << endl;

   system("PAUSE");
   return 0;
}
