// Doubly Circular Linked List - Traversing (Java)
// Forward and backward traversal around the circle.

class Node {
    int data;
    Node prev;
    Node next;
    Node(int value) { this.data = value; this.prev = null; this.next = null; }
}

public class list {
    static void printForward(Node head) {
        if (head == null) { System.out.println(); return; }
        Node cur = head;
        do { System.out.print(cur.data + " "); cur = cur.next; } while (cur != head);
        System.out.println();
    }

    static Node getTail(Node head) {
        if (head == null) return null;
        Node cur = head;
        while (cur.next != head) cur = cur.next;
        return cur;
    }

    static void printBackward(Node tail) {
        if (tail == null) { System.out.println(); return; }
        Node cur = tail;
        do { System.out.print(cur.data + " "); cur = cur.prev; } while (cur != tail);
        System.out.println();
    }

    public static void main(String[] args) {
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30);
        n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2; n3.next = n1; n1.prev = n3;
        Node head = n1;
        System.out.print("Forward: "); printForward(head);
        System.out.print("Backward: "); printBackward(getTail(head));
    }
}


