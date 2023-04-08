#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;

const int INF = 2000000001;

struct edge
{
    int from, to, cost;
};

int main()
{
    int m, n;
    cin >> n >> m;

    g.resize(n);

    for (int i = 0; i < m; i++)
    {
        int s, f, x;
        cin >> s >> f >> x;
        s--;
        f--;
        g[s].push_back({f, x});
        g[f].push_back({s, x});
    }

    int START, FINISH;
    cin >> START >> FINISH;
    START--;
    FINISH--;

    set<pair<int, int>> s;
    vector<int> dist1(n, INF);
    s.insert({0, START});
    dist1[START] = 0;
    while (!s.empty())
    {
        int u = s.begin()->second;
        s.erase(s.begin());
        for (auto path : g[u])
        {
            int to = path.first;
            int ans = max(dist1[u], path.second);
            if (dist1[to] > ans)
            {
                s.erase({dist1[to], to});
                dist1[to] = ans;
                s.insert({dist1[to], to});
            }
        }
    }

    cout << dist1[FINISH] << endl;

    return 0;
}