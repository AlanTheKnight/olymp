def main():
    s = input()
    m = {}
    for i in range(0, len(s)):
        index = 0 if i == len(s) - 1 else i + 1
        pair2 = s[i] + s[index]
        pair2 = "".join(sorted(pair2))
        if pair2 in m:
            m[pair2] += 1
        else:
            m[pair2] = 1
    return m


n = int(input())
shared = {}
for i in range(n):
    res = main()
    for key, val in res.items():
        if key in shared:
            shared[key] += val
        else:
            shared[key] = val


maximal = max(shared.values())
for key, value in shared.items():
    if value == maximal:
        print(key)
