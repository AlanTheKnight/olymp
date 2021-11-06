#include <iostream>
#include <vector>
#include <set>
using namespace std;

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
        len,         // Длина маршрута
        prevStation, // Предыдущая станция
        curStation,  // Текущая станция
        curTime,     // Текущее время
        prevTime,    // Предыдущее время
        i, j; // Переменные для циклов
    cin >> n >> e >> m;
    const int INF = 1e9 + 1;
    vector<vector<Edge>> graph(n + 1);
    vector<int> dist(n + 1, INF);
    vector<bool> isFinal(n + 1, false);

    for (i = 0; i < m; ++i)
    {
        cin >> len >> prevStation >> prevTime;
        for (j = 1; j < len; ++j)
        {
            cin >> curStation >> curTime;
            graph[prevStation].push_back(Edge(prevTime, curTime, curStation));
        }
    }

    dist[1] = 0;

    while (true)
    {
        int minStation = -1;
        int minTime = INF;
        for (i = 1; i <= n; ++i)
        {
            if (dist[i] < minTime && !isFinal[i])
            {
                minTime = dist[i];
                minStation = i;
            }
        }

        if (minTime == INF)
        {
            break;
        }

        isFinal[minStation] = true;

        for (Edge e : graph[minStation])
        {
            // Можно отправиться на эту станцию
            if (e.tBegin >= dist[minStation])
            {
                if (e.tEnd < dist[e.dest])
                {
                    dist[e.dest] = e.tEnd;
                }
            }
        }
    }

    if (dist[e] == INF)
        cout << -1 << endl;
    else
        cout << dist[e] << endl;
}