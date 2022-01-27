n = int(input())

scoreboard = {}

for _ in range(n):
    team1, score1, team2, score2 = input().split(";")
    score1, score2 = int(score1), int(score2)
    if team1 not in scoreboard:
        scoreboard[team1] = [0, 0, 0, 0, 0]
    if team2 not in scoreboard:
        scoreboard[team2] = [0, 0, 0, 0, 0]
    scoreboard[team1][0] += 1
    scoreboard[team2][0] += 1
    if score1 > score2:
        scoreboard[team1][1] += 1
        scoreboard[team2][3] += 1
        scoreboard[team1][4] += 3
    elif score1 < score2:
        scoreboard[team1][3] += 1
        scoreboard[team2][1] += 1
        scoreboard[team2][4] += 3
    else:
        scoreboard[team1][2] += 1
        scoreboard[team2][2] += 1
        scoreboard[team1][4] += 1
        scoreboard[team2][4] += 1


for team in scoreboard:
    print(team, ":", sep="", end="")
    print(*scoreboard[team])
