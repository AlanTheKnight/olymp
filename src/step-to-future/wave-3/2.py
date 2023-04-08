n = input()
print(len(set(str(int(n, 6))).difference(set(n))))
