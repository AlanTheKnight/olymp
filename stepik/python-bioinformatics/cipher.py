alph1 = input()
alph2 = input()
inp1 = input()
inp2 = input()

table1, table2 = {}, {}
for index, sym in enumerate(alph1):
    table1[sym] = alph2[index]
for index, sym in enumerate(alph2):
    table2[sym] = alph1[index]

print("".join([table1[sym] for sym in inp1]))
print("".join([table2[sym] for sym in inp2]))
