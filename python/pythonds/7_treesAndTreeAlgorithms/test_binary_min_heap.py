import unittest
from binary_min_heap import BinaryMinHeap

class TestBinaryMinHeap(unittest.TestCase):
    def setUp(self):
        self.bh = BinaryMinHeap()

    def test_all(self):
        self.assertTrue(self.bh.isEmpty())
        self.assertEqual(0, self.bh.size())
        self.bh.insert(14)
        self.bh.insert(18)
        self.bh.insert(19)
        self.bh.insert(21)
        self.bh.insert(9)
        self.bh.insert(11)
        self.bh.insert(33)
        self.bh.insert(17)
        self.bh.insert(27)
        self.bh.insert(5)
        self.assertFalse(self.bh.isEmpty())
        self.assertEqual(5, self.bh.findMin())
        self.assertEqual(10, self.bh.size())
        self.assertEqual(5, self.bh.delMin())
        self.assertEqual(9, self.bh.delMin())
        self.assertEqual(11, self.bh.delMin())
        self.assertEqual(14, self.bh.delMin())
        self.assertEqual(17, self.bh.delMin())
        self.assertEqual(18, self.bh.delMin())
        self.assertEqual(19, self.bh.delMin())
        self.assertEqual(21, self.bh.delMin())
        self.assertEqual(27, self.bh.delMin())
        self.assertEqual(1, self.bh.size())
        self.assertEqual(33, self.bh.delMin())
        self.assertTrue(self.bh.isEmpty())
        self.assertEqual(0, self.bh.size())

    def test_buildheap(self):
        self.assertTrue(self.bh.isEmpty())
        self.assertEqual(0, self.bh.size())
        alist = [9, 6, 5, 2, 3]
        self.bh.buildHeap(alist)
        self.assertFalse(self.bh.isEmpty())
        self.assertEqual(5, self.bh.size())
        self.assertEqual(2, self.bh.delMin())
        self.assertEqual(3, self.bh.delMin())
        self.assertEqual(5, self.bh.delMin())
        self.assertEqual(6, self.bh.delMin())
        self.assertEqual(9, self.bh.delMin())
        self.assertTrue(self.bh.isEmpty())
        self.assertEqual(0, self.bh.size())

if __name__ == '__main__':
    unittest.main()
