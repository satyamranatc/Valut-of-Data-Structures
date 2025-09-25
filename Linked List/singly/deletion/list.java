// Singly Linked List - Deletion (Java)
// Demonstrates deleting the head and deleting by value.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    static Node deleteHead(Node head) {
        if (head == null) return null;
        return head.next; // old head becomes unreachable and will be GC'd
    }

    static Node deleteByValue(Node head, int target) {
        if (head == null) return null;
        if (head.data == target) return head.next;
        Node current = head;
        while (current.next != null && current.next.data != target) {
            current = current.next;
        }
        if (current.next != null) {
            current.next = current.next.next; // bypass the target node
        }
        return head;
    }

    static void traverse(Node head) {
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Build list: 10 -> 20 -> 30 -> 40
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(40);

        System.out.print("Initial list: ");
        traverse(head);

        head = deleteHead(head);
        System.out.print("After deleteHead: ");
        traverse(head);

        head = deleteByValue(head, 30);
        System.out.print("After deleteByValue(30): ");
        traverse(head);
    }
}


