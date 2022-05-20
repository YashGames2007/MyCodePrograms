class Node:
    data = None
    next_Node = None
    
    def __init__(self, data = 0):
        self.data = data

    def __repr__(self):
        return f"< Node Object | Data: {self.data} >"

class Linked_List:
    def __init__(self) -> None:
        self.head = None

    def is_Empty(self) -> True or False:
        return self.head == None

    def prepend(self, data) -> None:
        new_Node = Node(data)
        new_Node.next_Node = self.head
        self.head = new_Node

    def insert(self, data, index) -> None:
        if index == 0:
            self.prepend(data)
        if index > 0:
            new = Node(data)
            position = index
            current = self.head

            while position > 1:
                current = current.next_Node
                position -= 1
            previous_node = current
            next_node = current.next_Node

            previous_node.next_Node = new
            new.next_Node = next_node

    def remove(self, key):
        current = self.head
        previous = None
        found = False

        while not found and current:
            if current.data == key and current == self.head:
                found = True
                self.head = current.next_Node
            elif current.data == key:
                found = True
                previous.next_Node = current.next_Node
            else:
                previous = current
                current = current.next_Node
        return current

    def find(self, target) -> int:
        current = self.head
        while current:
            if current.data == target:
                return current
            current = current.next_Node
        return None

    def get(self, index):
        if index == 0:
            return self.head
        else:
            current = self.head
            for i in range(index):
                current = current.next_Node
            return current

    def size(self) -> int:
        current = self.head
        count = 0
        while current:
            count += 1
            current = current.next_Node
        return count

    def __repr__(self) -> str:
        nodes = []
        current = self.head

        while current:
            if current is self.head:
                nodes.append(f"[Head: {current.data}]")
            elif current.next_Node is None:
                nodes.append(f"[Tail: {current.data}]")
            else:
                nodes.append(f"[Node: {current.data}]")
            current = current.next_Node
        return ' -> '.join(nodes)

if __name__ == '__main__':
    l = Linked_List()
    l.prepend(30)
    l.prepend(20)
    l.prepend((10))
    node = l.find(100)
    print(node)
    l.insert(50, 2)
    l.remove(22)
    print(l.size())
    print(l)
