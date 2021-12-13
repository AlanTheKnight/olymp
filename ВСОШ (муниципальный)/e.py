from itertools import combinations

def factor(n):
    ans = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            ans.append(d)
            n //= d
        else:
            d += 1
    if n > 1:
        ans.append(n)
    return ans


def print_out(nums):
    for i in nums:
        print(i, end=' ')
    print()


n = int(input())
res = factor(abs(n))
if n > 0:
    print_out(res)


start = 2 if n > 0 else 1
for i in range(start, len(res) + 1, 2):
    r = set(combinations(res, i))
    for case in r:
        res_copy = res.copy()
        for value in case:
            res_copy.remove(value)
            res_copy.append(-value)
        print_out(res_copy)
