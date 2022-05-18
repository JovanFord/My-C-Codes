#include <iostream>
#include "Student.h"
using namespace std;


int main() {
  	node *head = NULL;
	node *last = NULL;
	char choice = 0;
	string name;
	int age;
	string newName;
	int newAge;

	while(choice != 5){
		choice = menu();

		if(choice == '1'){
			cout << "Please enter a name: ";
			cin >> name;
			cout << "Please enter an age: ";
			cin >> age;
			
			insert(head, last, name, age);
		}
		else if(choice == '2'){
			remove(head, last); 
		}
		else if(choice == '3'){
			cout << "Which student would you like to update? \nName: ";
			cin >> name;
			cout << "Age: ";
			cin >> age;
			cout << "What is the new name?: ";
			cin >> newName;
			cout << "What is the new age?: ";
			cin >> newAge;
			update(head, name, age, newName, newAge);
		}
		else if (choice == '4'){
			showList(head); 
		}
		else if (choice == '5'){
			break;
		}
		cout << endl;
		
		choice = 0;
	}
	
}