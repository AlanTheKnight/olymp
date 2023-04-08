a = [0] * 41

for i in range(2, 41):
    a[i] = a[i - 1]
    if i % 3 == 0:
        a[i] += a[i // 3]

print(a[20])

# 2 + 2 + 2
# 2 + 2 * 2

