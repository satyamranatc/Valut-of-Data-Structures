// Singly Linked List - Addition (C++)
// This program demonstrates how to add (insert) nodes in a singly linked list.
// We'll insert at the head and at the tail, then print the result.

#include <iostream>
using namespace std;

// Node represents an element with data and a pointer to the next node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// insertAtHead adds a new node before the current head and returns the new head
Node* insertAtHead(Node* head, int value) {
    Node* newNode = new Node(value); // create the new node
    newNode->next = head;            // link new node to the old head
    return newNode;                  // new node becomes the new head
}

// insertAtTail adds a new node at the end of the list
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) { // empty list: new node is the head
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) { // move to the last node
        current = current->next;
    }
    current->next = newNode; // attach new node at the end
}

// traverse prints all elements in the list
void traverse(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    // Start with a small list: 20 -> 30
    Node* head = nullptr;
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    cout << "Initial list: ";
    traverse(head);

    // Add at head: insert 10 at the front -> 10 -> 20 -> 30
    head = insertAtHead(head, 10);
    cout << "After insertAtHead(10): ";
    traverse(head);

    // Add at tail: insert 40 at the end -> 10 -> 20 -> 30 -> 40
    insertAtTail(head, 40);
    cout << "After insertAtTail(40): ";
    traverse(head);

    // Cleanup memory
    Node* cur = head;
    while (cur != nullptr) {
        Node* toDelete = cur;
        cur = cur->next;
        delete toDelete;
    }
    return 0;
}


