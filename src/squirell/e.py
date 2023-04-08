alph = "0123456789ABCDEFG"


def convert(n, base):
    a = []
    while n:
        a.append(n % base)
        n //= base
    a.append(n % base)
    a.reverse()
    while a[0] == 0:
        del a[0]
    return len(a)


print(convert(38416, 3), convert(537823, 3))
