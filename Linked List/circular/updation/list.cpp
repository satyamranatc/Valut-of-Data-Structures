// Circular Singly Linked List - Updation (C++)
// Update first occurrence of a value.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

bool updateFirst(Node* head, int target, int newValue) {
    if (head == nullptr) return false;
    Node* cur = head;
    do {
        if (cur->data == target) { cur->data = newValue; return true; }
        cur = cur->next;
    } while (cur != head);
    return false;
}

void traverse(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* cur = head; do { cout << cur->data << " "; cur = cur->next; } while (cur != head); cout << "\n";
}

int main() {
    // Build: 10 -> 20 -> 30 -> back to 10
    Node* n1 = new Node(10); Node* n2 = new Node(20); Node* n3 = new Node(30);
    n1->next = n2; n2->next = n3; n3->next = n1; Node* head = n1;
    cout << "Before: "; traverse(head);
    bool ok = updateFirst(head, 20, 25);
    cout << (ok ? "Updated" : "Not found") << "\n";
    cout << "After: "; traverse(head);

    // cleanup
    Node* tail = head; if (tail != nullptr) { while (tail->next != head) tail = tail->next; tail->next = nullptr; }
    Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    return 0;
}


