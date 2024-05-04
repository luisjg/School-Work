#ifndef RECTANGLE1_H

//Rectangle Class Declaration
class Rectangle
{
   private:                 //make the attributes private
     double length;
     double width;

   public:                 //function prototypes
     bool setLength(double);
     bool setWidth(double);
     double getLength()const;
     double getWidth()const;
     double getArea()const;
};

#endif
