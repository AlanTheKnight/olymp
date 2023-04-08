n = int(input())

alph = {}
for i in range(n):
    letter, value = input().split()
    alph[letter] = int(value)


s = list(input())


cnt = 0
for i in range(len(s)):
    for j in range(len(s) - 1):
        if alph[s[j]] > alph[s[j + 1]]:
            s[j], s[j + 1] = s[j + 1], s[j]
            cnt += 1

print(cnt)
