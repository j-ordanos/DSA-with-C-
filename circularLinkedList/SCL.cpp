#include <iostream>
using namespace std;

struct studentNode{
	int id;
	string name;
	studentNode* next;
};

void display(studentNode* head){
	studentNode* temp = head;
	if(head == NULL){
		cout << "List is empty"<<endl;
		return;
	}
	do{
		cout << "ID: "<<temp->id<<" "<<"Name: "<<temp->name<<endl;
		temp = temp->next;	
	}while(temp != head);
}

int main(){
	int num;
	cout << "Enter number of students: ";
	cin >> num;
	
	studentNode* head = NULL;
	studentNode* current = NULL;
	
	cout << "Entering data..."<<endl;
	for(int i=0; i < num; i++){
		studentNode* newNode = new studentNode();
		cout << "Student "<<i+1<<endl;
		cout << "Id: ";
		cin >> newNode->id;
		cout << "Name: ";
		cin >> newNode->name;
		newNode->next = NULL;
		
		if(head == NULL){
			head = current = newNode;
		}else{
			current->next = newNode;
			current = newNode;	
		}
	}
		current->next = head;
		
	cout << "\nBefore:"<<endl;
	display(head);
}
