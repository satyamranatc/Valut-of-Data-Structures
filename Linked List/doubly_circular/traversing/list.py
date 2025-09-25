# Doubly Circular Linked List - Traversing (Python)
# Forward and backward traversal around the circle.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def print_forward(head: "Node | None") -> None:
    if head is None:
        print()
        return
    cur = head
    while True:
        print(cur.data, end=" ")
        cur = cur.next
        if cur is head:
            break
    print()


def get_tail(head: "Node | None") -> "Node | None":
    if head is None:
        return None
    cur = head
    while cur.next is not head:
        cur = cur.next
    return cur


def print_backward(tail: "Node | None") -> None:
    if tail is None:
        print()
        return
    cur = tail
    while True:
        print(cur.data, end=" ")
        cur = cur.prev
        if cur is tail:
            break
    print()


if __name__ == "__main__":
    n1 = Node(10); n2 = Node(20); n3 = Node(30)
    n1.next = n2; n2.prev = n1
    n2.next = n3; n3.prev = n2
    n3.next = n1; n1.prev = n3
    head = n1
    print("Forward:", end=" "); print_forward(head)
    print("Backward:", end=" "); print_backward(get_tail(head))


