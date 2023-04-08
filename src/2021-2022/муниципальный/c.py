n = int(input())
trainings = list(map(int, input().split()))
s = 0
for i in range(n):
    x, y = map(int, input().split())
    if trainings[i] and y > x:
        s += y - x
print(s)
