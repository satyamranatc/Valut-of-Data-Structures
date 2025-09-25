# Circular Singly Linked List - Traversing (Python)
# Traverse once around the circle starting from head.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.next: "Node | None" = None


def traverse(head: "Node | None") -> None:
    if head is None:
        print()
        return
    current = head
    while True:
        print(current.data, end=" ")
        current = current.next
        if current is head:
            break
    print()


if __name__ == "__main__":
    n1 = Node(10); n2 = Node(20); n3 = Node(30)
    n1.next = n2; n2.next = n3; n3.next = n1
    head = n1
    print("Circular traverse:", end=" ")
    traverse(head)


