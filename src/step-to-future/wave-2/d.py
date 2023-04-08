n = int(input())

m = []

for i in range(n):
    m.append(list(map(int, input().split())))

p1 = [n - 1, 0]
p2 = [0, n - 1]

d1, d2 = 0, 0

dir1 = False
dir2 = False

while d1 != n - 1 and d2 != n - 1:
    print(m[p2[0]][p2[1]], end=" ")
    print(m[p1[0]][p1[1]], end=" ")
    
    if dir1:
        if p1[1] == 0:
            dir1 = False
            d1 += 1
            p1 = [p1[0] - 1 , p1[1]]
        else:
            p1 = [p1[0] - 1, p1[1] - 1]
    else:
        if p1[0] == n - 1:
            dir1 = True
            d1 += 1
            p1 = [p1[0], p1[1] + 1]
        else:
            p1 = [p1[0] + 1, p1[1] + 1]
    
    if dir2:
        if p2[0] == 0:
            dir2 = False
            d2 += 1
            p2 = [p2[0], p2[1] - 1]
            
        else:
            p2 = [p2[0] - 1, p2[1] - 1]
    else:
        if p2[1] == n - 1:
            dir2 = True
            d2 += 1
            p2 = [p2[0] + 1 , p2[1]]
        else:
            p2 = [p2[0] + 1, p2[1] + 1]



for i in range(0, n):
    print(m[i][i], end=" ")


print()
