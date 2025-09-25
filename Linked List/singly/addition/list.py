# Singly Linked List - Addition (Python)
# Demonstrates inserting nodes at head and tail, then printing the list.

class Node:
    """A node stores data and a reference to the next node."""

    def __init__(self, value: int) -> None:
        self.data = value
        self.next = None


def insert_at_head(head: "Node | None", value: int) -> Node:
    """Create a node and place it before the current head, returning new head."""
    new_node = Node(value)
    new_node.next = head
    return new_node


def insert_at_tail(head: "Node | None", value: int) -> Node:
    """Add a node at the end. If list is empty, new node becomes head."""
    new_node = Node(value)
    if head is None:
        return new_node
    current = head
    while current.next is not None:
        current = current.next
    current.next = new_node
    return head


def traverse(head: "Node | None") -> None:
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()


if __name__ == "__main__":
    # Start with 20 -> 30
    head = None
    head = insert_at_tail(head, 20)
    head = insert_at_tail(head, 30)
    print("Initial list:", end=" ")
    traverse(head)

    # Insert at head -> 10 -> 20 -> 30
    head = insert_at_head(head, 10)
    print("After insert_at_head(10):", end=" ")
    traverse(head)

    # Insert at tail -> 10 -> 20 -> 30 -> 40
    head = insert_at_tail(head, 40)
    print("After insert_at_tail(40):", end=" ")
    traverse(head)


