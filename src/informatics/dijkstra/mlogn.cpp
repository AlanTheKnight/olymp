#include <bits/stdc++.h>
using namespace std;

#define graph(name, nodes) vector<vector<pair<int, int>>>(name)(nodes)
#define FOR(var, n) for (size_t var = 0; (var) < (size_t)(n); (var)++)
#define ll long long
#define vect2d(name, h, w, v) vector<vector<int>>(name)(h, vector<int>(w, v))
#define INF 2009000999

void solve() {
    int n, m, start;
    cin >> n >> m;

    graph(g, n);
    vector<int> dist(n, INF);
    set<pair<int, int>> s;

    FOR(i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].push_back(make_pair(to, cost));
        g[to].push_back(make_pair(from, cost));
    }

    cin >> start;

    s.insert({0, start});
    dist[start] = 0;

    while (!s.empty()) {
        auto a = *s.begin();
        s.erase(s.begin());

        for (auto b : g[a.second]) {
            int w = a.first + b.second;

            if (w < dist[b.first]) {
                s.erase({w, b.first});
                dist[b.first] = w;
                s.insert({w, b.first});
            }
        }
    }

    FOR(i, n) { cout << dist[i] << ' '; }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}