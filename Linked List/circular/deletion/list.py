# Circular Singly Linked List - Deletion (Python)
# Delete head and first occurrence by value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.next: "Node | None" = None


def delete_head(head: "Node | None") -> "Node | None":
    if head is None:
        return None
    if head.next is head:
        return None
    tail = head
    while tail.next is not head:
        tail = tail.next
    new_head = head.next
    tail.next = new_head
    return new_head


def delete_by_value(head: "Node | None", target: int) -> "Node | None":
    if head is None:
        return None
    cur = head
    prev = None
    while True:
        if cur.data == target:
            if prev is None:
                return delete_head(head)
            prev.next = cur.next
            return head
        prev = cur
        cur = cur.next
        if cur is head:
            break
    return head


def traverse(head: "Node | None") -> None:
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
    n1.next = n2; n2.next = n3; n3.next = n1
    head = n1
    print("Initial:", end=" "); traverse(head)
    head = delete_head(head); print("After delete_head:", end=" "); traverse(head)
    head = delete_by_value(head, 30); print("After delete_by_value(30):", end=" "); traverse(head)


