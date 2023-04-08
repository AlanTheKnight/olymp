DELTA = [(0, 1), (1, 0), (-1, 0), (0, -1)]

k, n, m = map(int, input().split())

font = []
for i in range(k):
    char = []
    for j in range(16):
        char.append(input())
    font.append(char)


g = [[0 for _col in range(8 * m)] for _row in range(16 * n)]

for i in range(n):
    r = list(map(lambda x: int(x) - 1, input().split()))
    for j in range(m):
        for _row in range(16):
            for _col in range(8):
                g[16 * i + _row][8 * j + _col] = font[r[j]][_row][_col]


def dfs(row, col):
    if g[row][col] != "0":
        return 0
    g[row][col] = " "
    cnt = 1
    for dx, dy in DELTA:
        n_row, n_col = row + dy, col + dx
        if 0 <= n_row < 16 * n and 0 <= n_col < 8 * m:
            cnt += dfs(n_row, n_col)
    return cnt


for r in range(0, 16 * n):
    dfs(r, 0)
    dfs(r, 8 * m - 1)

for c in range(0, 8 * n):
    dfs(0, c)
    dfs(16 * n - 1, c)

mx = 0
for r in range(0, 16 * n):
    for c in range(0, 8 * m):
        if g[r][c] == "0":
            mx = max(dfs(r, c), mx)
print(mx)
