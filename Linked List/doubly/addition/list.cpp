// Doubly Linked List - Addition (C++)
// Insert at head and tail, then print forward and backward.

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
    if (head != nullptr) {
        node->next = head;
        head->prev = node;
    }
    return node;
}

void insertAtTail(Node*& head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) { head = node; return; }
    Node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = node; node->prev = cur;
}

Node* getTail(Node* head) {
    Node* cur = head;
    while (cur != nullptr && cur->next != nullptr) cur = cur->next;
    return cur;
}

void printForward(Node* head) {
    Node* cur = head;
    while (cur != nullptr) { cout << cur->data << " "; cur = cur->next; }
    cout << "\n";
}

void printBackward(Node* tail) {
    Node* cur = tail;
    while (cur != nullptr) { cout << cur->data << " "; cur = cur->prev; }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    head = insertAtHead(head, 10);
    insertAtTail(head, 40);

    cout << "Forward: ";
    printForward(head);
    cout << "Backward: ";
    printBackward(getTail(head));

    // cleanup
    Node* cur = head;
    while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    return 0;
}


