# Singly Linked List - Updation (Python)
# Demonstrates updating the first occurrence of a target value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.next = None


def update_first(head: "Node | None", target: int, new_value: int) -> bool:
    current = head
    while current is not None:
        if current.data == target:
            current.data = new_value
            return True
        current = current.next
    return False


def traverse(head: "Node | None") -> None:
    cur = head
    while cur is not None:
        print(cur.data, end=" ")
        cur = cur.next
    print()


if __name__ == "__main__":
    # Build list: 10 -> 20 -> 30
    head = Node(10)
    head.next = Node(20)
    head.next.next = Node(30)

    print("Before update:", end=" ")
    traverse(head)

    updated = update_first(head, 20, 25)
    print("Updated successfully" if updated else "Value not found")

    print("After update:", end=" ")
    traverse(head)


