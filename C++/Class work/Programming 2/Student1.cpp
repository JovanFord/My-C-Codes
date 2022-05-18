#include <iostream>
#include <string>
#include <array>
#include "Student1.h"

using namespace std;

/*
getdata – returns a student pointer of an array of student instances. 
Takes as input an int of how many student instances to create for the array. 
This method also sets the data for each instance in the array by asking the user for that information.

printdata – takes an input a student pointer and int of how student instances are in the array. 
Prints in separate lists the name of the male students and female students. 
*/

int Student :: males = 0;
int Student :: females = 0;

int main(){
    Student s;
    int size;
    cout << "How many students would you like?: ";
	cin >> size;
	Student* slist = getdata(size);

	cout << "There are " << s.numofmales() << " male students." << endl;
	cout << "There are " << s.numofemales() << " female students." << endl;

	printData(slist, size);

	delete [] slist;
}

Student* getdata(int size){
	Student* temp = new Student[size];
	string name, gender;
	
	for(int i = 0; i < size; i++){
		cout << "Enter student name: ";
		cin >> name;
		cout << "Enter student gender (male or female): ";
		cin >> gender; 
		(temp + i) -> setdata(name, gender);
	}
	return temp;
}

void printData(Student* temp, int size){
	cout << "Male Students: " << endl;
	for(int i = 0; i < size; i++){
		if((temp + i)-> getgender() == "male"){
			cout << (temp + i) -> getname() << endl;
		}
	}
	cout << "Female Students: " << endl;
	for(int i = 0; i < size; i++){
		if((temp + i)-> getgender() == "female"){
			cout << (temp + i) -> getname() << endl;
		}
	}
}