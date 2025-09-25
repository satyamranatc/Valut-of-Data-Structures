// Doubly Linked List - Updation (C++)
// Update first occurrence of a value.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

bool updateFirst(Node* head, int target, int newValue) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data == target) { cur->data = newValue; return true; }
        cur = cur->next;
    }
    return false;
}

void printForward(Node* head) {
    Node* cur = head; while (cur != nullptr) { cout << cur->data << " "; cur = cur->next; } cout << "\n";
}

int main() {
    // Build: 10 <-> 20 <-> 30
    Node* n1 = new Node(10); Node* n2 = new Node(20); Node* n3 = new Node(30);
    n1->next = n2; n2->prev = n1; n2->next = n3; n3->prev = n2;
    Node* head = n1;

    cout << "Before: "; printForward(head);
    bool ok = updateFirst(head, 20, 25);
    cout << (ok ? "Updated" : "Not found") << "\n";
    cout << "After: "; printForward(head);

    // cleanup
    Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    return 0;
}


