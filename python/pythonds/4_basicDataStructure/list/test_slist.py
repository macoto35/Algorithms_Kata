import unittest
from slist import SList

class TestSList(unittest.TestCase):
    def setUp(self):
        self.list = SList()

    def test_isEmpty(self):
        self.assertTrue(self.list.isEmpty())
        self.list.append('new')
        self.assertFalse(self.list.isEmpty())

    def test_size(self):
        self.assertEqual(0, self.list.size())
        self.list.append('new1')
        self.assertEqual(1, self.list.size())
        self.list.append('new2')
        self.list.append('new3')
        self.assertEqual(3, self.list.size())

    def test_index(self):
        self.assertIsNone(self.list.index('not exist'))
        self.list.append('1')
        self.list.append('2')
        self.list.append('3')
        self.assertEqual(0, self.list.index('1'))
        self.assertEqual(1, self.list.index('2'))
        self.assertEqual(2, self.list.index('3'))
        self.list.pop()
        self.assertIsNone(self.list.index('3'))

    def test_search(self):
        self.assertFalse(self.list.search('1'))
        self.list.append('1')
        self.assertTrue(self.list.search('1'))
        self.assertFalse(self.list.search('2'))

    def test_insertAppendAdd(self):
        self.list.append('1')
        self.list.append('2')
        self.list.add('3')
        self.list.add('4')
        self.list.insert(2, '5')
        self.list.insert(0, '6')
        self.list.insert(7, '7')
        # [6,4,3,5,1,2,7]
        self.assertEqual('6', self.list.get(0))
        self.assertEqual('4', self.list.get(1))
        self.assertEqual('3', self.list.get(2))
        self.assertEqual('5', self.list.get(3))
        self.assertEqual('1', self.list.get(4))
        self.assertEqual('2', self.list.get(5))
        self.assertEqual('7', self.list.get(6))

    def test_popRemove(self):
        self.list.append('1')
        self.list.append('2')
        self.list.add('3')
        self.list.add('4')
        self.list.insert(2, '5')
        self.list.insert(0, '6')
        self.list.insert(7, '7')
        # [6,4,3,5,1,2,7]
        self.assertEqual('7', self.list.pop())
        self.assertEqual('6', self.list.pop(0))
        self.assertEqual('5', self.list.remove('5'))
        # [4,3,1,2]
        self.list.append('8')

if __name__ == '__main__':
    unittest.main()
