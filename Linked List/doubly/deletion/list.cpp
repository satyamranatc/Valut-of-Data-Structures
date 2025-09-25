// Doubly Linked List - Deletion (C++)
// Delete head and delete first occurrence by value.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* newHead = head->next;
    if (newHead != nullptr) newHead->prev = nullptr;
    delete head;
    return newHead;
}

Node* deleteByValue(Node* head, int target) {
    Node* cur = head;
    while (cur != nullptr && cur->data != target) cur = cur->next;
    if (cur == nullptr) return head;
    if (cur->prev != nullptr) cur->prev->next = cur->next; else head = cur->next;
    if (cur->next != nullptr) cur->next->prev = cur->prev;
    delete cur;
    return head;
}

void printForward(Node* head) {
    Node* cur = head; while (cur != nullptr) { cout << cur->data << " "; cur = cur->next; } cout << "\n";
}

int main() {
    // Build: 10 <-> 20 <-> 30 <-> 40
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    n1->next = n2; n2->prev = n1; n2->next = n3; n3->prev = n2; n3->next = n4; n4->prev = n3;
    Node* head = n1;

    cout << "Initial: "; printForward(head);
    head = deleteHead(head); cout << "After deleteHead: "; printForward(head);
    head = deleteByValue(head, 30); cout << "After deleteByValue(30): "; printForward(head);

    while (head != nullptr) head = deleteHead(head);
    return 0;
}


