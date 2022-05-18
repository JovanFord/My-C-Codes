#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <string>
#include "Rectangle1.h"
/*
Create a derived class called square that has a public inheritance from the rectangle class. It has the following two public methods

A redefined method called "set" that takes one integer input for the length of the square. 
This input is used to set the length and width variables from the parent class to the same value.
A constant method that returns the perimeter of the square.
*/
using namespace std;

class Square : public Rectangle{
private:
    int width;
	int length;

public:
	int getPerimeter() const{
		return (length*4);
	}
    void setWidth(int width_){
        width = width_;
    }
    void setLength(int length_){
        length = length_;
    }
    int getArea(){
        return (length * width);
    }
    int getWidth(){
        return width;
    }
    int getLength(){
        return length;
    }
};
#endif