class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete(self, data):
        if self.is_empty():
            return

        if self.head.data == data:
            self.head = self.head.next
            return

        current = self.head
        while current.next:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        print(" -> ".join(map(str, elements)))

    def search(self, data):
        current = self.head
        index = 0
        while current:
            if current.data == data:
                return index
            current = current.next
            index += 1
        return -1

# Example usage of the LinkedList
if __name__ == "__main__":
    llist = LinkedList()

    # Adding elements
    llist.append(1)
    llist.append(2)
    llist.append(3)
    llist.prepend(0)

    print("Linked List:")
    llist.display()

    # Searching for an element
    print("Index of 2:", llist.search(2))

    # Deleting an element
    llist.delete(2)
    print("Linked List after deleting 2:")
    llist.display()

    # Trying to delete a non-existent element
    llist.delete(5)
    print("Linked List after trying to delete 5:")
    llist.display()

