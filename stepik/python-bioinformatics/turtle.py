n = int(input())

x, y = 0, 0
for _ in range(n):
    direction, distance = input().split()
    distance = int(distance)
    if direction == "север":
        y += distance
    elif direction == "юг":
        y -= distance
    elif direction == "восток":
        x += distance
    else:
        x -= distance

print(x, y)
