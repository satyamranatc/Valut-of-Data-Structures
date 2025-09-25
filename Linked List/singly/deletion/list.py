# Singly Linked List - Deletion (Python)
# Demonstrates deleting the head and deleting by value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.next = None


def delete_head(head: "Node | None") -> "Node | None":
    if head is None:
        return None
    return head.next


def delete_by_value(head: "Node | None", target: int) -> "Node | None":
    if head is None:
        return None
    if head.data == target:
        return head.next
    current = head
    while current.next is not None and current.next.data != target:
        current = current.next
    if current.next is not None:
        current.next = current.next.next
    return head


def traverse(head: "Node | None") -> None:
    cur = head
    while cur is not None:
        print(cur.data, end=" ")
        cur = cur.next
    print()


if __name__ == "__main__":
    # Build list: 10 -> 20 -> 30 -> 40
    head = Node(10)
    head.next = Node(20)
    head.next.next = Node(30)
    head.next.next.next = Node(40)

    print("Initial list:", end=" ")
    traverse(head)

    head = delete_head(head)
    print("After delete_head:", end=" ")
    traverse(head)

    head = delete_by_value(head, 30)
    print("After delete_by_value(30):", end=" ")
    traverse(head)


