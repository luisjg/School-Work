#ifndef RECTANGLE_H

//Rectangle Class Declaration
class Rectangle
{
   private:                 //make the attributes private
     double length;
     double width;

   public:                 //function prototypes
     Rectangle(double, double);
     bool setLength(double);
     bool setWidth(double);
     double getLength();
     double getWidth();
     double getArea();
};

#endif
