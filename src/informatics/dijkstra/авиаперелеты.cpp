#include <bits/stdc++.h>
using namespace std;

#define graph(name, nodes) vector<vector<pair<int, int>>>(name)(nodes)
#define FOR(var, n) for (size_t var = 0; (var) < (size_t)(n); (var)++)
#define ll long long
#define vect2d(name, h, w, v) vector<vector<int>>(name)(h, vector<int>(w, v))
#define INF 10000000

struct Record {
    int cost;
    int l;
    int node;

    friend bool operator<(const Record &a, const Record &b) {
        return a.cost < b.cost;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, start, finish;
    cin >> n >> m >> k >> start >> finish;

    start--;
    finish--;

    graph(g, n);
    vect2d(dist, n, k + 1, INF);
    set<Record> s;

    FOR(i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        g[from].push_back(make_pair(to, cost));
    }

    s.insert({0, 0, start});
    FOR(i, k + 1) dist[start][i] = 0;

    while (!s.empty()) {
        auto a = *s.begin();
        s.erase(s.begin());

        for (auto b : g[a.node]) {
            int w = a.cost + b.second;
            int l = a.l + 1;

            if (w < dist[b.first][l] && l <= k) {
                dist[b.first][l] = w;
                s.insert({w, l, b.first});
            }
        }
    }

    int ans = INF;
    FOR(i, k + 1) ans = min(ans, dist[finish][i]);
    cout << (ans == INF ? -1 : ans) << endl;
}
