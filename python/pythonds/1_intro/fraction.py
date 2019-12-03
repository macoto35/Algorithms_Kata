def gcd(m, n):
    while n != 0:
        m, n = n, m%n
    return m

class Fraction:
    def __init__(self, top, bottom):
        try:
            top = int(top)
            bottom = int(bottom)

            common = gcd(top, bottom)
            self.num = top // common
            self.den = bottom // common
        except:
            raise ValueError

    def __repr__(self):
        return str(self.num) + '/' + str(self.den)
    
    '''def __str__(self):
        return str(self.num) + '/' + str(self.den)'''

    def __add__(self, other):
        if isinstance(other, Fraction):
            newnum = self.num*other.den + other.num*self.den
            newden = self.den*other.den
            return Fraction(newnum, newden)
        else:
            newnum = self.num + self.den*other
            return Fraction(newnum, self.den)

    def __radd__(self, other):
        return self.__add__(other)

    def __iadd__(self, other):
        return self.__add__(other)

    def __sub__(self, other):
        newnum = self.num*other.den - other.num*self.den
        newden = self.den*other.den
        return Fraction(newnum, newden)

    def __mul__(self, other):
        newnum = self.num*other.num
        newden = self.den*other.den
        return Fraction(newnum, newden)

    def __truediv__(self, other):
        newnum = self.num*other.den
        newden = self.den*other.num
        return Fraction(newnum, newden)

    def __lt__(self, other):
        return self.num*other.den < other.num*self.den

    def __le__(self, other):
        return self.num*other.den <= other.num*self.den
    
    def __eq__(self, other):
        return self.num*other.den == other.num*self.den
    
    def __ne__(self, other):
        return self.num*other.den != other.num*self.den
    
    def __gt__(self, other):
        return self.num*other.den > other.num*self.den
    
    def __ge__(self, other):
        return self.num*other.den >= other.num*self.den
    
    def getNum(self):
        return self.num

    def getDen(self):
        return self.den

