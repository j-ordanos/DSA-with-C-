#include <iostream>
using namespace std;

struct studentNode {
    int id;
    string name;
    studentNode* next;
};

void display(studentNode* head) {
    studentNode* temp = head;
    if (head == NULL) {  
        cout << "List is empty" << endl;
        return;
    }
    do {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;  // Display current node's data
        temp = temp->next;  
    } while (temp != head);  // Loop until back at the head node
}

int main() {
    int num;
    cout << "Enter number of students: ";
    cin >> num;

    studentNode* head = NULL;
    studentNode* current = NULL;

    cout << "Entering data..." << endl;
    for (int i = 0; i < num; i++) {
        studentNode* newNode = new studentNode();  // Allocate memory for a new node
        cout << "Student " << i + 1 << endl;
        cout << "Id: ";
        cin >> newNode->id;
        cout << "Name: ";
        cin >> newNode->name;
        newNode->next = NULL;

        if (head == NULL) {  // If list is empty, initialize head
            head = current = newNode;
        } else {
            current->next = newNode;  // Link current node to the new node
            current = newNode;  // Update current to the new node
        }
    }
    current->next = head;  // Make the list circular by linking last node to head

    cout << "\nDisplaying the list..." << endl;
    display(head);  // Display the circular linked list

    return 0;
}
