FILENAME = "dataset_3363_4.txt"


with open(FILENAME, "r") as f:
    data = f.readlines()

answer = ""
total_amount = len(data)
all_grades = [0, 0, 0]
for row in data:
    surname, *grades = row.split(";")
    grades = list(map(int, grades))
    for i in range(len(grades)):
        all_grades[i] += int(grades[i])
    answer += str(round(sum(grades) / len(grades), 9)) + "\n"


for subj in all_grades:
    answer += str(round(subj / total_amount, 9)) + " "

with open("output.txt", "w") as f:
    f.write(answer)
