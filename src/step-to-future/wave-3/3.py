arr = []
expr = input()
while expr != ".":
    arr.append(eval(expr))
    expr = input()

mx_len, mx_len_sum, mx_len_l, mx_len_r, l, l_l, cur = 0, 0, 0, 0, 0, 0, 0
for i, val in enumerate(arr):
    cur += val
    if cur >= 0:
        l_l = i + 1
        cur = 0
        l = 0
    else:
        l += 1
        if l > mx_len or (l == mx_len and cur < mx_len_sum):
            mx_len = l
            mx_len_l = l_l
            mx_len_r = i
            mx_len_sum = cur

print(mx_len_l + 1, mx_len_r + 1)
