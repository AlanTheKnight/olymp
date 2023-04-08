def rotate(a, b, c):
    return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0])


def search(points):
    n = len(points)
    p = list(range(n))

    for i in range(1, n):
        if points[p[i]][1] > points[p[0]][1]:
            p[i], p[0] = p[0], p[i]

    ans = [p[0]]
    del p[0]
    p.append(ans[0])

    while True:
        right = 0
        for i in range(1, len(p)):
            if rotate(points[ans[-1]], points[p[right]], points[p[i]]) < 0:
                right = i
        if p[right] == ans[0]:
            break
        else:
            ans.append(p[right])
            del p[right]

    ans = list(map(lambda x: x + 1, ans))
    return ans


n = int(input())
a = []
for p in range(n):
    x, y = map(float, input().replace(",", ".").split())
    a.append((x, y))

print(*search(a))
