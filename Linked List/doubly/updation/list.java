// Doubly Linked List - Updation (Java)
// Update first occurrence of a value.

class Node {
    int data;
    Node prev;
    Node next;
    Node(int value) { this.data = value; this.prev = null; this.next = null; }
}

public class list {
    static boolean updateFirst(Node head, int target, int newValue) {
        Node cur = head;
        while (cur != null) {
            if (cur.data == target) { cur.data = newValue; return true; }
            cur = cur.next;
        }
        return false;
    }

    static void printForward(Node head) {
        Node cur = head; while (cur != null) { System.out.print(cur.data + " "); cur = cur.next; } System.out.println();
    }

    public static void main(String[] args) {
        // Build: 10 <-> 20 <-> 30
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30);
        n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2;
        Node head = n1;

        System.out.print("Before: "); printForward(head);
        boolean ok = updateFirst(head, 20, 25);
        System.out.println(ok ? "Updated" : "Not found");
        System.out.print("After: "); printForward(head);
    }
}


