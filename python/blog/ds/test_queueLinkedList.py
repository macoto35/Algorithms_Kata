import unittest
from queueLinkedList import QueueLinkedList

class QueueLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.queue = QueueLinkedList()

    def test_all(self):
        for i in range(1, 11):
            self.queue.enqueue(i)

        self.assertEqual('1,2,3,4,5,6,7,8,9,10', self.queue.toString())

        for i in range(1, 11):
            self.assertEqual(i, self.queue.dequeue())
        
        self.assertIsNone(self.queue.dequeue())

if __name__ == '__main__':
    unittest.main()
