t = int(input()) # Кол-во баллов на карте
r = int(input()) # Кол-во динозавров в коллекции
l = int(input()) # Стоимость одного динозавра

p1 = int(input())
p2 = int(input())
p3 = int(input())

# Количество баллов, которое нужно набрать 
POINTS_NEEDED = r * l - t

s = p1 + p2 + p3

cnt = 3 * (POINTS_NEEDED // s)

left = POINTS_NEEDED % s
if left > 0:
    left -= p1
    cnt += 1

    if left > 0:
        left -= p2
        cnt += 1

print(cnt)
