//Luis Guzman
//David Ortiz

#include<iostream>
#include "Rectangle.h"
using namespace std;

int main(){
Rectangle box(2.0, 5.0);

Rectangle box2(2.0, 5.0);

Rectangle box3;

Rectangle box4(box);

box.areEqual(box2);
box.areEqual(box3);

system("PAUSE");
return 0;
}