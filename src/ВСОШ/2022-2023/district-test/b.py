from math import log, ceil

a = {"$": -1, "1": 1, "0": 0}


def checker(ans: str):
    return sum([(a[ans[-(i + 1)]]) * 3 ** i for i in range(0, len(ans))])


def solve():
    n = int(input())
    rvrsed = n < 0
    n = abs(n)

    l = ceil(log(n, 3))
    res = [0] * (l + 1)
    res[0] = 1
    left = n - l
    print(left)


# print(checker("1$1"))
solve()
