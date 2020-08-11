//Luis Guzman
//David Ortiz

#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(){
	length = 1.0;
	width = 1.0;
}
Rectangle::Rectangle(double l, double w){
	if(l >= 0){
		length = l;
	}
	else 
		length = 0;
	if(w >= 0){
		width = w;
	}
	else
		width = 0;
}

bool Rectangle::setLength(double l){
	bool valid;

		if(l >= 0){
		length = l;
		valid = true;
		}
	
		else{
		valid = false;
		}

		return valid;
}

bool Rectangle::setWidth(double w){
	bool valid;

		if(w >= 0){
		width = w;
		valid = true;
		}
	
		else{
		valid = false;
		}

		return valid;
}

double Rectangle::getLength(){
	return length;
}

double Rectangle::getWidth(){
	return width;
}

double Rectangle::getArea(){
	return (length * width);
}

bool Rectangle::areEqual(const Rectangle& r){
	if(r.getLength() == getLength() && r.getWidth() == getWidth()){
	cout << "The rectangles are equal." << endl;
	return true;
	}
	else{
	cout << "They're not equal" << endl;
	return false;
	}
}

Rectangle Rectangle::combinedRectangle(const Rectangle& r){
	Rectangle bos;
	bos.setLength(getLength() + r.getLength());
	bos.setWidth(getWidth() + r.getWidth());
	return bos;
}