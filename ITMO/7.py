import prettytable


t = prettytable.PrettyTable(["A", "B", "C", "A^B", "A^C", "B^C", "not A or C", "not A or not B", "B => A and C", "f"])

def func(a, b, c):
    if (not (a ^ c)):
        return not a or c
    elif a ^ c:
        return not a or not b
    elif b ^ c:
        return (not b or a) and c

for a in [True, False]:
    for b in [True, False]:
        for c in [True, False]:
            t.add_row([a, b, c, a ^ b, a ^ c, b ^ c, not a or c, not a or not b, (not b or a) and c, func(a, b, c)])

print(t)