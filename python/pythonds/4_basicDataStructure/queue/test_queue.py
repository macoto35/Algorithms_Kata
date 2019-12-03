import unittest
from queue import Queue

class TestQueue(unittest.TestCase):
    def setUp(self):
        self.q = Queue()

    def test_all(self):
        self.assertTrue(self.q.isEmpty())
        self.q.enqueue(4)
        self.q.enqueue('dog')
        self.q.enqueue(True)
        self.assertEqual(3, self.q.size())
        self.assertFalse(self.q.isEmpty())
        self.q.enqueue(8.4)
        self.assertEqual(4, self.q.dequeue())
        self.assertEqual('dog', self.q.dequeue())
        self.assertEqual(2, self.q.size())

if __name__ == '__main__':
    unittest.main()
