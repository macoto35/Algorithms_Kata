import unittest
from binary_search_tree import BinarySearchTree 

class TestBinarySearchTree(unittest.TestCase):
    def setUp(self):
        self.bst = BinarySearchTree()

        self.bst[70] = '1st'
        self.bst[31] = '2nd'
        self.bst[93] = '3rd'
        self.bst[99] = '4th'
        self.bst.put(14, '5th')
        self.bst.put(23, '6th')
        self.bst.put(73, '7th')
        self.bst.put(71, '8th')
        self.bst.put(82, '9th')
        self.bst.put(95, '10th')
        self.bst.put(102, '11th')
        print('bst:', self.bst)

    '''def test_getContains(self):
        self.assertIsNone(self.bst[40])
        self.assertEqual('1st', self.bst[70])
        self.assertEqual('2nd', self.bst[31])
        self.assertEqual('3rd', self.bst[93])
        self.assertEqual('4th', self.bst[99])
        self.assertEqual('5th', self.bst.get(14))
        self.assertEqual('6th', self.bst.get(23))
        self.assertEqual('7th', self.bst.get(73))
        self.assertEqual('8th', self.bst.get(71))
        self.assertEqual('9th', self.bst.get(82))
        self.assertEqual('10th', self.bst.get(95))
        self.assertEqual('11th', self.bst.get(102))
        self.assertTrue(23 in self.bst)
        self.assertFalse(111 in self.bst)

    def test_del(self):
        size = self.bst.size
        result = ['14, 23, 31, 71, 73, 82, 93, 95, 99, 102, '
                  , '14, 23, 31, 73, 82, 93, 95, 99, 102, '
                  , '14, 23, 31, 82, 93, 95, 99, 102, '
                  , '14, 23, 31, 93, 95, 99, 102, '
                  , '14, 23, 31, 95, 99, 102, '
                  , '14, 23, 31, 99, 102, '
                  , '14, 23, 31, 102, '
                  , '14, 23, 31, '
                  , '14, 23, '
                  , '23, '
                  , '']

        for i in range(size):
            del self.bst[self.bst.root.key]
            self.assertEqual(result[i], str(self.bst))'''

    def test_iter(self):
        i = iter(self.bst)
        print(next(i))
        print(next(i))

if __name__ == '__main__':
    unittest.main()
