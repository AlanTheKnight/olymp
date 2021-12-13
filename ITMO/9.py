def main(n):
    d = 2
    while n > 0:
        print(n, d)
        c = 0
        while n % d == 0:
            c += 1
            n = n // d
        if c != 0:
            yield d, c
        d += 1


n = 898425
print(list(main(n)))
