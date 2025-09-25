// Doubly Circular Linked List - Traversing (C++)
// Demonstrates forward and backward traversal around the circle.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void printForward(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* cur = head;
    do { cout << cur->data << " "; cur = cur->next; } while (cur != head);
    cout << "\n";
}

Node* getTail(Node* head) {
    if (head == nullptr) return nullptr;
    Node* cur = head;
    while (cur->next != head) cur = cur->next;
    return cur;
}

void printBackward(Node* tail) {
    if (tail == nullptr) { cout << "\n"; return; }
    Node* cur = tail;
    do { cout << cur->data << " "; cur = cur->prev; } while (cur != tail);
    cout << "\n";
}

int main() {
    // Build: 10 <-> 20 <-> 30 and circular
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n1; n1->prev = n3; // make circular
    Node* head = n1;

    cout << "Forward: "; printForward(head);
    cout << "Backward: "; printBackward(getTail(head));

    // cleanup: break circle then delete
    Node* tail = getTail(head);
    if (tail != nullptr) { tail->next = nullptr; head->prev = nullptr; }
    Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    return 0;
}


