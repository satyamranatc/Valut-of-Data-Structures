# Doubly Linked List - Addition (Python)
# Insert at head and tail, then print forward and backward.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.prev: "Node | None" = None
        self.next: "Node | None" = None


def insert_at_head(head: "Node | None", value: int) -> Node:
    node = Node(value)
    if head is not None:
        node.next = head
        head.prev = node
    return node


def insert_at_tail(head: "Node | None", value: int) -> Node:
    node = Node(value)
    if head is None:
        return node
    cur = head
    while cur.next is not None:
        cur = cur.next
    cur.next = node
    node.prev = cur
    return head


def get_tail(head: "Node | None") -> "Node | None":
    cur = head
    while cur is not None and cur.next is not None:
        cur = cur.next
    return cur


def print_forward(head: "Node | None") -> None:
    cur = head
    while cur is not None:
        print(cur.data, end=" ")
        cur = cur.next
    print()


def print_backward(tail: "Node | None") -> None:
    cur = tail
    while cur is not None:
        print(cur.data, end=" ")
        cur = cur.prev
    print()


if __name__ == "__main__":
    head = None
    head = insert_at_tail(head, 20)
    head = insert_at_tail(head, 30)
    head = insert_at_head(head, 10)
    head = insert_at_tail(head, 40)

    print("Forward:", end=" ")
    print_forward(head)
    print("Backward:", end=" ")
    print_backward(get_tail(head))


