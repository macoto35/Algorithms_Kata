class Node:
    def __init__(self, data, node=None):
        self.data = data
        self.node = node

def main():
    a = Node(2)
    b = Node(3)
    a.node = b

    print(a.data, a.node.data)
    print(b.data, b.node)

if __name__ == '__main__':
    main()
