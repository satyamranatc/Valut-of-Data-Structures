# Circular Singly Linked List - Addition (Python)
# Insert at head and tail.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.next: "Node | None" = None


def insert_at_head(head: "Node | None", value: int) -> Node:
    node = Node(value)
    if head is None:
        node.next = node
        return node
    tail = head
    while tail.next is not head:
        tail = tail.next
    node.next = head
    tail.next = node
    return node


def insert_at_tail(head: "Node | None", value: int) -> Node:
    node = Node(value)
    if head is None:
        node.next = node
        return node
    tail = head
    while tail.next is not head:
        tail = tail.next
    tail.next = node
    node.next = head
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
    head = None
    head = insert_at_tail(head, 20)
    head = insert_at_tail(head, 30)
    head = insert_at_head(head, 10)
    head = insert_at_tail(head, 40)
    traverse(head)


