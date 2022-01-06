#include <bits/stdc++.h>
using namespace std;

vector<bool> used;
vector<vector<int>> g;
int maxLevel;

void dfs(int u, int level)
{
    used[u] = true;
    maxLevel = max(level, maxLevel);
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v, level + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("beads.in", "r", stdin);
    // freopen("beads.out", "w", stdout);

    int n;
    cin >> n;
    g.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    maxLevel = 0;
    for (int i = 0; i < n; i++)
    {
        used.assign(n, false);
        dfs(i, 1);
    }
    cout << maxLevel << endl;

    return 0;
}
