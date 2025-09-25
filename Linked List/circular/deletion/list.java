// Circular Singly Linked List - Deletion (Java)
// Delete head and first occurrence by value.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    static Node deleteHead(Node head) {
        if (head == null) return null;
        if (head.next == head) return null;
        Node tail = head;
        while (tail.next != head) tail = tail.next;
        Node newHead = head.next;
        tail.next = newHead;
        return newHead;
    }

    static Node deleteByValue(Node head, int target) {
        if (head == null) return null;
        Node cur = head, prev = null;
        do {
            if (cur.data == target) {
                if (prev == null) return deleteHead(head);
                prev.next = cur.next;
                return head;
            }
            prev = cur; cur = cur.next;
        } while (cur != head);
        return head;
    }

    static void traverse(Node head) {
        if (head == null) { System.out.println(); return; }
        Node cur = head; do { System.out.print(cur.data + " "); cur = cur.next; } while (cur != head); System.out.println();
    }

    public static void main(String[] args) {
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30);
        n1.next = n2; n2.next = n3; n3.next = n1;
        Node head = n1;
        System.out.print("Initial: "); traverse(head);
        head = deleteHead(head); System.out.print("After deleteHead: "); traverse(head);
        head = deleteByValue(head, 30); System.out.print("After deleteByValue(30): "); traverse(head);
    }
}


