n = int(input())

coords = []
for i in range(n):
    x = int(input())
    y = int(input())
    coords.append([x, y, i + 1])

coords.sort(key=lambda x: (x[0], x[1]))

print(len(coords) - 1)
for i in range(len(coords) - 1):
    print(coords[i][2], coords[i + 1][2])
