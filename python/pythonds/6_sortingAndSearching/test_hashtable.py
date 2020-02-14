import unittest
from hashtable import HashTable

class TestHashTable(unittest.TestCase):
    def setUp(self):
        self.ht = HashTable()

    def test_putget(self):
        self.ht.put(54, 'A')
        self.ht.put(26, 'B')
        self.ht.put(93, 'C')
        self.ht.put(54, 'D')
        self.ht.put(17, 'E')
        self.ht.put(77, 'F')
        self.ht.put(17, 'G')
        self.ht.put(31, 'H')
        self.ht.put(44, 'I')
        self.ht.put(55, 'J')
        self.ht.put(20, 'K')

        '''
        self.assertEqual('D', self.ht.data[10])
        self.assertEqual('B', self.ht.data[4])
        self.assertEqual('C', self.ht.data[5])
        self.assertEqual('G', self.ht.data[6])
        self.assertEqual('F', self.ht.data[0])
        self.assertEqual('H', self.ht.data[9])
        self.assertEqual('I', self.ht.data[1])
        self.assertEqual('J', self.ht.data[2])
        self.assertEqual('K', self.ht.data[3])
        '''
        self.assertEqual('D', self.ht.get(54))
        self.assertEqual('B', self.ht.get(26))
        self.assertEqual('C', self.ht.get(93))
        self.assertEqual('G', self.ht.get(17))
        self.assertEqual('F', self.ht.get(77))
        self.assertEqual('H', self.ht.get(31))
        self.assertEqual('I', self.ht.get(44))
        self.assertEqual('J', self.ht.get(55))
        self.assertEqual('K', self.ht.get(20))

    def test_getsetitem(self):
        self.ht[54]='cat'
        self.ht[26]='dog'
        self.ht[93]='lion'
        self.ht[17]='tiger'
        self.ht[77]='bird'
        self.ht[31]='cow'
        self.ht[44]='goat'
        self.ht[55]='pig'
        self.ht[20]='chicken'

        #print(self.ht.slots)
        #print(self.ht.data)
        self.assertEqual('chicken', self.ht[20])
        self.assertEqual('tiger', self.ht[17])

        self.ht[20] = 'duck'
        self.assertEqual('duck', self.ht[20])
        #print(self.ht.data)

        self.assertIsNone(self.ht[99])

    def test_delete(self):
        self.ht.put(54, 'A')
        self.ht.put(26, 'B')
        self.ht.put(93, 'C')

        del self.ht[54]
        self.assertIsNone(self.ht.get(54))

    def test_len(self):
        self.ht.put(54, 'A')
        self.ht.put(26, 'B')
        self.ht.put(93, 'C')
        self.assertEqual(3, len(self.ht))
        self.ht.put(54, 'D')
        self.assertEqual(3, len(self.ht))
        self.ht.put(17, 'E')
        self.assertEqual(4, len(self.ht))
        del self.ht[26]
        self.assertEqual(3, len(self.ht))
        del self.ht[93]
        self.assertEqual(2, len(self.ht))

    def test_in(self):
        self.ht.put(54, 'A')
        self.ht.put(26, 'B')
        self.ht.put(93, 'C')
        
        self.assertTrue(54 in self.ht)
        self.assertFalse(55 in self.ht)
        self.assertTrue(26 in self.ht)
        self.assertTrue(93 in self.ht)

if __name__ == '__main__':
    unittest.main()
