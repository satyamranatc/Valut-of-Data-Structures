# Doubly Linked List - Updation (Python)
# Update first occurrence of a value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def update_first(head: "Node | None", target: int, new_value: int) -> bool:
    cur = head
    while cur is not None:
        if cur.data == target:
            cur.data = new_value
            return True
        cur = cur.next
    return False


def print_forward(head: "Node | None") -> None:
    cur = head
    while cur is not None:
        print(cur.data, end=" ")
        cur = cur.next
    print()


if __name__ == "__main__":
    # Build: 10 <-> 20 <-> 30
    n1 = Node(10); n2 = Node(20); n3 = Node(30)
    n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2
    head = n1

    print("Before:", end=" "); print_forward(head)
    ok = update_first(head, 20, 25)
    print("Updated" if ok else "Not found")
    print("After:", end=" "); print_forward(head)


