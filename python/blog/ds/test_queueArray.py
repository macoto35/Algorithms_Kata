import unittest
from queueArray import QueueArray

class QueueArrayTest(unittest.TestCase):
    def setUp(self):
        self.queue = QueueArray()

    def test_enqueue(self):
        for i in range(1, 6):
            self.queue.enqueue(i)

        self.assertEqual('1,2,3,4,5', self.queue.toString())
        with self.assertRaises(IndexError):
            self.queue.enqueue(6)

    def test_dequeue1(self):
        self.test_enqueue()
        
        for i in range(1, 6):
            self.assertEqual(i, self.queue.dequeue())

    def _test_data(self):
        self.queue.enqueue(1)
        self.queue.enqueue(2)
        self.queue.enqueue(3)
        self.assertEqual(1, self.queue.dequeue())
        self.assertEqual(2, self.queue.dequeue())
        self.queue.enqueue(4)
        self.queue.enqueue(5)
        self.queue.enqueue(6)
        self.queue.enqueue(7)

    def test_dequeue2(self):
        self._test_data()

        with self.assertRaises(IndexError):
            self.queue.enqueue(8)
    
    def test_dequeue3(self):
        self._test_data()
        self.assertEqual(3, self.queue.dequeue())
        self.queue.enqueue(8)

if __name__ == '__main__':
    unittest.main()
