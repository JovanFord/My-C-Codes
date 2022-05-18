#include <iostream>

using namespace std;

class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;
public: 
    Employee(string, int, string, string);
    Employee(string, int);
	Employee();

    void setName(string na)
		{ name = na; }
	void setID(int id)
		{	idNumber = id; }
	void setPos(string pos)
		{ position = pos; }
	void setDep(string dep)
		{ department = dep; }

	string getName() const
		{ return name; }
	int getID() const
		{ return idNumber; }
	string getDep() const
		{ return department; }
	string getPos() const
		{ return position; }
};

void displayEmployee(Employee);

int main(){
    Employee a("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee b("Mark Jones", 39119, "IT", "Programmer");
	Employee c("Joy Rogers", 81774, "Manufacturing", "Engineer");
	displayEmployee(a);
	displayEmployee(b);
	displayEmployee(c);
}

Employee :: Employee(string na, int id, string dep, string pos){
		name = na;
		idNumber = id;
		department = dep;
		position = pos;
	}
	Employee :: Employee(string na, int id){
		name = na;
		idNumber = id;
		department = "";
		position = "";
	}
	Employee :: Employee(){
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}

void displayEmployee(Employee e){
	cout << "Name: " << e.getName() << endl;
	cout << "ID Number: " << e.getID() << endl;
	cout << "Department: " << e.getDep() << endl;
	cout << "Position: " << e.getPos() << endl << endl;
}