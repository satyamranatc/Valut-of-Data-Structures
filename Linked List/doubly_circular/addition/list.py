# Doubly Circular Linked List - Addition (Python)
# Insert at head and tail.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def insert_at_head(head: "Node | None", value: int) -> Node:
    node = Node(value)
    if head is None:
        node.next = node; node.prev = node
        return node
    tail = head.prev
    node.next = head; node.prev = tail
    tail.next = node; head.prev = node
    return node


def insert_at_tail(head: "Node | None", value: int) -> Node:
    node = Node(value)
    if head is None:
        node.next = node; node.prev = node
        return node
    tail = head.prev
    tail.next = node; node.prev = tail; node.next = head; head.prev = node
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
    head = None
    head = insert_at_tail(head, 20)
    head = insert_at_tail(head, 30)
    head = insert_at_head(head, 10)
    head = insert_at_tail(head, 40)
    print_forward(head)


