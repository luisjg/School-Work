//David Ortiz
//Luis Guzman

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <istream>
using namespace std;

template <class T>
class Rectangle
{
    //overloaded << and >>  (should be simple since template is the same for all
    // numeric types)
	template <class T>
    friend ostream &operator<<(ostream&, const Rectangle<T>&);
    template <class T>
	friend istream &operator>>(istream&, Rectangle<T>&); 
    
    private:
		T width;
        T length;
    
	public:
		Rectangle();  //sets length and width to 0
		Rectangle(T, T);
        T getWidth()const;
        T getLength()const;
        bool setWidth(T w);
        bool setLength(T l);
        T calcArea()const;
        T calcPerimeter()const;
};

template <class T>
Rectangle<T>::Rectangle(T len, T w)
{
	if(setLength(len) == false)
	{
		length = 1;
	}

	if(setWidth(w) == false)
	{
		width = 1;
	}
}

template <class T>
bool Rectangle<T>::setLength(T len)
{
	if(len >= 0)
	{
		length = len;
		return true;
	}
	
	return false;
}

template <class T>
bool Rectangle<T>::setWidth(T w)
{
	if(w >= 0)
	{
		width = w;
		return true;
	}
	
	return false;
}

template <class T>
T Rectangle<T>::getLength()const
{
	return length;
}

template <class T>
T Rectangle<T>::getWidth()const
{
	return width;
}

template <class T>
T Rectangle<T>::calcArea()const
{
	return (getLength() * getWidth());
}

template <class T>
T Rectangle<T>::calcPerimeter()const
{
	return (2 * getLength()) + (2 * getWidth());
}

template <class T>
ostream& operator<<(ostream &output, Rectangle<T> &obj)
{
	output << "Length: " << obj.getLength() << " Width: " << obj.getWidth() << endl
		<< "Area: " << obj.calcArea() << " Perimeter: " << obj.calcPerimeter();
	return output;
}

template <class T>
istream& operator>>(istream &input, Rectangle<T> &obj)
{
//we used the private members instead of the 
//initializer function because setLength and setWidth are bools
	cout << "Enter length: ";
	input >> obj.length;

	cout << "Enter width: ";
	input >> obj.width;

	return input;
}

#endif