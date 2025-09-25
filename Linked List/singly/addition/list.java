// Singly Linked List - Addition (Java)
// Demonstrates inserting nodes at head and tail, then printing the list.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    // Insert a node at the head and return the new head
    static Node insertAtHead(Node head, int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        return newNode;
    }

    // Insert a node at the tail, possibly creating the head if list is empty
    static Node insertAtTail(Node head, int value) {
        Node newNode = new Node(value);
        if (head == null) return newNode; // list was empty
        Node current = head;
        while (current.next != null) current = current.next;
        current.next = newNode;
        return head;
    }

    // Print the list from head to end
    static void traverse(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Start with a small list: 20 -> 30
        Node head = null;
        head = insertAtTail(head, 20);
        head = insertAtTail(head, 30);

        System.out.print("Initial list: ");
        traverse(head);

        // Insert at head -> 10 -> 20 -> 30
        head = insertAtHead(head, 10);
        System.out.print("After insertAtHead(10): ");
        traverse(head);

        // Insert at tail -> 10 -> 20 -> 30 -> 40
        head = insertAtTail(head, 40);
        System.out.print("After insertAtTail(40): ");
        traverse(head);
    }
}


