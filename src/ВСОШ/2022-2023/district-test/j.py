def solve():
    a, b, c, d = list(map(int, input().split()))
    if a * b == c * d: return "E"
    return "M" if a * b > c * d else "P"

print(solve())
