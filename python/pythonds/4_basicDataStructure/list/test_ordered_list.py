import unittest
from ordered_list import OrderedList

class TestOrderedList(unittest.TestCase):
    def setUp(self):
        self.ol = OrderedList()

    def test_isEmpty(self):
        self.assertTrue(self.ol.isEmpty())
        self.ol.add(1)
        self.assertFalse(self.ol.isEmpty())

    def test_size(self):
        self.assertEqual(0, self.ol.size())
        self.ol.add(1)
        self.assertEqual(1, self.ol.size())

    def test_index(self):
        self.ol.add(1)
        self.ol.add(2)
        self.assertEqual(0, self.ol.index(1))
        self.assertEqual(1, self.ol.index(2))
        self.assertIsNone(self.ol.index(3))

    def test_search(self):
        self.ol.add(1)
        self.assertTrue(self.ol.search(1))
        self.assertFalse(self.ol.search(2))

    def test_add(self):
        self.ol.add(5)
        self.ol.add(3)
        self.ol.add(7)
        self.ol.add(6)
        self.assertEqual(0, self.ol.index(3))
        self.assertEqual(1, self.ol.index(5))
        self.assertEqual(2, self.ol.index(6))
        self.assertEqual(3, self.ol.index(7))

    def test_remove(self):
        # 3->5->6->7
        self.ol.add(5)
        self.ol.add(3)
        self.ol.add(7)
        self.ol.add(6)
        self.assertEqual(6, self.ol.remove(6))
        self.assertEqual(7, self.ol.remove(7))
        self.assertEqual(3, self.ol.remove(3))
        self.assertEqual(0, self.ol.index(5))
        with self.assertRaises(ValueError):
            self.ol.remove(3)

    def test_pop(self):
        # 3->5->6->7
        self.ol.add(5)
        self.ol.add(3)
        self.ol.add(7)
        self.ol.add(6)
        self.assertEqual(7, self.ol.pop())
        self.assertEqual(6, self.ol.pop())
        self.assertEqual(5, self.ol.pop())
        self.assertEqual(3, self.ol.pop())

    def test_pop_pos(self):
        # 3->5->6->7
        self.ol.add(5)
        self.ol.add(3)
        self.ol.add(7)
        self.ol.add(6)
        self.assertEqual(6, self.ol.pop_pos(2))
        self.assertEqual(7, self.ol.pop_pos(2))
        self.assertEqual(3, self.ol.pop_pos(0))
        self.assertEqual(5, self.ol.pop_pos(0))

if __name__ == '__main__':
    unittest.main()

