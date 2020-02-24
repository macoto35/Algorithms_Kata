import unittest
from avl_tree import AvlTree

class TestAvlTree(unittest.TestCase):
    def setUp(self):
        self.avl = AvlTree()
        
        self.avl[70] = '1st'
        self.avl[31] = '2nd'
        self.avl[93] = '3rd'
        self.avl[99] = '4th'
        self.avl.put(14, '5th')
        self.avl.put(23, '6th')
        self.avl.put(73, '7th')
        self.avl.put(71, '8th')
        self.avl.put(82, '9th')
        self.avl.put(95, '10th')
        self.avl.put(80, '11th')

    def test_getContains(self):
        keys = [14, 23, 31, 70, 71, 73, 80, 82, 93, 95, 99]
        bfs = [0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1]
        it = iter(self.avl)
        i = 0
        for e in it:
            self.assertEqual(keys[i], e.key)
            self.assertEqual(bfs[i], e.balanceFactor)
            i += 1

        self.assertIsNone(self.avl[40])
        self.assertEqual('1st', self.avl[70])
        self.assertEqual('2nd', self.avl[31])
        self.assertEqual('3rd', self.avl[93])
        self.assertEqual('4th', self.avl[99])
        self.assertEqual('5th', self.avl.get(14))
        self.assertEqual('6th', self.avl.get(23))
        self.assertEqual('7th', self.avl.get(73))
        self.assertEqual('8th', self.avl.get(71))
        self.assertEqual('9th', self.avl.get(82))
        self.assertEqual('10th', self.avl.get(95))
        self.assertEqual('11th', self.avl.get(80))
        self.assertTrue(23 in self.avl)
        self.assertFalse(111 in self.avl)

    def test_del(self):
        size = self.avl.size
        result = ['[14,0], [23,0], [31,0], [70,1], [71,0], [80,0], [82,0], [93,-1], [95,0], [99,1], '
                  , '[14,0], [23,0], [31,0], [70,1], [71,0], [82,1], [93,0], [95,0], [99,0], '
                  , '[14,0], [23,0], [31,0], [70,1], [71,0], [93,1], [95,-1], [99,0], '
                  , '[14,0], [23,0], [31,0], [70,0], [71,0], [95,0], [99,0], '
                  , '[14,0], [23,0], [31,0], [71,0], [95,-1], [99,0], '
                  , '[14,0], [23,0], [31,0], [95,1], [99,0], '
                  , '[14,0], [23,-1], [31,0], [99,1], '
                  , '[14,0], [31,0], [99,0], '
                  , '[14,0], [99,1], '
                  , '[14,0], '
                  , '']

        for i in range(size):
            del self.avl[self.avl.root.key]
            self.assertEqual(result[i], str(self.avl))

if __name__ == '__main__':
    unittest.main()
