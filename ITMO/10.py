def main(n):
    c = 7
    i = 0
    while n != 0:
        t = 0
        while n >= c:
            t += 1
            n -= c
        yield i, n
        i += 1
        n = t



J = 344678
print(list(main(J)))
        