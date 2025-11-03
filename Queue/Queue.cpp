#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue - add element at the end
    void enqueue(int data) {
        Node* newNode = new Node(data);

        // If queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        // Add new node at the end
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue - remove element from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Peek - see front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Display queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Test the Queue
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
