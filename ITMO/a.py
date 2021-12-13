s = 0
n = 0
while True:
    hexa = hex(33 ** n).split('x')[1]
    if len(hexa) > 2:
        hexa = hexa[-2] + hexa[-1]
    print(hexa)
    last = int(hexa, 16)
    print(last)
    s += last
    n += 1
    print("Сумма чисел до ", n, " равна ", s)
    if s >= 447:
        break
print(s)
