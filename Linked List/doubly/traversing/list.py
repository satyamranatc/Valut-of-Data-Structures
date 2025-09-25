# Doubly Linked List - Traversing (Python)
# Demonstrates forward and backward traversal.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def print_forward(head: "Node | None") -> None:
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()


def get_tail(head: "Node | None") -> "Node | None":
    current = head
    while current is not None and current.next is not None:
        current = current.next
    return current


def print_backward(tail: "Node | None") -> None:
    current = tail
    while current is not None:
        print(current.data, end=" ")
        current = current.prev
    print()


if __name__ == "__main__":
    # Build: 10 <-> 20 <-> 30
    n1 = Node(10)
    n2 = Node(20)
    n3 = Node(30)
    n1.next = n2; n2.prev = n1
    n2.next = n3; n3.prev = n2
    head = n1

    print("Forward:", end=" ")
    print_forward(head)

    tail = get_tail(head)
    print("Backward:", end=" ")
    print_backward(tail)


