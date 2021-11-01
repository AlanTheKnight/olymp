//
// Created by alantheknight on 09.10.2021.
//

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n, from, to;
    node(int n, int from, int to) : n(n), from(from), to(to) {}
};

int main()
{
    // Общее число деревень
    int n;
    cin >> n;
    vector<vector<node>> g(n);
    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    // Количество рейсов
    int r;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        int from, t1, to, t2;
        cin >> from >> t1 >> to >> t2;
        from--;
        to--;
        g[from].push_back(node(to, t1, t2));
    }

    // Время прибытия
    vector<int> dist(n, 1000000);
    set<pair<int, int>> s;
    s.insert({start, 0});
    dist[start] = 0;

    while (!s.empty())
    {
        // Текущая вершина
        int v = s.begin()->first;
        // Текущее минимальное расстояние
        int d = s.begin()->second;
        s.erase(s.begin());
        for (auto node : g[v])
        {
            // Можем отправиться этим рейсом только если
            // время отбытия позже чем время, в которое мы прибыли
            if (node.from >= d)
            {
                if (dist[node.n] > node.to)
                {
                    s.erase({node.n, node.to});
                    // Вместо расстояния храним время прибытия
                    dist[node.n] = node.to;
                    s.insert({node.n, node.to});
                }
            }
        }
    }

    if (dist[finish] == 1000000)
        cout << -1;
    else
        cout << dist[finish];
    cout << endl;
}
