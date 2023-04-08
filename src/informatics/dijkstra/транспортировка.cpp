//
// Created by alantheknight on 09.10.2021.
//

#include <bits/stdc++.h>

#define INF 1000000
#define FOR(var, n) for (size_t var = 0; (var) < (n); (var)++)

using namespace std;


vector<vector<pair<int, pair<int, int>>>> g;
int n;


bool dijkstra(int weight) {
    set<pair<int, int>> s;
    vector<int> dist(n, INF);
    s.insert({0, 0});
    dist[0] = 0;
    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());
        for (auto to: g[u]) {
            if (to.first != u && weight <= to.second.second) {
                int len = to.second.first;
                if (dist[to.first] > dist[u] + len) {
                    s.erase({dist[to.first], to.first});
                    dist[to.first] = dist[u] + len;
                    s.insert({dist[to.first], to.first});
                }
            }
        }
    }
    if (dist[n-1] <= 1440) return true;
    return false;
}


int main() {
    int m;
    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b, t, w;
        cin >> a >> b >> t >> w;
        a--;
        b--;
        g[a].push_back({b, {t, w}});
        g[b].push_back({a, {t, w}});
    }

    int l = 0;
    int r = 10000001;
    while (l < r - 1) {
        int med = (l + r) / 2;
        if (dijkstra(med * 100 + 3000000)) {
            l = med;
        } else {
            r = med;
        }
    }

    cout << l << endl;

}
