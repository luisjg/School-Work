//Luis Guzman
//David Ortiz

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{

	private:

	double length;
	double width;

	public:

	Rectangle();
	Rectangle(double, double);
	double getArea();
	
	double getLength();
	double getWidth();
	
	bool setWidth(double);
	bool setLength(double);

	bool areEqual(const Rectangle&);

	/*
	 *
	 * 
	 *
	 */
	Rectangle combinedRectangle(const Rectangle&);
};

#endif