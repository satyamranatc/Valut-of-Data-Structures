// Doubly Circular Linked List - Addition (Java)
// Insert at head and tail.

class Node {
    int data;
    Node prev;
    Node next;
    Node(int value) { this.data = value; this.prev = null; this.next = null; }
}

public class list {
    static Node insertAtHead(Node head, int value) {
        Node node = new Node(value);
        if (head == null) { node.next = node; node.prev = node; return node; }
        Node tail = head.prev;
        node.next = head; node.prev = tail;
        tail.next = node; head.prev = node;
        return node;
    }

    static Node insertAtTail(Node head, int value) {
        Node node = new Node(value);
        if (head == null) { node.next = node; node.prev = node; return node; }
        Node tail = head.prev;
        tail.next = node; node.prev = tail; node.next = head; head.prev = node;
        return head;
    }

    static void printForward(Node head) {
        if (head == null) { System.out.println(); return; }
        Node cur = head; do { System.out.print(cur.data + " "); cur = cur.next; } while (cur != head); System.out.println();
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertAtTail(head, 20);
        head = insertAtTail(head, 30);
        head = insertAtHead(head, 10);
        head = insertAtTail(head, 40);
        printForward(head);
    }
}


