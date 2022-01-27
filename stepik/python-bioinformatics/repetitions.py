FILENAME = "dataset_3363_2.txt"

with open(FILENAME, "r") as f:
    data = f.read()

answer = ""
digit_part = ""
i = 0
l = len(data)
while True:
    s = data[i]
    i += 1
    while i < l and data[i].isdigit():
        digit_part += data[i]
        i += 1
    print("digit_part:", digit_part, i, l)
    answer += str(int(digit_part) * s)
    digit_part = ""
    if i == l - 1:
        break

with open("output.txt", "w") as f:
    f.write(answer)
