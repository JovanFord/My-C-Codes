#include <iostream>
#include "grades.h"
#include "student2.h"

using namespace std;

int main(){
  student g;
  int n,age;
  float temp;
	string name;

  cout << "Enter amount of grades: ";
  cin >> n;

  g.setarraynum(n);
  for(int i = 0; i < n; i++){
    cout << "Enter grade number " << (i + 1) << ": ";
		cin >> temp;
		g.setgrade(temp, i);
  }
	
	g.setStuName();
	g.setStuAge();

	cout << "Name: " << g.getStuName() << endl;
	cout << "Age: " << g.getStuAge() << endl;
	cout << "Grades:" << endl;
	g.printall();
}