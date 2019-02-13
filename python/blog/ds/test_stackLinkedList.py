import unittest
from stackLinkedList import StackLinkedList

class StackLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.stack = StackLinkedList()

    def test_push(self):
        for i in range(1, 6): 
            self.stack.push(i)
        self.assertEqual('5,4,3,2,1', self.stack.toString())

    def test_pop(self):
        self.test_push()

        for i in range(5, 0, -1):
            self.assertEqual(i, self.stack.pop())
        self.assertIsNone(self.stack.pop())

    def test_empty(self):
        self.assertEqual(True, self.stack.empty())
        
        self.stack.push(1)
        self.assertEqual(False, self.stack.empty())

    def test_peek(self):
        self.assertIsNone(self.stack.peek())

        for i in range(1, 6):
            self.stack.push(i)
            self.assertEqual(i, self.stack.peek())

    def test_search(self):
        self.test_push();

        eIdx = 4
        for i in range(1, 6):
            self.assertEqual(eIdx, self.stack.search(i));
            eIdx -= 1
        self.assertEqual(-1, self.stack.search(6));

if __name__ == '__main__':
    unittest.main()
