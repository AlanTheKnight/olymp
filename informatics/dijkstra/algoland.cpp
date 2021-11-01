#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;

struct edge
{
    int from, to, cost;
};


int main(int argc, char const *argv[])
{
    int m, n;
    cin >> n >> m;

    g.resize(n);
    vector<edge> edges;

    for (int i = 0; i < m; i++)
    {
        int s, f, x;
        cin >> s >> f >> x;
        s--;
        f--;
        g[s].push_back({f, x});
        g[f].push_back({s, x});
        edges.push_back({s, f, x});
    }

    int START, FINISH;
    cin >> START >> FINISH;
    START--; FINISH--;

    set<pair<int, int>> s1;
    vector<int> dist1(n);
    s1.insert({0, START});
    dist1[START] = 0;
    while (!s1.empty())
    {
        int u = s1.begin()->second;
        s1.erase(s1.begin());
        for (auto path : g[u])
        {
            int to = path.first;
            int ans =  max(dist1[u], path.second);
            if (dist1[to] > ans)
            {
                s1.erase({dist1[to], to});
                dist1[to] = ans;
                s1.insert({dist1[to], to});
            }
        }
    }


    set<pair<int, int>> s2;
    vector<int> dist2(n);
    s2.insert({0, FINISH});
    dist2[FINISH] = 0;
    while (!s2.empty())
    {
        int u = s2.begin()->second;
        s2.erase(s2.begin());
        for (auto path : g[u])
        {
            int to = path.first;
            int ans =  max(dist2[u], path.second);
            if (dist2[to] > ans)
            {
                s2.erase({dist2[to], to});
                dist2[to] = ans;
                s2.insert({dist2[to], to});
            }
        }
    }

    int ans = 0;
    for (auto edge : edges) {
        int path_from_start = dist1[edge.from];
        int path_from_end = dist2[edge.to];
        int cur = max(path_from_end, path_from_start) + edge.cost;
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
