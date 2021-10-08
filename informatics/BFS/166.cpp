#include <bits/stdc++.h>

using namespace std;

vector<int> used;
vector<vector<int>> g;
int n;
vector<int> ans;
bool has_cycle = false;

enum Colors
{
    WHITE = 0,
    GRAY = 1,
    BLACK = 2
};

void dfs(int u)
{
    used[u] = Colors::GRAY;
    for (auto i : g[u])
    {

        // We haven't visited this node yet
        if (used[i] == Colors::WHITE)
            dfs(i);

        // We found a cycle
        else if (used[i] == Colors::GRAY)
        {
            has_cycle = true;
            return;
        }
    }
    used[u] = Colors::BLACK;
    ans.push_back(u + 1);
}

int main()
{
    int m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n);
    fill(used.begin(), used.end(), false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    ans.clear();
    for (int i = 0; i < n; i++)
    {
        if (used[i] == Colors::WHITE)
        {
            dfs(i);
            if (has_cycle)
                break;
        }
    }

    if (has_cycle)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << endl;
        cout << endl;
    }

    return 0;
}
