#n=input().replace(' ', '');print('ascending' if n=='12345678' else ('descending' if n=='87654321' else 'mixed'))
a=input()[::2];print({a:"mixed","12345678":"ascending","87654321":"descending"}[a])
