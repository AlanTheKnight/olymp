FILENAME = "dataset_3363_3.txt"

with open(FILENAME, "r") as f:
    data = f.read().split()

d = {}
for word in data:
    cur = word.lower()
    if cur in d:
        d[cur] += 1
    else:
        d[cur] = 1

most_popular = sorted(d.items(), key=lambda x: x[1], reverse=True)[0]

with open("output.txt", "w") as f:
    f.write(f"{most_popular[0]} {most_popular[1]}")
