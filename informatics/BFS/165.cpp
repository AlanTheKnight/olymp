#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> g;
vector<char> color;


inline char invert(int c) {
    return c == 1 ? 2 : 1;
}


void dfs(int u, char c) {
    color[u] = c;
    for (auto v : g[u]) {
        if (color[v] == 0) {
            dfs(v, invert(c));
        } else if (color[v] != c) {
            cout << "NO" << endl;
            exit(0);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    color.resize(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, 1);
    cout << "YES" << endl;
    return 0;
}