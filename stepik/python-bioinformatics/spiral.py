from enum import Enum


class Direction(Enum):
    RIGHT = 0
    DOWN = 1
    LEFT = 2
    UP = 3


n = int(input())

# Print out n x n table filled with numbers from 1 to n x n
# in spiral order starting from the top left corner.

# Initialize the table
answer = [[0 for _ in range(n)] for _ in range(n)]

x, y = 0, 0
step = n
direction = Direction.RIGHT
i = 1

while i <= n * n:
    answer[x][y] = i
    i += 1

    if direction == Direction.RIGHT:
        if y + 1 < n and answer[x][y + 1] == 0:
            y += 1
        else:
            direction = Direction.DOWN
            step -= 1
            x += 1
    elif direction == Direction.DOWN:
        if x + 1 < n and answer[x + 1][y] == 0:
            x += 1
        else:
            direction = Direction.LEFT
            step -= 1
            y -= 1
    elif direction == Direction.LEFT:
        if y - 1 >= 0 and answer[x][y - 1] == 0:
            y -= 1
        else:
            direction = Direction.UP
            step -= 1
            x -= 1
    else:
        if x - 1 >= 0 and answer[x - 1][y] == 0:
            x -= 1
        else:
            direction = Direction.RIGHT
            step -= 1
            y += 1


for i in range(n):
    for j in range(n):
        print(answer[i][j], end=' ')
    print()
