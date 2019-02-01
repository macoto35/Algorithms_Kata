import unittest
from linkedList import LinkedList
from node import Node

class LinkedListTest(unittest.TestCase):
    def setUp(self):
        self.list = LinkedList();

    def test_node(self):
        a = Node(2)
        b = Node(3)
        a.next = b

        self.assertEqual(2, a.data)
        self.assertEqual(3, a.next.data)
        self.assertEqual(3, b.data)
        self.assertIsNone(b.next)

    def test_addFirst(self):
        self.list.addFirst(1)
        self.list.addFirst(2)
        self.list.addFirst(3)
        self.list.addFirst(4)

        self.assertEqual('4,3,2,1', self.list.toString())

    def test_addLast(self):
        self.list.addLast(1)
        self.list.addLast(2)
        self.list.addLast(3)
        self.list.addLast(4)
        
        self.assertEqual('1,2,3,4', self.list.toString())

    def test_addFront(self):
        self.list.addFront(1, 0)
        self.list.addFront(2, 1)
        self.list.addFront(3, 1)
        self.list.addFront(4, 2)
        
        self.assertEqual('1,3,4,2', self.list.toString())

    def test_addBack(self):
        self.list.addBack(1, 0)
        self.list.addBack(2, 1)
        self.list.addBack(3, 1)
        self.list.addBack(4, 1)
        
        self.assertEqual('1,2,4,3', self.list.toString())


if __name__ == '__main__':
    unittest.main()
