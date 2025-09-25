// Circular Singly Linked List - Traversing (Java)
// Traverse once around the circle starting from head.

class Node {
    int data;
    Node next;
    Node(int value) { this.data = value; this.next = null; }
}

public class list {
    static void traverse(Node head) {
        if (head == null) { System.out.println(); return; }
        Node current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    public static void main(String[] args) {
        Node n1 = new Node(10), n2 = new Node(20), n3 = new Node(30);
        n1.next = n2; n2.next = n3; n3.next = n1;
        Node head = n1;
        System.out.print("Circular traverse: ");
        traverse(head);
    }
}


