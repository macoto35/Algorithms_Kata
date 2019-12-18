from stack import Stack

def infixToPostfix(str):
    try:
        opstack = Stack()
        output = []
        prec = {'+': 2, '-': 2, '*': 3, '/': 3, '**': 4, '(': 1}

        for token in str.upper().split():
            if token in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' or token in '01234567890':
                output.append(token)
            elif token == '(':
                opstack.push(token)
            elif token == ')':
                while opstack.peek() != '(':
                    output.append(opstack.pop())
                opstack.pop() # pop out open parentheses
            elif token in prec:
                while not opstack.isEmpty() and prec[token] <= prec[opstack.peek()]:
                    output.append(opstack.pop())
                opstack.push(token)
            else:
                raise ValueError

        while not opstack.isEmpty():
            output.append(opstack.pop())

        #print(str, ': ', output)
        return ' '.join(output)
    
    except:
        return ''

def postfixEval(str):
    try:
        opstack = Stack()

        for token in str.split():
            if token in '0123456789':
                opstack.push(int(token))
            else:
                second = opstack.pop()
                first = opstack.pop()
                opstack.push(doMath(first, second, token))
    
        return opstack.pop()
    except:
        return None

def doMath(first, second, operand):
    if operand == '+':
        return first + second
    elif operand == '-':
        return first - second
    elif operand == '*':
        return first * second
    elif operand == '/':
        return first / second
    elif operand == '**':
        return first ** second
    else:
        raise ValueError

def infixEval(str):
    tmp = infixToPostfix(str)
    if len(tmp) > 0:
        return postfixEval(tmp)
    else:
        return None

assert '' == infixToPostfix('A # B')
assert 'A B +' == infixToPostfix('A + B')
assert 'A B C * +' == infixToPostfix('A + B * C')
assert 'A B + C *' == infixToPostfix('( A + B ) * C')
assert 'A B C * + D +' == infixToPostfix('A + B * C + D')
assert 'A B + C D + *' == infixToPostfix('( A + B ) * ( C + D )')
assert 'A B * C D * +' == infixToPostfix('A * B + C * D')
assert 'A B + C + D +' == infixToPostfix('A + B + C + D')
assert 'A B C * +' == infixToPostfix('( A + ( B * C ) )')
assert 'A B + C * D E - F G + * -' == infixToPostfix('( A + B ) * C - ( D - E ) * ( F + G )')
assert 'A B C D - ** *' == infixToPostfix('A * B ** ( C - D )')
assert 'A B C ** * D *' == infixToPostfix('A * B ** C * D')

assert postfixEval('1 2 #') == None
assert postfixEval('1 2 +') == 1+2
assert postfixEval('4 5 6 * +') == 4+5*6
assert postfixEval('2 3 + 4 *') == (2+3)*4
assert postfixEval('4 5 6 * + 7 +') == 4+5*6+7
assert postfixEval('1 2 + 3 4 + *') == (1+2)*(3+4)
assert postfixEval('2 3 * 4 5 * +') == 2*3+4*5
assert postfixEval('2 3 + 4 + 5 +') == 2+3+4+5
assert postfixEval('4 5 6 * +') == (4+(5*6))
assert postfixEval('3 4 + 5 * 6 7 - 8 9 + * -') == (3+4)*5-(6-7)*(8+9)
assert postfixEval('7 8 + 3 2 + /') == (7+8)/(3+2)
assert postfixEval('5 3 4 2 - ** *') == 5*3**(4-2)
assert postfixEval('5 3 4 ** * 2 *') == 5*3**4*2

assert None == infixEval('1 # 2')
assert 1+2 == infixEval('1 + 2')
assert 1+2*3 == infixEval('1 + 2 * 3')
assert (1+2)*3 == infixEval('( 1 + 2 ) * 3')
assert 1+2*3+4 == infixEval('1 + 2 * 3 + 4')
assert (1+2)*(3+4) == infixEval('( 1 + 2 ) * ( 3 + 4 )')
assert 1*2+3*4 == infixEval('1 * 2 + 3 * 4')
assert 1+2+3+4 == infixEval('1 + 2 + 3 + 4')
assert (1+(2*3)) == infixEval('( 1 + ( 2 * 3 ) )')
assert (1+2)*3-(5-2)*(3+4) == infixEval('( 1 + 2 ) * 3 - ( 5 - 2 ) * ( 3 + 4 )')
assert 2*3**(4-2) == infixEval('2 * 3 ** ( 4 - 2 )')
assert 1*2**5*3 == infixEval('1 * 2 ** 5 * 3')

