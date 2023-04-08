def solve(x):
    ans = 0
    for i in range(3, len(x)):
        if int(x[i-3:i-1]) % 8 == int(x[i-1:i+1]) % 8:
            ans = len(x) - i
    return ans


print(solve(input()))
