# Singly Linked List - Traversing (Python)
# This script demonstrates how to traverse a singly linked list.
# A Node stores data and a reference to the next Node.

class Node:
    """Represents a single element in the singly linked list.

    Each node has:
    - data: value stored in this node
    - next: reference to the next node (or None if this is the last node)
    """

    def __init__(self, value: int) -> None:
        self.data = value
        self.next = None


def traverse(head: Node) -> None:
    """Print all node values from head to end.

    We use a temporary pointer that follows next references until None.
    """
    current = head  # start at the first node
    while current is not None:  # stop when we reach the end (None)
        print(current.data, end=" ")
        current = current.next  # follow the link to the next node
    print()


if __name__ == "__main__":
    # Create a small linked list with 3 nodes: 10 -> 20 -> 30 -> None
    head = Node(10)
    head.next = Node(20)
    head.next.next = Node(30)

    # Traverse and print the list
    print("Traversing singly linked list:", end=" ")
    traverse(head)


