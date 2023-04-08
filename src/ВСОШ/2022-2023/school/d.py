n = int(input())
k = int(input())

for i in range(n):
    x = int(input())

    if x == 1:
        continue

    cnt = 0
    while k < x - 1:
        x //= 2
        cnt += k
    cnt += x - 1

print(cnt)
