# Doubly Linked List - Deletion (Python)
# Delete head and first occurrence by value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def delete_head(head: "Node | None") -> "Node | None":
    if head is None:
        return None
    new_head = head.next
    if new_head is not None:
        new_head.prev = None
    return new_head


def delete_by_value(head: "Node | None", target: int) -> "Node | None":
    cur = head
    while cur is not None and cur.data != target:
        cur = cur.next
    if cur is None:
        return head
    if cur.prev is not None:
        cur.prev.next = cur.next
    else:
        head = cur.next
    if cur.next is not None:
        cur.next.prev = cur.prev
    return head


def print_forward(head: "Node | None") -> None:
    cur = head
    while cur is not None:
        print(cur.data, end=" ")
        cur = cur.next
    print()


if __name__ == "__main__":
    # Build: 10 <-> 20 <-> 30 <-> 40
    n1 = Node(10); n2 = Node(20); n3 = Node(30); n4 = Node(40)
    n1.next = n2; n2.prev = n1; n2.next = n3; n3.prev = n2; n3.next = n4; n4.prev = n3
    head = n1

    print("Initial:", end=" "); print_forward(head)
    head = delete_head(head); print("After delete_head:", end=" "); print_forward(head)
    head = delete_by_value(head, 30); print("After delete_by_value(30):", end=" "); print_forward(head)


