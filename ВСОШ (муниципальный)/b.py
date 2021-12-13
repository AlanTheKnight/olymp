def dist(x1, y1, x2, y2):
    """Расстояние между двумя клетками."""
    return abs(x1 - x2) + abs(y1 - y2)


def get_center(n):
    """Вовзращает координаты центра клетки."""
    return (n - 1) // 2


n = int(input())
a = int(input())
b = int(input())
center = get_center(n)
for row in range(n):
    for col in range(n):
        if a <= dist(center, center, col, row) <= b:
            print('*', end='')
        else:
            print('.', end='')
    print()
