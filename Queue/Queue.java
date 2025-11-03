// Node class - represents one element in the queue
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

// Queue class using Linked List
class Queue {
    Node front, rear;

    // Constructor
    Queue() {
        this.front = this.rear = null;
    }

    // Enqueue: Add element at the end
    void enqueue(int data) {
        Node newNode = new Node(data);

        // If queue is empty
        if (rear == null) {
            front = rear = newNode;
            return;
        }

        // Add the new node at the end
        rear.next = newNode;
        rear = newNode;
    }

    // Dequeue: Remove element from the front
    void dequeue() {
        // If queue is empty
        if (front == null) {
            System.out.println("Queue is empty");
            return;
        }

        // Move front to next
        front = front.next;

        // If front becomes null, then queue is empty
        if (front == null)
            rear = null;
    }

    // Peek: Get front element
    int peek() {
        if (front == null) {
            System.out.println("Queue is empty");
            return -1;
        }
        return front.data;
    }

    // Display the queue
    void display() {
        if (front == null) {
            System.out.println("Queue is empty");
            return;
        }

        Node temp = front;
        System.out.print("Queue: ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

// Test class
public class Main {
    public static void main(String[] args) {
        Queue q = new Queue();

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.display();

        System.out.println("Front element: " + q.peek());

        q.dequeue();
        q.display();

        System.out.println("Front element: " + q.peek());
    }
}
