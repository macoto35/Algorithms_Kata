import unittest
from stack import Stack

class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack = Stack()

    def test_all(self):
        self.assertTrue(self.stack.isEmpty())
        self.stack.push(12)
        self.stack.push('abc')
        self.assertEqual(self.stack.size(), 2)
        self.assertEqual(self.stack.peek(), 'abc')
        self.stack.push(False)
        self.assertFalse(self.stack.pop())
        self.stack.push(3.14)
        self.assertEqual(self.stack.pop(), 3.14)
        self.assertEqual(self.stack.peek(), 'abc')
        self.assertEqual(self.stack.pop(), 'abc')
        self.assertFalse(self.stack.isEmpty())
        self.assertEqual(self.stack.pop(), 12)
        self.assertEqual(self.stack.size(), 0)
        self.assertTrue(self.stack.isEmpty())

if __name__ == '__main__':
    unittest.main()
