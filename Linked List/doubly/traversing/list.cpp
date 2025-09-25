// Doubly Linked List - Traversing (C++)
// Demonstrates forward and backward traversal. Each node stores data,
// a pointer to the next node, and a pointer to the previous node.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// printForward: start at head and follow next pointers
void printForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

// getTail: return the last node by following next pointers
Node* getTail(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current; // could be nullptr if list empty
}

// printBackward: start at tail and follow prev pointers
void printBackward(Node* tail) {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << "\n";
}

int main() {
    // Build: 10 <-> 20 <-> 30
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    Node* head = n1;

    cout << "Forward: ";
    printForward(head);

    Node* tail = getTail(head);
    cout << "Backward: ";
    printBackward(tail);

    // cleanup
    Node* cur = head;
    while (cur != nullptr) {
        Node* toDelete = cur;
        cur = cur->next;
        delete toDelete;
    }
    return 0;
}


