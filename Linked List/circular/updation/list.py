# Circular Singly Linked List - Updation (Python)
# Update first occurrence of a value.

class Node:
    def __init__(self, value: int) -> None:
        self.data = value
        self.next: "Node | None" = None


def update_first(head: "Node | None", target: int, new_value: int) -> bool:
    if head is None:
        return False
    cur = head
    while True:
        if cur.data == target:
            cur.data = new_value
            return True
        cur = cur.next
        if cur is head:
            break
    return False


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
    print("Before:", end=" "); traverse(head)
    ok = update_first(head, 20, 25)
    print("Updated" if ok else "Not found")
    print("After:", end=" "); traverse(head)


