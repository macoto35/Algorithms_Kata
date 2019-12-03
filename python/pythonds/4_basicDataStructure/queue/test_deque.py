import unittest
from deque import Deque

class TestDeque(unittest.TestCase):
    def setUp(self):
        self.d = Deque()

    def test_all(self):
        self.assertTrue(self.d.isEmpty())
        self.d.addRear(4)
        self.d.addRear('dog')
        self.d.addFront('cat')
        self.d.addFront(True)
        self.assertEqual(4, self.d.size())
        self.assertFalse(self.d.isEmpty())
        self.d.addRear(8.4)
        self.assertEqual(8.4, self.d.removeRear())
        self.assertTrue(self.d.removeFront())

if __name__ == '__main__':
    unittest.main()
