#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> result;
vector<int> p;
vector<bool> used;

long long dfs(int v)
{
    long long res = 0;
    for (auto to : g[v])
    {
        if (!used[to])
        {
            res += dfs(to);
        }
    }
    used[v] = true;
    res += p[v];
    result.push_back(v + 1);
    return res;
}

int main()
{
    int n, k;

    cin >> n;

    g.resize(n);
    used.assign(n, false);
    p.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        g[i].assign(k, 0);
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            x--;
            g[i][j] = x;
        }
    }

    cout << dfs(0) << " " << result.size() << endl;

    for (int e : result)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}