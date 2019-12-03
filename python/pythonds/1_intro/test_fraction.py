import unittest
from fraction import Fraction

class FractionTest(unittest.TestCase):
    def setUp(self):
        self.f1 = Fraction(4, 6)
        self.f2 = Fraction(4, 16)
        self.f3 = Fraction(4, -6)
        self.f4 = Fraction(2, 5)

    def test_nan(self):
        with self.assertRaises(ValueError):
            Fraction(1, 'a')
            Fraction('a', 1)
            Fraction('a', 'b')

    def test_str(self):
        self.assertEqual(self.f1.__str__(), '2/3')
        self.assertEqual(self.f2.__str__(), '1/4')
        self.assertEqual(self.f3.__str__(), '-2/3')

    def test_add(self):
        self.assertEqual((self.f1 + self.f2).__str__(), '11/12')
        self.assertEqual((self.f3 + self.f2).__str__(), '-5/12')

    def test_radd(self):
        self.assertEqual((self.f1 + 2).__str__(), '8/3')
        self.assertEqual((2 + self.f1).__str__(), '8/3')

    def test_iadd(self):
        self.f4 += 2
        self.assertEqual(self.f4.__str__(), '12/5')

    def test_sub(self):
        self.assertEqual((self.f1 - self.f2).__str__(), '5/12')
        self.assertEqual((self.f3 - self.f2).__str__(), '-11/12')
    
    def test_mul(self):
        self.assertEqual((self.f1 * self.f2).__str__(), '1/6')
        self.assertEqual((self.f3 * self.f2).__str__(), '-1/6')

    def test_div(self):
        self.assertEqual((self.f1 / self.f2).__str__(), '8/3')
        self.assertEqual((self.f3 / self.f2).__str__(), '-8/3')

    def test_getNum(self):
        self.assertEqual(self.f1.getNum(), 2)
        self.assertEqual(self.f3.getNum(), -2)

    def test_getDen(self):
        self.assertEqual(self.f1.getDen(), 3)
        self.assertEqual(self.f3.getDen(), 3)

    def test_lessThan(self):
        self.assertFalse(self.f1 < self.f2)
        self.assertTrue(self.f3 < self.f2)

    def test_lessThanEqual(self):
        self.assertFalse(self.f1 <= self.f2)
        self.assertTrue(self.f3 <= self.f2)
    
    def test_equal(self):
        self.assertFalse(self.f1 == self.f2)
    
    def test_notEqual(self):
        self.assertTrue(self.f1 != self.f2)
    
    def test_greaterThan(self):
        self.assertTrue(self.f1 > self.f2)
        self.assertFalse(self.f3 > self.f2)
    
    def test_greaterThanEqual(self):
        self.assertTrue(self.f1 >= self.f2)
        self.assertFalse(self.f3 >= self.f2)

if __name__ == '__main__':
    unittest.main()
