// Circular Singly Linked List - Addition (Java)
// Insert at head and tail.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    static Node insertAtHead(Node head, int value) {
        Node node = new Node(value);
        if (head == null) { node.next = node; return node; }
        Node tail = head;
        while (tail.next != head) tail = tail.next;
        node.next = head;
        tail.next = node;
        return node;
    }

    static Node insertAtTail(Node head, int value) {
        Node node = new Node(value);
        if (head == null) { node.next = node; return node; }
        Node tail = head;
        while (tail.next != head) tail = tail.next;
        tail.next = node; node.next = head;
        return head;
    }

    static void traverse(Node head) {
        if (head == null) { System.out.println(); return; }
        Node cur = head;
        do { System.out.print(cur.data + " "); cur = cur.next; } while (cur != head);
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertAtTail(head, 20);
        head = insertAtTail(head, 30);
        head = insertAtHead(head, 10);
        head = insertAtTail(head, 40);
        traverse(head);
    }
}


