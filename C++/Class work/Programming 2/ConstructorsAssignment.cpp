#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

/*
Create a class called Student. 
This class will hold the first name, last name, and test grades for a student. 
Use separate files to create the class (.h and .cpp)
This is to be a default constructor
It takes as input the first and last name, and the number of grades.
It sets the name variables and the integer variable for the size
It allocates memory for the grades array based on the number of grades passed in
*/



int main() {
    string first_name;
    string last_name; 
    int numgrades; 

    cout << "Enter first name of student " << endl;;
    cin >> first_name;
    cout << "\nEnter last name of student " << endl; 
    cin >> last_name;
    string fullName = first_name + " " + last_name;
    cout << "\nEnter number of grades for " << fullName << endl; 
    cin >> numgrades;

    Student student(first_name, last_name, numgrades);
    cout << "\nEnter the grades of " << fullName << endl;
    float grade;
    for (int i = 0; i < numgrades; i++){
        cin >> grade;
        student.setGrade(grade, i);
    }
    cout << endl << fullName << "'s grades are: " << endl;
    for (int i = 0; i < numgrades; i++){
        cout << student.getGrade(i) << endl;
    }
    
    cout << fullName <<"'s average grade is: " << student.getAvg();
}