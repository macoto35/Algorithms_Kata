
def removeWhite(s):
    return ''.join([c for c in s.lower() if c in '0123456789abcdefghijklmnopqrstuvwxyz'])

def isPal(s):
    #print('enter isPal: ', s)
    if len(s) <= 1:
        return True
    return s[0] == s[-1] and isPal(s[1:-1])

assert True == isPal(removeWhite('kayak'))
assert True == isPal(removeWhite('aibohphobia'))
assert True == isPal(removeWhite('Live not on evil'))
assert True == isPal(removeWhite('Reviled did I live, said I, as evil I did deliver'))
assert True == isPal(removeWhite("Go hang a salami; I'm a lasagna hog."))
assert True == isPal(removeWhite('Able was I ere I saw Elba'))
assert True == isPal(removeWhite('Kanakanak'))
assert True == isPal(removeWhite('Wassamassaw'))
assert True == isPal(removeWhite('x'))
assert True == isPal(removeWhite('radar'))
assert False == isPal(removeWhite('hello'))
assert True == isPal(removeWhite(''))
assert True == isPal(removeWhite('hannah'))
assert True == isPal(removeWhite("madam i'm adam"))

