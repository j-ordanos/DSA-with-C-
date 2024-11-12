#include <iostream>
using namespace std;

struct StudentNode {
    int id;
    string name;
    StudentNode* next;
};

// Function to display the list of students
void displayList(StudentNode* head){
	StudentNode* current = head;
	while (current != NULL) {
        cout << "ID: " << current->id << ", Name: " << current->name << endl;
        current = current->next; 
    }
}
   
// Function to insert a new node at a given position
void insertNode(StudentNode*& head, int position){
	StudentNode* newNode = new StudentNode();
	cout << "Enter new student details:"<<endl;
	cout << "Id: ";
	cin >> newNode->id;
	cout << "Name: ";
	cin >> newNode->name;
	newNode->next = NULL;
	
	if(position == 0){  // Insert at the beginning
		newNode->next = head;
		head = newNode;
	}
	else if(position == -1){  // Insert at the end
		StudentNode* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	else{  // Insert at a specific position
		StudentNode* temp = head;
		int currentPos = 1;
		while(temp != NULL && currentPos < position -1){
			temp = temp->next;
			currentPos++;
		} 
		if(temp == NULL){
			cout << "Position out of range!!"<<endl;
		}else{
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}    

int main() {
    int num;
    cout << "Enter the number of students: ";
    cin >> num;

    StudentNode* head= NULL;
	StudentNode* current = NULL; 

    cout << "Entering data..." << endl;
    
    // Loop to create initial list of students
    for (int i = 0; i < num; i++) {
        StudentNode* newNode = new StudentNode();
        cout << "Student " << (i + 1) << endl;
        cout << "Id: ";
        cin >> newNode->id;
        cout << "Name: ";
        cin >> newNode->name;
        newNode->next = NULL;  

        if (head == NULL) {  // First node becomes the head
            head = newNode;
        } else {  // Link new node to the end of the list
            current->next = newNode;
        }
        current = newNode;
    }
    
    cout << "\nBefore:" << endl;
    displayList(head);
    
    // Choose insertion position
    int choice, position;
    cout << "\nWhere do you want to insert the new student?"<<endl;
    cout << "1. At the beginning"<<endl;
    cout << "2. At the end" << endl;
    cout << "3. At specific position"<< endl;
    cout << "Choice: ";
    cin >> choice;
    
    if(choice == 1){  // Insert at beginning
    	insertNode(head,0);
	}
	else if(choice == 2){  // Insert at end
		insertNode(head,-1);
	}
	else if(choice == 3){  // Insert at a specific position
		cout << "Enter the position: ";
		cin >> position;
		insertNode(head,position);
	}
	else{
		cout << "Invalid choice!" << endl;
	}
	cout << "\nUpdated List"<<endl;
	displayList(head);
    
    return 0;
}

