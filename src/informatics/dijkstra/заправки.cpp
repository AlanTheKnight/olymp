#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;


int main() {
    int n;
    cin >> n;

    vector<int> costs(n);
    for (int i = 0 ; i < n;i++) {
        cin >> costs[i];
    }

    int m;
    cin >> m;

    vector<vector<int>> g(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    set<pair<int, int>> q;
    q.insert({0, 0});
    vector<int> dist(n, INF);
    dist[0] = 0;

    while (q.size()) {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto to : g[u]) {
            int len = costs[u];
            if (dist[to] > dist[u] + len) {
                q.erase({dist[to], to});
                dist[to] = dist[u] + len;
                q.insert({dist[to], to});
            }
        }
    }

    int ans = dist[n - 1];
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}