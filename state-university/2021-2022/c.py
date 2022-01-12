from itertools import combinations


def ok(comb):
    s = sum(comb)
    for i in range(0, len(comb)):
        cur = comb[i]
        if s - cur <= cur:
            return False
    return True


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    for i in range(3, n + 1):
        for comb in combinations(nums, i):
            if ok(comb):
                print(i)
                exit(0)
    print(-1)


main()
