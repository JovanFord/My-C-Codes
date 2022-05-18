#include <iostream>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

struct node{
	string name;
	int age;
	node *next;
};

char menu(){
		char choice;

		cout << "Welcome! Here is our menu: " << endl;
		cout << "1. Add a Student" << endl;
		cout << "2. Remove a Student" << endl;
		cout << "3. Update a Student's Info" << endl;
		cout << "4. Show all Students" << endl;
		cout << "5. Exit" << endl;

		cin >> choice;

		return choice;
}

bool isEmpty(node *head){
		if(head == NULL)
			return true;
		else
			return false;
	}

void insertAsFirstElement(node *&head, node *&last, string name, int age){
		node *temp = new node;
		temp->name = name;
		temp->age = age;
		temp->next = NULL;
		head = temp;
		last = temp;
	}

void insert(node *&head, node*&last, string name, int age){
		if(isEmpty(head))
			insertAsFirstElement(head, last, name, age);
		else{
			node *temp = new node;
			temp->name = name;
			temp->age = age;
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
	}

void update(node *&head, string n, int a, string newN, int newA){
	node *current = head;
	while(current != NULL){
		if(current->name == n && current->age == a){		
			current->name = newN;
			current->age = newA;
    }
		current = current->next;
	}
}

void remove(node *&head, node*&last){
		if(isEmpty(head)){
			cout << "This list is already empty!\n";
		}
		else if (head == last){
			delete head;
			head = NULL;
			last = NULL;
		}
		else{
			node *temp = last;
			last = last->next;
			delete temp;
		}
	}

void showList(node *current){
		if(isEmpty(current)){
			cout << "This list is empty!\n";
		} 
    else{
			cout << "The students are: \n";
			while(current != NULL){
				cout << "Name: " << current->name << ", Age: " << current->age << endl;
				current = current->next;
			}
		}
	}

#endif