def calc(n):
    ans = 0
    for i in range(1, n + 1):
        x = (n - i) // (i * i)
        if x == 0:
            break
        ans += x
        print(x, n - i, i * i)
    return ans


def main():
    i = 10**18
    desired = str(calc(i))
    print(desired)


main()
