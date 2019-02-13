import unittest
from stackFixedArray import StackFixedArray

class StackFixedArrayTest(unittest.TestCase):
    def setUp(self):
        self.stack = StackFixedArray()

    def test_push(self):
        for i in range(1, 5):
            self.stack.push(i)
        self.assertEqual('1,2,3,4', self.stack.toString())
        
        with self.assertRaises(IndexError):
            self.stack.push(5)

    def test_pop(self):
        for i in range(1, 5):
            self.stack.push(i)

        for i in range(4, 0, -1):
            self.assertEqual(i, self.stack.pop())
        self.assertIsNone(self.stack.pop())

    def test_empty(self):
        self.assertEqual(True, self.stack.empty())

        self.stack.push(1)
        self.assertEqual(False, self.stack.empty())

    def test_peek(self):
        self.assertIsNone(self.stack.peek())

        self.stack.push(2)
        self.assertEqual(2, self.stack.peek())

    def test_search(self):
        for i in range(1, 5):
            self.stack.push(i)

        for i in range(0, 4):
            self.assertEqual(i, self.stack.search(i + 1))
        self.assertEqual(-1, self.stack.search(5))

if __name__ == '__main__':
    unittest.main()
