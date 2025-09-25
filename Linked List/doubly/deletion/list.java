// Doubly Linked List - Deletion (Java)
// Delete head and first occurrence by value.

class Node {
    int data;
    Node prev;
    Node next;
    Node(int value) { this.data = value; this.prev = null; this.next = null; }
}

public class list {
    static Node deleteHead(Node head) {
        if (head == null) return null;
        Node newHead = head.next;
        if (newHead != null) newHead.prev = null;
        return newHead;
    }

    static Node deleteByValue(Node head, int target) {
        Node cur = head;
        while (cur != null && cur.data != target) cur = cur.next;
        if (cur == null) return head;
        if (cur.prev != null) cur.prev.next = cur.next; else head = cur.next;
        if (cur.next != null) cur.next.prev = cur.prev;
        return head;
    }

    static void printForward(Node head) {
        Node cur = head;
        while (cur != null) { System.out.print(cur.data + " "); cur = cur.next; }
        System.out.println();
    }

    public static void main(String[] args) {
        // Build: 10 <-> 20 <-> 30 <-> 40
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30), n4 = new Node(40);
        n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2; n3.next = n4; n4.prev = n3;
        Node head = n1;

        System.out.print("Initial: "); printForward(head);
        head = deleteHead(head); System.out.print("After deleteHead: "); printForward(head);
        head = deleteByValue(head, 30); System.out.print("After deleteByValue(30): "); printForward(head);
    }
}


