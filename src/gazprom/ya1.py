class GFG:
    def __init__(self, graph):
        self.graph = graph
        self.ppl = len(graph)
        self.jobs = len(graph[0])

    def bpm(self, u, matchR, seen):
        for v in range(self.jobs):
            if self.graph[u][v] and seen[v] is False:
                seen[v] = True
                if matchR[v] == -1 or self.bpm(matchR[v], matchR, seen):
                    matchR[v] = u
                    return True
        return False

    def maxBPM(self):
        matchR = [-1] * self.jobs
        result = 0
        for i in range(self.ppl):
            seen = [False] * self.jobs
            if self.bpm(i, matchR, seen):
                result += 1
        return result


n, k = map(int, input().split())
juices = []
for i in range(n):
    m, *juice = list(map(int, input().split()))
    juices.append(set(juice))


bg = [[0 for _ in range(n)] for i in range(n)]
for i in range(len(juices)):
    for j in range(len(juices)):
        if i != j and not (juices[i] - juices[j]):
            bg[i][j] = 1


g = GFG(bg)
print(n - g.maxBPM())
