from queue import PriorityQueue


class Player:
    def __init__(self, name, n, time_spend=0):
        self.name = name
        self.n = n
        self.time_spend = time_spend

    def __lt__(self, other):
        if self.time_spend == other.time_spend:
            return self.n < other.n
        return self.time_spend < other.time_spend

    def inc_time(self):
        self.time_spend += 1
        return self

    def __str__(self) -> str:
        return f"{self.name}"

    def __repr__(self) -> str:
        return str(self)


def solve(team):
    field = team[:p]

    bench = PriorityQueue()
    for i in team[p:]:
        bench.put(i)

    for _ in range(m):
        for pl in field:
            pl.inc_time()

        # The one who must leave
        rem = sorted(field, key=lambda x: (x.time_spend, x.n), reverse=True)[0]

        # Player from bench joins the game
        field.append(bench.get())
        
        # The other player goes to the bench
        field.remove(rem)
        bench.put(rem)
        
    
    return [pl.name for pl in field]


n, m, p = map(int, input().split())

players = []
for i in range(n):
    players.append(Player(input(), i))

ans = solve(players[0::2]) + solve(players[1::2])
ans.sort()
print(" ".join(ans))
