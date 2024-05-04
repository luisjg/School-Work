#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Circle
{
   private:
     double radius;

   public:
      void setRadius(double r)
      {
         if(r > 0)
            radius = r;
         else
            radius = 0;
      }

      double getRadius()
      {
        return radius;
      }

      double getArea()
      {
         return 3.141592 * pow(radius,2);
      }
};

int main()
{
   Circle circ1;
   Circle circ2;

   circ1.setRadius(1);
   circ2.setRadius(2.5);

   cout << "The radius of circ1 is " << circ1.getRadius() << endl;
   cout << "The radius of circ2 is " << circ2.getRadius() << endl;

   system("PAUSE");
   return 0;
}
