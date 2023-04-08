h, w, n = map(int, input().split())

screen = [["." for i in range(w)] for j in range(h)]
a = "abcdefgijklmnopqrstuvwxyz"

for w in range(n):
    y1, x1, y2, x2 = map(lambda x: int(x) - 1, input().split())

    for col in range(x1, x2 + 1):
        screen[y1][col] = a[w]
        screen[y2][col] = a[w]
    
    for row in range(y1, y2 + 1):
        screen[row][x1] = a[w]
        screen[row][x2] = a[w]


for row in screen:
    print("".join(row))
