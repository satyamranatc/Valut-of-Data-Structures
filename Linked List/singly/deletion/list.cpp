// Singly Linked List - Deletion (C++)
// Demonstrates deleting a node by value and deleting the head.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// deleteHead removes the first node and returns the new head
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* newHead = head->next;
    delete head; // free memory of the old head
    return newHead;
}

// deleteByValue removes the first node whose data equals target, returns head
Node* deleteByValue(Node* head, int target) {
    if (head == nullptr) return nullptr;
    if (head->data == target) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != target) {
        current = current->next; // move forward until we find the node before target
    }
    if (current->next != nullptr) {
        Node* toDelete = current->next; // node to remove
        current->next = toDelete->next; // bypass the deleted node
        delete toDelete;                // free memory
    }
    return head;
}

void traverse(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

int main() {
    // Build list: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Initial list: ";
    traverse(head);

    // Delete head -> 20 -> 30 -> 40
    head = deleteHead(head);
    cout << "After deleteHead: ";
    traverse(head);

    // Delete by value (30) -> 20 -> 40
    head = deleteByValue(head, 30);
    cout << "After deleteByValue(30): ";
    traverse(head);

    // Cleanup
    while (head != nullptr) head = deleteHead(head);
    return 0;
}


