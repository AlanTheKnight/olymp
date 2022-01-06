def main(n):
    d = 2
    while n > 0:
        c = 0
        if d > 20: break
        print(n, d)
        while n % d == 0:
            print(n, "//", d, " = ", n // d)
            c += 1
            n //= d
        if c != 0:
            print(d, c)
        d += 1


n = 898425
print(list(main(n)))
