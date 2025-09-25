// Singly Linked List - Traversing (C++)
// This program demonstrates how to traverse a singly linked list.
// A Node stores data and a pointer to the next Node.

#include <iostream>
using namespace std;

// Node represents a single element in the singly linked list.
// It has two parts:
// 1) data: the value stored in this node
// 2) next: a pointer to the next node in the list (or nullptr if this is the last node)
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// traverse prints all node values from head to end.
// We move a temporary pointer step-by-step using the next pointers.
void traverse(Node* head) {
    Node* current = head; // start at the first node
    while (current != nullptr) { // stop when we fall off the list (next is nullptr)
        cout << current->data << " ";
        current = current->next; // follow the link to the next node
    }
    cout << "\n";
}

int main() {
    // Create a small linked list with 3 nodes: 10 -> 20 -> 30 -> null
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Traverse and print the list
    cout << "Traversing singly linked list: ";
    traverse(head);

    // Clean up allocated memory to avoid leaks
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    return 0;
}


