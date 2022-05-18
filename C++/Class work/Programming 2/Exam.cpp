#include <iostream>
#include <string>
#include "Rectangle1.h"
#include "Square.h"
/*
In the main function
Create an instance of the square class.
Use the set method from the square class to set the side of the square instance to the value of 23.
Print out the area, side length, and perimeter of the square instance.

Dos and Don’ts
Don’t use inline functions.
Use function prototype.
Use separate files for the classes and main function.
Write a full C++ problem with appropriate headers
*/
using namespace std;
int main(){
    Square s;
	s.setLength(23);
    cout << "Area: " << s.getArea() << endl;
    cout << "Side Length: " << s.getLength() << endl;
    cout << "Perimiter: " << s.getPerimeter() << endl;
}