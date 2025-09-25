// Doubly Circular Linked List - Deletion (C++)
// Delete head and first occurrence by value.

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
    if (head->next == head) { delete head; return nullptr; }
    Node* tail = head->prev;
    Node* newHead = head->next;
    tail->next = newHead; newHead->prev = tail;
    delete head;
    return newHead;
}

Node* deleteByValue(Node* head, int target) {
    if (head == nullptr) return nullptr;
    Node* cur = head;
    do {
        if (cur->data == target) {
            if (cur == head) return deleteHead(head);
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            return head;
        }
        cur = cur->next;
    } while (cur != head);
    return head;
}

void printForward(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* cur = head; do { cout << cur->data << " "; cur = cur->next; } while (cur != head); cout << "\n";
}

int main() {
    // Build circular: 10 <-> 20 <-> 30
    Node* n1 = new Node(10); Node* n2 = new Node(20); Node* n3 = new Node(30);
    n1->next = n2; n2->prev = n1; n2->next = n3; n3->prev = n2; n3->next = n1; n1->prev = n3;
    Node* head = n1;
    cout << "Initial: "; printForward(head);
    head = deleteHead(head); cout << "After deleteHead: "; printForward(head);
    head = deleteByValue(head, 30); cout << "After deleteByValue(30): "; printForward(head);
    return 0;
}


