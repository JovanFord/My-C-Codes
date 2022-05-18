#include <iostream>
#include "grades.h"

using namespace std;

class student : public grades{

private:
  string name;
  int age;
public:
  void setStuName(){
    cout << "Enter Student's name: ";
    cin >> name;
  }
  void setStuAge(){
    cout << "Enter students age: ";
    cin >> age;
  }
string getStuName(){
  return name;
}
int getStuAge(){
  return age;
}
};
