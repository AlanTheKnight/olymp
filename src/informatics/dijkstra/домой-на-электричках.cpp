#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define FOR(var, n) for (size_t var = 0; (var) < (n); (var)++)
[[maybe_unused]] typedef pair<int, int> pair_int;
[[maybe_unused]] typedef vector<vector<int>> v_2d_int;
[[maybe_unused]] typedef vector<vector<double>> v_2d_double;
const int INF = 10000000;

struct Edge
{
    int tBegin, tEnd, dest;
    Edge(int from, int to, int dest) : tBegin(from), tEnd(to), dest(dest) {}
};

void printGraph(vector<vector<Edge>> &graph)
{
    // Print out the graph
    for (int i = 1; i <= graph.size() - 1; ++i)
    {
        cout << "Station " << i << ": ";
        for (Edge e : graph[i])
        {
            cout << "(" << e.tBegin << "," << e.tEnd << "," << e.dest << ") ";
        }
        cout << endl;
    }
}

int main()
{

    int n,           // Количество станций
        e,           // Целевая станция
        m,           // Количество поездов
        prevStation, // Предыдущая станция
        curStation,  // Текущая станция
        curTime,     // Текущее время
        prevTime;    // Предыдущее время

    cin >> n >> e >> m;
    vector<vector<Edge>> graph(n + 1);
    vector<int> dist(n + 1, INF);
    vector<bool> isFinal(n + 1, false);

    FOR(i, m)
    {
        int len;
        cin >> len;
        vector<pair<int, int>> temp(len);
        FOR(j, len)
        {
            cin >> temp[j].first >> temp[j].second;
        }

        FOR(j, len)
        {
            for (size_t k = j + 1; k < len; k++)
            {
                graph[temp[j].first].push_back(
                    Edge(temp[j].second, temp[k].second, temp[k].first));
            }
        }
    }

    // printGraph(graph);

    dist[1] = 0;
    set<pair<int, int>> q;
    q.insert({1, 0});

    while (!q.empty())
    {
        auto cur = q.begin();
        q.erase(q.begin());
        int u = cur->first;
        int t = cur->second; // Время прибытия на текущую станцию

        for (Edge e : graph[u])
        {
            // Можно отправиться на эту станцию
            if (e.tBegin >= t)
            {
                if (dist[e.dest] > e.tEnd)
                {
                    q.erase({e.dest, e.tEnd});
                    dist[e.dest] = e.tEnd;
                    q.insert({e.dest, e.tEnd});
                }
            }
        }
    }

    if (dist[e] == INF)
        cout << -1 << endl;
    else
        cout << dist[e] << endl;
}