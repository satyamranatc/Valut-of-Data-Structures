// Singly Linked List - Updation (Java)
// Demonstrates updating the first node matching a target value.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    static boolean updateFirst(Node head, int target, int newValue) {
        Node current = head;
        while (current != null) {
            if (current.data == target) {
                current.data = newValue;
                return true;
            }
            current = current.next;
        }
        return false;
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
        // Build list: 10 -> 20 -> 30
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        System.out.print("Before update: ");
        traverse(head);

        boolean updated = updateFirst(head, 20, 25);
        System.out.println(updated ? "Updated successfully" : "Value not found");

        System.out.print("After update: ");
        traverse(head);
    }
}


