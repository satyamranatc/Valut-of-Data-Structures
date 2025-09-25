// Doubly Circular Linked List - Deletion (Java)
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
        if (head.next == head) return null;
        Node tail = head.prev;
        Node newHead = head.next;
        tail.next = newHead; newHead.prev = tail;
        return newHead;
    }

    static Node deleteByValue(Node head, int target) {
        if (head == null) return null;
        Node cur = head;
        do {
            if (cur.data == target) {
                if (cur == head) return deleteHead(head);
                cur.prev.next = cur.next;
                cur.next.prev = cur.prev;
                return head;
            }
            cur = cur.next;
        } while (cur != head);
        return head;
    }

    static void printForward(Node head) {
        if (head == null) { System.out.println(); return; }
        Node cur = head; do { System.out.print(cur.data + " "); cur = cur.next; } while (cur != head); System.out.println();
    }

    public static void main(String[] args) {
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30);
        n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2; n3.next = n1; n1.prev = n3;
        Node head = n1;
        System.out.print("Initial: "); printForward(head);
        head = deleteHead(head); System.out.print("After deleteHead: "); printForward(head);
        head = deleteByValue(head, 30); System.out.print("After deleteByValue(30): "); printForward(head);
    }
}


