#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
using namespace std;
class Rectangle{
private:
    int width;
    int length;
public:
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