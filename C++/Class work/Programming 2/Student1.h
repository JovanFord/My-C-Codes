#include <iostream>
#include <string>
#include <array>
#ifndef STUDENT1_H
#define STUDENT1_H

using namespace std;

/*
Next create the following four methods

setdata – sets the name and gender of the student. It also updates the static variable 
males and females with the total current number of males and females.



*/

class Student{
private:
//member variables
    string name;
    string gender;
public:
//static variables
    static int males;
    static int females;
//method to set name, gender, and update static variables male & female
    void setdata(string name_, string gender_){
        name = name_;
        gender = gender_;
        if (gender == "male"){
            males++;
        }
        if(gender == "female"){
            females++;
        }
    }
    string getname(){
        return name;
    }
    string getgender(){
        return gender;
    }
    int numofmales(){
        return males;
    }
    int numofemales(){
        return females;
    }
};

#endif