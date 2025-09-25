# Doubly Circular Linked List - Deletion (Python)
# Delete head and first occurrence by value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def delete_head(head: "Node | None") -> "Node | None":
    if head is None:
        return None
    if head.next is head:
        return None
    tail = head.prev
    new_head = head.next
    tail.next = new_head
    new_head.prev = tail
    return new_head


def delete_by_value(head: "Node | None", target: int) -> "Node | None":
    if head is None:
        return None
    cur = head
    while True:
        if cur.data == target:
            if cur is head:
                return delete_head(head)
            cur.prev.next = cur.next
            cur.next.prev = cur.prev
            return head
        cur = cur.next
        if cur is head:
            break
    return head


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


if __name__ == "__main__":
    n1 = Node(10); n2 = Node(20); n3 = Node(30)
    n1.next = n2; n2.prev = n1
    n2.next = n3; n3.prev = n2
    n3.next = n1; n1.prev = n3
    head = n1
    print("Initial:", end=" "); print_forward(head)
    head = delete_head(head); print("After delete_head:", end=" "); print_forward(head)
    head = delete_by_value(head, 30); print("After delete_by_value(30):", end=" "); print_forward(head)


