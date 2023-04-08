from itertools import permutations


letters = "a, b, c, c, d, d, d".split(", ")


s = set()
for comb in permutations(letters):
    s.add("".join(comb))
print(len(s))
