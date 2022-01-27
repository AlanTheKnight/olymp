FILENAME = "table.in.txt"

with open(FILENAME, "r") as f:
    data = list(
        map(
            lambda x: [int(x[0]), x[1], int(x[2])],
            map(lambda x: x.split("\t"), f.read().splitlines()),
        )
    )


for i in range(1, 12):
    students = list(filter(lambda x: x[0] == i, data))
    if len(students) == 0:
        print(i, "-")
    else:
        avg = sum(map(lambda x: x[2], students)) / len(students)
        print(i, avg)
