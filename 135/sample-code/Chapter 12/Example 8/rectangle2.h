#ifndef RECTANGLE2_H

//Rectangle Class Declaration
class Rectangle
{
   private:                 //make the attributes private
     double length;
     double width;

   public:                 //function prototypes
     Rectangle();          //default constructor
     Rectangle(double, double); //constructor that takes two parameters
     bool setLength(double);
     bool setWidth(double);
     double getLength();
     double getWidth();
     double getArea();
};

#endif
