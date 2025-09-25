// Circular Singly Linked List - Addition (C++)
// Insert at head and tail in a circular list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* insertAtHead(Node* head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) { node->next = node; return node; }
    Node* tail = head;
    while (tail->next != head) tail = tail->next;
    node->next = head;
    tail->next = node;
    return node;
}

Node* insertAtTail(Node* head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) { node->next = node; return node; }
    Node* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = node;
    node->next = head;
    return head;
}

void traverse(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* cur = head;
    do { cout << cur->data << " "; cur = cur->next; } while (cur != head);
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 40);
    traverse(head);

    // cleanup: break circle then delete
    Node* tail = head; if (tail != nullptr) { while (tail->next != head) tail = tail->next; tail->next = nullptr; }
    Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    return 0;
}


