matrix = []
s = input()
while s != 'end':
    matrix.append([int(i) for i in s.split()])
    s = input()

height = len(matrix)
width = len(matrix[0])


def convert(index, limit):
    if index == limit:
        return 0
    return index
    

new_matrix = [[0 for _ in range(width)] for _ in range(height)]
for i in range(height):
    for j in range(width):
        indexes = [[i + 1, j], [i - 1, j], [i, j + 1], [i, j - 1]]
        indexes = list(map(lambda x: [convert(x[0], height), convert(x[1], width)], indexes))
        new_matrix[i][j] = sum(map(lambda x: matrix[x[0]][x[1]], indexes))

for row in new_matrix:
    print(*row)
