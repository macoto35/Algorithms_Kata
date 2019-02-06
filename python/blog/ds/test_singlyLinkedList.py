import unittest
from singlyLinkedList import SinglyLinkedList
from node import Node

class SinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.list = SinglyLinkedList();

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

    def _addNodes(self):
        self.list.addLast(1)
        self.list.addLast(2)
        self.list.addLast(3)
        self.list.addLast(4)
        self.list.addLast(5)

    def test_removeFirst(self):
        self._addNodes();

        self.assertEqual(1, self.list.removeFirst())
        self.assertEqual(2, self.list.removeFirst())
        self.assertEqual(3, self.list.removeFirst())
        self.assertEqual(4, self.list.removeFirst())
        self.assertEqual(5, self.list.removeFirst())
        self.assertIsNone(self.list.removeFirst())

    def test_remove(self):
        self._addNodes()

        self.assertIsNone(self.list.remove(5))
        self.assertEqual(5, self.list.remove(4))
        self.assertEqual(1, self.list.remove(0))
        self.assertEqual(3, self.list.remove(1))
        self.assertEqual(4, self.list.remove(1))
        self.assertEqual(2, self.list.remove(0))

    def test_removeLast(self):
        self._addNodes()

        self.assertEqual(5, self.list.removeLast())
        self.assertEqual(4, self.list.removeLast())
        self.assertEqual(3, self.list.removeLast())
        self.assertEqual(2, self.list.removeLast())
        self.assertEqual(1, self.list.removeLast())
        self.assertIsNone(self.list.removeLast())

    def test_size(self):
        self.assertEqual(0, self.list.size())

        self._addNodes()
        self.assertEqual(5, self.list.size())

    def test_empty(self):
        self.assertEqual(True, self.list.empty())
        
        self._addNodes()
        self.assertEqual(False, self.list.empty())

    def test_get(self):
        self._addNodes()

        self.assertIsNone(self.list.get(-1))
        self.assertEqual(1, self.list.get(0))
        self.assertEqual(2, self.list.get(1))
        self.assertEqual(3, self.list.get(2))
        self.assertEqual(4, self.list.get(3))
        self.assertEqual(5, self.list.get(4))
        self.assertIsNone(self.list.get(5))
    
    def test_indexOf(self):
        self._addNodes()

        self.assertEqual(0, self.list.indexOf(1))
        self.assertEqual(1, self.list.indexOf(2))
        self.assertEqual(2, self.list.indexOf(3))
        self.assertEqual(3, self.list.indexOf(4))
        self.assertEqual(4, self.list.indexOf(5))
        self.assertEqual(-1, self.list.indexOf(6))

if __name__ == '__main__':
    unittest.main()
