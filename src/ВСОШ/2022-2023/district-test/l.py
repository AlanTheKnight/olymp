n = int(input())

m, f = [], []
for _ in range(n):
    sex, h = map(int, input().split())
    if sex:
        f.append(h)
    else:
        m.append(h)

f.sort(reverse=True)
m.sort(reverse=True)

l = m + f

ans = 0
for i in range(1, len(l)):
    ans = max(ans, abs(l[i] - l[i - 1]))
print(ans)
