#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<vector<int>> g;
int n;


void dfs(int u) {
    used[u] = true;
    for (auto i : g[u]) {
        if (!used[i]) {
            cout << u+1 << ' ' << i+1 << endl;
            dfs(i);
        }
    }
}


int main() {
    int m;
    cin >> n >> m;
    g.resize(n);
    used.assign(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    return 0;
}

