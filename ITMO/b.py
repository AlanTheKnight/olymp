n = 1
while True:
    x = 32 ** n + 16 ** n + 4 ** n 
    x = bin(x).split('b')[1]
    print(x.count('1'))
    if x.count('1' * 40) == 1:
        print(n)
    n += 1