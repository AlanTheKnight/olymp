with open("c.txt", "r") as f:
    data = list(map(int, f.readlines()))


rainy_cnt = 0
clear_cnt = 0
for i in range(1, len(data)):
    if data[i] == 2 and data[i - 1] == 2:
        rainy_cnt += 1
    if data[i] == 2 and data[i - 1] == 0:
        clear_cnt += 1

print(max(rainy_cnt, clear_cnt) - min(rainy_cnt, clear_cnt))
