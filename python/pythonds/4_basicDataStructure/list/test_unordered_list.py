import unittest
from unordered_list import UnorderedList

class TestUnorderedList(unittest.TestCase):
    def setUp(self):
        self.l = UnorderedList()

    def test_all(self):
        self.assertTrue(self.l.isEmpty())
        # 54 26 93 17 77 31
        self.l.add(31)
        self.l.add(77)
        self.l.add(17)
        self.l.add(93)
        self.l.add(26)
        self.l.add(54)
        
        self.assertFalse(self.l.isEmpty())
        self.assertEqual(6, self.l.size())
        self.assertTrue(self.l.search(93))
        self.assertEqual(2, self.l.index(93))
        self.assertFalse(self.l.search(100))
        self.assertIsNone(self.l.index(100))

        # 100 54 26 93 17 77 31
        self.l.add(100)
        self.assertTrue(self.l.search(100))
        self.assertEqual(0, self.l.index(100))
        self.assertEqual(7, self.l.size())

        # 100 26 93 17 77 31
        self.assertEqual(2, self.l.index(26))
        self.l.remove(54)
        self.assertEqual(6, self.l.size())
        self.assertEqual(1, self.l.index(26))
        # 100 26 17 77 31
        self.assertEqual(3, self.l.index(17))
        self.l.remove(93)
        self.assertEqual(5, self.l.size())
        self.assertEqual(2, self.l.index(17))
        # 100 26 17 77
        self.assertEqual(3, self.l.index(77))
        self.l.remove(31)
        self.assertEqual(4, self.l.size())
        self.assertEqual(3, self.l.index(77))
        self.assertFalse(self.l.search(93))

    def test_appendInsertPop(self):
        # 31 93 77 17
        self.l.append(77)
        self.l.insert(31, 0)
        self.l.append(17)
        self.l.insert(93, 1)

        self.assertEqual(4, self.l.size())
        self.assertEqual(0, self.l.index(31))
        self.assertEqual(1, self.l.index(93))
        self.assertEqual(2, self.l.index(77))
        self.assertEqual(3, self.l.index(17))

        # 31 93 77
        self.l.pop()
        self.assertEqual(0, self.l.index(31))
        self.assertEqual(1, self.l.index(93))
        self.assertEqual(2, self.l.index(77))

        # 31 77
        self.l.pop(1)
        self.assertEqual(0, self.l.index(31))
        self.assertEqual(1, self.l.index(77))

    def test_dupitem(self):
        self.l.append(3)
        self.l.append(3)
        self.l.append(2)
        self.l.append(3)

        self.assertEqual(4, self.l.size())
        self.l.remove(3)
        self.assertTrue(self.l.search(3))
        self.assertEqual(0, self.l.index(3))
        self.assertEqual('[3, 2, 3]', self.l.__str__())

    def test_slice(self):
        self.assertEqual([], self.l.slice(0, 5))
        # 1 2 3 4 5
        self.l.append(1)
        self.l.append(2)
        self.l.append(3)
        self.l.append(4)
        self.l.append(5)
        self.assertEqual([1, 2], self.l.slice(0, 2))
        self.assertEqual([3, 4, 5], self.l.slice(2, 5))


if __name__ == '__main__':
    unittest.main()
