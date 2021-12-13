n, k, m = map(int, input().split())
a = list(map(int, input().split()))
 
 
def count_zeros(nums):
    start = 0
    res = []
    count = 0
    minimal = 1e9
    for end in range(len(nums)):
        if nums[end] == 0:
            count += 1
        res.append(count)
        if end - start + 1 == k:
            if nums[start] == 0:
                count -= 1
            start += 1
        if end >= k - 1:
            minimal = min(minimal, res[end])
    return minimal
 
 
order = sorted(a, reverse=True)
win = None
for b in order:
    new = [i if i > b else 0 for i in a]
    zeros = count_zeros(new)
    if zeros < m:
        break
    win = sum(new) - b
print(win)