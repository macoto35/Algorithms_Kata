def revStr(s):
    if len(s) <= 1:
        return s

    return s[-1] + revStr(s[0:-1])

'dcba' == revStr('abcd')
'!dlrow ,olleH' == revStr('Hello, world!')
'' == revStr('')
'olleh' == revStr('hello')
'l' == revStr('l')
'wollof' == revStr('follow')

