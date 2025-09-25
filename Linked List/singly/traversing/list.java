// Singly Linked List - Traversing (Java)
// This program demonstrates how to traverse a singly linked list.
// A Node stores data and a reference to the next Node.

class Node {
    int data;        // value stored in the node
    Node next;       // reference to the next node (null if last)

    Node(int value) {
        this.data = value;
        this.next = null;
    }
}

public class list {
    // traverse prints all node values from head to end.
    static void traverse(Node head) {
        Node current = head; // start at the first node
        while (current != null) { // stop when we reach null (no next node)
            System.out.print(current.data + " ");
            current = current.next; // follow the link to the next node
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create a small linked list with 3 nodes: 10 -> 20 -> 30 -> null
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        // Traverse and print the list
        System.out.print("Traversing singly linked list: ");
        traverse(head);
    }
}


