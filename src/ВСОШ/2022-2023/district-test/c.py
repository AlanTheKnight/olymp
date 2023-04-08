from itertools import combinations

n, k = map(int, input().split())

c = tuple(map(int, input().split()))

combs = list(combinations(range(1, n + 1), k))

print(*combs[combs.index(c) + 1])
