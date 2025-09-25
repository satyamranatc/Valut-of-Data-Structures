// Circular Singly Linked List - Deletion (C++)
// Delete head and first occurrence by value.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == head) { delete head; return nullptr; }
    Node* tail = head;
    while (tail->next != head) tail = tail->next;
    Node* newHead = head->next;
    tail->next = newHead;
    delete head;
    return newHead;
}

Node* deleteByValue(Node* head, int target) {
    if (head == nullptr) return nullptr;
    Node* cur = head;
    Node* prev = nullptr;
    do {
        if (cur->data == target) {
            if (prev == nullptr) return deleteHead(head);
            prev->next = cur->next;
            delete cur;
            return head;
        }
        prev = cur; cur = cur->next;
    } while (cur != head);
    return head;
}

void traverse(Node* head) {
    if (head == nullptr) { cout << "\n"; return; }
    Node* cur = head; do { cout << cur->data << " "; cur = cur->next; } while (cur != head); cout << "\n";
}

int main() {
    // Build: 10 -> 20 -> 30 -> back to 10
    Node* n1 = new Node(10); Node* n2 = new Node(20); Node* n3 = new Node(30);
    n1->next = n2; n2->next = n3; n3->next = n1;
    Node* head = n1;
    cout << "Initial: "; traverse(head);
    head = deleteHead(head); cout << "After deleteHead: "; traverse(head);
    head = deleteByValue(head, 30); cout << "After deleteByValue(30): "; traverse(head);

    // cleanup
    if (head != nullptr) {
        Node* tail = head; while (tail->next != head) tail = tail->next; tail->next = nullptr;
        Node* cur = head; while (cur != nullptr) { Node* d = cur; cur = cur->next; delete d; }
    }
    return 0;
}


