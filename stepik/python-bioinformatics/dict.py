known = set()
d = int(input())
for _ in range(d):
    known.add(input().lower())

mistakes = set()
l = int(input())
for _ in range(l):
    text = input().lower().split()
    for word in text:
        if word not in known:
            mistakes.add(word)

print(*mistakes, sep="\n")
