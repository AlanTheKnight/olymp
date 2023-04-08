def solve(n):
    n = list(reversed(str(n)))

    mnd = n[0]
    for d in n:
        mnd = min(mnd, d)

    return 2 * (10 ** n.index(mnd))

print(solve(int(input())))
