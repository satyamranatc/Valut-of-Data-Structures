// Singly Linked List - Updation (C++)
// Demonstrates updating a node's value by searching for a target value.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// updateFirst replaces the first occurrence of target with newValue.
// Returns true if an update happened, false otherwise.
bool updateFirst(Node* head, int target, int newValue) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            current->data = newValue;
            return true;
        }
        current = current->next;
    }
    return false;
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
    // Build list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before update: ";
    traverse(head);

    // Update first node with value 20 to 25 -> 10 -> 25 -> 30
    bool updated = updateFirst(head, 20, 25);
    cout << (updated ? "Updated successfully" : "Value not found") << "\n";
    cout << "After update: ";
    traverse(head);

    // Cleanup
    Node* cur = head;
    while (cur != nullptr) {
        Node* toDelete = cur;
        cur = cur->next;
        delete toDelete;
    }
    return 0;
}


