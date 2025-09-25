// Doubly Circular Linked List - Addition (C++)
// Insert at head and tail.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

Node* insertAtHead(Node* head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        node->next = node; node->prev = node; return node;
    }
    Node* tail = head->prev;
    node->next = head; node->prev = tail;
    tail->next = node; head->prev = node;
    return node;
}

Node* insertAtTail(Node* head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) { node->next = node; node->prev = node; return node; }
    Node* tail = head->prev;
    tail->next = node; node->prev = tail; node->next = head; head->prev = node;
    return head;
}

void printForward(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* cur = head; do { cout << cur->data << " "; cur = cur->next; } while (cur != head); cout << "\n";
}

int main() {
    Node* head = nullptr;
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 40);
    printForward(head);

    // cleanup: break circle then delete
    if (head != nullptr) {
        Node* tail = head->prev; tail->next = nullptr; head->prev = nullptr;
        Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    }
    return 0;
}


