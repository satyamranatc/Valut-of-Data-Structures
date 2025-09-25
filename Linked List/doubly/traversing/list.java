// Doubly Linked List - Traversing (Java)
// Demonstrates forward and backward traversal.

class Node {
    int data;
    Node prev;
    Node next;
    Node(int value) { this.data = value; this.prev = null; this.next = null; }
}

public class list {
    static void printForward(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    static Node getTail(Node head) {
        Node current = head;
        while (current != null && current.next != null) current = current.next;
        return current;
    }

    static void printBackward(Node tail) {
        Node current = tail;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.prev;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Build: 10 <-> 20 <-> 30
        Node n1 = new Node(10);
        Node n2 = new Node(20);
        Node n3 = new Node(30);
        n1.next = n2; n2.prev = n1;
        n2.next = n3; n3.prev = n2;
        Node head = n1;

        System.out.print("Forward: ");
        printForward(head);

        Node tail = getTail(head);
        System.out.print("Backward: ");
        printBackward(tail);
    }
}


