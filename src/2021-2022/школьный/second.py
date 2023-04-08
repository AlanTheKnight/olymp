x, y, n = int(input()), int(input()), int(input())
if (n % (x + y)) == 0:
    res = int((n / (x + y))*2)
else:
    if (n % (x + y)) <= y:
        res = int(((n // (x + y))*2)+1)
    else:
        res = int(((n // (x + y))*2)+2)
print(res)
