// Circular Singly Linked List - Traversing (C++)
// Demonstrates traversal starting from head and stopping after one full cycle.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void traverse(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << "\n";
}

int main() {
    // Build circular list: 10 -> 20 -> 30 -> back to 10
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    n1->next = n2; n2->next = n3; n3->next = n1;
    Node* head = n1;

    cout << "Circular traverse: ";
    traverse(head);

    // cleanup (break the circle then delete)
    n3->next = nullptr;
    Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    return 0;
}


