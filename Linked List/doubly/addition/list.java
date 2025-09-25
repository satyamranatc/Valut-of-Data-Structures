// Doubly Linked List - Addition (Java)
// Insert at head and tail, then print forward and backward.

class Node {
    int data;
    Node prev;
    Node next;
    Node(int value) { this.data = value; this.prev = null; this.next = null; }
}

public class list {
    static Node insertAtHead(Node head, int value) {
        Node node = new Node(value);
        if (head != null) { node.next = head; head.prev = node; }
        return node;
    }

    static Node insertAtTail(Node head, int value) {
        Node node = new Node(value);
        if (head == null) return node;
        Node cur = head;
        while (cur.next != null) cur = cur.next;
        cur.next = node; node.prev = cur;
        return head;
    }

    static Node getTail(Node head) {
        Node cur = head;
        while (cur != null && cur.next != null) cur = cur.next;
        return cur;
    }

    static void printForward(Node head) {
        Node cur = head;
        while (cur != null) { System.out.print(cur.data + " "); cur = cur.next; }
        System.out.println();
    }

    static void printBackward(Node tail) {
        Node cur = tail;
        while (cur != null) { System.out.print(cur.data + " "); cur = cur.prev; }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertAtTail(head, 20);
        head = insertAtTail(head, 30);
        head = insertAtHead(head, 10);
        head = insertAtTail(head, 40);

        System.out.print("Forward: ");
        printForward(head);
        System.out.print("Backward: ");
        printBackward(getTail(head));
    }
}


