#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // növbəti node-a göstərici
};

int main() {
    Node* head = new Node(); 
    
    head->next = new Node(); 
    head->next->data = 10;
    head->next->next = NULL; 
    
    Node* temp = head;

  
    cout << "Node List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next; 
    }
    cout << "NULL" << endl;

    return 0;
}