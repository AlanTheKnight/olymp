nums = list(map(int, input().split()))

mx = -10 ** 9
for i in range(4):
    for j in range(4):
        if i == j:
            continue
        s = [nums[k] for k in range(len(nums)) if k != i and k != j]
        f = [nums[i], nums[j]]
        mx = max(mx, f[0] * f[1] + s[0] * s[1])
print(mx)
