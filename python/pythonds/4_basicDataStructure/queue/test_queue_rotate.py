import unittest
from queue_rotate import QueueRotate

class TestQueueRotate(unittest.TestCase):
    def setUp(self):
        self.q = QueueRotate()

    def test_all1(self):
        self.assertTrue(self.q.isEmpty())
        self.assertEqual(0, self.q.size)
        self.q.enqueue(1)
        self.q.enqueue(2)
        self.q.enqueue(3)
        self.assertFalse(self.q.isEmpty())
        self.assertEqual(3, self.q.size)
        self.assertEqual(1, self.q.dequeue())
        self.assertEqual(2, self.q.dequeue())
        self.q.enqueue(4)
        self.q.enqueue(5)
        self.q.enqueue(6)
        self.q.enqueue(7)
        self.assertEqual(3, self.q.dequeue())
        self.assertEqual(4, self.q.dequeue())
        self.assertEqual(5, self.q.dequeue())
        self.assertEqual(6, self.q.dequeue())
        self.assertEqual(7, self.q.dequeue())

    def test_all2(self):
        self.assertTrue(self.q.isEmpty())
        self.assertEqual(0, self.q.size)
        self.q.enqueue(1)
        self.q.enqueue(2)
        self.q.enqueue(3)
        self.assertFalse(self.q.isEmpty())
        self.assertEqual(3, self.q.size)
        self.assertEqual(1, self.q.dequeue())
        self.assertEqual(2, self.q.dequeue())
        self.q.enqueue(4)
        self.q.enqueue(5)
        self.q.enqueue(6)
        self.assertEqual(3, self.q.dequeue())
        self.assertEqual(4, self.q.dequeue())
        self.assertEqual(5, self.q.dequeue())
        self.assertEqual(6, self.q.dequeue())

if __name__ == '__main__':
    unittest.main()
