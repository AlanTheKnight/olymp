from math import sqrt
from collections import Counter


def factors(n):
    j = 2
    while n > 1:
        for i in range(j, int(sqrt(n+0.05)) + 1):
            if n % i == 0:
                n //= i
                j = i
                yield i
                break
        else:
            if n > 1:
                yield n
                break


q = int(input())

cnt = Counter([i for i in factors(q) if i != 2] * 2)

ans = 1
for i, j in cnt.items():
    ans *= j + 1

print(ans)
