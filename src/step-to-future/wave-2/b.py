def solve(n):
    cnt = 0
    while n:
        if n % 4 == 2:
            cnt += 1
        n //= 4
    return cnt


print(solve(int(input())))
