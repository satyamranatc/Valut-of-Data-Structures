// Circular Singly Linked List - Updation (Java)
// Update first occurrence of a value.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    static boolean updateFirst(Node head, int target, int newValue) {
        if (head == null) return false;
        Node cur = head;
        do {
            if (cur.data == target) { cur.data = newValue; return true; }
            cur = cur.next;
        } while (cur != head);
        return false;
    }

    static void traverse(Node head) {
        if (head == null) { System.out.println(); return; }
        Node cur = head; do { System.out.print(cur.data + " "); cur = cur.next; } while (cur != head); System.out.println();
    }

    public static void main(String[] args) {
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30);
        n1.next = n2; n2.next = n3; n3.next = n1; Node head = n1;
        System.out.print("Before: "); traverse(head);
        boolean ok = updateFirst(head, 20, 25);
        System.out.println(ok ? "Updated" : "Not found");
        System.out.print("After: "); traverse(head);
    }
}


