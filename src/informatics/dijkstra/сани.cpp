#include <bits/stdc++.h>
using namespace std;

#define FOR(var, n) for (size_t var = 0; (var) < (n); (var)++)
[[maybe_unused]] typedef pair<int, int> pair_int;
[[maybe_unused]] typedef vector<vector<int>> v_2d_int;
[[maybe_unused]] typedef vector<vector<double>> v_2d_double;
const float INF = 10000000;

void printGraph(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

struct Node
{
    double dist; // Время
    int n;       // Скорость саней
    int id;      // Номер вершины
    Node(double dist, int id, int n) : dist(dist), n(n), id(id) {}

    bool operator<(const Node &rhs) const
    {
        return dist > rhs.dist;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    vector<int> t(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int ti, vi;
        cin >> ti >> vi;
        t[i] = ti;
        v[i] = vi;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int from, to, distance;
        cin >> from >> to >> distance;
        from--;
        to--;
        g[from].push_back({to, distance});
        g[to].push_back({from, distance});
    }

    double mm = -1;

    // printGraph(g);

    FOR(start, n)
    {
        v_2d_double d(n, vector<double>(101, INF));
        set<Node> q;
        // Выдвигаемся из начального города на начальных санях
        q.insert(Node(t[start], start, v[start]));
        d[start][v[start]] = t[start];

        while (!q.empty())
        {
            auto p = *q.begin();
            q.erase(q.begin());

            int cur = p.id;          // Текущий город
            int curV = p.n;          // Скорость текущих саней
            double curTime = p.dist; // Текущее время

            // Рассматриваем путь в каждый из городов
            for (auto x : g[cur])
            {
                int to = x.first;
                int distance = x.second;

                int newV;       // Скорость выбранных саней
                double newTime; // Время поездки в выбранный город

                // Если мы едем на тех же санях

                newV = curV;
                // Новое время = расстояние до города / скорость
                newTime = (double) distance / newV;
                if (d[to][curV] > curTime + newTime)
                {
                    q.erase(Node(d[to][curV], to, curV));
                    d[to][curV] = curTime + newTime;
                    q.insert(Node(d[to][curV], to, curV));
                }

                // Если мы меняем сани
                newV = v[cur]; // Берем сани в текущем городе
                // Время = расстояние до города / скорость + время ожидания
                newTime = (double) distance / newV + t[cur];

                if (d[to][newV] > curTime + newTime)
                {
                    q.erase(Node(d[to][newV], to, newV));
                    d[to][newV] = curTime + newTime;
                    q.insert(Node(d[to][newV], to, newV));
                }
            }
        }

        double m = INF;
        for (int i = 0; i <= 100; i++) {
            if (d[0][i] < m) {
                m = d[0][i];
            }
        }

        if (m > mm) {
            mm = m;
        }
    }

    cout << fixed << mm << endl;

    return 0;
}
